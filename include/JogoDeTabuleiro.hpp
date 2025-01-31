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
         /**
        * @brief Estrutura de dados vector para simular o tabuleiro representado por caracteres
        */
        std::vector<std::vector<char>> tabuleiro;
        int linhas; /** <Número de linhas no tabuleiro. */
        int colunas; /** <Número de colunas no tabuleiro. */
    
    public:
        /**
        * @brief Construtor padrão do tabuleiro, inicia todas as células como vazias.
        * @param linhas Quantidade de linhas a ser instanciada.
        * @param colunas Quantidade de colunas a ser instanciada.
        */
        JogoDeTabuleiro(int linhas, int colunas) : linhas(linhas), colunas(colunas), tabuleiro(linhas, std::vector<char>(colunas, '.')) {}
    
        /**
        * @brief Destrutor virtual do tabuleiro.
        */
        virtual ~JogoDeTabuleiro() = default;
    
        // Métodos puramente virtuais (obrigatórios para classes derivadas):

        /**
        * @brief Chama o método para executar a partida.
        */
        virtual int Jogar() = 0;

        /**
        * @brief Imprime o tabuleiro completo.
        */
        virtual void ImprimirTabuleiro() const = 0;

        /**
        * @brief Verifica se a jogada escolhida é válida.
        * @param linha Linha da jogada.
        * @param coluna Coluna da jogada.
        * @return Valor que indica a validade da jogada (true ou false).
        */
        virtual bool JogadaValida(int linha, int coluna) const = 0;

        /**
        * @brief Realiza uma jogada conforme escolhido.
        * @param linha Linha da jogada.
        * @param coluna Coluna da jogada.
        * @param jogador Jogador 1 (X) ou jogador 2 (O).
        */
        virtual void RealizarJogada(int linha, int coluna, char jogador) = 0;

        /**
        * @brief Reinicia o tabuleiro, deixando-o vazio novamente.
        */
        virtual void Reiniciar() = 0;

        /**
        * @brief Verifica se algum dos jogadores ganhou após sua última jogada.
        * @param jogador Jogador 1 (X) ou jogador 2 (O).
        * @return True caso o jogador tenha ganhado, false caso contrário.
        */
        virtual bool VerificarVitoria(char jogador) const = 0;

        /**
        * @brief Implementa o loop de gameplay do jogo.
        * @return Número que indica o jogador vencedor.
        */
        virtual int ExecutarPartida() = 0;
};

#endif
