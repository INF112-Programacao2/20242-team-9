#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>  
#include <time.h> 


int main() {
    // cria a janela
    sf::RenderWindow window(sf::VideoMode(1280, 720), "");

    // define as dimensões dos quadrados e o espaçamento
    const float squareSize = 100.0f;
    const float padding = 20.0f;
    const int numSquares = 5;

    // calcula a largura total ocupada pelos quadrados e espaçamento
    const float totalWidth = numSquares * squareSize + (numSquares - 1) * padding;

    // calcula a posição inicial para centralizar horizontalmente
    const float startX = (1280 - totalWidth) / 2.0f;

    // cria os quadrados vermelhos na parte de cima
    std::vector<sf::RectangleShape> redSquares;
    for (int i = 0; i < numSquares; ++i) {
        sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
        square.setFillColor(sf::Color::Red);
        square.setPosition(startX + i * (squareSize + padding), padding);
        redSquares.push_back(square);
    }

    // cria os quadrados azuis na parte de baixo
    std::vector<sf::RectangleShape> blueSquares;
    for (int i = 0; i < numSquares; ++i) {
        sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
        square.setFillColor(sf::Color::Blue);
        square.setPosition(startX + i * (squareSize + padding), 720 - squareSize - padding);
        blueSquares.push_back(square);
    }

    // executa o programa enquanto a janela está aberta
    while (window.isOpen()) {
        // verifica todos os eventos que foram acionados na janela desde a última iteração do loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // evento "fechar" acionado: fecha a janela
            if (event.type == sf::Event::Closed)
                window.close();

            // tecla pressionada
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    // comportamento para a tecla esquerda (se necessário)
                }
            }
        }

        // limpa a tela com a cor branca
        window.clear(sf::Color::White);

        // desenha os quadrados vermelhos
        for (const auto& square : redSquares)
            window.draw(square);

        // desenha os quadrados azuis
        for (const auto& square : blueSquares)
            window.draw(square);

        // termina e desenha o frame corrente
        window.display();
    }

    return 0;
}


