#ifndef ABELHA_RAINHA_H
#define ABELHA_RAINHA_H

#include "Abelha.h"

class AbelhaRainha : public Abelha {
    private:

        const static Tipo tipo = Tipo::AbelhaRainha;

    public:
        //int ferroar() override;
        //int voar() override;
        AbelhaRainha(sf::Vector2f coords);
        //void carrega_icone_inseto(sf::Vector2f coords, std::string caminho);
};

#endif