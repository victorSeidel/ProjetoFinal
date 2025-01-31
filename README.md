# ProjetoFinal
Projeto final da disciplina Programação e Desenvolvimento de Software II do curso de Ciência da Computação da Universidade Federal de Minas Gerais.

# Objetivo
Aplicar os conceitos de programação orientada a objetos aprendidos durante a disciplina em um projeto de escopo grande.

# Importante
O sistema foi desenvolvido e testado utilizando o sistema operacional Windows 10.

# Introdução
O desafio era criar um sistema de jogos e implementar 3 jogos de tabuleiro: Jogo da velha, Lig4 e Reversi. O sistema também deveria ser capaz de realizar o cadastro de jogadores, no qual seriam salvos as estatísiticas de vitórias e derrotas em cada jogo. O cadastro deveria ser preservadas durante diferentes execuções do programa. Tudo isso deveria ser implementado utilizando-se dos conceitos de POO, modularização e corretude, na intenção de se criar um sistema confiável, reutilizável e de fácil manutenção e expansão.

# A Solução
Para alcançarmos o que foi solicitado, foi criada uma classe abstrata "JogoDeTabuleiro", no qual contém os atributos primoridiais e todas as funções comuns entre jogos de tabuleiro, classe essa que foi herdada e especializada por cada classe própria de um jogo. Além disso, foram criadas as classes "Jogador" com os atributos necessários a serem salvos e "Cadastro", para controlar a inclusão e o salvamento dos jogadores. Abaixo está listado as principais classes e um detalhamento maior de seus métodos e atributos.

"JogoDeTabuleiro": classe abstrata que ontém métodos virtuais para verificar a validade de jogadas, realizar jogadas, verificar a vitória de algum jogador, reiniciar o tabuleiro após uma partida e iniciar uma partida. Tem como atributo uma matriz de duas dimensões que representa o tabuleiro. As classes herdeiras sobrescrevem e/ou especializam esses métodos para seus propósitos.

"Cadastro": classe responsável por armazenar todos os jogadores cadastrados em um map. Ela cadastrar, remove e lista os jogadores, verifica a existência (ou não) de cadastros e salva tudo em um arquvivo de texto para posteriormente ser lido e carregada as informações em uma nova execução do programa.

# Partidas
Cada partida ocorre entre dois jogadores, aos quais são assinalados um símbolo "X" ou "O", que representam as suas jogadas no tabubleiro. É, então, requisitado que o primeiro jogador faça sua jogada, informando as coordenadas x e y do tabuleiro em que deseja operar. É testado se essa jogada é válida e em caso positivo, ela é realizada, salva na matriz e o tabuleiro é mostrado para o jogador. Isso ocorre diversas vezes até que um jogador ganhe ou ocorra um empate, a depender da lógica implementada em cada jogo.

# Dificuldades
A maior dificuldade observada por nós durante o desenvolvimento do projeto foi a de coordenar as atuações de cada membro do grupo e estabelecer uma comunicação clara e objetiva, mantendo a estrutura do programa como um todo funcional e compatível entre si. Além disso, fazer com que todos os arquivos pudessem ser compilados de forma conjunta também foi um desafio.
