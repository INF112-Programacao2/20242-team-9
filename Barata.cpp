#include "Barata.h"
#include <iostream>

Barata::Barata(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Carta(coordsCarta), ressuscitou(false) {
    nome = "Barata";
    dano = 4;
    vida = 35;
    vida_inicial = vida;
    velocidade = 15;
    custo = 2;
    efeito = 1;
    caminho = "assets/insects/barata.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void Barata::receber_dano(unsigned int dano_recebido) {
    if (dano_recebido >= vida && !ressuscitou) {
        vida = 1;
        ressuscitou = true;
        std::cout << nome << " sobreviveu com 1 ponto de vida extra!" << std::endl;
    } else {
        Carta::receber_dano(dano_recebido);
    }
}