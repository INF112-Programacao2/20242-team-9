#include "Gafanhoto.h"

Gafanhoto::Gafanhoto(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Carta(coordsCarta){
    dano = 6;
    vida = 80;
    velocidade = 15;
    efeito = 0;
    custo = 4;
    caminho = "assets/insects/gafanhoto.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}