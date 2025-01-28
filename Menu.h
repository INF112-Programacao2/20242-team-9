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
        bool isSomAtivado;
        sf::RenderWindow *window;
        int pos;
        bool escolhido, selecionado;
        EstadoJogo estadoAtual;
        sf::Font *fonte;
        std::vector<sf::SoundBuffer> buffersRegras;
        std::vector<sf::Sound> sonsRegras;
        sf::Sprite fundoRegras1, fundoRegras2, com_som, sem_som;
        sf::Texture txtComSom, txtSemSom;
        sf::Sprite fundoMenu;
        sf::Sprite setaDir, setaEsq;
        sf::Texture txtSetaDir, txtSetaEsq;
        sf::Texture texturaRegras1, texturaRegras2, texturaMenu;
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
        void carrega_spriteSetas();
        void carrega_fonte();
        void carrega_fundoRegras();
        void carrega_sonsRegras();
        void carrega_iconeSom();
        void tocar_sonsRegras();
        void atualizar_icone_som(bool comSom);
        void parar_sonsRegras();
        void toggleSom();
        sf::Sprite get_fundoMenu() const {return fundoMenu;}
        sf::Sprite get_setaDir() const {return setaDir;}
        sf::Sprite get_setaEsq() const {return setaEsq;}
        sf::Sprite get_comSom() const {return com_som;}
        sf::Sprite get_semSom() const {return sem_som;}
        bool get_isSomAtivado() const {return isSomAtivado;}
        void carrega_fundoMenu();
        sf::Sprite get_fundoRegras_1() const{return fundoRegras1;}
        sf::Sprite get_fundoRegras_2() const{return fundoRegras2;}
        void run_menu();
        void resetar_estado(){estadoAtual = EstadoJogo::Menu;}
        bool is_jogar_selecionado();
        bool is_regras_selecionado();
        bool is_opcoes_selecionado();
        bool will_sem_som_selecionado(float x, float y);
        bool will_com_som_selecionado(float x, float y);
        bool is_setaDir_on_click(float x, float y);
        bool is_setaEsq_on_click(float x, float y);
};

#endif