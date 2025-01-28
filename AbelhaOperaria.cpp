#include "AbelhaOperaria.h"

AbelhaOperaria::AbelhaOperaria(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Abelha(coordsCarta){
    dano = 12;       
    vida = 30;
    vidaOriginal = 30;       
    velocidade = 20;  
    efeito = 1;      // Efeito 1: Cura 1 ponto de vida a cada turno
    caminho = "assets/insects/abelha_operaria.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}