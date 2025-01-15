#ifndef DECK_H
#define DECK_H
#include "Carta.h"
#include <vector>
#include <string>
int numCartas=5;

class Deck {
    private:
        std::vector<Carta> cartasPossiveis;
    public:
        Carta sortear_carta();

};

#endif