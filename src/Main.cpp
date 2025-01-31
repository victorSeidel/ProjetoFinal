#include "ExecutarPartida.hpp"
#include "cadastro.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <limits>

void exibirMenu() {
    std::cout << "\nComandos disponiveis:\n";
    std::cout << "CJ <Apelido> <Nome>        - Cadastrar jogador\n";
    std::cout << "RJ <Apelido>               - Remover jogador\n";
    std::cout << "LJ [A|N]                   - Listar jogadores ordenados\n";
    std::cout << "EP <Jogo: R|L|V> <Jog1> <Jog2> - Executar partida\n";
    std::cout << "FS                         - Finalizar sistema\n";
}

int main() {
    CadastroJogadores cadastro;
    cadastro.carregarDoArquivo(); // Carrega dados ao iniciar

    std::cout << "=== Sistema de Jogos de Tabuleiro ===\n";
    exibirMenu();

    std::string linha;
    while (true) {
        std::cout << "\n> ";
        std::getline(std::cin, linha);
        std::stringstream ss(linha);
        std::string comando;
        ss >> comando;

        if (comando == "CJ") {
            std::string apelido, nome;
            if (ss >> apelido >> nome) {
                std::cout << cadastro.cadastrar(apelido, nome) << "\n";
            } else {
                std::cout << "ERRO: dados incorretos\n";
            }
        } 
        else if (comando == "RJ") {
            std::string apelido;
            if (ss >> apelido) {
                std::cout << cadastro.remover(apelido) << "\n";
            } else {
                std::cout << "ERRO: dados incorretos\n";
            }
        } 
        else if (comando == "LJ") {
            char ordem;
            if (ss >> ordem && (ordem == 'A' || ordem == 'N')) {
                cadastro.listar(ordem);
            } else {
                std::cout << "ERRO: use 'LJ A' ou 'LJ N'\n";
            }
        } 
        else if (comando == "EP") {
            std::string jogo, apelido1, apelido2;
                if (ss >> jogo >> apelido1 >> apelido2) {
                    // Verifica jogadores
                    if (!cadastro.jogadorExiste(apelido1) || !cadastro.jogadorExiste(apelido2)) {
                        std::cout << "ERRO: Jogador(es) nao cadastrado(s): " 
                        << (!cadastro.jogadorExiste(apelido1) ? apelido1 : "") 
                        << (!cadastro.jogadorExiste(apelido2) ? " " + apelido2 : "") 
                        << "\n";
                    continue;
                    }


                Jogador& jogador1 = cadastro.getJogador(apelido1);
                Jogador& jogador2 = cadastro.getJogador(apelido2);
                int codigoJogo;

                if (jogo == "R") codigoJogo = 1;      // Reversi
                else if (jogo == "L") codigoJogo = 2; // Lig4
                else if (jogo == "V") codigoJogo = 3; // Velha
                else {
                    std::cout << "ERRO: jogo invalido. Use R, L ou V\n";
                    continue;
                }

                // Executa a partida
                JogoDeTabuleiro* jogoPtr = nullptr;
                switch (codigoJogo) {
                    case 1: // Reversi
                        jogoPtr = new Reversi();
                        dynamic_cast<Reversi*>(jogoPtr)->DefinirApelidos(apelido1, apelido2);
                    break;
                    case 2: // Lig4
                        jogoPtr = new Lig4();
                        dynamic_cast<Lig4*>(jogoPtr)->DefinirApelidos(apelido1, apelido2);
                    break;
                    case 3: // Velha
                        jogoPtr = new JogoDaVelha();
                        dynamic_cast<JogoDaVelha*>(jogoPtr)->DefinirApelidos(apelido1, apelido2);
                    break;
                }

                int resultado = jogoPtr->Jogar();
                delete jogoPtr;

                // Atualiza estatísticas
                if (resultado == 1) {
                    switch (codigoJogo) {
                        case 1: jogador1.stats.vitorias_reversi++; jogador2.stats.derrotas_reversi++; break;
                        case 2: jogador1.stats.vitorias_lig4++; jogador2.stats.derrotas_lig4++; break;
                        case 3: jogador1.stats.vitorias_velha++; jogador2.stats.derrotas_velha++; break;
                    }
                } else if (resultado == 2) {
                    switch (codigoJogo) {
                        case 1: jogador2.stats.vitorias_reversi++; jogador1.stats.derrotas_reversi++; break;
                        case 2: jogador2.stats.vitorias_lig4++; jogador1.stats.derrotas_lig4++; break;
                        case 3: jogador2.stats.vitorias_velha++; jogador1.stats.derrotas_velha++; break;
                    }
                }

                cadastro.salvarEmArquivo();
                std::cout << "Partida finalizada! Estatisticas atualizadas.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer
                exibirMenu();

            } else {
                std::cout << "ERRO: Formato incorreto. Use: EP <R|L|V> <apelido1> <apelido2>\n";
            }
        } 
        else if (comando == "FS") {
            std::cout << "Finalizando sistema...\n";
            break;
        } 
        else {
            std::cout << "ERRO: comando desconhecido\n";
            exibirMenu();
        }
    }

    return 0;
}