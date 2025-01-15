#ifndef CARTA_H
#define CARTA_H

#include "Tipo.h"
#include <SFML/Graphics.hpp>

class Carta{
    private:
        float escala = 0.6;
        sf::Vector2f coordsFrente;
        int vida, poder;
        Tipo tipo;
        sf::Sprite carta;
        sf::Texture texturaCarta;
    public:
        Carta();
        void inicializa_jogador();
        void carregar_carta_frente(sf::Vector2f coords);
        sf::Vector2f get_coords_frente() const;
        void carregar_carta_tras(sf::Vector2f coords);
        void carregar_carta_monte(sf::Vector2f coords);
        sf::Sprite get_sprite();

};

#endif