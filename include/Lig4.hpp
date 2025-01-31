#ifndef LIG4_HPP
#define LIG4_HPP

#include "JogoDeTabuleiro.hpp"

/**
 * @brief Classe que herda a classe JogoDeTabuleiro e implementa lógica do jogo Lig4.
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

    void DefinirApelidos(const std::string& x, const std::string& o);

    private:
    /**
    * @brief Retorna true se algum jogador tiver feito uma sequência com 4.
    * @param linha Verifica as linhas.
    * @param coluna Verifica as colunas.
    * @param dLinha Nova direção de verificação das linhas.
    * @param dColuna Nova direção de verificação das colunas.
    * @param jogador Jogador 1 (X) ou Jogador 2 (O).
    */
    bool VerificarDirecao(int linha, int coluna, int dLinha, int dColuna, char jogador) const;

    std::string jogadorX;
    std::string jogadorO;
    std::string ObterApelido(char simbolo) const;

};

#endif
