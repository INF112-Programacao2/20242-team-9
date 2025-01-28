#ifndef CARTA_H
#define CARTA_H

#include "Tipo.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Carta {
    private:
        const float escala = 0.6;
    
    protected:
        sf::Sprite carta;
        sf::Texture texturaCarta1;
        sf::Texture texturaCarta;

        sf::Sprite inseto;
        sf::Texture texturaInseto;

        std::vector<sf::Vector2f> coordsCartas = {{250, 520}, {410, 520}, {570, 520}, {730, 520}, {890, 520}, {1050, 520}};
        std::vector<sf::Vector2f> coordsInsetos = {{275, 580}, {435, 580}, {595, 580}, {755, 580}, {915, 580}, {940, 580}};
        const float escalaInseto = 0.4;
        
        unsigned int vida;
        unsigned int vidaOriginal;  // Novo: para controlar vida máxima
        std::string caminho;
        unsigned int dano;
        unsigned int efeito;
        unsigned int velocidade;
        unsigned int custo;

        // Novos atributos para controle de efeitos
        bool efeitoBarataUsado;
        bool efeitoGafanhotoUsado;

    public:
        Carta(sf::Vector2f coords);
        Carta() {}
        virtual ~Carta() {}

        // Métodos existentes
        virtual void carrega_icone_inseto(sf::Vector2f coords, std::string caminho);
        void inicializa_jogador();
        void carregar_carta_frente(sf::Vector2f coords);
        sf::Vector2f get_coords_frente() const;
        void carregar_carta_tras(sf::Vector2f coords);
        void carregar_carta_monte();
        sf::Vector2f get_coords_carta(int pos);
        sf::Vector2f get_coords_inseto(int pos);
        virtual sf::Sprite& get_sprite_carta();
        virtual sf::Sprite get_sprite_inseto() const;
        void centraliza(sf::Sprite& c);

        static int player;

        // Getters existentes
        unsigned int get_vida() const { return vida; }
        unsigned int get_custo() const { return custo; }
        unsigned int get_efeito() const { return efeito; }
        unsigned int get_velocidade() const { return velocidade; }
        unsigned int get_dano() const { return dano; }

        // Novos getters e setters para efeitos
        unsigned int get_vida_original() const { return vidaOriginal; }
        bool get_efeito_barata_usado() const { return efeitoBarataUsado; }
        bool get_efeito_gafanhoto_usado() const { return efeitoGafanhotoUsado; }

        void set_vida(unsigned int novaVida) { vida = novaVida; }
        void set_dano(unsigned int novoDano) { dano = novoDano; }
        void set_velocidade(unsigned int novaVelocidade) { velocidade = novaVelocidade; }
        void set_efeito_barata_usado(bool usado) { efeitoBarataUsado = usado; }
        void set_efeito_gafanhoto_usado(bool usado) { efeitoGafanhotoUsado = usado; }

        // Novo método para receber dano
        virtual void receber_dano(unsigned int dano_recebido) {
            // Se for o Besouro (efeito 4), reduz o dano em 1
            if (get_efeito() == 4 && dano_recebido > 0) {
                dano_recebido--;
            }

            // Aplica o dano
            if (dano_recebido >= vida) {
                vida = 0;
            } else {
                vida -= dano_recebido;
            }

            // Se for a Barata (efeito 3) e for morrer pela primeira vez
            if (get_efeito() == 3 && vida == 0 && !efeitoBarataUsado) {
                vida = 1;
                efeitoBarataUsado = true;
            }
        }
};

#endif