#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include "JogoDeTabuleiro.hpp"

class JogoDaVelha: public JogoDeTabuleiro{
    public:
    JogoDaVelha();
    virtual ~JogoDaVelha();
    bool JogadaValida(int linha, int coluna) override;
    void Reiniciar() override;
    bool VerificarVitoria(char)const override;
    void RealizarJogada(int, int , char) override;
    int ExecutarPartida() override;
    int Jogar() override;
    void ImprimirTabuleiro() override;
};
#endif
