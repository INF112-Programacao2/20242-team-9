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
        sf::Sprite seta;
        sf::Texture texturaSeta;
        Carta carta;
        MonteCarta monte;
        Jogador* jogador1, *jogador2;
        float posicaoSeta = 301.2;


    public:
        Jogo(sf::RenderWindow* window);
        void carrega_tabuleiro();
        void loop_eventos();
        void desenhar();
        void run_jogo();
        ~Jogo();
};


#endif