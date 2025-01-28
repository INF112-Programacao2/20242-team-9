#include "Barata.h"

Barata::Barata(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto) : Carta(coordsCarta){
    dano = 11;       
    vida = 20;
    vidaOriginal = 20;       
    velocidade = 30;  
    efeito = 3;      // Efeito 3: Sobrevive com 1 ponto de vida após dano letal
    efeitoBarataUsado = false;
    caminho = "assets/insects/barata.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}