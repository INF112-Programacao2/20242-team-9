#include "Jogador.h"

Jogador::Jogador(float coordX, float coordY){
    inicializa_jogador(coordX, coordY);
}

void Jogador::inicializa_jogador(float coordX, float coordY){
    coordsCartas = {{250, 520}, {300, 520}, {350, 520}, {400, 520}, {450, 520}, {500, 520}};
    carrega_barra(coordX, coordY);
    for(int i=0; i<mao.size(); i++){
        mao[i].carregar_carta_frente(coordsCartas[i]);
    }
}
void Jogador::carrega_barra(float coordX, float coordY){
    if(!texturaBarra.loadFromFile("barra_vida_energia")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    barra.setTexture(texturaBarra);

    barra.setPosition(coordX, coordY);
}


sf::Sprite Jogador::get_sprite_barra() const{
    return barra;
}

sf::Sprite Jogador::get_sprite_mao(int pos){
    return mao[pos].get_sprite();
}

int Jogador::get_numCartas() const{
    return mao.size();
}