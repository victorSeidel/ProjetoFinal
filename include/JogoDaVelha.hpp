#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include "JogoDeTabuleiro.hpp"
/** 
* @brief Classe que especializa a classe abstrata para o jogo da velha
*/
class JogoDaVelha: public JogoDeTabuleiro{
    public:
    JogoDaVelha();
    virtual ~JogoDaVelha() = default;
    bool JogadaValida(int linha, int coluna) const override;
    void Reiniciar() override;
    bool VerificarVitoria(char) const override;
    void RealizarJogada(int, int , char) override;
    int ExecutarPartida() override;
    int Jogar() override;
    void ImprimirTabuleiro() const override;
};
#endif
