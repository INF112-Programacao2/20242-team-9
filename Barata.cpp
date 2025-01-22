#include "Barata.h"

Barata::Barata(sf::Vector2f coords) : Carta(coords){
    dano = 5;
    vida = 80;
    velocidade = 15;
    efeito = 1;
    custo = 2;
    caminho = "assets/insects/barata.png";
    carrega_icone_inseto(coords, caminho);
    carregar_carta_frente(coords);
}