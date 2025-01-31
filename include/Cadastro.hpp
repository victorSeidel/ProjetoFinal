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
        * @brief Estrutura de dados Mapp para armazenar os jogadores cadastrados, utilizando o apelido do jogador como chave.
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
        * @param apelido apelido único para cadastro
        * @param nome nome do jogador
        */
        std::string cadastrar(const std::string& apelido, const std::string& nome);
        /**
        * @brief Método para remover cadastro de jogadores.
        * @param apelido remover cadastro com tal apelido
        */
        std::string remover(const std::string& apelido);
        /**
        * @brief Método para listar os jogadores cadastrados.
        * @param ordernarPor ordernar por nome ou apelido
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
        * @param apelido apelido que será verificado
        */
        bool jogadorExiste(const std::string& apelido) const;
        /**
        * @brief Retorna um objeto do tipo jogador.
        * @param apelido retorna o jogador com esse apelido
        */
        Jogador& getJogador(const std::string& apelido);
};

#endif
