#ifndef CADASTRO_H
#define CADASTRO_H
#include <string>
#include <map>
#include <fstream>
#include "jogador.hpp"
using namespace std;
class cadastro{
    public:
    map<string,jogador> jogadores; //fiz assim para que possamos ordenar os jogadores em ordem alfabética, aí cada um deles pode ter como chave o seu apelido, que é único
    void cadastrar_jogador();
    void add_jogador(jogador);
    void rmv_jogador(jogador);
    void listar_jgdrs();
    void export_jgdrs();
    void import_jgdrs();
};
#endif
