#include "Jogo.h"

//coordenadas da barra de vida e de energia na tela
unsigned int coordX1 = 1100, coordY1 = 600, coordX2= 400, coordY2= 400;

Jogo::Jogo(sf::RenderWindow* window) : janela(window){
    jogador1 = new Jogador(coordX1, coordY1);
    jogador2 = new Jogador(coordX2, coordY2);
    try{
        carrega_tabuleiro();
        std::cout << "CARREGOU TABULEIRO!" << std::endl;
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}
void Jogo::carrega_tabuleiro(){
    if (!texturaMesa.loadFromFile("assets/board/board.png")) {
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
    for(int i=0; i<5; i++){
        janela->draw(jogador1->get_sprite_mao_carta(i));
        janela->draw(jogador1->get_sprite_mao_inseto(i));
    }
    janela->draw(monte.get_sprite_monte());
    janela->draw(jogador1->get_sprite_barra());
    janela->draw(jogador2->get_sprite_barra());
    janela->display();
}

Jogo::~Jogo(){
    delete jogador1;
    delete jogador2;
}