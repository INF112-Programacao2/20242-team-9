#include "FormigaZangao.h"

FormigaZangao::FormigaZangao (sf::Vector2f coords): Formiga(coords){
    dano = 8;
    vida = 60;
    velocidade = 20;
    efeito = 0;
    custo = 4;
    caminho = "assets/insects/formiga_zangao.png";
    carrega_icone_inseto(coords, caminho);
    carregar_carta_frente(coords);
}