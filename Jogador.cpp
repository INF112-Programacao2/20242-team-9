#include "Jogador.h"

Jogador::Jogador(int playerNumber): cartaSelecionada(0), isCardFighting(false), numCartasVivas(5){
    std::srand(std::time(nullptr));
    Carta::player = playerNumber;
    inicializa_jogador();
}

bool Jogador::verifica_carta_morta(int pos) const{
    return mao[pos]->is_dead();
}

// Em Jogador.cpp
void Jogador::remover_carta(int pos) {
    if (pos < 0 || pos >= mao.size()) {
        std::cerr << "ERRO: Posição inválida para remover carta: " << pos << std::endl;
        return;
    }
    
    // Com unique_ptr, a carta será deletada automaticamente
    mao.erase(mao.begin() + pos);
    std::cout << "Carta removida. Número de cartas restantes: " << mao.size() << std::endl;
}


void Jogador::aumentar_dano_cartas(int bonus, Carta* excecao) {
    for (auto& carta : mao) {
        if (carta && carta.get() != excecao && !carta->is_dead()) {
            carta->modificar_dano(bonus);
        }
    }

}

void Jogador::aumentar_velocidade_cartas(int bonus, Carta* excecao) {
    for (auto& carta : mao) {
        if (carta && carta.get() != excecao && !carta->is_dead()) {
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
        std::cout << "Inicializando jogador com player number: " << Carta::player << std::endl;
        for (int i = 0; i < 5; i++) {
            // Criar unique_ptr e transferir ownership
            mao.emplace_back(deck.get_carta_deck(i));
            if (mao.back()) {
                mao.back()->set_jogador(this);
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao inicializar o jogador: " << e.what() << std::endl;
    }
}

Carta* Jogador::getCarta(int pos) {
    if (pos >= 0 && pos < mao.size()) {
        return mao[pos].get();  // Retorna raw pointer para compatibilidade
    }
    return nullptr;
}


sf::Sprite Jogador::get_sprite_mao_inseto(int pos) const {
    if (pos >= 0 && pos < mao.size() && mao[pos]) {
        return mao[pos]->get_sprite_inseto();
    }
    throw std::out_of_range("Carta inválida na mão");
}

sf::Sprite Jogador::get_sprite_mao_carta(int pos) const {

    if (pos >= 0 && pos < mao.size() && mao[pos]) {
        return mao[pos]->get_sprite_carta();
    }
    throw std::out_of_range("Carta inválida na mão");
}

int Jogador::get_numCartas() const{
    return numCartasVivas;
}

Jogador::~Jogador() {
    // unique_ptr limpa automaticamente a memória
    delete oponente;
}