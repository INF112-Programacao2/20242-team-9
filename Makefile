# Nome do executável
TARGET = RPGGame

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Bibliotecas da SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Arquivos fonte
SRCS = main.cpp GameManager.cpp Menu.cpp Jogo.cpp Carta.cpp MonteCarta.cpp Jogador.cpp Deck.cpp

# Arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIBS)

# Regra para compilar arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -f $(OBJS) $(TARGET)

# Dependências
main.o: GameManager.h Menu.h Jogo.h EstadoJogo.h Carta.h Tipo.h
GameManager.o: GameManager.h Menu.h Jogo.h EstadoJogo.h Carta.h Tipo.h
Menu.o: Menu.h EstadoJogo.h
Jogo.o: Jogo.h Carta.h EstadoJogo.h
Carta.o: Carta.h Tipo.h
