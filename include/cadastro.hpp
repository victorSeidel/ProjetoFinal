#ifndef CADASTRO_HPP
#define CADASTRO_HPP
#pragma once

#include <map>
#include <string>
#include <vector>
#include "jogador.hpp"

class CadastroJogadores {
private:
    std::map<std::string, Jogador> jogadores;
    const std::string arquivo = "jogadores.txt";

public:
    // Operações básicas
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