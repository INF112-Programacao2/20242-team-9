#include "Cigarra.h"

Cigarra::Cigarra(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Carta(coordsCarta){
    nome = "Cigarra";
    dano = 5;
    vida = 25;
    velocidade = 15;
    efeito = 2;
    custo = 4;
    caminho = "assets/insects/cigarra.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
    
}