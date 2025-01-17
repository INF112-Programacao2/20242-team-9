#include "Jogador.h"

Jogador::Jogador(unsigned int coordX, unsigned int coordY){
    inicializa_jogador(coordX, coordY);
}

void Jogador::inicializa_jogador(unsigned int coordX, unsigned int coordY){
    coordsCartas = {{250, 520}, {300, 520}, {350, 520}, {400, 520}, {450, 520}, {500, 520}};
    try{
        carrega_barra(coordX, coordY);
        std::cout << "CARREGOU BARRA DE VIDA!" << std::endl;
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    for(int i=0; i<5; i++){
        //PRE CARREGAR VETOR COM DECK SORTEADO
        mao.push_back(Carta(coordsCartas[i])); //PROBLEMA
        std::cout << "CARREGOU A MÃO DO JOGADOR" << std::endl;
    }
}
void Jogador::carrega_barra(unsigned int coordX, unsigned int coordY){
    if(!texturaBarra.loadFromFile("barra_vida_energia.png")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    barra.setTexture(texturaBarra);
    barra.setPosition(coordX, coordY);
    barra.setScale(escalaBarra, escalaBarra);
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