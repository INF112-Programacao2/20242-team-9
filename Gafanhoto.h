#ifndef GAFANHOTO_H
#define GAFANHOTO_H

#include "Carta.h"

class Gafanhoto : public Carta {
    private:
        const Tipo tipo = Tipo::Gafanhoto;
    public:
        Gafanhoto(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        //int voar();
        //int camuflar();
        //int morder();
};

#endif