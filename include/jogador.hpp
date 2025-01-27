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
    jogador(string,string); //para criar um jogador completamente novo
    jogador(string,string,int,int,int,int,int,int);//para criar um jogador a partir de um cadastro já salvo
    void imprime_estatisticas();
    void add_vit(string jogo); //para quem for usar: lembrar de chamar a função com as palavras certinhas, ou não vai contar a vitória ou derrota, e teremos um erro
    void add_derrt(string jogo);
    string get_nome();
    string get_apld();
    string export_estatisticas();
};
#endif