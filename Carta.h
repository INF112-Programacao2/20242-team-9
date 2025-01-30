#ifndef CARTA_H
#define CARTA_H

#include "Tipo.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>  // Inclua o header necessário para usar o vector

class Jogador;

class Carta {
private:
    const float escala = 0.6;
protected:
    sf::Sprite carta;
    sf::Texture texturaCarta1;
    sf::Texture texturaCarta;
    sf::Sprite inseto;
    sf::Texture texturaInseto;
    std::string nome;
    Jogador* jogador;
    std::string caminho;
    bool isDead, isOnBoard;
    unsigned int vida_inicial;

    std::vector<sf::Vector2f> coordsCartas = {{250, 520}, {410, 520}, {570, 520}, {730, 520}, {890, 520}, {1050, 520}}; // Corrigido o vetor
    std::vector<sf::Vector2f> coordsInsetos = {{275, 580}, {435, 580}, {595, 580}, {755, 580}, {915, 580}, {940, 580}}; // Corrigido o vetor
    const float escalaInseto = 0.4;
    unsigned int vida;
    unsigned int dano;
    unsigned int efeito; // pra ataques de veneno por exemplo
    unsigned int velocidade;

public:
    Carta(sf::Vector2f coords);
    Carta() {}
    virtual ~Carta() {}
    virtual void carrega_icone_inseto(sf::Vector2f coords, std::string caminho);
    void inicializa_jogador();
    void carregar_carta_frente(sf::Vector2f coords);
    sf::Vector2f get_coords_frente() const;
    void carregar_carta_tras(sf::Vector2f coords);
    void carregar_carta_monte();
    sf::Vector2f get_coords_carta(int pos);
    sf::Vector2f get_coords_inseto(int pos);
    void centraliza(int pos);
    void volta_posicao_carta(int pos);
    void set_dead();
    bool is_dead() const;
    virtual sf::Sprite& get_sprite_carta();
    virtual sf::Sprite get_sprite_inseto() const;
    virtual void atacar(Carta* alvo);
    virtual void receber_dano(unsigned int dano_recebido);
    bool esta_viva() const;
    std::string get_nome() const;
    virtual void aplicar_efeito_pre_ataque(Carta* inimigo);
    virtual void aplicar_efeito_pos_ataque(Carta* inimigo);
    virtual void aplicar_efeito_morte(Jogador* jogador_inimigo);
    void set_jogador(Jogador* jogador);
    void modificar_dano(int quantidade);
    void modificar_velocidade(int quantidade);

    static int player;

    unsigned int get_vida() const { return vida; }
    unsigned int get_efeito() const { return efeito; }
    unsigned int get_velocidade() const { return velocidade; }
    unsigned int get_dano() const { return dano; }
    void centraliza(sf::Sprite& c);
};

#endif
