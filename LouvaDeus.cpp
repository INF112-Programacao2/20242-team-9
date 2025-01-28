#include "LouvaDeus.h"

LouvaDeus::LouvaDeus(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Carta(coordsCarta){
    dano = 13;       
    vida = 40;
    vidaOriginal = 40;       
    velocidade = 30;  
    efeito = 11;     // Efeito 11: Se derrotar uma carta, recupera metade da vida
    caminho = "assets/insects/louva_deus.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}