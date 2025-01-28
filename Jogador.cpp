#include "Jogador.h"

Jogador::Jogador(unsigned int coordX, unsigned int coordY){
    std::srand(std::time(nullptr));
    inicializa_jogador(coordX, coordY);
    carrega_barra(coordX, coordY);
}

void Jogador::inicializa_jogador(unsigned int coordX, unsigned int coordY) {
    try {
        for (int i = 0; i < 5; i++) {
            Carta* carta = deck.get_carta_deck(i);
            carta->set_jogador(this); // Set the owner of the card
            mao.emplace_back(carta);
        }
    } catch (std::exception &e) {
        std::cerr << "Erro ao inicializar o jogador: " << e.what() << std::endl;
    }
}

void Jogador::carrega_barra(unsigned int coordX, unsigned int coordY){
    if(!texturaBarra.loadFromFile("assets/icons/barra_vida_energia.png")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    barra.setTexture(texturaBarra);
    barra.setPosition(coordX, coordY);
    barra.setScale(escalaBarra, escalaBarra);

    
}

sf::Sprite Jogador::get_sprite_barra() const{
    return barra;
}

Carta* Jogador::getCarta(int pos) {
    if (pos >= 0 && pos < mao.size()) {
        return mao[pos];
    }
    throw std::out_of_range("Posição inválida na mão do jogador");
}

sf::Sprite& Jogador::get_sprite_mao_carta(int pos) {
    if (pos >= 0 && pos < mao.size() && mao[pos] != nullptr) {
        return mao[pos]->get_sprite_carta();
    }
    throw std::out_of_range("Carta inválida na mão");
}

sf::Sprite Jogador::get_sprite_mao_inseto(int pos) const {
    if(pos >= 0 && pos < mao.size() && mao[pos] != nullptr) {
        return mao[pos]->get_sprite_inseto();
    }
    throw std::out_of_range("Carta inválida na mão");
}


int Jogador::get_numCartas() const{
    return mao.size();
}

void Jogador::remover_carta(Carta* carta) {
    auto it = std::find(mao.begin(), mao.end(), carta);
    if (it != mao.end()) {
        cartas_derrotadas.push_back(*it); // Adicionar à lista de derrotadas
        mao.erase(it);
    }
}

void Jogador::aumentar_dano_cartas(int bonus, Carta* excecao) {
    for (Carta* carta : mao) {
        if (carta != excecao && carta != nullptr) {
            carta->modificar_dano(bonus);
        }
    }
}

void Jogador::aumentar_velocidade_cartas(int bonus, Carta* excecao) {
    for (Carta* carta : mao) {
        if (carta != excecao && carta != nullptr) {
            carta->modificar_velocidade(bonus);
        }
    }
}

void Jogador::set_oponente(Jogador* oponente) {
    this->oponente = oponente;
}

Jogador* Jogador::get_oponente() const {
    return oponente;
}

int Jogador::get_num_cartas_derrotadas() const {
    return cartas_derrotadas.size();
}

Jogador::~Jogador() {
    for(auto carta : mao)
        delete carta;
}