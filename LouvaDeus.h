#ifndef LOUVADEUS_H
#define LOUVADEUS_H

#include "Carta.h"

class LouvaDeus : public Carta {
public:
    LouvaDeus(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método de efeito pós-ataque
    void aplicar_efeito_pos_ataque(Carta* inimigo) override;
};

#endif // LOUVADEUS_H