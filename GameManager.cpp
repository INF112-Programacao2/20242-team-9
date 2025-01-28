#include "GameManager.h"

GameManager::GameManager(): window(sf::VideoMode(1360, 768), "Insecttle"), 
estadoAtual(EstadoJogo::Menu), menu(&window), jogo(nullptr) {
    window.setFramerateLimit(60);
    jogo = new Jogo(&window);
}

GameManager::~GameManager() {
    if (jogo) {
        delete jogo;
        jogo = nullptr;
    }
}

void GameManager::run() {
    while (window.isOpen()) {
        switch (estadoAtual) {
            case EstadoJogo::Menu:
                menu.run_menu();
                if (menu.is_jogar_selecionado()) {
                    try {
                        std::cout << "Initializing game..." << std::endl;
                        jogo = new Jogo(&window);
                        estadoAtual = EstadoJogo::Jogando;
                        std::cout << "Game initialized successfully" << std::endl;
                    }
                    catch (const std::exception& e) {
                        // Return to menu if game initialization fails
                        estadoAtual = EstadoJogo::Menu;
                        menu.resetar_estado();
                    }
                } else if(menu.is_regras_selecionado()){
                    estadoAtual = EstadoJogo::Regras;
                }
                break;

            case EstadoJogo::Jogando:
                if (jogo) {
                    jogo->run_jogo();
                    if (jogo->getEstadoAtual() == EstadoJogo::Menu) {
                        estadoAtual = EstadoJogo::Menu;
                        menu.resetar_estado();
                    }
                } else {
                    // Failsafe in case jogo is null
                    estadoAtual = EstadoJogo::Menu;
                    menu.resetar_estado();
                }
                break;

            case EstadoJogo::Regras:
                run_regras();
                break;
        }
    }
}

void GameManager::run_regras() {
    sf::Event evento;
    while (window.isOpen() && estadoAtual == EstadoJogo::Regras) {
        bool mostrarOutroSprite=false;
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                estadoAtual = EstadoJogo::Menu; // Volta ao menu ao pressionar ESC
            }
            if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Verifica se o clique está no sprite da seta
                if (menu.is_setaDir_on_click(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    mostrarOutroSprite = !mostrarOutroSprite; // Alterna o sprite
                }
                else if(menu.is_setaEsq_on_click(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))){
                    mostrarOutroSprite = !mostrarOutroSprite;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                estadoAtual = EstadoJogo::Menu; // Volta ao menu ao pressionar ESC
            }
        }

        window.clear();
        if(!mostrarOutroSprite){
            window.draw(menu.get_fundoRegras_1());
            window.draw(menu.get_setaDir());
        } else{
            window.draw(menu.get_fundoRegras_2());
            window.draw(menu.get_setaEsq());
        }
        window.display();
    }
}

