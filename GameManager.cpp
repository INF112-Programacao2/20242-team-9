#include "GameManager.h"

GameManager::GameManager()
    : window(sf::VideoMode(1360, 768), "RPG Game"),
    estadoAtual(EstadoJogo::Menu),
    menu(&window) {
    window.setFramerateLimit(60);
}

GameManager::~GameManager() {
    if (jogo) {
        delete jogo;
    }
}

void GameManager::run() {
    while (window.isOpen()) {
        switch (estadoAtual) {
            case EstadoJogo::Menu:
                menu.run_menu();
                if (menu.is_jogar_selecionado() && jogo) {
                    jogo = new Jogo(&window);
                    estadoAtual = EstadoJogo::Jogando;
                }
                break;

            case EstadoJogo::Jogando:
                if (jogo) {
                    jogo->run_jogo();
                }
                break;
            default:
                break;
        }
    }
}
