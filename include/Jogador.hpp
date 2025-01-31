#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <map>

class Jogador {
public:
    std::string apelido;
    std::string nome;
    struct Estatisticas {
        int vitorias_reversi = 0;
        int derrotas_reversi = 0;
        int vitorias_lig4 = 0;
        int derrotas_lig4 = 0;
        int vitorias_velha = 0;
        int derrotas_velha = 0;
    };
    Estatisticas stats;
};

#endif
