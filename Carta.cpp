#include "Carta.h"
#include "Jogador.h"

Carta::Carta(sf::Vector2f coords)
{
    jogador = nullptr;
    std::cout << "Carta::player: " << Carta::player << std::endl;
    isDead = false;
    isOnBoard = false;
    // Modifica as coordenadas para o player 2
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
    caminho = "";
}

void Carta::modificar_dano(int quantidade) {
    dano += quantidade;
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

void Carta::centraliza(sf::Sprite& c){
    c.setPosition(500, 500);
}

sf::Sprite Carta::get_sprite_inseto() const
{
    return inseto;
}
/*
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
*/

void Carta::modificar_velocidade(int quantidade) {
    velocidade += quantidade;
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

void Carta::atacar(Carta* alvo) {
    if (alvo == nullptr) {
        std::cout << "Erro: Alvo inválido!" << std::endl;
        return;
    }
    std::cout << nome << " ataca " << alvo->get_nome() << " causando " << dano << " de dano." << std::endl;
    alvo->receber_dano(dano);
}

void Carta::receber_dano(unsigned int dano_recebido) {
    if (dano_recebido >= vida) {
        vida = 0;
    } else {
        vida -= dano_recebido;
    }
    std::cout << nome << " agora tem " << vida << " de vida." << std::endl;
}

bool Carta::esta_viva() const {
    return vida > 0;
}

std::string Carta::get_nome() const {
    return nome;
}

sf::Sprite& Carta::get_sprite_carta() {
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

void Carta::set_jogador(Jogador* jogador) {
    if (jogador != nullptr) {
        this->jogador = jogador;
    }
}

void Carta::set_dead(){
    isDead = true;
}

bool Carta::is_dead() const{
    return isDead;
}
void Carta::aplicar_efeito_pre_ataque(Carta* inimigo) {
    if (inimigo == nullptr) {
    std::cerr << "Erro: inimigo é nullptr em aplicar_efeito_pre_ataque!" << std::endl;
    return;
}
    std::cout << "Aplicou Efeito Ataque" << std::endl;
    // Implementação padrão (vazia)
}

void Carta::aplicar_efeito_pos_ataque(Carta* inimigo) {
    std::cout << "Aplicou Efeito Pos Ataque" << std::endl;
    // Implementação padrão (vazia)
}

void Carta::aplicar_efeito_morte(Jogador* jogador) {
    std::cout << "Aplicou Efeito Morte" << std::endl;
    // Implementação padrão (vazia)
}

int Carta::player = 1;
