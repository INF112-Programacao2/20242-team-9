#include "AbelhaOperaria.h"

AbelhaOperaria::AbelhaOperaria(sf::Vector2f coords): Abelha(coords){
    dano = 6;
    vida = 60;
    velocidade = 25;
    efeito = 0;
    custo = 4;
    caminho = "assets/insects/abelha_operaria.png";
    carrega_icone_inseto(coords, caminho);
    carregar_carta_frente(coords);
}