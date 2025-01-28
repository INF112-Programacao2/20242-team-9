#ifndef FORMIGA_ZANGAO_H
#define FORMIGA_ZANGAO_H
#include "Formiga.h"

class FormigaZangao : public Formiga {
    private:
        const Tipo tipo = Tipo::FormigaZangao;
    public:
        FormigaZangao(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto);
        unsigned int calcular_dano(const std::vector<Carta*>& mao_inimiga); // Efeito 9: Causa dano adicional igual ao número de cartas na mão do oponente
};
#endif