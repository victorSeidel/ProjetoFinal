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
    void ExecutarPartida(jogador&, jogador& );
    void Jogar(jogador&, jogador&);
    void ImprimirTabuleiro();
};
#endif
