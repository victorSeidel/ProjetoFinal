#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include "JogoDeTabuleiro.hpp"
/**
* @brief Classe que implementa o jogo da velha, especializando as funções da classe abstrata.
*/
class JogoDaVelha: public JogoDeTabuleiro{

private:


    std::string jogadorX; /** Representa o primeiro jogador */
    std::string jogadorO; /** Representa o segundo jogador. */
/**
* @brief Obtém o apelido de um jogador.
* @param simbolo "X" ou "O" para representar cada jogador.
* @return O apelido em si.
*/
    std::string ObterApelido(char simbolo) const;


public:

/**
* @brief Assinala "X" e "O" para os respectivos jogadores.
* @param x O apelido do jogador que terá "X" como símbolo.
* @param o O apelido do jogador que terá "O" como símbolo.
*/
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
