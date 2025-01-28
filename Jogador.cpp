#include "Jogador.h"

Jogador::Jogador(): cartaSelecionada(0), isCardFighting(false), numTrocas(0), numCartasVivas(5){
    std::srand(std::time(nullptr));
    inicializa_jogador();
}

bool Jogador::verifica_carta_morta(int pos){
    return mao[pos]->is_dead();
}

void Jogador::put_card_on_board(){
    isCardFighting = true;
}
void Jogador::take_card_from_board(){
    isCardFighting = false;
}
void Jogador::set_morte(int pos){
    mao[pos]->set_dead();
    numCartasVivas-=1;
}
void Jogador::inicializa_jogador() {
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

Carta* Jogador::getCarta(int pos){
    return mao[pos];
} 

sf::Sprite Jogador::get_sprite_mao_carta(int pos) {
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

Jogador::~Jogador() {
    for(auto carta : mao)
        delete carta;
}