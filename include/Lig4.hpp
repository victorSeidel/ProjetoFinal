#ifndef LIG4_HPP
#define LIG4_HPP

#include "JogoDeTabuleiro.hpp"

/**
 * @brief Classe que herda a classe JogoDeTabuleiro e implementa a lógica do jogo Lig4.
 */
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

    virtual int Jogar() override;

    int ExecutarPartida() override;

    private:
    /**
    * @brief Retorna true se algum jogador tiver feito uma sequência com 4.
    * @param linha Verifica as linhas.
    * @param coluna Verifica as colunas.
    * @param dLinha Nova direção de verificação das linhas.
    * @param dColuna Nova direção de verificação das colunas.
    * @param jogador Jogador 1 (X) ou Jogador 2 (O).
    * @return Retorna 1 se existe uma sequência com 4.
    */
    bool VerificarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador) const;

    std::string jogadorX;
    std::string jogadorO;

    /**
    * @brief Assinala "X" e "O" para os respectivos jogadores.
    * @param x O apelido do jogador que terá "X" como símbolo.
    * @param o O apelido do jogador que terá "O" como símbolo.
    */
    void DefinirApelidos(const std::string& x, const std::string& o);

    /**
    * @brief Obtém o apelido de um jogador.
    * @param Simbolo "X" ou "O" para representar cada jogador.
    * @return O apelido em si.
    */
    std::string ObterApelido(char simbolo) const;

};

#endif
