#ifndef LOUVA_DEUS_H
#define LOUVA_DEUS_H
#include "Carta.h"

class LouvaDeus : public Carta {
    private:
        const Tipo tipo = Tipo::LouvaDeus;
    public:
        LouvaDeus(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        void verificar_vitoria(Carta* alvo); // Efeito 11: Se derrotar uma carta, recupera metade da vida
};
#endif