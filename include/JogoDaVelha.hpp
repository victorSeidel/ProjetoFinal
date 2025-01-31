#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include "JogoDeTabuleiro.hpp"

class JogoDaVelha: public JogoDeTabuleiro{

private:


    std::string jogadorX;
    std::string jogadorO;
    std::string ObterApelido(char simbolo) const;


public:


    void DefinirApelidos(const std::string& x, const std::string& o);
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
