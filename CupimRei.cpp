#include "CupimRei.h"

CupimRei::CupimRei(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Cupim(coordsCarta){
    dano = 12;       
    vida = 40;
    vidaOriginal = 40;       
    velocidade = 10;  
    efeito = 6;      // Efeito 6: Ao morrer, dá 1 ponto de dano extra para cada carta
    caminho = "assets/insects/cupim_rei.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}