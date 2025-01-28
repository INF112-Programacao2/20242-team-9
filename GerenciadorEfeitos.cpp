// GerenciadorEfeitos.cpp
#include "GerenciadorEfeitos.h"
#include <algorithm>

void GerenciadorEfeitos::aplicar_efeito(Carta* carta, Carta* alvo, std::vector<Carta*>& mao_aliada, std::vector<Carta*>& mao_inimiga) {
    if (!carta || carta->get_vida() <= 0) return;

    switch (carta->get_efeito()) {
        case 1: // Abelha Operária - Cura 1 ponto de vida a cada turno
            curar_por_turno(carta);
            break;
        case 2: // Abelha Rainha - Aumenta o dano de todas as outras cartas em 1 ponto
            buff_dano_aliados(mao_aliada);
            break;
        case 3: // Barata - Sobrevive com 1 ponto de vida após dano letal
            sobrevivencia_barata(carta);
            break;
        case 4: // Besouro - Reduz o dano recebido em 1 ponto
            reducao_dano(carta);
            break;
        case 5: // Cigarra - Pode atacar duas vezes por turno
            ataque_duplo(carta, alvo);
            break;
        case 6: // Cupim Rei - Ao morrer, dá 1 ponto de dano extra para cada carta aliada
            efeito_ao_morrer(carta, mao_aliada);
            break;
        case 7: // Cupim Soldado - Ganha 1 ponto de dano para cada carta aliada derrotada
            buff_por_derrotados(carta);
            break;
        case 8: // Formiga Zangão - Causa dano adicional igual ao número de cartas na mão do oponente
            dano_baseado_mao_inimiga(carta, mao_inimiga);
            break;
        case 9: // Gafanhoto - Pode pular o ataque do oponente uma vez por partida
            esquiva_unica(carta);
            break;
        case 10: // Louva-Deus - Se derrotar uma carta, recupera metade da vida
            recuperar_vida_apos_vitoria(carta, alvo);
            break;
        case 11: // Formiga Rainha - Aumenta a velocidade de todas as cartas aliadas em 1 ponto
            buff_velocidade_aliados(mao_aliada);
            break;
    }
}

void GerenciadorEfeitos::curar_por_turno(Carta* carta) {
    unsigned int vida_atual = carta->get_vida();
    unsigned int vida_maxima = carta->get_vida_original();
    if (vida_atual < vida_maxima) {
        carta->set_vida(vida_atual + 1);
    }
}

void GerenciadorEfeitos::buff_dano_aliados(std::vector<Carta*>& mao_aliada) {
    for (Carta* aliado : mao_aliada) {
        if (aliado && aliado->get_efeito() != 2) { // Não aplica na própria Abelha Rainha
            aliado->set_dano(aliado->get_dano() + 1);
        }
    }
}

void GerenciadorEfeitos::sobrevivencia_barata(Carta* carta) {
    if (carta->get_vida() <= 0 && !carta->get_efeito_barata_usado()) {
        carta->set_vida(1);
        carta->set_efeito_barata_usado(true);
    }
}

void GerenciadorEfeitos::reducao_dano(Carta* carta) {
    // Este efeito é passivo e já está implementado no método receber_dano da carta
}

void GerenciadorEfeitos::ataque_duplo(Carta* carta, Carta* alvo) {
    if (carta && alvo && carta->get_vida() > 0 && alvo->get_vida() > 0) {
        alvo->receber_dano(carta->get_dano());
    }
}

void GerenciadorEfeitos::efeito_ao_morrer(Carta* carta, std::vector<Carta*>& mao_aliada) {
    if (carta && carta->get_vida() <= 0) {
        for (Carta* aliado : mao_aliada) {
            if (aliado) {
                aliado->set_dano(aliado->get_dano() + 1);
            }
        }
    }
}

void GerenciadorEfeitos::buff_por_derrotados(Carta* carta) {
    static unsigned int cartas_derrotadas = 0;
    if (carta) {
        carta->set_dano(carta->get_dano() + cartas_derrotadas);
    }
}

void GerenciadorEfeitos::dano_baseado_mao_inimiga(Carta* carta, std::vector<Carta*>& mao_inimiga) {
    if (carta) {
        unsigned int dano_adicional = mao_inimiga.size();
        carta->set_dano(carta->get_dano() + dano_adicional);
    }
}

void GerenciadorEfeitos::esquiva_unica(Carta* carta) {
    if (carta && !carta->get_efeito_gafanhoto_usado()) {
        carta->set_efeito_gafanhoto_usado(true);
    }
}

void GerenciadorEfeitos::recuperar_vida_apos_vitoria(Carta* carta, Carta* alvo) {
    if (carta && alvo && alvo->get_vida() <= 0) {
        unsigned int recuperacao = carta->get_vida_original() / 2;
        unsigned int nova_vida = std::min(carta->get_vida() + recuperacao, carta->get_vida_original());
        carta->set_vida(nova_vida);
    }
}

void GerenciadorEfeitos::buff_velocidade_aliados(std::vector<Carta*>& mao_aliada) {
    for (Carta* aliado : mao_aliada) {
        if (aliado && aliado->get_efeito() != 11) { // Não aplica na própria Formiga Rainha
            aliado->set_velocidade(aliado->get_velocidade() + 1);
        }
    }
}