#ifndef FORMIGA_RAINHA_H
#define FORMIGA_RAINHA_H

#include "Formiga.h"

class FormigaRainha : public Formiga {
    private:
        const Tipo tipo = Tipo::FormigaRainha;
    public:
        FormigaRainha(sf::Vector2f coords);
        //int morder() override;
        //int ataqueEnxame();
};

#endif