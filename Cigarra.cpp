#include "Cigarra.h"

Cigarra::Cigarra(sf::Vector2f coords): Carta(coords){
    dano = 6;
    vida = 60;
    velocidade = 15;
    efeito = 2;
    custo = 4;
    caminho = "assets/insects/cigarra.png";
    carrega_icone_inseto(coords, caminho);
    carregar_carta_frente(coords);
    
}