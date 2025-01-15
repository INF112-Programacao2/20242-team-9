#ifndef JOGADOR_H
#define JOGADOR_H

#include "Carta.h"
#include "Deck.h"
#include "MonteCarta.h"
#include <vector>

class Jogador {
    private:
        Deck deck;
        MonteCarta monte;
        int vida, energia;
        sf::Sprite barra;
        sf::Texture texturaBarra;
        std::vector<Carta> mao;
        std::vector<sf::Vector2f> coordsCartas;
    public:
        Jogador(float coordX, float coordY);
        void carrega_barra(float coordX, float coordY);
        void descerCarta();
        void comprarCarta();
        void comprarEnergia();
        int get_numCartas() const;
        void inicializa_jogador(float coordX, float coordY);
        sf::Sprite get_sprite_mao(int pos);
        sf::Sprite get_sprite_barra() const;
};

#endif