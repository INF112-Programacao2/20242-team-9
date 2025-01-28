#ifndef FORMIGA_RAINHA_H
#define FORMIGA_RAINHA_H

#include "Formiga.h"

class FormigaRainha : public Formiga {
public:
    FormigaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método de efeito pré-ataque
    void aplicar_efeito_pre_ataque(Carta* inimigo) override;
};

#endif // FORMIGA_RAINHA_H