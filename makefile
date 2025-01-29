# Compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Lista de arquivos-fonte
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Lista de arquivos objeto
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Nome do executável
TARGET = $(BIN_DIR)/ProjetoFinal

# Regra principal
all: $(TARGET)

# Compilação do executável
$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilação dos arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criar diretórios se não existirem
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Limpeza dos arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Remover apenas os objetos
clean-obj:
	rm -rf $(OBJ_DIR)

# Recompilação total
rebuild: clean all

# Executar o programa
run: all
	./$(TARGET)
