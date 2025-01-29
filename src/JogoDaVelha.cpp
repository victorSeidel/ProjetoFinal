/**
 * 
 */
#include "JogoDaVelha.hpp"
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

    //JogoDaVelha::~JogoDaVelha() = default;

    void JogoDaVelha::ImprimirTabuleiro() const {
    for (const auto& linha : tabuleiro) 
    {
        for (char celula : linha)
        {
            std::cout << celula << " ";
        }

        std::cout << "\n";
    }
}
bool JogoDaVelha::JogadaValida(int linha, int coluna) const{
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
    int JogoDaVelha::ExecutarPartida()
{
        std::cout << "O jogador 1 será representado por um X e o jogador 2 por uma O." << std::endl;
        int num_jogadas = 0;
        while(num_jogadas < 9){
            this->ImprimirTabuleiro();
            num_jogadas++;
            int lin,col;
            if(num_jogadas%2 != 0){
                std::cout << "É a vez do jogador 1" << std::endl;
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
                    std::cout << "Jogador 1 ganhou!" << std::endl;
                    num_jogadas = 0;
                    return 1;
                }else{
                    continue;
                }
            }else{
                std::cout << "É a vez de jogador 2" << std::endl;
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
                    std::cout << " Jogador 2 ganhou!" << std::endl;
                    num_jogadas = 0;
                    return 2;
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
    int JogoDaVelha::Jogar()
    {
        return this->ExecutarPartida();
    }
