#ifndef GAFANHOTO_H
#define GAFANHOTO_H
#include "Carta.h"

class Gafanhoto : public Carta {
    private:
        const Tipo tipo = Tipo::Gafanhoto;
    public:
        Gafanhoto(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        bool tentar_esquiva(); // Efeito 10: Pode pular o ataque do oponente uma vez por partida
};
#endif