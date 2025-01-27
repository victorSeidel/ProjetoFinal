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
    JogoDeTabuleiro(int linhas, int colunas);

    virtual ~JogoDeTabuleiro();

    virtual void ImprimirTabuleiro() const;

    virtual bool JogadaValida(int linha, int coluna) const;

    virtual void RealizarJogada(int linha, int coluna, char jogador);

    virtual void Reiniciar();

    virtual bool VerificarVitoria(char jogador) const = 0;

    virtual void ExecutarPartida();
};

#endif
