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
        const static unsigned int elixirMax = 10;
        Deck deck;
        MonteCarta monte;
        int vida, energia;
        sf::Sprite barra;
        
        sf::Texture texturaBarra; float escalaBarra=1;
        std::vector<Carta*> mao;
    public:
        Jogador(unsigned int coordX, unsigned int coordY);
        void carrega_barra(unsigned int coordX, unsigned int coordY);
        void descerCarta();
        void comprarCarta();
        void comprarEnergia();
        int get_numCartas() const;
        void inicializa_jogador(unsigned int coordX, unsigned int coordY);
        sf::Sprite& get_sprite_mao_carta(int pos);
        sf::Sprite get_sprite_mao_inseto(int pos) const;
        sf::Sprite get_sprite_barra() const;
        //sf::Sprite get_sprite_seta() const;
        Carta* getCarta(int pos);
        ~Jogador();
};

#endif