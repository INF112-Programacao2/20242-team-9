#include "Gafanhoto.h"
#include <iostream>

Gafanhoto::Gafanhoto(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Carta(coordsCarta), pulou_ataque(false) {
    nome = "Gafanhoto";
    dano = 5;
    vida = 35;
    vida_inicial = vida;
    velocidade = 15;
    efeito = 0;
    caminho = "assets/insects/gafanhoto.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void Gafanhoto::receber_dano(unsigned int dano_recebido) {
    if (!pulou_ataque) {
        pulou_ataque = true;
        std::cout << nome << " pulou o ataque do oponente!" << std::endl;
    } else {
        Carta::receber_dano(dano_recebido);
    }
}