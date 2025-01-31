#ifndef JOGODETABULEIRO_HPP
#define JOGODETABULEIRO_HPP

#include <vector>
#include <iostream>

/**
 * @brief Classe genérica com funções comuns para todos os jogos de tabuleiro.
 */
class JogoDeTabuleiro 
{
    protected:
        std::vector<std::vector<char>> tabuleiro; /** estrutura de dados vector para simular o tabuleiro representado por caracteres */
        int linhas; /** número de linhas no tabuleiro */
        int colunas; /** número de colunas no tabuleiro */
    
    public:
        /**
        * @brief construtor padrão do tabuleiro, inicia todas as células como vazias
        * @param linhas quantidade de linhas a ser instanciada
        * @param colunas quantidade de colunas a ser instanciada
        */
        JogoDeTabuleiro(int linhas, int colunas) : linhas(linhas), colunas(colunas), tabuleiro(linhas, std::vector<char>(colunas, '.')) {}
    
        /**
        * @brief destrutor virtual do tabuleiro
        */
        virtual ~JogoDeTabuleiro() = default;
    
        // Métodos puramente virtuais (obrigatórios para classes derivadas):

        /**
        * @brief chama o método para executar a partida
        */
        virtual int Jogar() = 0;

        /**
        * @brief imprime o tabuleiro completo
        */
        virtual void ImprimirTabuleiro() const = 0;

        /**
        * @brief verifica se a jogada escolhida é válida
        * @param linha linha da jogada
        * @param coluna coluna da jogada
        * @return valor que indica a validade da jogada (true ou false)
        */
        virtual bool JogadaValida(int linha, int coluna) const = 0;

        /**
        * @brief realiza uma jogada conforme escolhido
        * @param linha linha da jogada
        * @param coluna coluna da jogada
        * @param jogador jogador 1 (X) ou jogador 2 (O)
        */
        virtual void RealizarJogada(int linha, int coluna, char jogador) = 0;

        /**
        * @brief reinicia o tabuleiro, deixando-o vazio novamente
        */
        virtual void Reiniciar() = 0;

        /**
        * @brief verifica se algum dos jogadores ganhou após sua última jogada
        * @param jogador jogador 1 (X) ou jogador 2 (O)
        * @return True caso o jogador tenha ganhado, false caso contrário
        */
        virtual bool VerificarVitoria(char jogador) const = 0;

        /**
        * @brief implementa o loop de gameplay do jogo
        * @return número que indica o jogador vencedor
        */
        virtual int ExecutarPartida() = 0;
};

#endif
