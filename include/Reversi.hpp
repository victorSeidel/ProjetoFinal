#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "JogoDeTabuleiro.hpp"
#include <vector>
#include <string>
/**
* @brief Classe que implenta o Reversi a partir da classe abstrata.
*/
class Reversi : public JogoDeTabuleiro {
private:
    char jogadorAtual;
    bool jogoFinalizado;
    std::string jogadorX;
    std::string jogadorO;

    // Métodos auxiliares
    bool VerificarDirecao(int linha, int coluna, int dirLinha, int dirColuna) const;
    void VirarDiscos(int linha, int coluna, int dirLinha, int dirColuna);
    bool PodeJogar(char jogador) const;
    bool ConverterEntrada(const std::string& entrada, int& linha, int& coluna) const;
    void ExibirInstrucoes() const;
public:
    Reversi();
    virtual ~Reversi() override = default;

    void DefinirApelidos(const std::string& x, const std::string& o);
/**
* @brief Obtém o apelido de um jogador.
* @param simbolo "X" ou "O" para representar cada jogador.
* @return O apelido em si.
*/
    std::string ObterApelido(char simbolo) const;
    // Métodos sobrescritos
    virtual int Jogar() override;
    virtual void ImprimirTabuleiro() const override;
    virtual bool JogadaValida(int linha, int coluna) const override;
    virtual void RealizarJogada(int linha, int coluna, char jogador) override;
    virtual void Reiniciar() override;
    virtual bool VerificarVitoria(char jogador) const override;
    virtual int ExecutarPartida() override;
};

#endif
