#ifndef MONTE_CARTA_H
#define MONTE_CARTA_H
#include "Carta.h"
#include "Deck.h"
class MonteCarta{
    private:
        Carta carta;
    public:
        MonteCarta();
        sf::Sprite get_sprite();
        void sorteia_carta_do_deck();
};

#endif