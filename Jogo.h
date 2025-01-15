#ifndef JOGO_H
#define JOGO_H

#include <SFML/Graphics.hpp>
#include "Carta.h"
#include "MonteCarta.h"
#include "EstadoJogo.h"
#include "Jogador.h"

class Jogo {
    private:
        sf::RenderWindow* janela;
        sf::Sprite mesa;
        sf::Texture texturaMesa;
        Carta carta;
        MonteCarta monte;
        bool saidaRequerida;
        Jogador jogador1, jogador2;

    public:
        Jogo(sf::RenderWindow* window);
        void loop_eventos();
        void desenhar();
        void run_jogo();
        
};


#endif