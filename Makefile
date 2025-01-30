install:
	sudo apt-get install libsfml-dev

compilar: 
	g++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

executar:
	./a.out

limpar:
	rm a.out

jogo:
	make install
	make compilar
	make executar
	make limpar