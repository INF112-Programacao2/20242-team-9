#ifndef BARATA_H
#define BARATA_H

#include "Tipo.h"
#include "Carta.h"


class Barata : public Carta {
    private:
        const static Tipo tipo = Tipo::Barata;
    public:
        Barata(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        int defender();
        int voar();
        int ataqueQuimico();
};

#endif