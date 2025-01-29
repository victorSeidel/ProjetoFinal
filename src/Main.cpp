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
    std::cout << "Ola, seja muito bem-vindo(a)! \n";
    Mostrar();
    int opcao=0;
        std::cin >> opcao;
                ExecutarPartida jogo; 
                jogo.IniciarJogo();

    return 0;
}
