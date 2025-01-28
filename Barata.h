#ifndef BARATA_H
#define BARATA_H

#include "Carta.h"

class Barata : public Carta {
private:
    bool ressuscitou;

public:
    Barata(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método 'receber_dano'
    void receber_dano(unsigned int dano_recebido) override;
};

#endif // BARATA_H