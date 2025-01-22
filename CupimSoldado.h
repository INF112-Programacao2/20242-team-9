#ifndef CUPIM_SOLDADO_H
#define CUPIM_SOLDADO_H

#include "Cupim.h"

class CupimSoldado : public Cupim {

    private:
        const Tipo tipo = Tipo::CupimSoldado;
    public:
        CupimSoldado(sf::Vector2f);
        //int morder() override;
        //int voar() override;
};

#endif