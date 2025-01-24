#include "Jogador.h"

Jogador::Jogador(unsigned int coordX, unsigned int coordY){
    std::srand(std::time(nullptr));
    inicializa_jogador(coordX, coordY);
    carrega_barra(coordX, coordY);
}

void Jogador::inicializa_jogador(unsigned int coordX, unsigned int coordY) {
    try {
        
        for (int i = 0; i < 5; i++) {
            mao.emplace_back(deck.get_carta_deck(i)); // Constrói a Carta no vetor
        }
        Carta::player = 2;

    } catch (std::runtime_error &e) {
        std::cerr << "Erro ao inicializar o jogador: " << e.what() << std::endl;
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

sf::Sprite Jogador::get_sprite_mao_carta(int pos) const {
    if(pos >= 0 && pos < mao.size() && mao[pos] != nullptr) {
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

Jogador::~Jogador() {
    for(auto carta : mao)
        delete carta;
}