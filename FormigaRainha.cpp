#include "FormigaRainha.h"

FormigaRainha::FormigaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Formiga(coordsCarta){
    dano = 11;       
    vida = 40;
    vidaOriginal = 40;       
    velocidade = 15;  
    efeito = 8;      // Efeito 8: Aumenta a velocidade de todas as cartas aliadas em 1 ponto
    caminho = "assets/insects/formiga_rainha.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}