#ifndef CADASTRO_DE_JOGADORES_H
#define CADASTRO_DE_JOGADORES_H

#include "Jogador.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

class CadastroDeJogadores {
private:
    std::vector<Jogador> jogadores;
    const std::string arquivoCadastro = "jogadores.txt";

    void salvarEmArquivo();
    void carregarDoArquivo();

public:
    CadastroDeJogadores();
    ~CadastroDeJogadores();

    void cadastrarJogador(const std::string& nome, const std::string& apelido);
    void removerJogador(const std::string& apelido);
    void listarJogadores() const;
};

#endif // CADASTRO_DE_JOGADORES_H
