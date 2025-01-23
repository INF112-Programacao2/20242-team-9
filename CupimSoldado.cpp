#include "CupimSoldado.h"

CupimSoldado::CupimSoldado(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Cupim(coordsCarta) {
    dano = 6;
    vida = 60;
    velocidade = 15;
    efeito = 0;
    custo = 1;
    caminho = "assets/insects/cupim_soldado.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}