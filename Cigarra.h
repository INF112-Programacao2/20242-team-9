#ifndef CIGARRA_H
#define CIGARRA_H

#include "Carta.h"

class Cigarra : public Carta{
    private:
        const static Tipo tipo = Tipo::Cigarra;
    public:
        Cigarra(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        //void carrega_icone_inseto(sf::Vector2f coords, std::string caminho);
};

#endif