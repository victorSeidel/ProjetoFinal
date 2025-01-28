#include "cadastro.hpp"

void cadastro::cadastrar_jogador()
{
    string nome;
    string apelido;

    std::cout << "\n Digite seu nome: ";
    std::cin >> nome;

    std::cout << "\n Digite seu apelido: ";
    std::cin >> apelido;

    try
    {
        jogador novo = jogador(nome, apelido);
        add_jogador(novo);

        std::cout << "\n Cadastro do jogador " << apelido << " realizado com sucesso! \n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
        std::cout << "Não foi possível cadastrar um novo jogador. Tente novamente.";
    }
}

void cadastro::add_jogador(jogador novo){
        this->jogadores.insert({novo.get_apld(),novo});
    }

    void cadastro::rmv_jogador(jogador removido){
        this->jogadores.erase(removido.get_apld());
    }

    void cadastro::listar_jgdrs(){
        map<string,jogador>::iterator it;
        for(it = this->jogadores.begin();it != this->jogadores.end();it++){
            it->second.imprime_estatisticas();
        }
    }

    void cadastro::export_jgdrs(){
        fstream outpt;
        outpt.open("jogadores_salvos.txt", ios::app);
        map<string,jogador>::iterator it;
        for(it = this->jogadores.begin();it != this->jogadores.end();it++){
            outpt << it->second.export_estatisticas();
        }
        outpt.close();
    }

    void cadastro::import_jgdrs(){
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
