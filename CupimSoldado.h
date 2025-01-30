#ifndef CUPIM_SOLDADO_H
#define CUPIM_SOLDADO_H

#include "Cupim.h"

class CupimSoldado : public Cupim {
public:
    CupimSoldado(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método de efeito pré-ataque
    void aplicar_efeito_pre_ataque(Carta* inimigo) override;
};

#endif // CUPIM_SOLDADO_H