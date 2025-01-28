#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Reversi.hpp"

TEST_CASE("Teste de Inicialização do Tabuleiro") {
    Reversi jogo;
    CHECK(jogo.tabuleiro[3][3] == 'O');
    CHECK(jogo.tabuleiro[3][4] == 'X');
    CHECK(jogo.tabuleiro[4][3] == 'X');
    CHECK(jogo.tabuleiro[4][4] == 'O');
    
    // Verifica células vazias
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i == 3 || i == 4) && (j == 3 || j == 4)) continue;
            CHECK(jogo.tabuleiro[i][j] == ' ');
        }
    }
}

TEST_CASE("Teste de Jogadas Válidas") {
    Reversi jogo;
    CHECK(jogo.JogadaValida(2, 3) == true);   // Jogada inicial válida para X
    CHECK(jogo.JogadaValida(5, 4) == true);   // Jogada inicial válida para X
    CHECK(jogo.JogadaValida(0, 0) == false);  // Posição inválida
}

TEST_CASE("Teste de Conversão de Entrada") {
    Reversi jogo;
    int linha, coluna;
    
    SUBCASE("Entrada válida") {
        CHECK(jogo.ConverterEntrada("A1", linha, coluna) == true);
        CHECK(linha == 0);
        CHECK(coluna == 0);
    }
    
    SUBCASE("Entrada inválida") {
        CHECK(jogo.ConverterEntrada("Z9", linha, coluna) == false);
        CHECK(jogo.ConverterEntrada("A0", linha, coluna) == false);
    }
}

TEST_CASE("Teste de Realização de Jogada") {
    Reversi jogo;
    jogo.RealizarJogada(2, 3, 'X');
    
    // Verifica se as peças foram invertidas
    CHECK(jogo.tabuleiro[2][3] == 'X');
    CHECK(jogo.tabuleiro[3][3] == 'X');  // Peça O original foi flanqueada
}

TEST_CASE("Teste de Vitória") {
    Reversi jogo;
    
    SUBCASE("Vitória de X") {
        // Simula tabuleiro com maioria X
        for (auto& linha : jogo.tabuleiro) std::fill(linha.begin(), linha.end(), 'X');
        CHECK(jogo.VerificarVitoria('X') == true);
    }
    
    SUBCASE("Empate") {
        // Configura tabuleiro com igualdade
        for (auto& linha : jogo.tabuleiro) {
            std::fill(linha.begin(), linha.end(), 'X');
            linha[7] = 'O'; // Garante igualdade
        }
        CHECK(jogo.VerificarVitoria('X') == false);
        CHECK(jogo.VerificarVitoria('O') == false);
    }
}

TEST_CASE("Teste de Reinicialização") {
    Reversi jogo;
    jogo.RealizarJogada(2, 3, 'X'); // Modifica o tabuleiro
    jogo.Reiniciar(); // Reinicia
    
    CHECK(jogo.tabuleiro[3][3] == 'O'); // Posição original
    CHECK(jogo.jogadorAtual == 'X');    // Jogador inicial
}

TEST_CASE("Teste de Passagem de Turno") {
    Reversi jogo;
    
    SUBCASE("Jogador O não pode jogar") {
        // Bloqueia todas as jogadas para O
        for (auto& linha : jogo.tabuleiro) std::fill(linha.begin(), linha.end(), 'X');
        CHECK(jogo.PodeJogar('O') == false);
    }
}