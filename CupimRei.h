#ifndef CUPIM_REI_H
#define CUPIM_REI_H

#include "Cupim.h"

class CupimRei : public Cupim{
    private:
        const Tipo tipo = Tipo::CupimRei;
    public:
        CupimRei(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        //int morder () override;
        //int voar () override {};
};

#endif