#ifndef FORMIGA_H
#define FORMIGA_H

#include "Carta.h"

class Formiga : public Carta{
    private:

    protected:
        //virtual int morder();
    public:
        Formiga(sf::Vector2f coordsCarta): Carta(coordsCarta){}
        //virtual void carrega_icone_inseto(sf::Vector2f coords, std::string caminho);
};  

#endif