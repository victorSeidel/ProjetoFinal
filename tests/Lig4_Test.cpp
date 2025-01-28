#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/JogoDeTabuleiro.hpp"
#include "../include/Lig4.hpp"

TEST_CASE("Jogada válida") 
{
    Lig4 jogo;
    jogo.Reiniciar();
    CHECK(jogo.JogadaValida(0, 0) == true);
    CHECK(jogo.JogadaValida(0, 6) == true);
}

TEST_CASE("Jogada inválida em coluna cheia") 
{
    Lig4 jogo;
    jogo.Reiniciar();

    for (int i = 0; i < 6; ++i) 
    {
        jogo.RealizarJogada(0, 0, 'X');
    }
    
    CHECK(jogo.JogadaValida(0, 0) == false);
}

TEST_CASE("Jogada inválida fora dos limites") 
{
    Lig4 jogo;
    jogo.Reiniciar();

    CHECK(jogo.JogadaValida(0, -1) == false);
    CHECK(jogo.JogadaValida(0, 7) == false);
}

TEST_CASE("Vitória horizontal") 
{
    Lig4 jogo;
    jogo.Reiniciar();

    for (int i = 0; i < 4; ++i) 
    {
        jogo.RealizarJogada(0, i, 'X');
    }

    CHECK(jogo.VerificarVitoria('X') == true);
}

TEST_CASE("Vitória vertical") 
{
    Lig4 jogo;
    jogo.Reiniciar();

    for (int i = 0; i < 4; ++i)
    {
        jogo.RealizarJogada(0, 0, 'X');
    }

    CHECK(jogo.VerificarVitoria('X') == true);
}

TEST_CASE("Vitória diagonal direita") 
{
    Lig4 jogo;
    jogo.Reiniciar();

    jogo.RealizarJogada(0, 0, 'X');
    jogo.RealizarJogada(0, 1, 'O');
    jogo.RealizarJogada(0, 1, 'X');
    jogo.RealizarJogada(0, 2, 'O');
    jogo.RealizarJogada(0, 2, 'O');
    jogo.RealizarJogada(0, 2, 'X');
    jogo.RealizarJogada(0, 3, 'O');
    jogo.RealizarJogada(0, 3, 'O');
    jogo.RealizarJogada(0, 3, 'O');
    jogo.RealizarJogada(0, 3, 'X');

    CHECK(jogo.VerificarVitoria('X') == true);
}

TEST_CASE("Vitória diagonal esquerda") 
{
    Lig4 jogo;
    jogo.Reiniciar();

    jogo.RealizarJogada(0, 3, 'X');
    jogo.RealizarJogada(0, 2, 'O');
    jogo.RealizarJogada(0, 2, 'X');
    jogo.RealizarJogada(0, 1, 'O');
    jogo.RealizarJogada(0, 1, 'O');
    jogo.RealizarJogada(0, 1, 'X');
    jogo.RealizarJogada(0, 0, 'O');
    jogo.RealizarJogada(0, 0, 'O');
    jogo.RealizarJogada(0, 0, 'O');
    jogo.RealizarJogada(0, 0, 'X');

    CHECK(jogo.VerificarVitoria('X') == true);
}

TEST_CASE("Empate") 
{
    Lig4 jogo;
    jogo.Reiniciar();

    for (int col = 0; col < 7; ++col) 
    {
        for (int row = 0; row < 6; ++row) 
        {
            jogo.RealizarJogada(0, col, (row % 2 == 0) ? 'X' : 'O');
        }
    }

    CHECK(jogo.VerificarVitoria('X') == false);
    CHECK(jogo.VerificarVitoria('O') == false);

    for (int col = 0; col < 7; ++col)
    {
        CHECK(jogo.JogadaValida(0, col) == false);
    }
}
