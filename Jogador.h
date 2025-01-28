#ifndef JOGADOR_H
#define JOGADOR_H

#include "Carta.h"
#include "Deck.h"
#include "MonteCarta.h"
#include <vector>
#include <exception>
#include <iostream>

class Jogador {
    private:
        const static unsigned int elixirMax = 10;
        Deck deck;
        MonteCarta monte;
        int vida, energia;
        sf::Sprite barra;
        sf::Texture texturaBarra; float escalaBarra=1;
        std::vector<Carta*> mao;
        Jogador* oponente;
    public:
        Jogador(unsigned int coordX, unsigned int coordY);
        void carrega_barra(unsigned int coordX, unsigned int coordY);
        void descerCarta();
        void comprarCarta();
        void comprarEnergia();
        int get_numCartas() const;
        void inicializa_jogador(unsigned int coordX, unsigned int coordY);
        sf::Sprite& get_sprite_mao_carta(int pos);
        sf::Sprite get_sprite_mao_inseto(int pos) const;
        sf::Sprite get_sprite_barra() const;
        //sf::Sprite get_sprite_seta() const;
        Carta* getCarta(int pos);
        void remover_carta(Carta* carta);
        void set_oponente(Jogador* oponente);
        Jogador* get_oponente() const;
        void aumentar_dano_cartas(int bonus, Carta* excecao);
        int get_num_cartas_derrotadas() const;
        std::vector<Carta*> cartas_derrotadas;
        void aumentar_velocidade_cartas(int bonus, Carta* excecao);
        ~Jogador();

};

#endif