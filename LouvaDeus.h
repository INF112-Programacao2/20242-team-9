#ifndef LOUVA_DEUS_H
#define LOUVA_DEUS_H
#include "Carta.h"

class LouvaDeus : public Carta {
    private:
        const Tipo tipo = Tipo::LouvaDeus;
    public:
        LouvaDeus(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        //int morder();
        //int camuflar();
        //int golpear();


};

#endif