#ifndef JOGADOR_H
#define JOGADOR_H

#include "Carta.h"
#include "Deck.h"
#include <vector>
#include <deque>
#include <memory>
#include <exception>
#include <iostream>

class Jogador {
    private:
        Deck deck;
        sf::Sprite barra;
        std::deque<std::unique_ptr<Carta>> mao;
        //int numTrocas;
        int numCartasVivas;
        bool isCardFighting;
        Jogador* oponente;
    public:
        Jogador(int playerNumber = 1);
        void descerCarta();
        void set_morte(int pos);
        bool verifica_carta_morta(int pos) const;
        bool has_card_in_board()const{return isCardFighting;}
        int get_numCartas() const;
        int get_numCartasVivas() const {return numCartasVivas;}
        int get_num_cartas_derrotadas() const {return get_numCartas() - get_numCartasVivas();}
        void inicializa_jogador();
        void put_card_on_board();
        void take_card_from_board();
        sf::Sprite get_sprite_mao_carta(int pos) const;
        sf::Sprite get_sprite_mao_inseto(int pos) const;
        Carta* getCarta(int pos);
        void remover_carta(int pos);
        void set_oponente(Jogador* oponente);
        Jogador* get_oponente() const;
        void aumentar_dano_cartas(int bonus, Carta* excecao);
        void aumentar_velocidade_cartas(int bonus, Carta* excecao);
        int cartaSelecionada;
        ~Jogador();
};

#endif