#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "JogoDeTabuleiro.hpp"
#include <vector>

class Reversi : public JogoDeTabuleiro
{
private:
    std::vector<std::vector<char>> tabuleiro;

public:
    Reversi(int linhas = 8, int colunas = 8)
        : linhas(linhas), colunas(colunas)
    {
        tabuleiro.resize(linhas, std::vector<char>(colunas, ' '));
        tabuleiro[3][3] = tabuleiro[4][4] = 'X';
        tabuleiro[3][4] = tabuleiro[4][3] = 'O';
    }

    void RealizarJogada(int linha, int coluna, char jogador) override
    {
        if (!JogadaValida(linha, coluna, jogador))
        {
            std::cout << "Jogada inválida!" << std::endl;
            return;
        }

        tabuleiro[linha][coluna] = jogador;
        char adversario = (jogador == 'X') ? 'O' : 'X';
        const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                     {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        for (auto &direcao : direcoes)
        {
            int dLinha = direcao[0], dColuna = direcao[1];
            int x = linha + dLinha, y = coluna + dColuna;
            std::vector<std::pair<int, int>> toFlip;

            while (x >= 0 && x < linhas && y >= 0 && y < colunas)
            {
                if (tabuleiro[x][y] == adversario)
                {
                    toFlip.push_back({x, y});
                }
                else if (tabuleiro[x][y] == jogador)
                {
                    for (auto &[flipX, flipY] : toFlip)
                    {
                        tabuleiro[flipX][flipY] = jogador;
                    }
                    break;
                }
                else
                {
                    break;
                }
                x += dLinha;
                y += dColuna;
            }
        }
    }

    bool JogadaValida(int linha, int coluna, char jogador) const override
    {
        if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas)
            return false;
        if (tabuleiro[linha][coluna] != ' ')
            return false;

        char adversario = (jogador == 'X') ? 'O' : 'X';
        const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                     {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        for (auto &direcao : direcoes)
        {
            int dLinha = direcao[0], dColuna = direcao[1];
            int x = linha + dLinha, y = coluna + dColuna;
            bool encontrouAdversario = false;

            while (x >= 0 && x < linhas && y >= 0 && y < colunas)
            {
                if (tabuleiro[x][y] == adversario)
                {
                    encontrouAdversario = true;
                }
                else if (tabuleiro[x][y] == jogador && encontrouAdversario)
                {
                    return true;
                }
                else
                {
                    break;
                }
                x += dLinha;
                y += dColuna;
            }
        }

        return false;
    }

    bool VerificarVitoria(char jogador) const override
    {
        int countJogador = 0, countAdversario = 0;
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                if (tabuleiro[i][j] == jogador)
                    countJogador++;
                else if (tabuleiro[i][j] == (jogador == 'X' ? 'O' : 'X'))
                    countAdversario++;
            }
        }
        return countJogador > countAdversario;
    }

    void ImprimirTabuleiro() const override
    {
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                std::cout << (tabuleiro[i][j] == ' ' ? '.' : tabuleiro[i][j]) << " ";
            }
            std::cout << std::endl;
        }
    }

    void Reiniciar() override
    {
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                tabuleiro[i][j] = ' ';
            }
        }
        tabuleiro[3][3] = tabuleiro[4][4] = 'X';
        tabuleiro[3][4] = tabuleiro[4][3] = 'O';
    }
};

#endif // REVERSI_HPP
