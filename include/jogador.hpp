#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <iostream>
using namespace std;
class jogador{
    private:
    int vit_velha;
    int derrt_velha;
    int vit_rvrsi;
    int derrt_rvrsi;
    int vit_lig;
    int derrt_lig;
    string nome;
    string apelido;
    public:
    jogador(string nm,string apld){
        this->nome = nm;
        this->apelido = apld;
    }
    void imprime_estatisticas(){
        cout << this->apelido << " " << this->nome << endl;
        cout << "REVERSI - V: " << this->vit_rvrsi << "D: " << this-> derrt_rvrsi << endl;
        cout << "LIG 4 - V: " << this->vit_lig << "D: " << this-> derrt_lig << endl;
        cout << "VELHA - V: " << this->vit_velha << "D: " << this-> derrt_velha << endl;
    }
    void add_vit(string jogo){ //para quem for usar: lembrar de chamar a função com as palavras certinhas, ou não vai contar a vitória ou derrota, e teremos um erro
        if(jogo == "velha"){
            this->vit_velha++;
        }else if(jogo == "reversi"){
            this->vit_rvrsi++;
        }else if(jogo == "lig"){
            this->vit_lig++;
        }
    }
    void add_derrt(string jogo){
        if(jogo == "velha"){
            this->derrt_velha++;
        }else if(jogo == "reversi"){
            this->derrt_rvrsi++;
        }else if(jogo == "lig"){
            this->derrt_lig++;
        }
    }
    string get_nome(){
        return this->nome;
    }
    string get_apld(){
        return this->apelido;
    }
};
#endif