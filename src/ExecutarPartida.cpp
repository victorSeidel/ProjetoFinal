#include "ExecutarPartida.hpp"
#include "JogoDaVelha.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"

void ExecutarPartida::IniciarJogo(jogador jogador1, jogador jogador2) 
{
    int escolha;

    int vitoriasJogador1 = 0, vitoriasJogador2 = 0;

    bool jogarNovamente = true;

    std::cout << "O jogador " << jogador1.get_apld << "será o X \n";
    std::cout << "O jogador " << jogador2.get_apld << "será a O \n";

    while (jogarNovamente) 
    {
        std::cout << "Escolha um jogo para jogar: \n";
        std::cout << "1. Reversi \n";
        std::cout << "2. Lig4 \n";
        std::cout << "3. Jogo da Velha \n";

        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;

        JogoDeTabuleiro* jogo;

        switch (escolha) 
        {
            case 1:
                jogo = new Reversi();  // Cria uma instância de Reversi
                int j = jogo->Jogar(); // Método que inicia a partida

                if (j == 1) 
                {
                    jogador1.add_vit("reversi");
                    jogador2.add_derrt("reversi");
                }
                else if (j == 2)
                {
                    jogador2.add_vit("reversi");
                    jogador1.add_derrt("reversi");
                }

                break;

            case 2:
                jogo = new Lig4();  // Cria uma instância de Lig4
                int j = jogo->Jogar(); // Método que inicia a partida

                if (j == 1) 
                {
                    jogador1.add_vit("lig");
                    jogador2.add_derrt("lig");
                }
                else if (j == 2)
                {
                    jogador2.add_vit("lig");
                    jogador1.add_derrt("lig");
                }

                break;  

            case 3:
                jogo = new JogoDaVelha();  // Cria uma instância de Jogo da Velha
                int j = jogo->Jogar(jogador1, jogador2); // Método que inicia a partida

                if (j == 1) 
                {
                    jogador1.add_vit("velha");
                    jogador2.add_derrt("velha");
                }
                else if (j == 2)
                {
                    jogador2.add_vit("velha");
                    jogador1.add_derrt("velha");
                }

                break;
   
            default:
                std::cout << "Erro: Opção inválida! Escolha um número de 1 a 3 \n";
                return;
        }

        std::cout << "\n ----- Fim de Jogo ----- \n";

        // Exibindo as estatísticas após cada partida
        std::cout << "Vitorias de " << jogador1.get_apld << " (X): " << vitoriasJogador1 << std::endl;
        std::cout << "Vitorias de " << jogador2.get_apld << " (O): " << vitoriasJogador2 << std::endl;

        // Pergunta se o usuário deseja jogar novamente ou mudar de jogo
        char resposta;
        while (1)
        {
            std::cout << "Deseja jogar novamente? (S/N): ";
            std::cin >> resposta;

            if (resposta == 'n' || resposta == 'N') 
            {
                jogarNovamente = false;
                std::cout << "Obrigado por jogar! Ate a proxima!" << std::endl;
                break;
            } 
            else if (resposta == 's' || resposta == 'S')
            {
                jogarNovamente = true;
                break;
            }
            else 
            {
                std::cout << "Erro: Opção inválida! Digite S (sim) ou N (não)." << std::endl;
                return;
            }
        }

        delete jogo; // Limpar a memória alocada para o jogo
    }
}
