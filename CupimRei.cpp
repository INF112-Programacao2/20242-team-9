#include "CupimRei.h"

CupimRei::CupimRei(sf::Vector2f coords): Cupim(coords){
    dano = 8;
    vida = 80;
    velocidade = 10;
    efeito = 0;
    custo = 2;
    caminho = "assets/insects/cupim_rei.png";
    carrega_icone_inseto(coords, caminho);
    carregar_carta_frente(coords);
}