#include <iostream>

#include "Lig4.hpp"

Lig4::Lig4() : JogoDeTabuleiro(6, 7) {}

Lig4::~Lig4() {}

void Lig4::ImprimirTabuleiro() const 
{
    for (const auto& linha : tabuleiro) 
    {
        for (const auto& celula : linha) 
        {
            std::cout << (celula == 0 ? '.' : celula) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "1 2 3 4 5 6 7" << std::endl;
}

bool Lig4::JogadaValida(int linha, int coluna) const 
{
    if (coluna < 0 || coluna >= colunas) return false;

    return tabuleiro[0][coluna] == '.'; // Verifica se a coluna não está cheia
}

void Lig4::RealizarJogada(int linha, int coluna, char jogador) 
{
    if (!JogadaValida(linha, coluna)) 
    {
        throw std::invalid_argument("Jogada inválida!");
    }

    // Encontra a posição mais baixa disponível na coluna
    for (int i = linhas - 1; i >= 0; --i) 
    {
        if (tabuleiro[i][coluna] == '.') 
        {
            tabuleiro[i][coluna] = jogador;
            break;
        }
    }
}

void Lig4::Reiniciar() 
{
    for (auto& linha : tabuleiro) 
    {
        std::fill(linha.begin(), linha.end(), '.');
    }
}

bool Lig4::VerificarVitoria(char jogador) const 
{
    // Verifica todas as células do tabuleiro
    for (int i = 0; i < linhas; ++i) 
    {
        for (int j = 0; j < colunas; ++j) 
        {
            if (tabuleiro[i][j] == jogador) 
            {
                // Verifica todas as direções a partir da célula atual
                if (VerificarDirecao(i, j, 0, 1, jogador) ||  // Direita
                    VerificarDirecao(i, j, 1, 0, jogador) ||  // Baixo
                    VerificarDirecao(i, j, 1, 1, jogador) ||  // Diagonal direita
                    VerificarDirecao(i, j, 1, -1, jogador))   // Diagonal esquerda
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Lig4::VerificarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador) const 
{
    int count = 0;

    for (int k = 0; k < 4; ++k) 
    {
        int novaLinha = linha + k * dLinha;
        int novaColuna = coluna + k * dColuna;

        if (novaLinha < 0 || novaLinha >= linhas || novaColuna < 0 || novaColuna >= colunas) return false;

        if (tabuleiro[novaLinha][novaColuna] == jogador) ++count;
        else break;
    }

    return count == 4;
}

int Lig4::Jogar()
{
    return ExecutarPartida();
}

int Lig4::ExecutarPartida() 
{
    char jogadorAtual = 'X';
    int jogador = 0;
    bool jogoAtivo = true;

    std::cout << "----- Lig4 -----" << std::endl;

    while (jogoAtivo) 
    {
        ImprimirTabuleiro();
        int coluna;

        std::cout << std::endl << "Jogador " << jogadorAtual << ", escolha uma coluna (1 a 7): ";

        std::cin >> coluna

        if (coluna < 1 || coluna > 7) 
        {
            std::cout << "Erro: Jogada inválida! Escolha uma coluna de 1 a 7." << std::endl;
            continue;
        }

        try 
        {
            RealizarJogada(0, coluna - 1, jogadorAtual);
            ImprimirTabuleiro();

            if (VerificarVitoria(jogadorAtual)) 
            {
                std::cout << "O jogador " << jogadorAtual << " venceu!" << std::endl;

                if (jogadorAtual == 'X') jogador = 1;
                else if (jogadorAtual == 'O') jogador = 2;

                jogoAtivo = false;
            } 
            else 
            {
                jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
            }
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << "Erro: " << e.what() << std::endl;
        }

        bool empate = true;
        for (int i = 0; i < 7; ++i) 
        {
            if (JogadaValida(0, i)) 
            {
                empate = false;
                break;
            }
        }

        if (empate) 
        {
            ImprimirTabuleiro();
            std::cout << "O jogo terminou em empate!" << std::endl;
            jogoAtivo = false;
        }
    }

    return jogador;
}
