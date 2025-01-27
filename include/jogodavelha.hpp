#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H
#include "JogoDeTabuleiro.hpp"
#include "jogador.hpp"
class JogoDaVelha: public JogoDeTabuleiro{
    JogoDaVelha():JogoDeTabuleiro(3,3){}
    bool VerificarVitoria(jogador& j1, jogador& j2){
        if(this->tabuleiro[0][0] == 'X' && this->tabuleiro[0][1] == 'X' && this->tabuleiro[0][2] == 'X'){
            std::cout << j1.get_apld() << "ganhou !" << std::endl;
            j1.add_vit("velha");
            return true;
        } else if(this->tabuleiro[1][0] == 'X' && this->tabuleiro[1][1] == 'X' && this->tabuleiro[1][2] == 'X'){
            std::cout << j1.get_apld() << "ganhou !" << std::endl;
            j1.add_vit("velha");
            return true;
        }else if(this->tabuleiro[2][0] == 'X' && this->tabuleiro[2][1] == 'X' && this->tabuleiro[2][2] == 'X'){
            std::cout << j1.get_apld() << "ganhou !" << std::endl;
            j1.add_vit("velha");
            return true;
        }else if(this->tabuleiro[0][0] == 'X' && this->tabuleiro[1][1] == 'X' && this->tabuleiro[2][2] == 'X'){
            std::cout << j1.get_apld() << "ganhou !" << std::endl;
            j1.add_vit("velha");
            return true;
        } else if(this->tabuleiro[0][2] == 'X' && this->tabuleiro[1][1] == 'X' && this->tabuleiro[2][0] == 'X'){
            std::cout << j1.get_apld() << "ganhou !" << std::endl;
            j1.add_vit("velha");
            return true;
        }else if(this->tabuleiro[0][0] == 'X' && this->tabuleiro[1][0] == 'X' && this->tabuleiro[2][0] == 'X'){
            std::cout << j1.get_apld() << "ganhou !" << std::endl;
            j1.add_vit("velha");
            return true;
        }else if(this->tabuleiro[0][1] == 'X' && this->tabuleiro[1][1] == 'X' && this->tabuleiro[2][1] == 'X'){
            std::cout << j1.get_apld() << "ganhou !" << std::endl;
            j1.add_vit("velha");
            return true;
        } else if(this->tabuleiro[0][2] == 'X' && this->tabuleiro[1][2] == 'X' && this->tabuleiro[1][1] == 'X'){
            std::cout << j1.get_apld() << "ganhou !" << std::endl;
            j1.add_vit("velha");
            return true;
        }else if(this->tabuleiro[0][0] == 'O' && this->tabuleiro[0][1] == 'O' && this->tabuleiro[0][2] == 'O'){
            std::cout << j2.get_apld() << "ganhou !" << std::endl;
            j2.add_vit("velha");
            return true;
        } else if(this->tabuleiro[1][0] == 'O' && this->tabuleiro[1][1] == 'O' && this->tabuleiro[1][2] == 'O'){
            std::cout << j2.get_apld() << "ganhou !" << std::endl;
            j2.add_vit("velha");
            return true;
        }else if(this->tabuleiro[2][0] == 'O' && this->tabuleiro[2][1] == 'O' && this->tabuleiro[2][2] == 'O'){
            std::cout << j2.get_apld() << "ganhou !" << std::endl;
            j2.add_vit("velha");
            return true;
        }else if(this->tabuleiro[0][0] == 'O' && this->tabuleiro[1][1] == 'O' && this->tabuleiro[2][2] == 'O'){
            std::cout << j2.get_apld() << "ganhou !" << std::endl;
            j2.add_vit("velha");
            return true;
        } else if(this->tabuleiro[0][2] == 'O' && this->tabuleiro[1][1] == 'O' && this->tabuleiro[2][0] == 'O'){
            std::cout << j2.get_apld() << "ganhou !" << std::endl;
            j2.add_vit("velha");
            return true;
        }else if(this->tabuleiro[0][0] == 'O' && this->tabuleiro[1][0] == 'O' && this->tabuleiro[2][0] == 'O'){
            std::cout << j2.get_apld() << "ganhou !" << std::endl;
            j2.add_vit("velha");
            return true;
        }else if(this->tabuleiro[0][1] == 'O' && this->tabuleiro[1][1] == 'O' && this->tabuleiro[2][1] == 'O'){
            std::cout << j2.get_apld() << "ganhou !" << std::endl;
            j2.add_vit("velha");
            return true;
        }else if(this->tabuleiro[0][2] == 'O' && this->tabuleiro[1][2] == 'O' && this->tabuleiro[2][1] == 'O'){
            std::cout << j2.get_apld() << "ganhou !" << std::endl;
            j2.add_vit("velha");
            return true;
        }else{
            return false;
        }
    }
    void RealizarJogada(int linha, int coluna, char jogador){
        this->tabuleiro[linha - 1][coluna - 1] = jogador;
    }
    void Executar_Partida(jogador& j1, jogador& j2){
        std::cout << "As jogadas de " << j1.get_apld() << " serão representadas por um X, enquanto as jogadas de " << j2.get_apld() << " serão representadas por um O." << std::endl;
        int num_jogadas = 0;
        while(num_jogadas < 9){
            this->ImprimirTabuleiro();
            num_jogadas++;
            int lin,col;
            if(num_jogadas%2 != 0){
                std::cout << "É a vez de " << j1.get_apld() << std::endl;
                std::cout << "Digite, nessa ordem, o número da linha e da coluna em que deseja realizar sua jogada." << std::endl << "(esperando jogada)" << std::endl;
                while(1){
                    std::cin >> lin >> col;
                    if(this->JogadaValida(lin - 1,col - 1)){
                        this->RealizarJogada(lin - 1,col - 1,'X');
                        break;
                    }else{
                        std::cout << "Jogada inválida, tente novamente." << std::endl << "(esperando jogada)" << std::endl;
                        continue;
                    }       
                }
                if(this->VerificarVitoria(j1,j2)){
                    num_jogadas = 0;
                    break;
                }else{
                    continue;
                }
            }else{
                std::cout << "É a vez de " << j2.get_apld() << std::endl;
                std::cout << "Digite, nessa ordem, o número da linha e da coluna em que deseja realizar sua jogada." << std::endl << "(esperando jogada)" << std::endl;
                while(1){
                    std::cin >> lin >> col;
                    if(this->JogadaValida(lin - 1,col - 1)){
                        this->RealizarJogada(lin - 1,col - 1,'O');
                        break;
                    }else{
                        std::cout << "Jogada inválida, tente novamente." << std::endl << "(esperando jogada)" << std::endl;
                        continue;
                    }       
                }
                if(this->VerificarVitoria(j1,j2)){
                    num_jogadas = 0;
                    break;
                }else{
                    continue;
                }
            }

        }
        if(num_jogadas == 9){
            std::cout << "O jogo terminou empatado." << std::endl;
        }
        this->Reiniciar();
    }
};
#endif