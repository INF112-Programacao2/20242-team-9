#ifndef FORMIGA_RAINHA_H
#define FORMIGA_RAINHA_H
#include "Formiga.h"

class FormigaRainha : public Formiga {
    private:
        const Tipo tipo = Tipo::FormigaRainha;
    public:
        FormigaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        void aplicar_efeito(std::vector<Carta*>& aliados); // Efeito 8: Aumenta a velocidade de todas as cartas aliadas em 1 ponto
};
#endif