#ifndef CIGARRA_H
#define CIGARRA_H

#include "Carta.h"

class Cigarra : public Carta {
public:
    Cigarra(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método 'atacar'
    void atacar(Carta* alvo) override;
};

#endif // CIGARRA_H