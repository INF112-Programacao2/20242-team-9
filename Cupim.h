#ifndef CUPIM_H
#define CUPIM_H

#include "Carta.h"

class Cupim : public Carta {
    private:

    public:
        virtual ~Cupim(){};
        //virtual void carrega_icone_inseto(sf::Vector2f coords, std::string caminho);
        Cupim(sf::Vector2f coords): Carta(coords) {}
        //virtual int morder()=0;
        //virtual int voar()=0;
};
#endif