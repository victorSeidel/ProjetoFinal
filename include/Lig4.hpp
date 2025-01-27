#ifndef LIG4_HPP
#define LIG4_HPP

#include "JogoDeTabuleiro.hpp"

class Lig4 : public JogoDeTabuleiro 
{
    public:
    Lig4();

    virtual ~Lig4();

    void ImprimirTabuleiro() const override;

    bool JogadaValida(int linha, int coluna) const override;

    void RealizarJogada(int linha, int coluna, char jogador) override;

    void Reiniciar() override;

    bool VerificarVitoria(char jogador) const override;

    private:
    bool VerificarDirecao(int linha, int coluna, int deltaLinha, int deltaColuna, char jogador) const;
};

#endif
