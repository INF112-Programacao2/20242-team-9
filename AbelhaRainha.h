#ifndef ABELHA_RAINHA_H
#define ABELHA_RAINHA_H

#include "Abelha.h"

class AbelhaRainha : public Abelha {
public:
    AbelhaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método de efeito pré-ataque
    void aplicar_efeito_pre_ataque(Carta* inimigo) override;
};

#endif // ABELHA_RAINHA_H