#include "FormigaZangao.h"
#include "Jogador.h"
#include <iostream>

FormigaZangao::FormigaZangao(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Formiga(coordsCarta) {
    nome = "Formiga Zangão";
    dano = 2;
    vida = 30;
    vida_inicial = vida;
    velocidade = 20;
    custo = 4;
    efeito = 0;
    caminho = "assets/insects/formiga_zangao.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void FormigaZangao::aplicar_efeito_pre_ataque(Carta* inimigo) {
    int dano_adicional = jogador->get_oponente()->get_numCartas();
    dano += dano_adicional;
    std::cout << nome << " aumentou seu dano em " << dano_adicional << " pontos (Dano atual: " << dano << ")." << std::endl;
}