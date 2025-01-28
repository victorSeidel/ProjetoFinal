# Compilador
CC = g++

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c++11 -Iinclude

# Nome do executável
TARGET = PROJECTOFINAL

# Diretórios
SRC_DIR = output
BUILD_DIR = build

# Lista de arquivos fonte (.cpp)
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Cabeçalhos
HEADERS = $(wildcard include/*.hpp)

# Regra padrão
all: $(BUILD_DIR) $(TARGET)

# Cria diretório de build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Regra para o executável
$(TARGET).exe: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Regra para arquivos objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean