#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H
#include "JogoDeTabuleiro.hpp"
#include "jogador.hpp"
class JogoDaVelha: public JogoDeTabuleiro{
    public:
    JogoDaVelha();
    ~JogoDaVelha() = default;
    bool JogadaValida(int linha, int coluna);
    void Reiniciar();
    bool VerificarVitoria(char)const;
    void RealizarJogada(int, int , char);
    int ExecutarPartida(jogador&, jogador& );
    int Jogar(jogador&, jogador&);
    void ImprimirTabuleiro();
};
#endif
