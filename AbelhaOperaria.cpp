#include "AbelhaOperaria.h"

AbelhaOperaria::AbelhaOperaria(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Abelha(coordsCarta){
    nome = "Abelha Operaria";
    dano = 5;
    vida = 30;
    velocidade = 25;
    efeito = 0;
    custo = 4;
    caminho = "assets/insects/abelha_operaria.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}