#ifndef CADASTRO_DE_JOGADORES_HPP
#define CADASTRO_DE_JOGADORES_HPP

#include "Jogador.hpp"
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
    void adicionarVitoria(const std::string& apelido);
    void adicionarDerrota(const std::string& apelido);
};

#endif // CADASTRO_DE_JOGADORES_H
