#include "CupimSoldado.h"

CupimSoldado::CupimSoldado(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Cupim(coordsCarta) {
    dano = 12;       
    vida = 30;
    vidaOriginal = 30;       
    velocidade = 30;  
    efeito = 7;      // Efeito 7: Ganha 1 ponto de dano para cada carta aliada derrotada
    cartas_aliadas_derrotadas = 0;
    caminho = "assets/insects/cupim_soldado.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}