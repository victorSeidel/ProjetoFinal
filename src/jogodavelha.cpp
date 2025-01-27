#include "jogodavelha.hpp"
JogoDaVelha::JogoDaVelha():JogoDeTabuleiro::JogoDeTabuleiro(3,3){}
    bool JogoDaVelha::VerificarVitoria(jogador& j1, jogador& j2){
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
    void JogoDaVelha::RealizarJogada(int linha, int coluna, char jogador){
        this->tabuleiro[linha - 1][coluna - 1] = jogador;
    }
    void JogoDaVelha::Executar_Partida(jogador& j1, jogador& j2){
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