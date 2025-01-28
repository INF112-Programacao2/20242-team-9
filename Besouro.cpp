#include "Besouro.h"

Besouro::Besouro (sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Carta(coordsCarta){
    dano = 5;
    vida = 70;
    velocidade = 15;
    efeito = 2;
    custo = 2;
    caminho = "assets/insects/besouro.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}