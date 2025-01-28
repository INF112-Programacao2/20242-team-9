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

void Jogo::run_jogo() {
    int cartaSelecionada = 0;
    float posicaoSeta = 301.2f;
    float espacamento = 160.0f;

    while (janela->isOpen()) {
        sf::Event event;

        while (janela->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                janela->close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right && 
                    cartaSelecionada < jogador1->get_numCartas() - 1) {
                    cartaSelecionada++;
                    posicaoSeta += espacamento;
                    seta.setPosition(posicaoSeta, 460);
                }
                else if (event.key.code == sf::Keyboard::Left && cartaSelecionada > 0) {
                    cartaSelecionada--;
                    posicaoSeta -= espacamento;
                    seta.setPosition(posicaoSeta, 460);
                }
                else if (event.key.code == sf::Keyboard::Enter) {
                    Carta* cartaJogador1 = jogador1->getCarta(cartaSelecionada);
                    int cartaSelecionadaJogador2 = rand() % jogador2->get_numCartas();
                    Carta* cartaJogador2 = jogador2->getCarta(cartaSelecionadaJogador2);

                    resolver_batalha(cartaJogador1, cartaJogador2);
                    
                    verificar_vitoria();
                }
            }
        }

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
    std::cout << "\n=== Início da Batalha ===\n" << std::endl;

    std::cout << "Jogador 1 utilizou a carta: " << carta1->get_nome() << std::endl;
    std::cout << "Jogador 2 utilizou a carta: " << carta2->get_nome() << std::endl;

    std::cout << "Velocidade da carta do Jogador 1: " << carta1->get_velocidade() << std::endl;
    std::cout << "Velocidade da carta do Jogador 2: " << carta2->get_velocidade() << std::endl;

    // Determinar a ordem de ataque
    if (carta1->get_velocidade() > carta2->get_velocidade()) {
        std::cout << "Jogador 1 ataca primeiro!" << std::endl;
        carta1->atacar(carta2);
        if (carta2->esta_viva()) {
            carta2->atacar(carta1);
        } else {
            std::cout << "A carta do Jogador 2 foi derrotada antes de atacar!" << std::endl;
        }
    } else if (carta1->get_velocidade() < carta2->get_velocidade()) {
        std::cout << "Jogador 2 ataca primeiro!" << std::endl;
        carta2->atacar(carta1);
        if (carta1->esta_viva()) {
            carta1->atacar(carta2);
        } else {
            std::cout << "A carta do Jogador 1 foi derrotada antes de atacar!" << std::endl;
        }
    } else {
        std::cout << "As cartas têm velocidades iguais! Ataque simultâneo!" << std::endl;
        carta1->atacar(carta2);
        carta2->atacar(carta1);
    }

    // Exibir o resultado da batalha
    if (!carta1->esta_viva() && !carta2->esta_viva()) {
        std::cout << "Ambas as cartas foram derrotadas!" << std::endl;
    } else if (!carta1->esta_viva()) {
        std::cout << "A carta do Jogador 1 foi derrotada!" << std::endl;
    } else if (!carta2->esta_viva()) {
        std::cout << "A carta do Jogador 2 foi derrotada!" << std::endl;
    } else {
        std::cout << "Ambas as cartas sobreviveram à batalha!" << std::endl;
    }

    // Atualizar mãos dos jogadores
    if (!carta1->esta_viva()) {
        jogador1->remover_carta(carta1);
    }
    if (!carta2->esta_viva()) {
        jogador2->remover_carta(carta2);
    }

    std::cout << "\n=== Fim da Batalha ===\n" << std::endl;
}

void Jogo::verificar_vitoria() {
    if (jogador1->get_numCartas() == 0) {
        std::cout << "Jogador 2 venceu o jogo!" << std::endl;
        janela->close();
    } else if (jogador2->get_numCartas() == 0) {
        std::cout << "Jogador 1 venceu o jogo!" << std::endl;
        janela->close();
    }
}