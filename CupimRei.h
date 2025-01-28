#ifndef CUPIM_REI_H
#define CUPIM_REI_H
#include "Cupim.h"

class CupimRei : public Cupim {
    private:
        const Tipo tipo = Tipo::CupimRei;
    public:
        CupimRei(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        void ao_morrer(std::vector<Carta*>& aliados); // Efeito 6: Ao morrer, dá 1 ponto de dano extra para cada carta
};
#endif