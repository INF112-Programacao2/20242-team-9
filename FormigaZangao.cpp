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
    efeito = 0;
    caminho = "assets/insects/formiga_zangao.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void FormigaZangao::aplicar_efeito_pre_ataque(Carta* inimigo) {
    std::cout << "ENTROU APLICAR EFEITO PRE FORMIGA ZANGAO" << std::endl;
    int dano_adicional;
    if (jogador != nullptr) {
        dano_adicional = jogador->get_oponente()->get_numCartas();
        std::cout << nome << "aumentou o dano de todas as outras cartas aliadas em 1 ponto." << std::endl;
    } else {
        std::cerr << "Erro: jogador não inicializado para " << nome << std::endl;
    }
    dano += dano_adicional;
    std::cout << nome << " aumentou seu dano em " << dano_adicional << " pontos (Dano atual: " << dano << ")." << std::endl;
}