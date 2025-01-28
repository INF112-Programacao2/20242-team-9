#include "FormigaRainha.h"

FormigaRainha::FormigaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Formiga(coordsCarta){
    dano = 10;
    vida = 80;
    velocidade = 15;
    efeito = 0;
    custo = 4;
    caminho = "assets/insects/formiga_rainha.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}