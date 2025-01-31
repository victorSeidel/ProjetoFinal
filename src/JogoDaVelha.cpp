/**
 * 
 */
#include "JogoDaVelha.hpp"
#include <limits>
#include <sstream>

JogoDaVelha::JogoDaVelha():JogoDeTabuleiro::JogoDeTabuleiro(3,3){}

// Método para definir apelidos
void JogoDaVelha::DefinirApelidos(const std::string& x, const std::string& o) {
    jogadorX = x;
    jogadorO = o;
}

// Método auxiliar para apelidos
std::string JogoDaVelha::ObterApelido(char simbolo) const {
    return (simbolo == 'X') ? jogadorX : jogadorO;
}

bool JogoDaVelha::VerificarVitoria(char j1) const {
    for (int i = 0; i < 3; ++i) {
        if ((tabuleiro[i][0] == j1 && tabuleiro[i][1] == j1 && tabuleiro[i][2] == j1) ||
            (tabuleiro[0][i] == j1 && tabuleiro[1][i] == j1 && tabuleiro[2][i] == j1)) {
            return true;
        }
    }
    return (tabuleiro[0][0] == j1 && tabuleiro[1][1] == j1 && tabuleiro[2][2] == j1) ||
           (tabuleiro[0][2] == j1 && tabuleiro[1][1] == j1 && tabuleiro[2][0] == j1);
}

    void JogoDaVelha::ImprimirTabuleiro() const {
    for (const auto& linha : tabuleiro) 
    {
        for (char celula : linha)
        {
            std::cout << celula << " ";
        }

        std::cout << "\n";
    }
    std::cout << "\n";
}

bool JogoDaVelha::JogadaValida(int linha, int coluna) const {
    // Verifica se os índices estão dentro dos limites do tabuleiro (0 a 2)
    return linha >= 0 && linha < linhas && 
           coluna >= 0 && coluna < colunas && 
           tabuleiro[linha][coluna] == '.';
}

    void JogoDaVelha::RealizarJogada(int linha, int coluna, char jogador){
        this->tabuleiro[linha][coluna] = jogador;
    }
    
    void JogoDaVelha::Reiniciar(){
    for (auto& linha : tabuleiro) 
    {
        std::fill(linha.begin(), linha.end(), '.');
    }
}

int JogoDaVelha::ExecutarPartida() {
    std::cout << jogadorX << " (X) vs " << jogadorO << " (O)\n";
    int num_jogadas = 0;

    // Limpa o buffer residual antes de iniciar
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (num_jogadas < 9) {
        ImprimirTabuleiro();
        int lin, col;
        char jogador_atual = (num_jogadas % 2 == 0) ? 'X' : 'O';

        while (true) {
            std::cout << "Vez de " << ObterApelido(jogador_atual) << std::endl;
            std::cout << "Digite linha e coluna (1-3): ";

            std::string entrada;
            std::getline(std::cin, entrada);

            // Verifica entrada vazia
            if (entrada.empty()) {
                std::cout << "Erro: Insira dois numeros separados por espaço (ex: 1 3)." << std::endl;
                continue;
            }

            std::stringstream ss(entrada);

            if (!(ss >> lin >> col)) {
                std::cout << "Erro: Formato invalido! Use dois números separados por espaço (ex: 1 3)." << std::endl;
                continue;
            }

            if (lin < 1 || lin > 3 || col < 1 || col > 3) {
                std::cout << "Erro: Valores devem ser entre 1 e 3!" << std::endl;
                continue;
            }

            if (JogadaValida(lin - 1, col - 1)) {
                break;
            } else {
                std::cout << "Erro: Posicao ocupada!" << std::endl;
            }
        }

        RealizarJogada(lin - 1, col - 1, jogador_atual);
        num_jogadas++;

        if (VerificarVitoria(jogador_atual)) {
            ImprimirTabuleiro();
            std::cout << ObterApelido(jogador_atual) << " ganhou!" << std::endl;
            std::cout << "Aperte ENTER para voltar ao menu. \n";
            Reiniciar();
            return (jogador_atual == 'X') ? 1 : 2;
        }
    }

        // Empate
        ImprimirTabuleiro();
        std::cout << "O jogo terminou empatado." << std::endl;
        std::cout << "Aperte ENTER para voltar ao menu. \n";
        Reiniciar();
    }
    
    int JogoDaVelha::Jogar()
    {
        return this->ExecutarPartida();
    }
