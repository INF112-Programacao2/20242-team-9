#include "AbelhaRainha.h"

AbelhaRainha::AbelhaRainha(sf::Vector2f coords): Abelha(coords){
    dano = 10;
    vida = 80;
    velocidade = 20;
    efeito = 2;
    custo = 6;
    caminho = "assets/insects/abelha_rainha.png";
    // Carregar textura da Abelha Rainha
    carrega_icone_inseto(coords, caminho);
    carregar_carta_frente(coords);
    //std::cout << "Abelha Rainha inicializada na posição (" << coords.x << ", " << coords.y << ")." << std::endl;
}



