#include "AbelhaRainha.h"

AbelhaRainha::AbelhaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Abelha(coordsCarta){
    dano = 11;       
    vida = 40;
    vidaOriginal = 40;       
    velocidade = 10;  
    efeito = 2;      // Efeito 2: Aumenta o dano de todas as outras cartas em 1 ponto
    caminho = "assets/insects/abelha_rainha.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}
