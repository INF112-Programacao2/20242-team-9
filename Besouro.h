#ifndef BESOURO_H
#define BESOURO_H

#include "Carta.h"

class Besouro : public Carta {
public:
    Besouro(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método 'receber_dano'
    void receber_dano(unsigned int dano_recebido) override;
};

#endif // BESOURO_H