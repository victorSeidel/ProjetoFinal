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
    std::cout << "4. Remover Jogador \n";
    std::cout << "5. Encerrar Programa \n";
}

int main() 
{
    std::cout << "Olá, seja muito bem-vindo(a)! \n";

    CadastroDeJogadores cadastro;
    
    do
    {
        Mostrar();
    
        int opcao;
        std::cin >> opcao;
    
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
                std::string nome, apelido;
                std::cout << "----- Cadastrar Novo Jogador ----- \n";
                std::cout << "Digite o nome do jogador: ";
                std::getline(stcin, nome);
                std::cout << "Digite o apelido do jogador: ";
                std::getline(stcin, apelido);
                cadastro.cadastrarJogador(nome, apelido);
                
                break;
            
            case 3:
                std::cout << "----- Lista de Jogadores ----- \n";
                cadastro.listarJogadores();
    
                break;

            case 4:
                std::string apelido;
                std::cout << "Digite o apelido do jogador a ser removido: ";
                std::getline(stcin, apelido);
                cadastro.removerJogador(apelido);

                break;

            case 5:
                break;
            
            default:
                std::cout << "Erro: Opção inválida! \n";
                break;
        }
    } while (opcao != 5)

    return 0;
}
