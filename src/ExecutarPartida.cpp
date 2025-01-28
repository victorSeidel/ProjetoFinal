#include "ExecutarPartida.hpp"

void IniciarPartida::IniciarJogo() {
    int escolha;
    int vitoriasJogador1 = 0, vitoriasJogador2 = 0;
    bool jogarNovamente = true;

    while (jogarNovamente) {
        // Solicitando os nomes dos jogadores
        std::cout << "Digite o nome do Jogador 1 (X): ";
        std::cin >> nomeJogador1;
        std::cout << "Digite o nome do Jogador 2 (O): ";
        std::cin >> nomeJogador2;

        std::cout << "Escolha um jogo para jogar:\n";
        std::cout << "1. Reversi\n";
        std::cout << "2. Jogo da velha\n";
        std::cout << "3. Lig4\n";
        // Adicione mais jogos aqui conforme necessário.
        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;

        JogoDeTabuleiro* jogo;

        switch (escolha) { // Adicionar os outros jogos conforme necessário
            case 1:
                jogo = new Reversi();  // Cria uma instância de Reversi
                break;
            case 2:
                jogo = new JogoDaVelha();  // Cria uma instância de Jogo da Velha
                break;
            case 3:
                jogo = new Lig4();  // Cria uma instância de Lig4
                break;    
            default:
                std::cout << "Escolha inválida!\n";
                return;
        }

        std::string nomeJogador1, nomeJogador2;
        char jogadorAtual = 'X';

        // Exibindo as estatísticas após cada partida
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
                jogo->Reiniciar(); // Reinicia o jogo atual, se necessário
            }
        } else {
            jogo->Reiniciar(); // Reinicia o jogo se o jogador escolher continuar com o mesmo
        }

        delete jogo; // Limpar a memória alocada para o jogo
    }
}
