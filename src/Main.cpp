#include "ExecutarPartida.hpp"
#include "Cadastro.hpp"

#include "<iostream>"

int main() 
{
    std::cout << "Olá, seja muito bem-vindo(a)! \n";
    std::cout << "Escolha o que deseja fazer: \n";
    std::cout << "1. Jogar \n";
    std::cout << "2. Cadastrar Jogador \n";
    std::cout << "3. Listar Jogadores \n";

    int opcao;
    std::cin >> opcao;

    switch(opcao)
    {
        case 1:
            string ap1, ap2;

            std::cout << "Digite o apelido do jogador 1: ";
            std::cin >> ap1;

            std::cout << "Digite o apelido do jogador 2: ";
            std::cin >> ap2;

            ExecutarPartida jogo; 
            jogo.IniciarJogo();

            break;
        case 2:
            std::cout << "----- Cadastrar Novo Jogador ----- \n";

            cadastro cad;
            cad.cadastrar_jogador();
            
            break;
        case 3:
            std::cout << "----- Lista de Jogadores ----- \n";

            cadastro cad;
            cad.listar_jgdrs();

            break;
        default:
            std::cout << "Erro: Opção inválida! \n";
            break;
    }

    return 0;
}
