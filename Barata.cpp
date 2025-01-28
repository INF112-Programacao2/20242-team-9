#include "Barata.h"

Barata::Barata(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto) : Carta(coordsCarta){
    nome = "Barata";
    dano = 7;
    vida = 35;
    velocidade = 15;
    efeito = 1;
    custo = 2;
    caminho = "assets/insects/barata.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}