#ifndef FORMIGA_ZANGAO_H
#define FORMIGA_ZANGAO_H

#include "Formiga.h"

class FormigaZangao : public Formiga {
public:
    FormigaZangao(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método de efeito pré-ataque
    void aplicar_efeito_pre_ataque(Carta* inimigo) override;
};

#endif // FORMIGA_ZANGAO_H