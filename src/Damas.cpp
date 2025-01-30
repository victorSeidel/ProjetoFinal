#include "Damas.hpp"
#include <iostream>
#include <limits>


Damas::Damas() 
    : JogoDeTabuleiro(8, 8), 
      jogadorAtual('B'), 
      capturaObrigatoria(false),
      ultimaCapturaLinha(-1), 
      ultimaCapturaColuna(-1) {
    Reiniciar();
}

bool Damas::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}

bool Damas::verificarCapturaPossivel(int linha, int coluna) const {
    const char peca = tabuleiro[linha][coluna];
    if (peca == '.') return false;

    const bool dama = isupper(peca);
    const int direcoes[4][2] = {{2,2}, {2,-2}, {-2,2}, {-2,-2}};

    for (const auto& dir : direcoes) {
        if (!dama) {
            if ((peca == 'B' && dir[0] < 0) || (peca == 'P' && dir[0] > 0)) continue;
        }

        const int novaLinha = linha + dir[0];
        const int novaColuna = coluna + dir[1];
        const int meioLinha = linha + dir[0]/2;
        const int meioColuna = coluna + dir[1]/2;

        if (posicaoValida(novaLinha, novaColuna) && 
            tabuleiro[novaLinha][novaColuna] == '.' &&
            posicaoValida(meioLinha, meioColuna) && 
            tabuleiro[meioLinha][meioColuna] != '.' &&
            tolower(tabuleiro[meioLinha][meioColuna]) != tolower(peca)) {
            return true;
        }
    }
    return false;
}

bool Damas::verificarCapturasDisponiveis(char jogador) const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (tolower(tabuleiro[i][j]) == jogador && verificarCapturaPossivel(i, j)) {
                return true;
            }
        }
    }
    return false;
}

bool Damas::verificarMovimentosDisponiveis(char jogador) const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (tolower(tabuleiro[i][j]) == jogador) {
                // Verifica movimentos simples
                for (int dx : {-1, 1}) {
                    for (int dy : {-1, 1}) {
                        const int novaLinha = i + dy;
                        const int novaColuna = j + dx;
                        if (posicaoValida(novaLinha, novaColuna) && 
                            tabuleiro[novaLinha][novaColuna] == '.') {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Damas::podeContinuarCapturando(int linha, int coluna) const {
    return verificarCapturaPossivel(linha, coluna);
}

void Damas::ImprimirTabuleiro() const {
    std::cout << "\n  ";
    for (int j = 0; j < colunas; ++j) std::cout << j << " ";
    std::cout << "\n";

    for (int i = 0; i < linhas; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < colunas; ++j) {
            std::cout << tabuleiro[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool Damas::JogadaValida(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) const {
    // Validações básicas
    if (!posicaoValida(linhaOrigem, colunaOrigem) || 
        !posicaoValida(linhaDestino, colunaDestino)) {
        return false;
    }

    const char peca = tabuleiro[linhaOrigem][colunaOrigem];
    if (tolower(peca) != tolower(jogadorAtual)) return false;

    const int deltaLinha = linhaDestino - linhaOrigem;
    const int deltaColuna = abs(colunaDestino - colunaOrigem);
    const bool dama = isupper(peca);

    // Movimento simples
    if (deltaColuna == 1) {
        if (dama && abs(deltaLinha) == 1) return true;
        if (!dama && ((peca == 'B' && deltaLinha == 1) || (peca == 'P' && deltaLinha == -1))) {
            return tabuleiro[linhaDestino][colunaDestino] == '.';
        }
    }

    // Captura
    if (deltaColuna == 2 && abs(deltaLinha) == 2) {
        const int meioLinha = (linhaOrigem + linhaDestino)/2;
        const int meioColuna = (colunaOrigem + colunaDestino)/2;

        return tabuleiro[linhaDestino][colunaDestino] == '.' &&
               tabuleiro[meioLinha][meioColuna] != '.' &&
               tolower(tabuleiro[meioLinha][meioColuna]) != tolower(peca);
    }

    return false;
}

void Damas::RealizarJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    const char peca = tabuleiro[linhaOrigem][colunaOrigem];
    const bool captura = (abs(linhaDestino - linhaOrigem) == 2);

    // Executa o movimento
    tabuleiro[linhaDestino][colunaDestino] = peca;
    tabuleiro[linhaOrigem][colunaOrigem] = '.';

    // Processa captura
    if (captura) {
        const int meioLinha = (linhaOrigem + linhaDestino)/2;
        const int meioColuna = (colunaOrigem + colunaDestino)/2;
        tabuleiro[meioLinha][meioColuna] = '.';
        ultimaCapturaLinha = linhaDestino;
        ultimaCapturaColuna = colunaDestino;
    }

    // Promoção a dama
    if ((linhaDestino == linhas - 1 && tolower(peca) == 'b') ||
        (linhaDestino == 0 && tolower(peca) == 'p')) {
        tabuleiro[linhaDestino][colunaDestino] = toupper(peca);
    }
}

void Damas::Reiniciar() {
    tabuleiro = std::vector<std::vector<char>>(8, std::vector<char>(8, '.'));
    
    // Posiciona peças brancas
    for (int i = 0; i < 3; ++i) {
        for (int j = (i % 2); j < 8; j += 2) {
            tabuleiro[i][j] = 'B';
        }
    }
    
    // Posiciona peças pretas
    for (int i = 5; i < 8; ++i) {
        for (int j = (i % 2); j < 8; j += 2) {
            tabuleiro[i][j] = 'P';
        }
    }
    
    jogadorAtual = 'B';
    capturaObrigatoria = false;
}

bool Damas::VerificarVitoria(char jogador) const {
    const char oponente = (jogador == 'B') ? 'P' : 'B';
    for (const auto& linha : tabuleiro) {
        for (char c : linha) {
            if (tolower(c) == oponente) return false;
        }
    }
    return true;
}

bool Damas::VerificarEmpate() const {
    return !verificarMovimentosDisponiveis(jogadorAtual) && 
           !verificarCapturasDisponiveis(jogadorAtual);
}

void Damas::validarEntradaNumerica(int valor, int max) const {
    if (valor < 0 || valor >= max) {
        throw JogoDamasException("Posição inválida! Valores devem estar entre 0 e " + 
                               std::to_string(max - 1));
    }
}

void Damas::lerCoordenadas(const std::string& mensagem, int& linha, int& coluna) const {
    std::cout << mensagem;
    if (!(std::cin >> linha >> coluna)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw JogoDamasException("Entrada inválida! Digite dois números.");
    }
    validarEntradaNumerica(linha, linhas);
    validarEntradaNumerica(coluna, colunas);
}

int Damas::ExecutarPartida() {
    try {
        while (true) {
            ImprimirTabuleiro();
            std::cout << "\n--- Vez do Jogador " << jogadorAtual << " ---\n";

            capturaObrigatoria = verificarCapturasDisponiveis(jogadorAtual);
            bool capturaMultipla = false;

            do {
                int origemL, origemC, destinoL, destinoC;
                bool entradaValida = false;

                while (!entradaValida) {
                    try {
                        lerCoordenadas("Origem (linha coluna): ", origemL, origemC);
                        lerCoordenadas("Destino (linha coluna): ", destinoL, destinoC);
                        entradaValida = true;
                    }
                    catch (const JogoDamasException& e) {
                        std::cerr << "Erro: " << e.what() << "\n";
                    }
                }

                if (!JogadaValida(origemL, origemC, destinoL, destinoC)) {
                    std::cerr << "Jogada inválida! Tente novamente.\n";
                    continue;
                }

                RealizarJogada(origemL, origemC, destinoL, destinoC);
                capturaMultipla = capturaObrigatoria && podeContinuarCapturando(destinoL, destinoC);

            } while (capturaMultipla);

            if (VerificarVitoria(jogadorAtual)) {
                ImprimirTabuleiro();
                return (jogadorAtual == 'B') ? 1 : 2;
            }

            if (VerificarEmpate()) {
                ImprimirTabuleiro();
                return 0;
            }

            jogadorAtual = (jogadorAtual == 'B') ? 'P' : 'B';
        }
    }
    catch (const std::exception& e) {
        std::cerr << "\nERRO FATAL: " << e.what() << "\nReiniciando o jogo...\n";
        Reiniciar();
        return -1;
    }
}

// Métodos dummy para compatibilidade com a interface
int Damas::Jogar() { 
    return ExecutarPartida(); 
}
