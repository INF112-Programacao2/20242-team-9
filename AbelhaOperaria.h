#ifndef ABELHA_OPERARIA_H
#define ABELHA_OPERARIA_H

#include "Abelha.h"
class AbelhaOperaria : public Abelha{
    private:
        const Tipo tipo = Tipo::AbelhaOperaria;
    public:
        AbelhaOperaria(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        //void carrega_icone_inseto(sf::Vector2f coords, std::string caminho);
};

#endif