#ifndef CUPIM_SOLDADO_H
#define CUPIM_SOLDADO_H
#include "Cupim.h"

class CupimSoldado : public Cupim {
    private:
        const Tipo tipo = Tipo::CupimSoldado;
        unsigned int cartas_aliadas_derrotadas;
    public:
        CupimSoldado(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        void aliado_derrotado(); // Efeito 7: Ganha 1 ponto de dano para cada carta aliada derrotada
};
#endif