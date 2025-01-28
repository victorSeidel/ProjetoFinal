# Compilador
CC = g++

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c++11

# Nome do executável
TARGET = jogo

# Lista de arquivos fonte (.cpp)
SOURCES = main.cpp ExecutarPartida.cpp reversi.cpp Lig4.cpp JogoDaVelha.cpp JogoDeTabuleiro.cpp Cadastro.cpp Jogador.cpp 

# Lista de arquivos objeto (.o)
OBJECTS = $(SOURCES:.cpp=.o)

# Cabeçalhos (headers)
HEADERS = ExecutarPartida.hpp Reversi.hpp Lig4.hpp JogoDaVelha.hpp JogoDeTabuleiro.hpp Cadastro.hpp Jogador.hpp

# Regra padrão: compila o executável
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Regra genérica para compilar arquivos .cpp em .o
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove arquivos objeto e o executável
clean:
	rm -f $(OBJECTS) $(TARGET)

# Marca as regras que não são arquivos
.PHONY: all clean