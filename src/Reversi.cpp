#include "Reversi.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

// Construtor
Reversi::Reversi() : JogoDeTabuleiro(8, 8), jogadorAtual('X'), jogoFinalizado(false) {
    Reiniciar();
}

// Impressão do tabuleiro com coordenadas
void Reversi::ImprimirTabuleiro() const {
    std::cout << "\n  ";
    for (char c = 'A'; c < 'A' + colunas; ++c) {
        std::cout << c << " ";
    }
    std::cout << "\n";

    for (int l = 0; l < linhas; ++l) {
        std::cout << l + 1 << " ";
        for (int c = 0; c < colunas; ++c) {
            std::cout << tabuleiro[l][c] << " ";
        }
        std::cout << "\n";
    }
}

// Validação de jogada com flanking
bool Reversi::JogadaValida(int linha, int coluna) const {
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas || tabuleiro[linha][coluna] != ' ') {
        return false;
    }

    const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                {0, -1},  {0, 1},  {1, -1},
                                {1, 0},   {1, 1}};
    char oponente = (jogadorAtual == 'X') ? 'O' : 'X';

    for (const auto& dir : direcoes) {
        int x = linha + dir[0];
        int y = coluna + dir[1];
        bool encontrouOponente = false;

        while (x >= 0 && x < linhas && y >= 0 && y < colunas) {
            if (tabuleiro[x][y] == oponente) {
                encontrouOponente = true;
                x += dir[0];
                y += dir[1];
            } else if (tabuleiro[x][y] == jogadorAtual) {
                if (encontrouOponente) return true;
                else break;
            } else {
                break;
            }
        }
    }
    return false;
}

// Implementação completa da jogada
void Reversi::RealizarJogada(int linha, int coluna, char jogador) {
    if (jogador != jogadorAtual || !JogadaValida(linha, coluna)) return;

    tabuleiro[linha][coluna] = jogador;
    const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                {0, -1},  {0, 1},  {1, -1},
                                {1, 0},   {1, 1}};
    char oponente = (jogador == 'X') ? 'O' : 'X';

    for (const auto& dir : direcoes) {
        int x = linha + dir[0];
        int y = coluna + dir[1];
        std::vector<std::pair<int, int>> paraVirar;

        while (x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == oponente) {
            paraVirar.emplace_back(x, y);
            x += dir[0];
            y += dir[1];
        }

        if (x >= 0 && x < linhas && y >= 0 && y < colunas && tabuleiro[x][y] == jogador) {
            for (const auto& pos : paraVirar) {
                tabuleiro[pos.first][pos.second] = jogador;
            }
        }
    }

    // Verificação de fim de jogo
    char proximoJogador = (jogador == 'X') ? 'O' : 'X';
    if (!PodeJogar(proximoJogador)) {
        if (!PodeJogar(jogador)) {
            jogoFinalizado = true;
        } else {
            std::cout << "Jogador " << proximoJogador << " não pode jogar. Turno mantido.\n";
        }
    }
    jogadorAtual = proximoJogador;
}

// Reinicialização correta do tabuleiro
void Reversi::Reiniciar() {
    for (auto& linha : tabuleiro) {
        std::fill(linha.begin(), linha.end(), ' ');
    }
    // Posições iniciais para tabuleiro 8x8
    tabuleiro[3][3] = 'O';
    tabuleiro[3][4] = 'X';
    tabuleiro[4][3] = 'X';
    tabuleiro[4][4] = 'O';
    jogoFinalizado = false;
    jogadorAtual = 'X';
}

// Verificação de vitória por contagem
bool Reversi::VerificarVitoria(char jogador) const {
    int countJogador = 0, countOponente = 0;
    char oponente = (jogador == 'X') ? 'O' : 'X';

    for (const auto& linha : tabuleiro) {
        for (char c : linha) {
            if (c == jogador) countJogador++;
            else if (c == oponente) countOponente++;
        }
    }
    return countJogador > countOponente;
}

// Loop principal totalmente funcional
void Reversi::ExecutarPartida() {
    std::string entrada;
    while (!jogoFinalizado) {
        // Verifica se o jogador atual pode jogar
        if (!PodeJogar(jogadorAtual)) {
            if (!PodeJogar((jogadorAtual == 'X') ? 'O' : 'X')) {
                jogoFinalizado = true;
                break;
            }
            std::cout << "Jogador " << jogadorAtual << " não pode jogar. Passando a vez.\n";
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
            continue;
        }

        ImprimirTabuleiro();
        std::cout << "\nJogador " << jogadorAtual << ", insira uma posição (ex: A1) ou 'sair': ";
        std::cin >> entrada;

        if (entrada == "sair") break;

        int linha, coluna;
        if (!ConverterEntrada(entrada, linha, coluna)) {
            std::cout << "Formato inválido! Use letra+número (ex: A1)\n";
            continue;
        }

        if (JogadaValida(linha, coluna)) {
            RealizarJogada(linha, coluna, jogadorAtual);
        } else {
            std::cout << "Jogada inválida!\n";
        }

        // Verifica se o tabuleiro está cheio
        bool tabuleiroCheio = true;
        for (const auto& linha : tabuleiro) {
            if (std::any_of(linha.begin(), linha.end(), [](char c) { return c == ' '; })) {
                tabuleiroCheio = false;
                break;
            }
        }
        if (tabuleiroCheio) jogoFinalizado = true;
    }

    // Resultado final
    ImprimirTabuleiro();
    std::cout << "\n--- Fim do Jogo! ---\n";
    if (VerificarVitoria('X') && VerificarVitoria('O')) {
        std::cout << "Empate!\n";
    } else if (VerificarVitoria('X')) {
        std::cout << "Jogador X venceu!\n";
    } else {
        std::cout << "Jogador O venceu!\n";
    }
}

// Métodos auxiliares
bool Reversi::PodeJogar(char jogador) const {
    for (int l = 0; l < linhas; ++l) {
        for (int c = 0; c < colunas; ++c) {
            if (tabuleiro[l][c] == ' ') {
                const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                                            {0, -1},  {0, 1},  {1, -1},
                                            {1, 0},   {1, 1}};
                char oponente = (jogador == 'X') ? 'O' : 'X';

                for (const auto& dir : direcoes) {
                    int x = l + dir[0];
                    int y = c + dir[1];
                    bool encontrouOponente = false;

                    while (x >= 0 && x < linhas && y >= 0 && y < colunas) {
                        if (tabuleiro[x][y] == oponente) {
                            encontrouOponente = true;
                            x += dir[0];
                            y += dir[1];
                        } else if (tabuleiro[x][y] == jogador && encontrouOponente) {
                            return true;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Reversi::ConverterEntrada(const std::string& entrada, int& linha, int& coluna) const {
    if (entrada.size() < 2 || !isalpha(entrada[0]) || !isdigit(entrada[1])) return false;
    
    coluna = toupper(entrada[0]) - 'A';
    linha = entrada[1] - '1';
    return (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas);
}