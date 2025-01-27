#ifndef CADASTRO_H
#define CADASTRO_H
#include <string>
#include <map>
#include <fstream>
#include "jogador.hpp"
using namespace std;
class cadastro{
    private:
    map<string,jogador> jogadores; //fiz assim para que possamos ordenar os jogadores em ordem alfabética, aí cada pode ter como chave o seu apelido, que é único
    public:
    void add_jogador(jogador novo){
        this->jogadores.insert({novo.get_apld(),novo});
    }
    void rmv_jogador(jogador removido){
        this->jogadores.erase(removido.get_apld());
    }
    void listar_jgdrs(){
        map<string,jogador>::iterator it;
        for(it = this->jogadores.begin();it != this->jogadores.end();it++){
            it->second.imprime_estatisticas();
        }
    }
    void export_jgdrs(){
        fstream outpt;
        outpt.open("jogadores_salvos.txt", ios::app);
        map<string,jogador>::iterator it;
        for(it = this->jogadores.begin();it != this->jogadores.end();it++){
            outpt << it->second.get_apld() << " " << it->second.get_nome() << endl;
        }
        outpt.close();
    }
    void import_jgdrs(){
        fstream inpt;
        inpt.open("jogadores_salvos.txt", ios::in);
        while(!(inpt.eof())){
            string nm, apld;
            inpt >> apld >> nm;
            jogador novo(nm,apld);
            this->add_jogador(novo);
        }
    }
};
#endif