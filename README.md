# ProjetoFinal
Projeto final da disciplina Programação e Desenvolvimento de Software II do curso de Ciência da Computação da UFMG.

# Introdução
O problema principal a ser resolvido era a implementação de 3 jogos - Lig4, jogo da velha e reversi - com base em classes herdeiras de uma classe abstrata para jogos. Além disso, era preciso fazer um sistema de cadastro de jogadores, o qual conteria as estatísticas dos jogadores (vitórias e derrotas em cada um dos jogos) e seria preservado entre diferentes execuções. Por fim, foi fortememte sugerido que algum tipo de funcionalidade extra fosse implementada.
# A Solução
Para fazer o que foi pedido, foram implementadas, além da classe abstrata e as suas herdeiras, a classe "ExecutarPartida". Passemos à análise delas, indicando o que fazem os seus métodos e o que representam os seus atributos.

"JogoDeTabuleiro": contém métodos virtuais para verificar a validade de jogadas, realizar jogadas, verificar a vitória de algum jogador, reiniciar o tabuleiro após uma partida e iniciar uma partida. Tem como atributo um vetor 2D que representa o tabuleiro. As classes herdeiras simplesmente sobrescrevem esses métodos para seus propósitos.

"ExecutarPartida": contém um método que verifica qual o jogo desejado e inicia a lógica dele.

As entradas tomadas por nosso programa diferem dos exemplos dados no enunciado do trabalho. Baseada na ideia de implementação do nosso grupo, consideramos que as entradas escolhidas são mais intuitivas e correspondem melhor à estrutura do código desenvolvido por nós, mantendo nosso método main mais 'clean' e fácil de entender. Além disso, os dados esperados do usuário são informados explicitamente durante a execução do código, portanto a mudança não acarreta em problemas.                   
# Partidas
Cada partida ocorre entre dois jogadores, aos quais são assinalados um símbolo "X" ou "O", que representam as suas jogadas. É, então, requisitado que o primeiro jogador faça sua jogada, informando as coordenadas da sua jogada. É testado se essa jogada é válida, e então, se for, ela é realizada e o tabuleiro é imprimido. Isso ocorre até que um jogador ganhe ou ocorra um empate, dependendo da lógica de cada jogo.
# Dificuldades
A maior dificuldade foi coordenar as atuações de cada membro do grupo, mantendo a estrutura em todo funcional. Além disso, fazer com que todos os arquivos pudessem ser compilados de forma conjunta e funcional também foi um desafio.
