#include "Carta.h"

Carta::Carta(sf::Vector2f coords)
{
     std::cout << "Criando carta para player: " << Carta::player << std::endl;
    isDead = false;
    isOnBoard = false;
    // Modifica as coordenadas para o player 2
    
    if (Carta::player == 2) {
        coords.y = 20;  // Posição Y para o jogador 2
    } else {
        coords.y = 520; // Posição Y para o jogador 1
    }

    std::cout << "x: " << coords.x << ", y: " << coords.y << std::endl;

    try
    {
        carregar_carta_frente(coords);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    dano = 0;
    velocidade = 0;
    efeito = 0;
    custo = 0;
    caminho = "";
}
void Carta::carregar_carta_frente(sf::Vector2f coords)
{
    if (!texturaCarta1.loadFromFile("assets/cards/carta_frente.png"))
    {
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    carta.setTexture(texturaCarta1);
    carta.setPosition(coords);
    carta.setScale(escala, escala);
}

void Carta::carregar_carta_tras(sf::Vector2f coords)
{
    if (!texturaCarta.loadFromFile("assets/cards/carta_tras.png"))
    {
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    carta.setTexture(texturaCarta);
    carta.setPosition(coords);
    carta.setScale(escala, escala);
}

void Carta::carregar_carta_monte()
{
    if (!texturaCarta.loadFromFile("assets/cards/carta_tras_monte.png"))
    {
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    carta.setTexture(texturaCarta);
    carta.setPosition(1050.0f, 250.0f);
    carta.setScale(escala, escala);
}

sf::Sprite Carta::get_sprite_carta() {
    return carta;
}

void Carta::centraliza(int pos){
    carta.setPosition(coordsCartas[pos].x, coordsCartas[pos].y-150);
    inseto.setPosition(coordsInsetos[pos].x, coordsInsetos[pos].y-150);
}

void Carta::volta_posicao_carta(int pos){
    carta.setPosition(coordsCartas[pos]);
    inseto.setPosition(coordsCartas[pos]);
}

sf::Sprite Carta::get_sprite_inseto() const{
    return inseto;
}

sf::Vector2f Carta::get_coords_carta(int pos) {
    sf::Vector2f coord = coordsCartas[pos];
   if (Carta::player == 2) {
        coord.y = 20;  // Posição Y fixa para jogador 2
    } else {
        coord.y = 520; // Posição Y fixa para jogador 1
    }
    return coord;
}

sf::Vector2f Carta::get_coords_inseto(int pos) {
    sf::Vector2f coord = coordsInsetos[pos];
   if (Carta::player == 2) {
        coord.y = 80;  // Posição Y fixa para insetos do jogador 2
    } else {
        coord.y = 580; // Posição Y fixa para insetos do jogador 1
    }
    return coord;
}

void Carta::carrega_icone_inseto(sf::Vector2f coords, std::string caminho)
{
    if (!texturaInseto.loadFromFile(caminho))
    {
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    inseto.setTexture(texturaInseto);
    inseto.setPosition(coords);
    inseto.setScale(escalaInseto, escalaInseto);
}

void Carta::set_dead(){
    isDead = true;
}


int Carta::player = 1;