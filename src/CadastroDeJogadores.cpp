#include "CadastroDeJogadores.h"

CadastroDeJogadores::CadastroDeJogadores() {
    carregarDoArquivo();
}

CadastroDeJogadores::~CadastroDeJogadores() {
    salvarEmArquivo();
}

void CadastroDeJogadores::salvarEmArquivo() {
    std::ofstream arquivo(arquivoCadastro);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar jogadores no arquivo." << std::endl;
        return;
    }
    for (const auto& jogador : jogadores) {
        arquivo << jogador.serialize() << "\n";
    }
    arquivo.close();
}

void CadastroDeJogadores::carregarDoArquivo() {
    std::ifstream arquivo(arquivoCadastro);
    if (!arquivo.is_open()) {
        return;
    }
    std::string linha;
    while (std::getline(arquivo, linha)) {
        jogadores.push_back(Jogador::deserialize(linha));
    }
    arquivo.close();
}

void CadastroDeJogadores::cadastrarJogador(const std::string& nome, const std::string& apelido) {
    auto it = std::find_if(jogadores.begin(), jogadores.end(), [&](const Jogador& j) {
        return j.apelido == apelido;
    });

    if (it != jogadores.end()) {
        std::cerr << "Erro: Já existe um jogador com esse apelido." << std::endl;
        return;
    }

    jogadores.push_back({nome, apelido, 0, 0});
    std::cout << "Jogador cadastrado com sucesso!" << std::endl;
}

void CadastroDeJogadores::removerJogador(const std::string& apelido) {
    auto it = std::remove_if(jogadores.begin(), jogadores.end(), [&](const Jogador& j) {
        return j.apelido == apelido;
    });

    if (it == jogadores.end()) {
        std::cerr << "Erro: Nenhum jogador encontrado com esse apelido." << std::endl;
        return;
    }

    jogadores.erase(it, jogadores.end());
    std::cout << "Jogador removido com sucesso!" << std::endl;
}

void CadastroDeJogadores::listarJogadores() const {
    if (jogadores.empty()) {
        std::cout << "Nenhum jogador cadastrado." << std::endl;
        return;
    }

    std::cout << "Lista de jogadores cadastrados:" << std::endl;
    for (const auto& jogador : jogadores) {
        std::cout << "Nome: " << jogador.nome
                  << ", Apelido: " << jogador.apelido
                  << ", Vitórias: " << jogador.vitorias
                  << ", Derrotas: " << jogador.derrotas << std::endl;
    }
}
