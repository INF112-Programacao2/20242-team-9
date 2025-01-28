#include "Cigarra.h"

Cigarra::Cigarra(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Carta(coordsCarta){
    dano = 12;       
    vida = 30;
    vidaOriginal = 30;       
    velocidade = 20;  
    efeito = 5;      // Efeito 5: Pode atacar duas vezes por turno
    segundo_ataque_disponivel = true;
    caminho = "assets/insects/cigarra.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}