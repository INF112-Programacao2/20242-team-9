#ifndef FORMIGA_RAINHA_H
#define FORMIGA_RAINHA_H

#include "Formiga.h"

class FormigaRainha : public Formiga {
    private:
        const Tipo tipo = Tipo::FormigaRainha;
    public:
        FormigaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        //int morder() override;
        //int ataqueEnxame();
};

#endif