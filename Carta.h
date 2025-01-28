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
        std::string caminho;
        bool isDead, isOnBoard;
        sf::Sprite inseto;
        sf::Texture texturaInseto;

        std::vector<sf::Vector2f> coordsCartas = {{250, 520}, {410, 520}, {570, 520}, {730, 520}, {890, 520}, {1050, 520}};
        std::vector<sf::Vector2f> coordsInsetos = {{275, 580}, {435, 580}, {595, 580}, {755, 580}, {915, 580}, {940, 580}};
        const float escalaInseto=0.4;
        unsigned int vida;
        unsigned int dano;
        unsigned int efeito; //pra ataques de veneno por exemplo
        unsigned int velocidade;
        unsigned int custo;

        
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
        void centraliza(int pos);
        void volta_posicao_carta(int pos);
        void set_dead();
        sf::Vector2f get_coords_carta(int pos) ;
        sf::Vector2f get_coords_inseto(int pos) ;
        virtual sf::Sprite get_sprite_carta();
        virtual sf::Sprite get_sprite_inseto() const;
        

        static int player;
        std::string get_caminho() const{return caminho;}
        bool is_dead() const {return isDead;}
        unsigned int get_vida() const{return vida;}
        unsigned int get_custo() const{return custo;}
        unsigned int get_efeito() const{return efeito;}
        unsigned int get_velocidade() const{return velocidade;}
        unsigned int get_dano() const{return dano;}

};

#endif