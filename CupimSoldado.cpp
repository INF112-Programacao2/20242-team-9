#include "CupimSoldado.h"
#include "Jogador.h"
#include <iostream>

CupimSoldado::CupimSoldado(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Cupim(coordsCarta) {
    nome = "Cupim Soldado";
    dano = 2;
    vida = 30;
    vida_inicial = vida;
    velocidade = 15;
    custo = 1;
    efeito = 0;
    caminho = "assets/insects/cupim_soldado.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void CupimSoldado::aplicar_efeito_pre_ataque(Carta* inimigo) {
    int cartas_derrotadas = jogador->get_num_cartas_derrotadas();
    dano += cartas_derrotadas;
    std::cout << nome << " aumentou seu dano em " << cartas_derrotadas << " pontos (Dano atual: " << dano << ")." << std::endl;
}