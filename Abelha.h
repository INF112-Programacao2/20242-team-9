#ifndef ABELHA_H
#define ABELHA_H

#include "Carta.h"

class Abelha : public Carta {
    private:

    public:
        Abelha(sf::Vector2f coords) : Carta(coords) {}
        virtual ~Abelha() {}
        //virtual int ferroar()=0;
        //virtual int voar()=0;

};

#endif