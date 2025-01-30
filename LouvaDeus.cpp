#include "LouvaDeus.h"
#include <iostream>

LouvaDeus::LouvaDeus(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Carta(coordsCarta) {
    nome = "Louva-Deus";
    dano = 5;
    vida = 30;
    vida_inicial = vida;
    velocidade = 25;
    efeito = 0;
    caminho = "assets/insects/louva_deus.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void LouvaDeus::aplicar_efeito_pos_ataque(Carta* inimigo) {
    std::cout << "ENTROU APLICAR EFEITO POS LOUVA A DEUS" << std::endl;
    if (!inimigo->esta_viva()) {
        int vida_recuperada = vida_inicial / 2;
        vida += vida_recuperada;
        if (vida > vida_inicial)
            vida = vida_inicial; // Não excede a vida inicial
        std::cout << nome << " recuperou " << vida_recuperada << " pontos de vida (Vida atual: " << vida << ")." << std::endl;
    }
}