#include "ExecutarPartida.hpp"
#include "Reversi.hpp"
#include "Lig4.hpp"
#include "JogoDeTabuleiro.hpp"
#include "<iostream>"

int main() 
{
    std::cout << "Olá, seja muito bem-vindo(a)! \n";
    std::cout << "Escolha o que deseja fazer: \n";
    std::cout << "1. Jogar \n";
    std::cout << "2. Cadastrar Jogador \n";
    std::cout << "2. Listar Jogadores \n";

    int opcao;
    std::cin >> opcao;

    switch(opcao)
    {
        case 1:
            ExecutarPartida jogo; 
            jogo.IniciarJogo();
            break;
        case 2:
            std::cout << "Cadastrar Jogador \n";
            break;
        case 3:
            std::cout << "Listar Jogadores \n";
            break;
        default:
            std::cout << "Opção inválida! \n";
            break;
    }


    return 0;
}
