#ifndef CIGARRA_H
#define CIGARRA_H
#include "Carta.h"

class Cigarra : public Carta {
    private:
        const static Tipo tipo = Tipo::Cigarra;
        bool segundo_ataque_disponivel;
    public:
        Cigarra(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        void atacar(Carta* alvo); // Efeito 5: Pode atacar duas vezes por turno
        void resetar_turno();
};
#endif