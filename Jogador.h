#ifndef JOGADOR_H
#define JOGADOR_H

#include "Carta.h"
#include "Deck.h"
#include "MonteCarta.h"
#include <vector>
#include <exception>
#include <iostream>

class Jogador {
    private:
        Deck deck;
        MonteCarta monte;
        int vida, energia;
        sf::Sprite barra;
        sf::Texture texturaBarra; float escalaBarra=1;
        std::vector<Carta> mao;
        std::vector<sf::Vector2f> coordsCartas;
    public:
        Jogador(unsigned int coordX, unsigned int coordY);
        void carrega_barra(unsigned int coordX, unsigned int coordY);
        void descerCarta();
        void comprarCarta();
        void comprarEnergia();
        int get_numCartas() const;
        void inicializa_jogador(unsigned int coordX, unsigned int coordY);
        sf::Sprite get_sprite_mao(int pos);
        sf::Sprite get_sprite_barra() const;
};

#endif