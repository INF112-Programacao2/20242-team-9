#ifndef BARATA_H
#define BARATA_H
#include "Carta.h"

class Barata : public Carta {
    private:
        const static Tipo tipo = Tipo::Barata;
    public:
        Barata(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        void receber_dano(unsigned int dano_recebido) override; // Efeito 3: Sobrevive com 1 ponto de vida após dano letal
};
#endif
