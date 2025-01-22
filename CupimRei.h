#ifndef CUPIM_REI_H
#define CUPIM_REI_H

#include "Cupim.h"

class CupimRei : public Cupim{
    private:
        const Tipo tipo = Tipo::CupimRei;
    public:
        CupimRei(sf::Vector2f coords);
        //int morder () override;
        //int voar () override {};
};

#endif