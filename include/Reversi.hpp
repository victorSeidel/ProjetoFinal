#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "JogoDeTabuleiro.hpp"
#include <vector>
#include <string>

class Reversi : public JogoDeTabuleiro {
private:
    char jogadorAtual;
    bool jogoFinalizado;

    // Métodos auxiliares
    bool VerificarDirecao(int linha, int coluna, int dirLinha, int dirColuna) const;
    void VirarDiscos(int linha, int coluna, int dirLinha, int dirColuna);
    bool PodeJogar(char jogador) const;
    bool ConverterEntrada(const std::string& entrada, int& linha, int& coluna) const;

public:
    Reversi();
    virtual ~Reversi() override = default;

    // Métodos sobrescritos
    virtual void ImprimirTabuleiro() const override;
    virtual bool JogadaValida(int linha, int coluna) const override;
    virtual void RealizarJogada(int linha, int coluna, char jogador) override;
    virtual void Reiniciar() override;
    virtual bool VerificarVitoria(char jogador) const override;
    virtual void ExecutarPartida() override;
};

#endif