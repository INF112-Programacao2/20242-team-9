#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <exception>
#include <string>
#include "EstadoJogo.h"
#include "Jogo.h"

class Menu{
    private:
        sf::RenderWindow *window;
        int pos;
        bool escolhido, selecionado;
        EstadoJogo estadoAtual;
        sf::Font *fonte;
        std::vector<const char*> opcoes;
        std::vector<sf::Vector2f> coordsTexto;
        std::vector<sf::Text> textos;
        std::vector<std::size_t> tamTexto;
    protected:
        void inicializa_menu();
        void loop_eventos();
        void desenhar();
    public:
        Menu();
        Menu(sf::RenderWindow* janela);
        ~Menu();
        void carrega_fonte();
        void run_menu();
        bool is_jogar_selecionado();
};

#endif