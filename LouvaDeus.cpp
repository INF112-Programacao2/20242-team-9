#include "LouvaDeus.h"

LouvaDeus::LouvaDeus(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Carta(coordsCarta){
    nome = "Louva-Deus";
    dano = 7;
    vida = 25;
    velocidade = 25;
    efeito = 0;
    custo = 4;
    caminho = "assets/insects/louva_deus.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}