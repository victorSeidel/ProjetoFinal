#include "ExecutarPartida.hpp"
#include "Cadastro.hpp"
#include "Jogador.hpp"

#include <iostream>

void Mostrar()
{
    std::cout << "Escolha o que deseja fazer: \n";
    std::cout << "1. Jogar \n";
    std::cout << "2. Cadastrar Jogador \n";
    std::cout << "3. Listar Jogadores \n";
    std::cout << "4. Encerrar Programa \n";
}

int main() 
{
    std::cout << "Olá, seja muito bem-vindo(a)! \n";

    int l = 1;
    while(l)
    {
        Mostrar();
    
        int opcao;
        std::cin >> opcao;
    
        cadastro cadastro;
    
        string ap1, ap2;
        jogador jogador1, jogador2;
    
        switch(opcao)
        {
            case 1:
                std::cout << "Digite o apelido do jogador 1: ";
                std::cin >> ap1;
    
                std::cout << "Digite o apelido do jogador 2: ";
                std::cin >> ap2;
    
                ExecutarPartida jogo; 
                jogo.IniciarJogo(jogador1, jogador2);
    
                break;
            
            case 2:
                std::cout << "----- Cadastrar Novo Jogador ----- \n";
    
                cadastro.cadastrar_jogador();
                cadastro.export_jgdrs();
                
                break;
            
            case 3:
                std::cout << "----- Lista de Jogadores ----- \n";
    
                cadastro.listar_jgdrs();
    
                break;

            case 4:
                l = 0;
                break;
            
            default:
                std::cout << "Erro: Opção inválida! \n";
                break;
        }
    }

    return 0;
}
