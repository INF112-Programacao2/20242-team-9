#include "Jogo.h"

Jogo::Jogo(sf::RenderWindow *window) : janela(window), turnoAtual(TurnoJogador::JOGADOR1),
 cartaSelecionadaJ1(0),cartaSelecionadaJ2(0), estadoAtual(EstadoJogo::Jogando), cartaJogador1(nullptr), cartaJogador2(nullptr) {
    jogador1 = new Jogador(1);
    jogador2 = new Jogador(2);
    inicializa_botao_desistir();
    try
    {
        carrega_tabuleiro();
        carrega_setas();
        std::cout << "CARREGOU TABULEIRO!" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Jogo::inicializa_botao_desistir() {
    if (!fonte.loadFromFile("assets/fonts/fonte_menu.ttf")) {
        throw std::runtime_error("Erro ao carregar a fonte do botão desistir!");
    }
    
    // Configurar o texto
    botaoDesistir.setFont(fonte);
    botaoDesistir.setString("Desistir");
    botaoDesistir.setCharacterSize(24);
    botaoDesistir.setFillColor(sf::Color::White);  // Texto branco
    
    // Configurar o retângulo de fundo
    fundoBotaoDesistir.setSize(sf::Vector2f(200, 40));  // Tamanho do botão
    fundoBotaoDesistir.setFillColor(sf::Color(220, 20, 20));  // Vermelho mais escuro
    fundoBotaoDesistir.setOutlineThickness(2);
    fundoBotaoDesistir.setOutlineColor(sf::Color(180, 20, 20));  // Borda mais escura
    fundoBotaoDesistir.setPosition(1150, 20);
    
    // Centralizar o texto no retângulo
    sf::FloatRect textBounds = botaoDesistir.getLocalBounds();
    botaoDesistir.setPosition(
        fundoBotaoDesistir.getPosition().x + (fundoBotaoDesistir.getSize().x - textBounds.width) / 2,
        fundoBotaoDesistir.getPosition().y + (fundoBotaoDesistir.getSize().y - textBounds.height) / 2 - 5
    );
}

bool Jogo::verificar_clique_botao(const sf::Vector2i& posicaoMouse) {
    // Agora verifica o clique no retângulo de fundo
    sf::FloatRect bounds = fundoBotaoDesistir.getGlobalBounds();
    return bounds.contains(static_cast<float>(posicaoMouse.x), static_cast<float>(posicaoMouse.y));
}

void Jogo::carrega_tabuleiro()
{
    if (!texturaMesa.loadFromFile("assets/board/board.png"))
    {
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    mesa.setTexture(texturaMesa);
    mesa.setPosition(0, 0);
}

void Jogo::carrega_setas() {
    if (!texturaSeta1.loadFromFile("assets/icons/seta_1.png")) {
        throw std::runtime_error("Erro ao carregar a textura da seta 1!");
    }
    if (!texturaSeta2.loadFromFile("assets/icons/seta_2.png")) {
        throw std::runtime_error("Erro ao carregar a textura da seta 2!");
    }
    
    setaJogador1.setTexture(texturaSeta1);
    setaJogador1.setPosition(posicaoSeta1, 460);
    
    setaJogador2.setTexture(texturaSeta2);
    setaJogador2.setPosition(posicaoSeta2, 260); // Posição superior para o jogador 2
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
    float posicaoSeta = 301.2f;
    float espacamento = 160.0f;
    while (janela->isOpen()) {
        sf::Event event;

        while (janela->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                janela->close();

                sf::Vector2i posicaoMouse = sf::Mouse::getPosition(*janela);
                if (verificar_clique_botao(posicaoMouse)) {
                    fundoBotaoDesistir.setFillColor(sf::Color(180, 20, 20));  // Vermelho mais escuro quando hover
                } else {
                    fundoBotaoDesistir.setFillColor(sf::Color(220, 20, 20));  // Cor normal
                }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (verificar_clique_botao(posicaoMouse)) {
                        std::cout << "Jogador desistiu!" << std::endl;
                        if (turnoAtual == TurnoJogador::JOGADOR1) {
                            std::cout << "Jogador 2 Wins!" << std::endl;
                        } else {
                            std::cout << "Jogador 1 Wins!" << std::endl;
                        }
                        janela->close();
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                // Jogador 1
                if (event.key.code == sf::Keyboard::Right && cartaSelecionadaJ1 < jogador1->get_numCartas() - 1 && turnoAtual==TurnoJogador::JOGADOR1) {
                    cartaSelecionadaJ1++;
                    posicaoSeta += espacamento;
                    //seta.setPosition(posicaoSeta, 460);
                }
                else if (event.key.code == sf::Keyboard::Left && cartaSelecionadaJ1 > 0 && turnoAtual==TurnoJogador::JOGADOR1) {
                    cartaSelecionadaJ1--;
                    posicaoSeta -= espacamento;
                    //seta.setPosition(posicaoSeta, 460);
                }
                else if (event.key.code == sf::Keyboard::Enter && turnoAtual==TurnoJogador::JOGADOR1 && !jogador1->verifica_carta_morta(cartaSelecionadaJ1)) {
                    // SELECIONA CARTA JOGADOR 1
                    cartaJogador1 = jogador1->getCarta(cartaSelecionadaJ1);
                    turnoAtual = TurnoJogador::JOGADOR2;
                }
                
                // Jogador 2
                else if (event.key.code == sf::Keyboard::Right && 
                    cartaSelecionadaJ2 < jogador2->get_numCartas() - 1 && turnoAtual==TurnoJogador::JOGADOR2) {
                    cartaSelecionadaJ2++;
                    posicaoSeta += espacamento;
                    //seta.setPosition(posicaoSeta, 460);
                }
                else if (event.key.code == sf::Keyboard::Left && cartaSelecionadaJ2 > 0 && turnoAtual == TurnoJogador::JOGADOR2) {
                    cartaSelecionadaJ2--;
                    posicaoSeta -= espacamento;
                    //seta.setPosition(posicaoSeta, 460);
                }
                else if (event.key.code == sf::Keyboard::Enter && turnoAtual == TurnoJogador::JOGADOR2 && !jogador1->verifica_carta_morta(cartaSelecionadaJ2)) {
                    // SELECIONA CARTA JOGADOR 2
                    cartaJogador2 = jogador2->getCarta(cartaSelecionadaJ2);

                    int whoWin = resolver_batalha(cartaJogador1, cartaJogador2, cartaSelecionadaJ1, cartaSelecionadaJ2);
                    if(whoWin == 1){
                        jogador1->set_morte(cartaSelecionadaJ1);
                    } else if(whoWin == 2){
                        jogador2->set_morte(cartaSelecionadaJ2);
                    } else if (whoWin == 3){
                        jogador1->set_morte(cartaSelecionadaJ1);
                        jogador2->set_morte(cartaSelecionadaJ2);
                    }
                    std::cout << "NUM CARTAS J1: " << jogador1->get_numCartas() << std::endl;
                    std::cout << "NUM CARTAS J2: " << jogador2->get_numCartas() << std::endl;
                    verificar_vitoria();

                    turnoAtual=TurnoJogador::JOGADOR1;  // Passa a vez de volta para o Jogador 1
                    cartaSelecionadaJ1 = 0;  // Reseta a seleção de carta do Jogador 1
                    cartaSelecionadaJ2 = 0;  // Reseta a seleção de carta do Jogador 2
                    posicaoSeta = 301.2f;  // Reseta a posição da seta
                }
            }
        }

        loop_eventos();
        desenhar();
    }
}

void Jogo::centraliza_carta_selecionada(Carta *carta, int pos){
    carta->centraliza(pos);
}

void Jogo::volta_posicao_carta_selecionada(Carta *carta, int pos){
    carta->volta_posicao_carta(pos);
}

void Jogo::desenhar() {
    janela->clear();
    janela->draw(mesa);

    // Desenha as cartas dos jogadores
    for (int i = 0; i < 5; i++) {
        if(!jogador1->verifica_carta_morta(i)) {
            janela->draw(jogador1->get_sprite_mao_carta(i));
            janela->draw(jogador1->get_sprite_mao_inseto(i));
        }
    }

    for (int i = 0; i < 5; i++) {
        if(!jogador2->verifica_carta_morta(i)) {
            janela->draw(jogador2->get_sprite_mao_carta(i));
            janela->draw(jogador2->get_sprite_mao_inseto(i));
        }
    }

    // Desenha a seta apropriada baseada no turno atual
    if (turnoAtual == TurnoJogador::JOGADOR1) {
        janela->draw(setaJogador1);
    } else {
        janela->draw(setaJogador2);
    }

    // Desenha o fundo e o texto do botão de desistir
    janela->draw(fundoBotaoDesistir);
    janela->draw(botaoDesistir);

    janela->display();
}


Jogo::~Jogo()
{
    delete jogador1;
    delete jogador2;
}

int Jogo::resolver_batalha(Carta* carta1, Carta* carta2, int cartaSelecionadaJ1, int cartaSelecionadaJ2) {
    int whoWin;
    std::cout << "\n=== Início da Batalha ===\n" << std::endl;

    std::cout << "Jogador 1 utilizou a carta: " << carta1->get_nome() << std::endl;
    std::cout << "Jogador 2 utilizou a carta: " << carta2->get_nome() << std::endl;

    if (carta1 == nullptr || carta2 == nullptr) {
    std::cerr << "Erro: Uma das cartas é nullptr em resolver_batalha!" << std::endl;
    return -1;
    }

    carta1->aplicar_efeito_pre_ataque(carta2);
    carta2->aplicar_efeito_pre_ataque(carta1);

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

    carta1->aplicar_efeito_pos_ataque(carta2);
    carta2->aplicar_efeito_pos_ataque(carta1);

    // Exibir o resultado da batalha
    // Em Jogo.cpp, na função resolver_batalha

// Primeiro verificar o resultado da batalha e remover as cartas na ordem correta
    if (!carta1->esta_viva() && !carta2->esta_viva()) {
        std::cout << "Ambas as cartas foram derrotadas!" << std::endl;
        // Se ambas as cartas morreram, remove primeiro a que tem maior índice
        whoWin = 0;
    } 
    else if (!carta1->esta_viva()) {
        std::cout << "A carta do Jogador 1 foi derrotada!" << std::endl;;
        whoWin = 2;
    } 
    else if (!carta2->esta_viva()) {
        std::cout << "A carta do Jogador 2 foi derrotada!" << std::endl;
        whoWin = 3;
    } 
    else {
        std::cout << "Ambas as cartas sobreviveram à batalha!" << std::endl;
        whoWin = 0;
    }

    // Adicionar logs para debug
    std::cout << "\nStatus após a batalha:" << std::endl;
    std::cout << "Número de cartas Jogador 1: " << jogador1->get_numCartas() << std::endl;
    std::cout << "Número de cartas Jogador 2: " << jogador2->get_numCartas() << std::endl;

    // Atualizar mãos dos jogadores

    std::cout << "\n=== Fim da Batalha ===\n" << std::endl;
    return whoWin;
}

void Jogo::verificar_vitoria() {
    if (jogador1->get_numCartas() == 0) {
        std::cout << "Jogador 2 venceu o jogo!" << std::endl;
        if (janela && janela->isOpen()) janela->close();
    } else if (jogador2->get_numCartas() == 0) {
        std::cout << "Jogador 1 venceu o jogo!" << std::endl;
        if (janela && janela->isOpen()) janela->close();
    }
}
