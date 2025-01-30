#ifndef CUPIM_REI_H
#define CUPIM_REI_H

#include "Cupim.h"

class Jogador;

class CupimRei : public Cupim {
public:
    CupimRei(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método de efeito de morte
    void aplicar_efeito_morte(Jogador* jogador_inimigo) override;
};

#endif // CUPIM_REI_H