#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>

struct Jogador 
{
  std::string nome;
  std::string apelido;
  int vitorias;
  int derrotas;

  // Serialização para salvar em arquivo
  std::string serialize() const 
  {
      return nome + "," + apelido + "," + std::to_string(vitorias) + "," + std::to_string(derrotas);
  }

  // Deserialização para ler do arquivo
  static Jogador deserialize(const std::string& linha) 
  {
      Jogador jogador;
      size_t pos1 = linha.find(',');
      size_t pos2 = linha.find(',', pos1 + 1);
      size_t pos3 = linha.find(',', pos2 + 1);

      jogador.nome = linha.substr(0, pos1);
      jogador.apelido = linha.substr(pos1 + 1, pos2 - pos1 - 1);
      jogador.vitorias = std::stoi(linha.substr(pos2 + 1, pos3 - pos2 - 1));
      jogador.derrotas = std::stoi(linha.substr(pos3 + 1));

      return jogador;
  }
};

#endif // JOGADOR_H
