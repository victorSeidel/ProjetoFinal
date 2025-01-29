#ifndef EXECUTAR_PARTIDA_HPP
#define EXECUTAR_PARTIDA_HPP

#include <iostream>
#include <string>
#include "Reversi.hpp" // Inclua outros jogos conforme necessário
#include "JogoDaVelha.hpp"
#include "Lig4.hpp"
#include "Jogador.hpp"

class ExecutarPartida 
{
    public:
        void IniciarJogo(jogador j1, jogador j2);
};

#endif // EXECUTAR_PARTIDA_HPP
