#include "Besouro.h"
#include <iostream>

Besouro::Besouro(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Carta(coordsCarta) {
    nome = "Besouro";
    dano = 3;
    vida = 45;
    vida_inicial = vida;
    velocidade = 15;
    efeito = 2;
    caminho = "assets/insects/besouro.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void Besouro::receber_dano(unsigned int dano_recebido) {
    unsigned int dano_final = (dano_recebido > 1) ? dano_recebido - 1 : 0;
    Carta::receber_dano(dano_final);
    std::cout << nome << " reduziu o dano recebido em 1 ponto (Dano recebido: " << dano_final << ")." << std::endl;
}