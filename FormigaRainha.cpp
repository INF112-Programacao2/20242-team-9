#include "FormigaRainha.h"

FormigaRainha::FormigaRainha(sf::Vector2f coords): Formiga(coords){
    dano = 10;
    vida = 80;
    velocidade = 15;
    efeito = 0;
    custo = 4;
    caminho = "assets/insects/formiga_rainha.png";
    carrega_icone_inseto(coords, caminho);
    carregar_carta_frente(coords);
}