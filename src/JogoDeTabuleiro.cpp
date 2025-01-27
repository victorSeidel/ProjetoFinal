#include "JogoDeTabuleiro.hpp"

JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas) : linhas(linhas), colunas(colunas) 
{
    tabuleiro.resize(linhas, std::vector<char>(colunas, '.'));
}

JogoDeTabuleiro::~JogoDeTabuleiro() = default;

void JogoDeTabuleiro::ImprimirTabuleiro() const 
{
    for (const auto& linha : tabuleiro) 
    {
        for (char celula : linha)
        {
            std::cout << celula << " ";
        }

        std::cout << "\n";
    }
}

bool JogoDeTabuleiro::JogadaValida(int linha, int coluna) const 
{
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && tabuleiro[linha][coluna] == '.';
}

void JogoDeTabuleiro::RealizarJogada(int linha, int coluna, char jogador) 
{
    if (JogadaValida(linha, coluna))
    {
        tabuleiro[linha][coluna] = jogador;
    } 
    else 
    {
        std::cerr << "Jogada inválida!\n";
    }
}

void JogoDeTabuleiro::Reiniciar() 
{
    for (auto& linha : tabuleiro) 
    {
        std::fill(linha.begin(), linha.end(), '.');
    }
}

void JogoDeTabuleiro::ExecutarPartida()
{
    
} 
