#ifndef FORMIGA_ZANGAO_H
#define FORMIGA_ZANGAO_H

#include "Formiga.h"

class FormigaZangao : public Formiga{
    private:
        const Tipo tipo = Tipo::FormigaZangao;
    public:
        FormigaZangao(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
};

#endif