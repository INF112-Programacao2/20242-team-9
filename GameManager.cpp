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
    bool mostrarOutroSprite = false;  // Variável para controlar qual sprite deve ser mostrado
    bool trocarSprite = false;  // Variável para controlar a troca do sprite
    while (window.isOpen() && estadoAtual == EstadoJogo::Regras) {
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                estadoAtual = EstadoJogo::Menu; // Volta ao menu ao pressionar ESC
            }

            // Verifica se o clique foi no botão esquerdo do mouse
            if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Verifica se a seta direita foi clicada
                if (menu.is_setaDir_on_click(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && !trocarSprite) {
                    mostrarOutroSprite = true;  // Exibe o outro sprite
                    trocarSprite = true;  // Impede alternar novamente até o próximo clique
                }
                // Verifica se a seta esquerda foi clicada
                else if (menu.is_setaEsq_on_click(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && !trocarSprite) {
                    mostrarOutroSprite = false;  // Exibe o sprite original
                    trocarSprite = true;  // Impede alternar novamente até o próximo clique
                }
            }
        }

        // Redefine a variável trocarSprite após algum tempo ou ação
        if (evento.type == sf::Event::MouseButtonReleased) {
            trocarSprite = false;  // Permite nova troca após soltar o botão do mouse
        }

        window.clear();
        if (!mostrarOutroSprite) {
            window.draw(menu.get_fundoRegras_1());
            window.draw(menu.get_setaDir());  // Desenha a seta direita
        } else {
            window.draw(menu.get_fundoRegras_2());
            window.draw(menu.get_setaEsq());  // Desenha a seta esquerda
        }
        window.display();
    }
}




