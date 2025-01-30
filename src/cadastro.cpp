#include "cadastro.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stdexcept>

// Implementações dos métodos

std::string CadastroJogadores::cadastrar(const std::string& apelido, const std::string& nome) {
    if (apelido.empty() || nome.empty()) return "ERRO: dados incorretos";
    if (jogadores.find(apelido) != jogadores.end()) return "ERRO: jogador repetido";
    
    Jogador novoJogador;
    novoJogador.apelido = apelido;
    novoJogador.nome = nome;
    jogadores[apelido] = novoJogador;
    salvarEmArquivo();
    return "Jogador " + apelido + " cadastrado com sucesso";
}

std::string CadastroJogadores::remover(const std::string& apelido) {
    auto it = jogadores.find(apelido);
    if (it == jogadores.end()) return "ERRO: jogador inexistente";
    
    jogadores.erase(it);
    salvarEmArquivo();
    return "Jogador " + apelido + " removido com sucesso";
}

void CadastroJogadores::listar(char ordenarPor) {
    std::vector<Jogador> lista;
    for (const auto& pair : jogadores) lista.push_back(pair.second);

    if (ordenarPor == 'N') {
        std::sort(lista.begin(), lista.end(), [](const Jogador& a, const Jogador& b) {
            return a.nome < b.nome;
        });
    } else {
        std::sort(lista.begin(), lista.end(), [](const Jogador& a, const Jogador& b) {
            return a.apelido < b.apelido;
        });
    }

    for (const auto& jogador : lista) {
        std::cout << jogador.apelido << " " << jogador.nome << "\n";
        std::cout << "REVERSI - V: " << jogador.stats.vitorias_reversi 
                  << " D: " << jogador.stats.derrotas_reversi << "\n";
        std::cout << "LIG4 - V: " << jogador.stats.vitorias_lig4 
                  << " D: " << jogador.stats.derrotas_lig4 << "\n";
        std::cout << "VELHA - V: " << jogador.stats.vitorias_velha 
                  << " D: " << jogador.stats.derrotas_velha << "\n\n";
    }
}

void CadastroJogadores::salvarEmArquivo() {
    try {
        std::ofstream file(arquivo);
        if (!file) {
            throw std::runtime_error("Não foi possível criar/abrir o arquivo.");
        }

        for (const auto& pair : jogadores) {
            const Jogador& j = pair.second;
            file << j.apelido << ","
                 << j.nome << ","
                 << j.stats.vitorias_reversi << ","
                 << j.stats.derrotas_reversi << ","
                 << j.stats.vitorias_lig4 << ","
                 << j.stats.derrotas_lig4 << ","
                 << j.stats.vitorias_velha << ","
                 << j.stats.derrotas_velha << "\n";
        }
        file.close();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao salvar dados: " << e.what() << std::endl;
    }
}

void CadastroJogadores::carregarDoArquivo() {
    try {
        std::ifstream file(arquivo);
        
        // Cria arquivo se não existir
        if (!file) {
            std::ofstream novoArquivo(arquivo); // Cria arquivo vazio
            std::cout << "Arquivo de jogadores criado.\n"; // Log para depuração
            return;
        }

        std::string linha;
        while (std::getline(file, linha)) {
            std::stringstream ss(linha);
            Jogador j;
            
            // Lê apelido e nome
            if (!std::getline(ss, j.apelido, ',') || j.apelido.empty()) continue;
            if (!std::getline(ss, j.nome, ',') || j.nome.empty()) continue;

            // Função auxiliar para ler valores numéricos com segurança
            auto lerValor = [&](int& valor) {
                std::string temp;
                if (!std::getline(ss, temp, ',')) return false;
                try {
                    valor = std::stoi(temp);
                } catch (...) {
                    valor = 0;
                }
                return true;
            };

            // Lê estatísticas
            lerValor(j.stats.vitorias_reversi);
            lerValor(j.stats.derrotas_reversi);
            lerValor(j.stats.vitorias_lig4);
            lerValor(j.stats.derrotas_lig4);
            lerValor(j.stats.vitorias_velha);
            lerValor(j.stats.derrotas_velha);

            jogadores[j.apelido] = j;
        }
        file.close();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao carregar dados: " << e.what() << std::endl;
    }
}

bool CadastroJogadores::jogadorExiste(const std::string& apelido) const {
    return jogadores.find(apelido) != jogadores.end();
}

Jogador& CadastroJogadores::getJogador(const std::string& apelido) {
    auto it = jogadores.find(apelido);
    if (it == jogadores.end()) {
        throw std::runtime_error("Jogador não encontrado: " + apelido);
    }
    return it->second;
}