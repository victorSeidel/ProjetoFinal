#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <map>
/**
* @brief Classe que representa um jogador, com seus dados e estatísticas.
*/
class Jogador 
{
public:
    std::string apelido; 
    std::string nome;
/**
* @brief Número de vitórias e derrotas em cada jogo.
*/
    struct Estatisticas 
    {
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
