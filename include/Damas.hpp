#ifndef DAMAS_HPP
#define DAMAS_HPP

#include "JogoDeTabuleiro.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <limits>

class JogoDamasException : public std::runtime_error {
public:
    explicit JogoDamasException(const std::string& msg) 
        : std::runtime_error(msg) {}
};

class Damas : public JogoDeTabuleiro {
private:
    char jogadorAtual;
    bool capturaObrigatoria;
    int ultimaCapturaLinha;
    int ultimaCapturaColuna;

public:
    Damas();
    bool verificarMovimentosDisponiveis(char jogador) const;
    bool verificarCapturasDisponiveis(char jogador) const;
    bool posicaoValida(int linha, int coluna) const;
    void ImprimirTabuleiro() const override;
    bool JogadaValida(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) const;
    void RealizarJogada(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    void Reiniciar() override;
    bool VerificarVitoria(char jogador) const override;
    bool VerificarEmpate() const;
    int ExecutarPartida() override;
    int Jogar() override;
    bool JogadaValida(int, int) const override; // Para compatibilidade
    void RealizarJogada(int, int, char) override; // Para compatibilidade
    bool verificarCapturaPossivel(int linha, int coluna) const;
    bool podeContinuarCapturando(int linha, int coluna) const;

private:
    void validarEntradaNumerica(int valor, int max) const;
    void lerCoordenadas(const std::string& mensagem, int& linha, int& coluna) const;
};

#endif