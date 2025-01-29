#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>

struct Jogador {
    std::string nome;
    std::string apelido;
    int vitorias;
    int derrotas;

    std::string serialize() const;
    static Jogador deserialize(const std::string& linha);
};

#endif // JOGADOR_HPP
