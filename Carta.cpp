#include "Carta.h"

Carta::Carta(sf::Vector2f coords)
{
    std::cout << "Carta::player: " << Carta::player << std::endl;
    std::cout << "x: " << coords.x << ", y: " << coords.y << std::endl;

    try
    {
        carregar_carta_frente(coords);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    // Inicialização dos atributos
    dano = 0;
    vida = 0;
    vidaOriginal = 0;
    velocidade = 0;
    efeito = 0;
    custo = 0;
    caminho = "";
    
    // Inicialização dos novos atributos de controle de efeitos
    efeitoBarataUsado = false;
    efeitoGafanhotoUsado = false;
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

sf::Sprite& Carta::get_sprite_carta() {
    return carta;
}

void Carta::centraliza(sf::Sprite& c){
    c.setPosition(500, 500);
}

sf::Sprite Carta::get_sprite_inseto() const
{
    return inseto;
}

sf::Vector2f Carta::get_coords_carta(int pos) 
{
    if (Carta::player == 2)
    {
        for (auto& coord : coordsCartas) {
            coord.y -= 500;
        }

        for (auto& coordInseto : coordsInsetos) {
            coordInseto.y -= 500;
        }
    }
    return coordsCartas[pos];
}

sf::Vector2f Carta::get_coords_inseto(int pos) 
{
    return coordsInsetos[pos];
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

void Carta::inicializa_jogador()
{
    // Implementação da inicialização do jogador, se necessário
}

sf::Vector2f Carta::get_coords_frente() const
{
    return carta.getPosition();
}

int Carta::player = 1;