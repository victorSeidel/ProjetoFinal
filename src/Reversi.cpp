#include "Reversi.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

/**
 * @brief Inicia o jogo de Reversi chamando o loop principal.
 */
int Reversi::Jogar() {
    return ExecutarPartida(); // Chama o loop principal do jogo
}

// Construtor
/**
 * @brief Construtor da classe Reversi.
 * Inicializa o tabuleiro 8x8, define o jogador inicial como 'X' e reinicia o jogo.
 */
Reversi::Reversi() : JogoDeTabuleiro(8, 8), jogadorAtual('X'), jogoFinalizado(false) {
    Reiniciar();
}

/**
 * @brief Exibe as instruções do jogo, incluindo regras e comandos.
 */
void Reversi::ExibirInstrucoes() const {
    std::cout << "\n=== REVERSI ===\n";
    std::cout << "Instrucoes:\n";
    std::cout << "1. Objetivo: Ter mais pecas (" << jogadorAtual << ") no tabuleiro\n";
    std::cout << "2. Coloque uma peca que flanqueie as pecas do oponente\n";
    std::cout << "3. Flanquear = cercar pecas adversarias em linha reta (horizontal, vertical ou diagonal)\n";
    std::cout << "4. Formato: Letra (coluna) + Numero (linha). Ex: C4\n";
    std::cout << "5. Comandos:\n";
    std::cout << "   - 'sair': Encerra o jogo\n";
    std::cout << "   - 'instrucoes': Mostra este guia\n";
    std::cout << "------------------------------------------------\n";
}

/**
 * @brief Imprime o tabuleiro com coordenadas de coluna (A-H) e linha (1-8).
 */
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

/**
 * @brief Verifica se uma jogada é válida conforme as regras do Reversi.
 * @param linha Índice da linha (0 a 7).
 * @param coluna Índice da coluna (0 a 7).
 * @return true se a jogada é válida, false caso contrário.
 */
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

/**
 * @brief Executa uma jogada válida, invertendo as peças do oponente conforme as regras.
 * @param linha Índice da linha (0 a 7).
 * @param coluna Índice da coluna (0 a 7).
 * @param jogador Jogador atual ('X' ou 'O').
 */
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
            std::cout << "Jogador " << proximoJogador << " nao pode jogar. Turno mantido.\n";
        }
    }
    jogadorAtual = proximoJogador;
}

/**
 * @brief Reinicia o jogo, resetando o tabuleiro e variáveis de estado.
 */
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

/**
 * @brief Verifica se um jogador venceu com base na contagem de peças.
 * @param jogador Jogador a ser verificado ('X' ou 'O').
 * @return true se o jogador tem mais peças que o oponente, false caso contrário.
 */
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

/**
 * @brief Loop principal do jogo, gerencia turnos, entradas e finalização.
 */
int Reversi::ExecutarPartida() {
    std::string entrada;
    bool instrucoesMostradas = false;

    while (!jogoFinalizado) {
        if (!instrucoesMostradas) {
            ExibirInstrucoes();
            instrucoesMostradas = true;
        }
        // Verifica se o jogador atual pode jogar
        if (!PodeJogar(jogadorAtual)) {
            if (!PodeJogar((jogadorAtual == 'X') ? 'O' : 'X')) {
                jogoFinalizado = true;
                break;
            }
            std::cout << "Jogador " << jogadorAtual << " nao pode jogar. Passando a vez.\n";
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
            continue;
        }

        ImprimirTabuleiro();
        std::cout << "\nJogador " << jogadorAtual << ", insira uma posicao (ex: A1), ";
        std::cout << "'sair' ou 'instrucoes': "; // Atualizado
        std::cin >> entrada;

        if (entrada == "sair") break;
        if (entrada == "instrucoes") { // Novo comando
            ExibirInstrucoes();
            continue;
        }

        int linha, coluna;
        if (!ConverterEntrada(entrada, linha, coluna)) {
            std::cout << "Formato invalido! Use letra+numero (ex: A1)\n";
            continue;
        }

        if (JogadaValida(linha, coluna)) {
            RealizarJogada(linha, coluna, jogadorAtual);
        } else {
            std::cout << "Jogada invalida!\n";
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

        int countX = 0, countO = 0;
        for (const auto& linha : tabuleiro) {
            for (char c : linha) {
                if (c == 'X') countX++;
            else if (c == 'O') countO++;
            }
        }

        if (countX == countO) {
            std::cout << "Empate!\n";
        } else if (VerificarVitoria('X')) {
            std::cout << "Jogador X venceu!\n";
            return 1;
        } else {
            std::cout << "Jogador O venceu!\n";
            return 2;
        }
}
/**
 * @brief Verifica se um jogador tem movimentos válidos disponíveis.
 * @param jogador Jogador a ser verificado ('X' ou 'O').
 * @return true se o jogador pode jogar, false caso contrário.
 */
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

/**
 * @brief Converte uma entrada do usuário (ex: "A1") em índices de linha e coluna.
 * @param entrada String de entrada do usuário.
 * @param linha Referência para armazenar o índice da linha (0 a 7).
 * @param coluna Referência para armazenar o índice da coluna (0 a 7).
 * @return true se a conversão foi bem-sucedida, false caso contrário.
 */
bool Reversi::ConverterEntrada(const std::string& entrada, int& linha, int& coluna) const {
    if (entrada.empty() || !isalpha(entrada[0])) return false;

    // Extrair parte numérica (tudo após a letra)
    size_t i = 1;
    while (i < entrada.size() && isdigit(entrada[i])) {
        i++;
    }
    std::string parteNumerica = entrada.substr(1, i - 1);
    if (parteNumerica.empty()) return false;

    // Converter letra para coluna (A-H)
    coluna = toupper(entrada[0]) - 'A';
    // Converter número para linha (1-8)
    linha = stoi(parteNumerica) - 1; // Subtrai 1 para índice 0-based

    return (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas);
}