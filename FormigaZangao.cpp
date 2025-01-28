#include "FormigaZangao.h"

FormigaZangao::FormigaZangao(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Formiga(coordsCarta){
    dano = 12;       
    vida = 30;
    vidaOriginal = 30;       
    velocidade = 20;  
    efeito = 9;      // Efeito 9: Causa dano adicional igual ao número de cartas na mão do oponente
    caminho = "assets/insects/formiga_zangao.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}