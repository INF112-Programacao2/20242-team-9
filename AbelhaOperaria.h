#ifndef ABELHA_OPERARIA_H
#define ABELHA_OPERARIA_H

#include "Abelha.h"
class AbelhaOperaria : public Abelha{
    private:
        const Tipo tipo = Tipo::AbelhaOperaria;
    public:
        AbelhaOperaria(sf::Vector2f coords);
        //void carrega_icone_inseto(sf::Vector2f coords, std::string caminho);
};

#endif