#ifndef CUPIM_SOLDADO_H
#define CUPIM_SOLDADO_H

#include "Cupim.h"

class CupimSoldado : public Cupim {

    private:
        const Tipo tipo = Tipo::CupimSoldado;
    public:
        CupimSoldado(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
};

#endif