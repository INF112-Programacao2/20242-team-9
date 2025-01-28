#ifndef ABELHA_OPERARIA_H
#define ABELHA_OPERARIA_H

#include "Abelha.h"

class AbelhaOperaria : public Abelha{
public:
    AbelhaOperaria(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Declaração do método sobrescrito
    void aplicar_efeito_pos_ataque(Carta* inimigo) override;
};

#endif