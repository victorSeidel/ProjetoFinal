#include "ExecutarPartida.hpp"

#include <iostream>

void Mostrar()
{
    std::cout << "Escolha o que deseja fazer: \n";
    std::cout << "1. Jogar \n";
    std::cout << "4. Encerrar Programa \n";
}

int main() 
{
    std::cout << "Olá, seja muito bem-vindo(a)! \n";

    do
    {
        Mostrar();
    
        int opcao;
        std::cin >> opcao;
    
        switch(opcao)
        {
            case 1:
                ExecutarPartida jogo; 
                jogo.IniciarJogo();
    
                break;
            
            case 2:
                std::cout << "----- Cadastrar Novo Jogador ----- \n";
                break;
            
            case 3:
                std::cout << "----- Lista de Jogadores ----- \n";
                break;

            case 4:
                break;
            
            default:
                std::cout << "Erro: Opção inválida! \n";
                break;
        }
    } while (opcao != 4);

    return 0;
}
