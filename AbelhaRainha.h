#ifndef ABELHA_RAINHA_H
#define ABELHA_RAINHA_H
#include "Abelha.h"

class AbelhaRainha : public Abelha {
    private:
        const static Tipo tipo = Tipo::AbelhaRainha;
    public:
        AbelhaRainha(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        void aplicar_efeito(std::vector<Carta*>& aliados); // Efeito 2: Aumenta o dano de todas as outras cartas em 1 ponto
};
#endif
