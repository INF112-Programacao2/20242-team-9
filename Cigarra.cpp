#include "Cigarra.h"
#include <iostream>

Cigarra::Cigarra(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Carta(coordsCarta) {
    nome = "Cigarra";
    dano = 3;
    vida = 25;
    vida_inicial = vida;
    velocidade = 15;
    custo = 4;
    efeito = 2;
    caminho = "assets/insects/cigarra.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void Cigarra::atacar(Carta* alvo) {
    for (int i = 0; i < 2; ++i) {
        if (alvo->esta_viva()) {
            std::cout << nome << " ataca (" << (i + 1) << "/2)." << std::endl;
            alvo->receber_dano(dano);
        } else {
            break;
        }
    }
}