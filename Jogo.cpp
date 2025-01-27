#include "Jogo.h"

// coordenadas da barra de vida e de energia na tela
unsigned int coordX1 = 1100, coordY1 = 670, coordX2 = 1100, coordY2 = 50;

Jogo::Jogo(sf::RenderWindow *window) : janela(window)
{
    jogador1 = new Jogador(coordX1, coordY1);
    jogador2 = new Jogador(coordX2, coordY2);
    try
    {
        carrega_tabuleiro();
        std::cout << "CARREGOU TABULEIRO!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
void Jogo::carrega_tabuleiro()
{
    if (!texturaMesa.loadFromFile("assets/board/board.png"))
    {
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    mesa.setTexture(texturaMesa);
    mesa.setPosition(0, 0);

    if (!texturaSeta.loadFromFile("assets/icons/seta.png"))
    {
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    seta.setTexture(texturaSeta);
    seta.setPosition(posicaoSeta, 460);
}
void Jogo::loop_eventos()
{
    sf::Event evento;
    while (janela->pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
        {
            janela->close();
        }
    }
}

void Jogo::run_jogo()
{
    int cartaSelecionada = 0;        // Índice da carta selecionada (0 a 4)
         // Posição inicial da seta
    float espacamento = 160;        // Espaçamento entre as cartas
    

    while (janela->isOpen())
    {
        sf::Event event;

        // Processar eventos
        while (janela->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                janela->close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right && cartaSelecionada < 4) {
                    cartaSelecionada++;
                    posicaoSeta += espacamento; // Move a seta para a direita
                }
                else if (event.key.code == sf::Keyboard::Left && cartaSelecionada > 0) {
                    cartaSelecionada--;
                    posicaoSeta -= espacamento; // Move a seta para a esquerda
                }

                // Atualizar a posição da seta
                seta.setPosition(posicaoSeta, 460);

                if (event.key.code == sf::Keyboard::Enter) {
                    // Iniciar batalha com a carta selecionada
                    Carta* cartaJogador1 = jogador1->getCarta(cartaSelecionada);
                    Carta* cartaJogador2 = jogador2->getCarta(cartaSelecionada);

                    // Now we get a reference to the actual sprite and pass it to centraliza
                    sf::Sprite& sprite = jogador1->get_sprite_mao_carta(cartaSelecionada);
                    cartaJogador1->centraliza(sprite);

                    resolver_batalha(cartaJogador1, cartaJogador2);
                }
            }
        }

        // Chamar a lógica principal
        loop_eventos();
        desenhar();
    }
}




void Jogo::desenhar()
{
    janela->clear();
    janela->draw(mesa);

    for (int i = 0; i < 5; i++)
    {
        janela->draw(jogador1->get_sprite_mao_carta(i));
        janela->draw(jogador1->get_sprite_mao_inseto(i));
    }

    for (int i = 0; i < 5; i++)
    {
        janela->draw(jogador2->get_sprite_mao_carta(i));
        janela->draw(jogador2->get_sprite_mao_inseto(i));
    }

    janela->draw(monte.get_sprite_monte());
    janela->draw(seta);
    janela->draw(jogador1->get_sprite_barra());
    janela->draw(jogador2->get_sprite_barra());
    janela->display();
}

Jogo::~Jogo()
{
    delete jogador1;
    delete jogador2;
}

void Jogo::resolver_batalha(Carta* carta1, Carta* carta2) {


        
         
        
        if (carta1->get_dano() > carta2->get_dano()) {
            std::cout << "Jogador 1 vence a batalha!" << std::endl;
            // Atualizar estado do jogo, como reduzir vida do jogador 2
        } else if (carta1->get_dano() < carta2->get_dano()) {
            std::cout << "Jogador 2 vence a batalha!" << std::endl;
            // Atualizar estado do jogo, como reduzir vida do jogador 1
        } else {
            std::cout << "A batalha terminou em empate!" << std::endl;
            // Lógica para empate, se necessário
        }
}