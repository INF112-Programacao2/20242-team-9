# Nome do executável
TARGET = RPGGame

# Compilador e flags
CXX = g++
# Adicionadas flags de debug (-g), sem otimização (-O0) e mantida saída de stdout (-fsanitize=address)
CXXFLAGS = -Wall -Wextra -std=c++17 -g -O0 -fsanitize=address

# Flags de depuração para o linker
LDFLAGS = -fsanitize=address

# Bibliotecas da SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Arquivos fonte
SRCS = main.cpp GameManager.cpp Menu.cpp Jogo.cpp Carta.cpp MonteCarta.cpp Jogador.cpp

# Arquivos objeto (em diretório separado para debug)
BUILD_DIR = build
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Regra padrão
all: $(BUILD_DIR) $(TARGET)

# Criar diretório de build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(SFML_LIBS)

# Regra para compilar arquivos .cpp em .o
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra de debug (compila com saída extra)
debug: CXXFLAGS += -DDEBUG
debug: clean all

# Limpeza
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Executar com saída redirecionada para arquivo de log
run: $(TARGET)
	./$(TARGET) 2>&1 | tee debug.log

# Dependências
$(BUILD_DIR)/main.o: GameManager.h Menu.h Jogo.h EstadoJogo.h Carta.h Tipo.h
$(BUILD_DIR)/GameManager.o: GameManager.h Menu.h Jogo.h EstadoJogo.h Carta.h Tipo.h
$(BUILD_DIR)/Menu.o: Menu.h EstadoJogo.h
$(BUILD_DIR)/Jogo.o: Jogo.h Carta.h EstadoJogo.h
$(BUILD_DIR)/Carta.o: Carta.h Tipo.h

.PHONY: all clean debug run