#ifndef CADASTRO_HPP
#define CADASTRO_HPP
#pragma once

#include <map>
#include <string>
#include <vector>
#include "jogador.hpp"
/**
* @brief Classe que cuida do cadastro de jogadores. 
*/
class CadastroJogadores {
private:
/**
* @brief Mapa com cada jogador cadastrado, utilizando o apelido do jogador como chave.
*/
    std::map<std::string, Jogador> jogadores;
/**
* @brief Nome do arquivo em que são salvos os dados dos jogadores.
*/
    const std::string arquivo = "jogadores.txt";

public:
    // Operações básicas
/**
* @brief Método para adicionar jogadores ao mapa.
*/
    std::string cadastrar(const std::string& apelido, const std::string& nome);
    std::string remover(const std::string& apelido);
    void listar(char ordenarPor);

    // Persistência
    void salvarEmArquivo();
    void carregarDoArquivo();

    // Consultas
    bool jogadorExiste(const std::string& apelido) const;
    Jogador& getJogador(const std::string& apelido);
};

#endif
