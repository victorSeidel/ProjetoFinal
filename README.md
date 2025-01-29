# ProjetoFinal
Projeto final da disciplina Programação e Desenvolvimento de Software II do curso de Ciência da Computação da UFMG.

# Introdução
O problema principal a ser resolvido era a implementação de 3 jogos - Lig4, jogo da velha e reversi - com base em classes herdeiras de uma classe abstrata para jogos. Além disso, era preciso fazer um sistema de cadastro de jogadores, o qual conteria as estatísticas dos jogadores (vitórias e derrotas em cada um dos jogos) e seria preservado entre diferentes execuções. Por fim, foi fortememte sugerido que algum tipo de funcionalidade extra fosse implementada.
# A Solução
Para fazer o que foi pedido, foram implementadas, além da classe abstrata e as suas herdeiras - as classes "cadastro", "jogador" e "ExecutarPartida". Passemos à análise delas, indicando o que fazem os seus métodos e o que representam os seus atributos.

"JogoDeTabuleiro": contém métodos virtuais para verificar a validade de jogadas, realizar jogadas, verificar a vitória de algum jogador, reiniciar o tabuleiro após uma partida e iniciar uma partida. Tem como atributo um vetor 2D que representa o tabuleiro. As classes herdeiras simplesmente sobrescrevem esses métodos para seus propósitos.

"cadastro": tem como atributo um mapa que representa a coleção de todos os cadastros de jogadores individuais, usando os seus apelidos como chave. A motivação do uso desse container foi o fato de que cada um de seus elementos terem uma chave única, assim como cada um dos jogadores tem um apelido único, o que facilita a procura por cada um dos jogadores. Possui métodos para adicionar e remover jogadores, listar os jogadores cadastrados, exportar os cadastros para um arquivo e importar os cadastros de tal arquivo.

"ExecutarPartida": contém simplesmente um método para iniciar algum jogo dado.

As entradas tomadas por nosso programa diferem dos exemplos dados no enunciado do trabalho. Baseada na ideia de implementação do grupo, consideramos que as entradas tomadas são mais intuitivas e correspondem melhor à estrutura do código. Além disso, os dados esperados do usuário são informados explicitamente durante a execução do código, portanto a mudança não acarreta em problemas.                   
# Partidas
Cada partida ocorre entre dois jogadores, aos quais são assinalados um símbolo "X" ou "O", que representam as suas jogadas. É, então, requisitado que o primeiro jogador faça sua jogada, informando as coordenadas da sua jogada. É testado se essa jogada é válida, e então, se for, ela é realizada e o tabuleiro é imprimido. Isso ocorre até que um jogador ganhe ou ocorra um empate, dependendo da lógica de cada jogo.
# Dificuldades
A maior dificuldade foi coordenar as atuações de cada membro do grupo, mantendo a estrutura em todo funcional. Além disso, fazer com que todos os arquivos pudessem ser compilados de forma conjunta e funcional também foi um desafio.
