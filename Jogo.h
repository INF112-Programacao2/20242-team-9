#ifndef JOGO_H
#define JOGO_H

#include <SFML/Graphics.hpp>
#include "Carta.h"
#include "EstadoJogo.h"
#include "Jogador.h"
#include "TurnoJogador.h"

class Jogo {
    private:
        sf::Font fonte;
        sf::Text botaoDesistir;
        sf::RectangleShape fundoBotaoDesistir;  // Novo elemento para o fundo do botão
        void inicializa_botao_desistir();
        bool verificar_clique_botao(const sf::Vector2i& posicaoMouse);
        int cartaSelecionadaJ1, cartaSelecionadaJ2;
        TurnoJogador turnoAtual;
        EstadoJogo estadoAtual;
        sf::RenderWindow* janela;
        sf::Sprite mesa;
        sf::Texture texturaMesa;
        sf::Sprite setaJogador1;
        sf::Sprite setaJogador2;
        sf::Texture texturaSeta1, texturaSeta2;
        Carta *cartaJogador1, *cartaJogador2;
        float posicaoSeta1 = 301.2;
        float posicaoSeta2 = 301.2;
        Carta carta;
        Jogador* jogador1, *jogador2;
        float posicaoSeta = 301.2;
        int ultimaPosicaoValidaJogador1 = 0;
        int ultimaPosicaoValidaJogador2 = 0;

    public:
        void verificar_vitoria();
        Jogo(sf::RenderWindow* window);
        void carrega_tabuleiro();
        void loop_eventos();
        void seta_cartas_perdedoras();
        void carrega_fonte_vez();
        EstadoJogo getEstadoAtual() const {return estadoAtual;}
        void desenhar();
        void run_jogo();
        void carrega_setas();
        void fecha_janela();
        void volta_posicao_carta_selecionada(Carta *carta, int pos);
        void centraliza_carta_selecionada(Carta* carta, int pos);
        ~Jogo();
        int resolver_batalha(Carta* carta1, Carta* carta2, int posCarta1, int posCarta2);
};


#endif