#include "FormigaZangao.h"

FormigaZangao::FormigaZangao (sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Formiga(coordsCarta){
    nome = "Formiga Zangão";
    dano = 7;
    vida = 35;
    velocidade = 20;
    efeito = 0;
    custo = 4;
    caminho = "assets/insects/formiga_zangao.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}