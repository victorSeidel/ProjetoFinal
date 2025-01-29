#include "ExecutarPartida.hpp"
#include "JogoDaVelha.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"

void ExecutarPartida::IniciarJogo() 
{
    int escolha;

    int vitoriasJogador1 = 0, vitoriasJogador2 = 0;

    bool jogarNovamente = true;

    std::cout << "O jogador 1 sera o X \n";
    std::cout << "O jogador 2 sera a O \n";

    int j;

    while (jogarNovamente) 
    {
        std::cout << "Escolha um jogo para jogar: \n";
        std::cout << "1. Reversi \n";
        std::cout << "2. Lig4 \n";
        std::cout << "3. Jogo da Velha \n";

        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;

        JogoDeTabuleiro* jogo;

        j = 0;
        
        switch (escolha) 
        {
            case 1:
                jogo = new Reversi();  // Cria uma instância de Reversi
                j = jogo->Jogar(); // Método que inicia a partida

                break;

            case 2:
                jogo = new Lig4();  // Cria uma instância de Lig4
                j = jogo->Jogar(); // Método que inicia a partida

                break;  

            case 3:
                jogo = new JogoDaVelha();  // Cria uma instância de Jogo da Velha
                j = jogo->Jogar(); // Método que inicia a partida

                break;
   
            default:
                std::cout << "Erro: Opção invalida! Escolha um número de 1 a 3 \n";
                return;
        }

        std::cout << "\n ----- Fim de Jogo ----- \n";

        // Exibindo as estatísticas após cada partida
        std::cout << "Vitorias do jogador 1 (X): " << vitoriasJogador1 << std::endl;
        std::cout << "Vitorias do jogador 2 (O): " << vitoriasJogador2 << std::endl;

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
                std::cout << "Erro: Opcao invalida! Digite S (sim) ou N (não)." << std::endl;
                return;
            }
        }

        delete jogo; // Limpar a memória alocada para o jogo
    }
}
