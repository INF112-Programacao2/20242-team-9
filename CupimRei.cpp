#include "CupimRei.h"
#include "Jogador.h"
#include <iostream>

CupimRei::CupimRei(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Cupim(coordsCarta) {
    nome = "Cupim Rei";
    dano = 4;
    vida = 35;
    vida_inicial = vida;
    velocidade = 10;
    custo = 2;
    efeito = 0;
    caminho = "assets/insects/cupim_rei.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void CupimRei::aplicar_efeito_morte(Jogador* jogador_inimigo) {
    int dano_extra = jogador->get_numCartas();
    std::cout << nome << " causou " << dano_extra << " pontos de dano ao oponente ao morrer!" << std::endl;
    // Implementar lógica para causar dano ao jogador inimigo (se houver vida do jogador)
    // Se não houver, talvez cause dano à carta do oponente
}