#include "ExecutarPartida.hpp"

#include <iostream>
/**
* @brief Mostra as possíveis opções de entrada para cada funcionalidade do sistema
*/
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
    int opcao=0; /** @brief Armazena a opção escolhida pelo jogador. */
        std::cin >> opcao;
                ExecutarPartida jogo; /** @brief Jogo a ser jogado */
                jogo.IniciarJogo();

    return 0;
}
