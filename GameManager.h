#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <exception>
#include <string>
#include <memory>
#include "Jogo.h"
#include "Menu.h"
#include "EstadoJogo.h"

class GameManager {
    private:
        sf::RenderWindow window;
        EstadoJogo estadoAtual;
        Menu menu;
        Jogo *jogo;
    public:
        ~GameManager();
        GameManager();
        void run();
};

#endif
