#ifndef INICIAR_PARTIDA_HPP
#define INICIAR_PARTIDA_HPP

#include <iostream>
#include <string>
#include "Reversi.hpp"  // Inclua outros jogos e funcionalidades conforme necessário

class IniciarPartida {
public:
    void IniciarJogo() {
        int escolha;
        int vitoriasJogador1 = 0, vitoriasJogador2 = 0;
        bool jogarNovamente = true;

        while (jogarNovamente) {
            std::cout << "Escolha um jogo para jogar:\n";
            std::cout << "1. Reversi\n";
            // Adicione mais jogos aqui conforme necessário.
            std::cout << "Digite sua escolha (1): ";
            std::cin >> escolha;

            JogoDeTabuleiro* jogo;

            switch (escolha) { // Adicionar os outros jogos conforme necessário
                case 1:
                    jogo = new Reversi();  // Cria uma instância de Reversi
                    break;
                default:
                    std::cout << "Escolha inválida!\n";
                    return;
            }

            std::string nomeJogador1, nomeJogador2;
            char jogadorAtual = 'X';
            int linha, coluna;
            bool jogoAtivo = true;

            // Solicitando os nomes dos jogadores, analisar se é necessário manter ou implementar alguma relação com jogador.hpp
            std::cout << "Digite o nome do Jogador 1 (X): ";
            std::cin >> nomeJogador1;
            std::cout << "Digite o nome do Jogador 2 (O): ";
            std::cin >> nomeJogador2;

            // Executando a partida
            while (jogoAtivo) {
                jogo->ImprimirTabuleiro();

                std::cout << "É a vez de " << (jogadorAtual == 'X' ? nomeJogador1 : nomeJogador2) << " (" << (jogadorAtual == 'X' ? 'X' : 'O') << "), insira sua jogada (linha e coluna): ";
                std::cin >> linha >> coluna;

                jogo->RealizarJogada(linha - 1, coluna - 1, jogadorAtual);  // Ajuste para índice 0 e analisar se vai dar certo pra todos jogos
                if (jogo->VerificarVitoria(jogadorAtual)) {
                    jogo->ImprimirTabuleiro();
                    std::cout << "Jogador " << (jogadorAtual == 'X' ? nomeJogador1 : nomeJogador2) << " venceu!" << std::endl;

                    // Atualizando as estatísticas dos jogadores, analisar se é necessário manter ou implementar alguma relação com cadastro.hpp
                    if (jogadorAtual == 'X')
                        vitoriasJogador1++;
                    else
                        vitoriasJogador2++;

                    jogoAtivo = false;
                } else {
                    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
                }
            }

            // Exibindo as estatísticas após cada partida, analisar se é necessário manter ou implementar alguma relação com cadastro.hpp
            std::cout << "\n--- Fim de Jogo ---\n";
            std::cout << "Vitórias de " << nomeJogador1 << " (X): " << vitoriasJogador1 << std::endl;
            std::cout << "Vitórias de " << nomeJogador2 << " (O): " << vitoriasJogador2 << std::endl;

            // Pergunta se o usuário deseja jogar novamente ou mudar de jogo
            char resposta;
            std::cout << "Deseja jogar novamente o mesmo jogo? (s/n): ";
            std::cin >> resposta;
            if (resposta == 'n' || resposta == 'N') {
                std::cout << "Deseja mudar para outro jogo? (s/n): ";
                std::cin >> resposta;
                if (resposta == 'n' || resposta == 'N') {
                    jogarNovamente = false;
                    std::cout << "Obrigado por jogar! Até a próxima!" << std::endl;
                } else {
                    jogo->Reiniciar();  // Reinicia o jogo atual, se necessário
                }
            } else {
                jogo->Reiniciar();  // Reinicia o jogo se o jogador escolher continuar com o mesmo
            }

            delete jogo;  // Limpar a memória alocada para o jogo
        }
    }
};

#endif // INICIAR_PARTIDA_HPP
