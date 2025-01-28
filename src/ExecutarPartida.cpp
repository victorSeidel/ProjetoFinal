#include "ExecutarPartida.hpp"
//#include "JogoDaVelha.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"

void ExecutarPartida::IniciarJogo() 
{
    int escolha;
    int vitoriasJogador1 = 0, vitoriasJogador2 = 0;
    bool jogarNovamente = true;
    std::string nomeJogador1, nomeJogador2;

    std::cout << "Digite o nome do Jogador 1 (X): ";
    std::cin >> nomeJogador1;
    std::cout << "Digite o nome do Jogador 2 (O): ";
    std::cin >> nomeJogador2;

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
                jogo->Reiniciar();
                jogo->ExecutarPartida(); // Método que inicia a partida
                break;

            case 2:
                jogo = new Lig4();  // Cria uma instância de Lig4
                jogo->Reiniciar();
                jogo->ExecutarPartida(); // Método que inicia a partida
                break;  

            case 3:
                //jogo = new JogoDaVelha();  // Cria uma instância de Jogo da Velha
                //jogo->Reiniciar();
                //jogo->ExecutarPartida(); // Método que inicia a partida
                break;
   
            default:
                std::cout << "Erro: Opção inválida! Escolha um número de 1 a 3 \n";
                return;
        }

        std::cout << "\n ----- Fim de Jogo ----- \n";

        // Exibindo as estatísticas após cada partida
        std::cout << "Vitorias de " << nomeJogador1 << " (X): " << vitoriasJogador1 << std::endl;
        std::cout << "Vitorias de " << nomeJogador2 << " (O): " << vitoriasJogador2 << std::endl;

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
