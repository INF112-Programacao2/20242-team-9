#include "AbelhaRainha.h"

AbelhaRainha::AbelhaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Abelha(coordsCarta){
    nome = "Abelha Rainha";
    dano = 5;
    vida = 40;
    velocidade = 20;
    efeito = 2;
    custo = 6;
    caminho = "assets/insects/abelha_rainha.png";
    // Carregar textura da Abelha Rainha
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
    //std::cout << "Abelha Rainha inicializada na posição (" << coords.x << ", " << coords.y << ")." << std::endl;
}



