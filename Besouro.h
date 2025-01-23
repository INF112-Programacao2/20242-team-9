#ifndef BESOURO_H
#define BESOURO_H

#include "Carta.h"

class Besouro : public Carta {
    private:
        const Tipo tipo = Tipo::Besouro;
    public:
        Besouro(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        void armaduraEspinhos();
        int golpear();
        int voar();
};



#endif