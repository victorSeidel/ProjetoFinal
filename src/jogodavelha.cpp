/**
 * 
 */
#include "jogodavelha.hpp"
JogoDaVelha::JogoDaVelha():JogoDeTabuleiro::JogoDeTabuleiro(3,3){}
    bool JogoDaVelha::VerificarVitoria(char j1)const{
        if(this->tabuleiro[0][0] == j1 && this->tabuleiro[0][1] == j1 && this->tabuleiro[0][2] == j1){
            return true;
        } else if(this->tabuleiro[1][0] == j1 && this->tabuleiro[1][1] == j1 && this->tabuleiro[1][2] == j1){
            return true;
        }else if(this->tabuleiro[2][0] == j1 && this->tabuleiro[2][1] == j1 && this->tabuleiro[2][2] == j1){
            return true;
        }else if(this->tabuleiro[0][0] == j1 && this->tabuleiro[1][1] == j1 && this->tabuleiro[2][2] == j1){
            return true;
        } else if(this->tabuleiro[0][2] == j1 && this->tabuleiro[1][1] == j1 && this->tabuleiro[2][0] == j1){
            return true;
        }else if(this->tabuleiro[0][0] == j1 && this->tabuleiro[1][0] == j1 && this->tabuleiro[2][0] == j1){
            return true;
        }else if(this->tabuleiro[0][1] == j1 && this->tabuleiro[1][1] == j1 && this->tabuleiro[2][1] == j1){
            return true;
        } else if(this->tabuleiro[0][2] == j1 && this->tabuleiro[1][2] == j1 && this->tabuleiro[2][2] == j1){
            return true;
        }else{
            return false;
        }
    }
    void JogoDaVelha::ImprimirTabuleiro(){
    for (const auto& linha : tabuleiro) 
    {
        for (char celula : linha)
        {
            std::cout << celula << " ";
        }

        std::cout << "\n";
    }
}
bool JogoDaVelha::JogadaValida(int linha, int coluna){
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas && tabuleiro[linha][coluna] == '.';
}
    void JogoDaVelha::RealizarJogada(int linha, int coluna, char jogador){
        this->tabuleiro[linha - 1][coluna - 1] = jogador;
    }
    void JogoDaVelha::Reiniciar(){
    for (auto& linha : tabuleiro) 
    {
        std::fill(linha.begin(), linha.end(), '.');
    }
}
    void JogoDaVelha::ExecutarPartida(jogador& j1, jogador& j2){
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
                if(this->VerificarVitoria('X')){
                    std::cout << j1.get_apld() << "ganhou !" << std::endl;
                    j1.add_vit("velha");
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
                if(this->VerificarVitoria('O')){
                    std::cout << j2.get_apld() << "ganhou !" << std::endl;
                    j2.add_vit("velha");
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
    void JogoDaVelha::Jogar(jogador& j1, jogador& j2){
        this->ExecutarPartida(j1,j2);
    }