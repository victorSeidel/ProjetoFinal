#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <iostream>
using namespace std;
/**
 * @brief Classe para armazenar e manipular dados e estatísticas de um jogador.
 */
class jogador{
    private:
    int vit_velha; /** número de vitórias no jogo da velha */
    int derrt_velha; /** número de derrotas no jogo da velha */
    int vit_rvrsi; /** número de vitórias no reversi */
    int derrt_rvrsi; /** número de derrotas no reversi */
    int vit_lig; /** número de vitórias no lig4 */
    int derrt_lig; /** número de derrotas no lig4 */
    string nome; /** nome do jogador */
    string apelido;/** apelido único do jogador */
    public:
    /**
     * @brief construtor para jogadores ainda não cadastrados
     * @param nm nome do jogador a ser cadastrado
     * @param apld apelido do jogador a ser cadastrado
     */
    jogador(string nm,string apld); 
    /**
     * @brief construtor para jogadores já antes cadastrados, com dados salvos em um arquivo.
     * @param nm nome do jogador a ser cadastrado
     * @param apld apelido do jogador a ser cadastrado
     * @param vv vitórias no jogo da velha
     * @param dv derrotas no jogo da velha
     * @param vr vitórias no reversi
     * @param dr derrotas no reversi
     * @param vl vitórias no lig4
     * @param dl derrotas no lig4
     */
    jogador(string nm,string apld,int vv,int dv,int vr,int dr,int vl,int dl);
    /**
     * @brief imprime as estatísticas do jogador.
     */
    void imprime_estatisticas();
    /**
     * @brief contabiliza uma vitória para o jogador.
     * @param jogo informa em qual jogo a vitória ocorreu
     */
    void add_vit(string jogo); //para quem for usar: lembrar de chamar a função com as palavras certinhas, ou não vai contar a vitória ou derrota, e teremos um erro
    /**
     * @brief contabiliza uma derrota para o jogador.
     * @param jogo informa em qual jogo a derrota ocorreu
     */
    void add_derrt(string jogo);
    /**
     * @brief método para obter o nome do jogador.
     * @return o nome do jogador
     */
    string get_nome();
    /**
     * @brief método para obter o apelido do jogador.
     * @return o apelido do jogador
     */
    string get_apld();
    /**
     * @brief método para obter as estatísticas do jogador, visando a salvá-las em um arquivo.
     * @details este método é complementado por outro na classe "cadastro", que efetivamente escreve as informações no arquivo.
     * @return as estatísticas do jogador, em uma linha
     */
    string export_estatisticas();
};
#endif
