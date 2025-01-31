#ifndef CADASTRO_HPP
#define CADASTRO_HPP
#pragma once

#include <map>
#include <string>
#include <vector>
#include "Jogador.hpp"

/**
* @brief Classe que cuida do cadastro de jogadores. 
*/
class CadastroJogadores 
{
    private:
        /**
        * @brief Estrutura de dados Map para armazenar os jogadores cadastrados, utilizando o apelido do jogador como chave.
        */
        std::map<std::string, Jogador> jogadores;
        /**
        * @brief Nome do arquivo em que são salvos os dados dos jogadores.
        */
        const std::string arquivo = "jogadores.txt";

    public:
        // Operações básicas
        /**
        * @brief Método para cadastrar novos jogadores e adicionar ao mapa.
        * @param apelido Apelido único para cadastro.
        * @param nome Nome do jogador.
        */
        std::string cadastrar(const std::string& apelido, const std::string& nome);
        /**
        * @brief Método para remover cadastro de jogadores.
        * @param apelido Apelido do jogador que será removido.
        */
        std::string remover(const std::string& apelido);
        /**
        * @brief Método para listar os jogadores cadastrados.
        * @param ordernarPor Representa como a listagem será feita, ou seja, por apelido ("A") ou por ranking de vitórias ("R").
        */
        void listar(char ordenarPor);
    
        // Persistência
        /**
        * @brief Salvar os dados dos jogadores cadastrados em um arquivo de texto.
        */
        void salvarEmArquivo();
        /**
        * @brief Carregar os dados de jogadores salvos em um arquivo de texto.
        */
        void carregarDoArquivo();
    
        // Consultas
        /**
        * @brief Verifica se existe um cadastro.
        * @param apelido Apelido que será verificado.
        */
        bool jogadorExiste(const std::string& apelido) const;
        /**
        * @brief Retorna um objeto do tipo jogador.
        * @param apelido Apelido do jogador que deve ser retornado.
        */
        Jogador& getJogador(const std::string& apelido);
};

#endif
