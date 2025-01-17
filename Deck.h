#ifndef DECK_H
#define DECK_H
#include "Carta.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

class Deck {
    private:
        int numCartas=5;
        std::vector<Carta> cartasPossiveis;
        std::vector<Tipo> tiposPossiveis;
    public:
        Carta sortear_carta();
        void sortear_tipos();
};

#endif