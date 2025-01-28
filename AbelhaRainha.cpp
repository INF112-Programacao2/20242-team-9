#include "AbelhaRainha.h"
#include "Jogador.h"
#include <iostream>

AbelhaRainha::AbelhaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Abelha(coordsCarta) {
    nome = "Abelha Rainha";
    dano = 3;
    vida = 40;
    vida_inicial = vida;
    velocidade = 20;
    custo = 6;
    efeito = 2;
    caminho = "assets/insects/abelha_rainha.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void AbelhaRainha::aplicar_efeito_pre_ataque(Carta* inimigo) {
    jogador->aumentar_dano_cartas(1, this);
    std::cout << nome << " aumentou o dano de todas as outras cartas aliadas em 1 ponto." << std::endl;
}