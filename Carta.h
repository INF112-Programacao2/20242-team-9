#ifndef CARTA_H
#define CARTA_H

#include "Tipo.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Carta{
    private:
        const float escala=0.6;
    protected:
        sf::Sprite carta;
        sf::Texture texturaCarta1;
        sf::Texture texturaCarta;

        sf::Sprite inseto;
        sf::Texture texturaInseto;

        std::vector<sf::Vector2f> coordsCartas = {{250, 520}, {300, 520}, {350, 520}, {400, 520}, {450, 520}, {500, 520}};

        const float escalaInseto=0.5;
        unsigned int vida;
        std::string caminho;
        unsigned int dano;
        unsigned int efeito; //pra ataques de veneno por exemplo
        unsigned int velocidade;
        unsigned int custo;

        unsigned int get_vida() const{return vida;}
        unsigned int get_custo() const{return custo;}
        unsigned int get_efeito() const{return efeito;}
        unsigned int get_velocidade() const{return velocidade;}
        unsigned int get_dano() const{return dano;}

        
    public:
        Carta(sf::Vector2f coords);
        Carta(){}
        virtual ~Carta() {}
        virtual void carrega_icone_inseto(sf::Vector2f coords, std::string caminho);
        void inicializa_jogador();
        void carregar_carta_frente(sf::Vector2f coords);
        sf::Vector2f get_coords_frente() const;
        void carregar_carta_tras(sf::Vector2f coords);
        void carregar_carta_monte();
        sf::Vector2f get_coords_carta(int pos) const;
        virtual sf::Sprite get_sprite_carta() const;
        virtual sf::Sprite get_sprite_inseto() const;

};

#endif