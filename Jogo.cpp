#include "Jogo.h"

//coordenadas da barra de vida e de energia na tela
float coordX1 = 1300, coordY1 = 700, coordX2= 100, coordY2= 60;

Jogo::Jogo(sf::RenderWindow* window) : janela(window), carta(), jogador1(coordX1, coordY1),
jogador2(coordX2, coordY2){
    if (!texturaMesa.loadFromFile("board.png")) {
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    mesa.setTexture(texturaMesa);
    mesa.setPosition(0, 0);
}

void Jogo::loop_eventos() {
    sf::Event evento;
    while (janela->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            janela->close();
        }
    }
}

void Jogo::run_jogo() {
    while (janela->isOpen()) {
        loop_eventos();
        desenhar();
    }
}

void Jogo::desenhar() {
    janela->clear();
    janela->draw(mesa);
    //janela->draw(carta.get_sprite());
    for(int i=0; i<jogador1.get_numCartas(); i++){
        janela->draw(jogador1.get_sprite_mao(i));
    }
    janela->draw(monte.get_sprite());
    janela->draw(jogador1.get_sprite_barra());
    janela->draw(jogador2.get_sprite_barra());
    janela->display();
}