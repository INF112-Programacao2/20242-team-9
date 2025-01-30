#ifndef GAFANHOTO_H
#define GAFANHOTO_H

#include "Carta.h"

class Gafanhoto : public Carta {
private:
    bool pulou_ataque;

public:
    Gafanhoto(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);

    // Sobrescrever o método 'receber_dano'
    void receber_dano(unsigned int dano_recebido) override;
};

#endif // GAFANHOTO_H