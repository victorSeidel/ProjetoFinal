#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H
#include "JogoDeTabuleiro.hpp"
#include "jogador.hpp"
class JogoDaVelha: public JogoDeTabuleiro{
    public:
    JogoDaVelha();
    bool VerificarVitoria(jogador&,jogador&);
    void RealizarJogada(int, int , char);
    void Executar_Partida(jogador&, jogador& );
};
#endif