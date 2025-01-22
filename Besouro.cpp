#include "Besouro.h"

Besouro::Besouro (sf::Vector2f coords): Carta(coords){
    dano = 5;
    vida = 70;
    velocidade = 15;
    efeito = 2;
    custo = 2;
    caminho = "assets/insects/besouro.png";
}