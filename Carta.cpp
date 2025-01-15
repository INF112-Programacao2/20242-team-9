#include "Carta.h"

void Carta::carregar_carta_frente(sf::Vector2f coords){
    if(!texturaCarta.loadFromFile("carta_frente.png")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    carta.setTexture(texturaCarta);
    carta.setPosition(coords); coordsFrente=coords;
    carta.setScale(escala, escala);
}

sf::Vector2f Carta::get_coords_frente() const{
    return coordsFrente;
}

void Carta::carregar_carta_tras(sf::Vector2f coords){
    if(!texturaCarta.loadFromFile("carta_tras.png")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    carta.setTexture(texturaCarta);
    carta.setPosition(coords);
    carta.setScale(escala, escala);
}

void Carta::carregar_carta_monte(sf::Vector2f coords){
    if(!texturaCarta.loadFromFile("carta_tras_monte.png")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    carta.setTexture(texturaCarta);
    carta.setPosition(1050.0f, 250.0f);
    carta.setScale(escala, escala);
}

sf::Sprite Carta::get_sprite(){
    return carta;
}