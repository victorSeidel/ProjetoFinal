#ifndef JOGODETABULEIRO_HPP
#define JOGODETABULEIRO_HPP

#include <vector>
#include <iostream>

class JogoDeTabuleiro 
{
    protected:
        std::vector<std::vector<char>> tabuleiro;
        int linhas;
        int colunas;
    
    public:
        // Construtor: inicializa apenas tamanho e estrutura do tabuleiro.
        JogoDeTabuleiro(int linhas, int colunas) : linhas(linhas), colunas(colunas), tabuleiro(linhas, std::vector<char>(colunas, '.')) {}
    
        virtual ~JogoDeTabuleiro() = default;
    
        // Métodos puramente virtuais (obrigatórios para classes derivadas):
        virtual int Jogar() = 0;
        virtual void ImprimirTabuleiro() const = 0;
        virtual bool JogadaValida(int linha, int coluna) const = 0;
        virtual void RealizarJogada(int linha, int coluna, char jogador) = 0;
        virtual void Reiniciar() = 0;
        virtual bool VerificarVitoria(char jogador) const = 0;
        virtual int ExecutarPartida() = 0;
};

#endif
