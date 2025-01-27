#ifndef CADASTRO_H
#define CADASTRO_H
#include <string>
#include <map>
#include <fstream>
#include "jogador.hpp"
using namespace std;
class cadastro{
    private:
    map<string,jogador> jogadores; //fiz assim para que possamos ordenar os jogadores em ordem alfabética, aí cada um deles pode ter como chave o seu apelido, que é único
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
            outpt << it->second.export_estatisticas();
        }
        outpt.close();
    }
    void import_jgdrs(){
        fstream inpt;
        inpt.open("jogadores_salvos.txt", ios::in);
        while(!(inpt.eof())){
            string nm, apld;
            int vv,dv,vr,dr,vl,dl;
            inpt >> apld >> nm >> vv >> dv >> vr >> dr >> vl >> dl;
            jogador novo(nm,apld,vv,dv,vr,dr,vl,dl);
            this->add_jogador(novo);
        }
    }
};
#endif