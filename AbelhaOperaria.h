#ifndef ABELHA_OPERARIA_H
#define ABELHA_OPERARIA_H
#include "Abelha.h"

class AbelhaOperaria : public Abelha {
    private:
        const Tipo tipo = Tipo::AbelhaOperaria;
    public:
        AbelhaOperaria(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        void aplicar_efeito(); // Efeito 1: Cura 1 ponto de vida a cada turno
};
#endif