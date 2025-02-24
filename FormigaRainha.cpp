#include "FormigaRainha.h"
#include "Jogador.h"
#include <iostream>

FormigaRainha::FormigaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto)
    : Formiga(coordsCarta) {
    nome = "Formiga Rainha";
    dano = 3;
    vida = 40;
    vida_inicial = vida;
    velocidade = 15;
    efeito = 0;
    caminho = "assets/insects/formiga_rainha.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

void FormigaRainha::aplicar_efeito_pre_ataque(Carta* inimigo) {
    std::cout << "ENTROU APLICAR EFEITO PRE FORMIGA RAINHA" << std::endl;
    if (jogador != nullptr) {
        jogador->aumentar_velocidade_cartas(1, this);
        std::cout << nome << " aumentou o dano de todas as outras cartas aliadas em 1 ponto." << std::endl;
    } else {
        std::cerr << "Erro: jogador não inicializado para " << nome << std::endl;
    }
    std::cout << nome << " aumentou a velocidade de todas as outras cartas aliadas em 1 ponto." << std::endl;
}