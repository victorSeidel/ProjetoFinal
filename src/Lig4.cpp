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
    if (coluna < 0 || coluna >= colunas) 
        return false;

    return tabuleiro[0][coluna] == 0; // Verifica se a coluna não está cheia
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
        if (tabuleiro[i][coluna] == 0) 
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
        std::fill(linha.begin(), linha.end(), 0);
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

        if (novaLinha < 0 || novaLinha >= linhas || novaColuna < 0 || novaColuna >= colunas) 
            return false;

        if (tabuleiro[novaLinha][novaColuna] == jogador) 
            ++count;
        else 
            break;
    }

    return count == 4;
}
