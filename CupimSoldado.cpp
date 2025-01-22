#include "CupimSoldado.h"

CupimSoldado::CupimSoldado(sf::Vector2f coords): Cupim(coords) {
    dano = 6;
    vida = 60;
    velocidade = 15;
    efeito = 0;
    custo = 1;
    caminho = "assets/insects/cupim_soldado.png";
    carrega_icone_inseto(coords, caminho);
    carregar_carta_frente(coords);
}