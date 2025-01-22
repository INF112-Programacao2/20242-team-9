#include "Gafanhoto.h"

Gafanhoto::Gafanhoto(sf::Vector2f coords): Carta(coords){
    dano = 6;
    vida = 80;
    velocidade = 15;
    efeito = 0;
    custo = 4;
    caminho = "assets/insects/gafanhoto.png";
    carrega_icone_inseto(coords, caminho);
    carregar_carta_frente(coords);
}