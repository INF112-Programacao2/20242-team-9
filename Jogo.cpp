#include "Jogo.h"

Jogo::Jogo(sf::RenderWindow *window) : janela(window), turnoAtual(TurnoJogador::JOGADOR1), estadoAtual(EstadoJogo::Jogando){
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
    float espacamento = 160;
    float posicaoInicialJogador1 = 301.2f;
    float posicaoInicialJogador2 = 301.2f;

    while (janela->isOpen() && estadoAtual == EstadoJogo::Jogando) {
        sf::Event event;
        while (janela->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                janela->close();
            //std::cout << "JOGANDO" << std::endl;
            // Efeito de hover
            sf::Vector2i posicaoMouse = sf::Mouse::getPosition(*janela);
            if (verificar_clique_botao(posicaoMouse)) {
                fundoBotaoDesistir.setFillColor(sf::Color(180, 20, 20));  // Vermelho mais escuro quando hover
            } else {
                fundoBotaoDesistir.setFillColor(sf::Color(220, 20, 20));  // Cor normal
            }
            
            // Verificar clique do mouse no botão desistir
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (verificar_clique_botao(posicaoMouse)) {
                        std::cout << "Jogador desistiu!" << std::endl;
                        if (turnoAtual == TurnoJogador::JOGADOR1) {
                            std::cout << "Jogador 2 Wins!" << std::endl;
                        } else {
                            std::cout << "Jogador 1 Wins!" << std::endl;
                        }
                        estadoAtual = EstadoJogo::Menu;
                        return;
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if(jogador1->get_numCartasVivas()!=0 && jogador2->get_numCartasVivas()!=0){
                    if (turnoAtual == TurnoJogador::JOGADOR1) {
                        int maxCartas = jogador1->get_numCartas();
                        if (event.key.code == sf::Keyboard::Right && jogador1->cartaSelecionada < maxCartas - 1) {
                            jogador1->cartaSelecionada++;
                        }
                        else if (event.key.code == sf::Keyboard::Left && jogador1->cartaSelecionada > 0) {
                            jogador1->cartaSelecionada--;
                        }
                        
                        posicaoSeta1 = posicaoInicialJogador1 + jogador1->cartaSelecionada * espacamento;
                        setaJogador1.setPosition(posicaoSeta1, 460);
                        
                        if (event.key.code == sf::Keyboard::Enter) {
                            if (!jogador1->has_card_in_board() && jogador1->get_numTrocas() <= 3) {
                                // Place new card
                                centraliza_carta_selecionada(jogador1->getCarta(jogador1->cartaSelecionada), jogador1->cartaSelecionada);
                                jogador1->put_card_on_board();
                                ultimaPosicaoValidaJogador1 = jogador1->cartaSelecionada;
                                turnoAtual = TurnoJogador::JOGADOR2;
                            } 
                            else if (jogador1->has_card_in_board() && jogador1->get_numTrocas() < 3) {
                                // Replace card
                                jogador1->incrementa_numTrocas();
                                volta_posicao_carta_selecionada(jogador1->getCarta(ultimaPosicaoValidaJogador1), ultimaPosicaoValidaJogador1);
                                centraliza_carta_selecionada(jogador1->getCarta(jogador1->cartaSelecionada), jogador1->cartaSelecionada);
                                ultimaPosicaoValidaJogador1 = jogador1->cartaSelecionada;
                                
                                if (jogador2->has_card_in_board()) {
                                    // If player 2 has a card, resolve battle
                                    seta_cartas_perdedoras();
                                }
                                turnoAtual = TurnoJogador::JOGADOR2;
                            }
                        } else if (jogador1->get_numTrocas() >= 3) {
                                std::cout << "Você já atingiu o numero de trocas maximo numa partida!" << std::endl;
                                turnoAtual = TurnoJogador::JOGADOR2;
                        }
                    }
                    else { // JOGADOR2
                        int maxCartas = jogador2->get_numCartas();
                        if (event.key.code == sf::Keyboard::Right && jogador2->cartaSelecionada < maxCartas - 1) {
                            jogador2->cartaSelecionada++;
                        }
                        else if (event.key.code == sf::Keyboard::Left && jogador2->cartaSelecionada > 0) {
                            jogador2->cartaSelecionada--;
                        }
                        
                        posicaoSeta2 = posicaoInicialJogador2 + jogador2->cartaSelecionada * espacamento;
                        setaJogador2.setPosition(posicaoSeta2, 260);
                        
                        if (event.key.code == sf::Keyboard::Enter) {
                            if (!jogador2->has_card_in_board() && jogador2->get_numTrocas() <= 3) {
                                // Place new card
                                centraliza_carta_selecionada(jogador2->getCarta(jogador2->cartaSelecionada), jogador2->cartaSelecionada);
                                jogador2->put_card_on_board();
                                ultimaPosicaoValidaJogador2 = jogador2->cartaSelecionada;
                                
                                if (jogador1->has_card_in_board()) {
                                    // If player 1 has a card, resolve battle
                                    seta_cartas_perdedoras();
                                }
                                turnoAtual = TurnoJogador::JOGADOR1;
                            }
                            else if (jogador2->has_card_in_board() && jogador2->get_numTrocas() < 3) {
                                // Replace card
                                jogador2->incrementa_numTrocas();
                                volta_posicao_carta_selecionada(jogador2->getCarta(ultimaPosicaoValidaJogador2), ultimaPosicaoValidaJogador2);
                                centraliza_carta_selecionada(jogador2->getCarta(jogador2->cartaSelecionada), jogador2->cartaSelecionada);
                                ultimaPosicaoValidaJogador2 = jogador2->cartaSelecionada;
                                
                                if (jogador1->has_card_in_board()) {
                                    // If player 1 has a card, resolve battle
                                    seta_cartas_perdedoras();
                                }
                                turnoAtual = TurnoJogador::JOGADOR1;
                            }
                            else if (jogador2->get_numTrocas() >= 3) {
                                if (jogador1->has_card_in_board()) {
                                    seta_cartas_perdedoras();
                                }
                                std::cout << "Você já atingiu o numero de trocas maximo numa partida!" << std::endl;
                                turnoAtual = TurnoJogador::JOGADOR1;
                            }
                        }
                    }
                }
                else{
                    estadoAtual = EstadoJogo::GameOver;
                    if(jogador1->get_numCartas()!=0){
                        std::cout << "Jogador 1 Wins!" << std::endl;
                    } else{
                        std::cout << "Jogador 2 Wins!" << std::endl;
                    }
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

void Jogo::seta_cartas_perdedoras(){
    int who_win = resolver_batalha(jogador1->getCarta(jogador1->cartaSelecionada), jogador2->getCarta(jogador2->cartaSelecionada));
    if(who_win == 1){
        jogador2->set_morte(jogador2->cartaSelecionada);
        jogador2->take_card_from_board();
    } else if(who_win == 2){
        jogador1->set_morte(jogador1->cartaSelecionada);
        jogador1->take_card_from_board();
    } else{
        jogador1->set_morte(jogador1->cartaSelecionada);
        jogador2->set_morte(jogador2->cartaSelecionada);
        jogador1->take_card_from_board();
        jogador2->take_card_from_board();
    }
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

int Jogo::resolver_batalha(Carta* carta1, Carta* carta2) {
    if (carta1->get_dano() > carta2->get_dano()) {
        std::cout << "Jogador 1 vence a batalha!" << std::endl;
        return 1;
        // Atualizar estado do jogo, como reduzir vida do jogador 2
    } else if (carta1->get_dano() < carta2->get_dano()) {
        std::cout << "Jogador 2 vence a batalha!" << std::endl;
        return 2;
        // Atualizar estado do jogo, como reduzir vida do jogador 1
    } else {
        std::cout << "A batalha terminou em empate!" << std::endl;
        return 0;
        // Lógica para empate, se necessário
    }
}