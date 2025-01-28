#include "CupimRei.h"

CupimRei::CupimRei(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Cupim(coordsCarta){
    nome = "Cupim Rei";
    dano = 8;
    vida = 35;
    velocidade = 10;
    efeito = 0;
    custo = 2;
    caminho = "assets/insects/cupim_rei.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}