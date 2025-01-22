#include "Cigarra.h"

Cigarra::Cigarra(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Carta(coordsCarta){
    dano = 6;
    vida = 60;
    velocidade = 15;
    efeito = 2;
    custo = 4;
    caminho = "assets/insects/cigarra.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
    
}