#ifndef JOGADOR_H
#define JOGADOR_H

#include "Carta.h"
#include "Deck.h"
#include <vector>
#include <exception>
#include <iostream>

class Jogador {
    private:
        Deck deck;
        sf::Sprite barra;
        std::vector<Carta*> mao;
        int numTrocas;
        int numCartasVivas;
        bool isCardFighting;
    public:
        Jogador();
        void descerCarta();
        void set_morte(int pos);
        bool verifica_carta_morta(int pos);
        bool has_card_in_board()const{return isCardFighting;}
        int get_numCartas() const;
        int get_numTrocas() const{return numTrocas;}
        int get_numCartasVivas() const {return numCartasVivas;}
        void incrementa_numTrocas() {numTrocas+=1;}
        void inicializa_jogador();
        void put_card_on_board();
        void take_card_from_board();
        sf::Sprite get_sprite_mao_carta(int pos);
        sf::Sprite get_sprite_mao_inseto(int pos) const;
        Carta* getCarta(int pos);
        int cartaSelecionada;
        ~Jogador();
};

#endif