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
                    }
                    catch (const std::exception& e) {
                        // Return to menu if game initialization fails
                        estadoAtual = EstadoJogo::Menu;
                        menu.resetar_estado();
                        //std::cout << "Teste" << std::endl;
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
                    std::cout << "TESTE COMMIT" << std::endl;
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
    size_t indiceRegra = 0;  // Para controlar qual regra está sendo exibida
    bool mostrarOutroSprite = false;
    bool isComSom = true;
    bool somTocado = false; // Para garantir que o som seja tocado apenas uma vez

    while (window.isOpen() && estadoAtual == EstadoJogo::Regras) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                estadoAtual = EstadoJogo::Menu; // Volta ao menu ao pressionar ESC
            }

            if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Verifica se o clique está na seta direita
                if (menu.is_setaDir_on_click(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    mostrarOutroSprite = !mostrarOutroSprite;
                    // Debug: Verifique se o clique foi registrado
                    std::cout << "Seta direita clicada!" << std::endl;
                }
                // Verifica se o clique está na seta esquerda
                else if (menu.is_setaEsq_on_click(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    mostrarOutroSprite = !mostrarOutroSprite;
                    // Debug: Verifique se o clique foi registrado
                    std::cout << "Seta esquerda clicada!" << std::endl;
                }
                // Verifique o clique no ícone de som
                if (menu.will_com_som_selecionado(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) ||
                    menu.will_sem_som_selecionado(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) ) {
                    menu.toggleSom();
                }

            }
        }

        window.clear();
        if (!mostrarOutroSprite) {
            window.draw(menu.get_fundoRegras_1());
            window.draw(menu.get_setaDir());
        } else {
            window.draw(menu.get_fundoRegras_2());
            window.draw(menu.get_setaEsq());
        }

        if (isComSom && !somTocado) { // Toca o som apenas uma vez
            menu.tocar_sonsRegras();
            somTocado = true; // Marca que o som foi tocado
        }

        // Desenha o ícone de som (com ou sem som)
        if(menu.get_isSomAtivado()){
            window.draw(menu.get_comSom());
        } else {
            window.draw(menu.get_semSom());
        }

        window.display();
    }
}






