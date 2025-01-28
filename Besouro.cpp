#include "Besouro.h"

Besouro::Besouro(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Carta(coordsCarta){
    dano = 12;       
    vida = 50;
    vidaOriginal = 50;       
    velocidade = 10;  
    efeito = 4;      // Efeito 4: Reduz o dano recebido em 1 ponto
    caminho = "assets/insects/besouro.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}