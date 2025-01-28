#ifndef DECK_H
#define DECK_H

#include "Carta.h"
#include "AbelhaRainha.h"
#include "CupimRei.h"
#include "CupimSoldado.h"
#include "AbelhaOperaria.h"
#include "Barata.h"
#include "Besouro.h"
#include "CupimRei.h"
#include "CupimSoldado.h"
#include "Cigarra.h"
#include "LouvaDeus.h"
#include "Gafanhoto.h"
#include "FormigaRainha.h"
#include "FormigaZangao.h"

#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <iostream>

class Deck {
    private:
        static const int numCartas=5;
        std::vector<Carta*> cartasEscolhidas;
    public:
        Deck();
        ~Deck();
        void sortear_deck();
        void converte_tipo(Tipo tipo, int pos);
        Carta* get_carta_deck(int pos) const;
};

#endif