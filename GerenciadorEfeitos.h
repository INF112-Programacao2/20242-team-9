// GerenciadorEfeitos.h
#ifndef GERENCIADOR_EFEITOS_H
#define GERENCIADOR_EFEITOS_H

#include "Carta.h"
#include <vector>

class GerenciadorEfeitos {
public:
    // Método principal para aplicar efeitos
    static void aplicar_efeito(Carta* carta, Carta* alvo, std::vector<Carta*>& mao_aliada, std::vector<Carta*>& mao_inimiga);

private:
    // Métodos para cada tipo de efeito
    static void curar_por_turno(Carta* carta);
    static void buff_dano_aliados(std::vector<Carta*>& mao_aliada);
    static void sobrevivencia_barata(Carta* carta);
    static void reducao_dano(Carta* carta);
    static void ataque_duplo(Carta* carta, Carta* alvo);
    static void efeito_ao_morrer(Carta* carta, std::vector<Carta*>& mao_aliada);
    static void buff_por_derrotados(Carta* carta);
    static void dano_baseado_mao_inimiga(Carta* carta, std::vector<Carta*>& mao_inimiga);
    static void esquiva_unica(Carta* carta);
    static void recuperar_vida_apos_vitoria(Carta* carta, Carta* alvo);
    static void buff_velocidade_aliados(std::vector<Carta*>& mao_aliada);
};

#endif