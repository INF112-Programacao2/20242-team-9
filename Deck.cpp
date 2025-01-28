#include "Deck.h"

Deck::Deck() {
    sortear_deck();
}

Deck::~Deck(){
    for(auto carta : cartasEscolhidas){
        delete carta;
    }
}

void Deck::sortear_deck() {
    std::vector<Tipo> tiposPossiveis = { 
        Tipo::AbelhaRainha, Tipo::AbelhaOperaria, Tipo::Barata, Tipo::Besouro, 
        Tipo::CupimRei, Tipo::CupimSoldado, Tipo::Cigarra, Tipo::LouvaDeus, 
        Tipo::Gafanhoto, Tipo::FormigaRainha, Tipo::FormigaZangao
    };
    std::vector<int> numerosSorteados;
    
    // Primeiro sorteia os números
    while (numerosSorteados.size() < numCartas) {
        int numero = std::rand() % tiposPossiveis.size();
        if (std::find(numerosSorteados.begin(), numerosSorteados.end(), numero) == numerosSorteados.end()) {
            numerosSorteados.push_back(numero);
        }
    }
    
    // Depois converte os tipos
    for(int i = 0; i < numCartas; i++) {
        converte_tipo(tiposPossiveis[numerosSorteados[i]], i);
    }
}

void Deck::converte_tipo(Tipo tipo, int pos){
    Carta *temp = new Carta();
    sf::Vector2f coordsCarta = temp->get_coords_carta(pos);
    sf::Vector2f coordsInseto = temp->get_coords_inseto(pos);
    
    if(tipo == Tipo::AbelhaRainha){
        cartasEscolhidas.emplace_back(new AbelhaRainha(coordsCarta, coordsInseto));
    }
    else if(tipo == Tipo::AbelhaOperaria){
        cartasEscolhidas.emplace_back(new AbelhaOperaria(coordsCarta, coordsInseto));
    } 
    else if (tipo == Tipo::Barata){
        cartasEscolhidas.emplace_back(new Barata(coordsCarta, coordsInseto));
    } 
    else if (tipo == Tipo::Besouro){
        cartasEscolhidas.emplace_back(new Besouro(coordsCarta, coordsInseto));
    } 
    else if (tipo == Tipo::CupimRei){
        cartasEscolhidas.emplace_back(new CupimRei(coordsCarta, coordsInseto));
    } 
    else if (tipo == Tipo::CupimSoldado){
        cartasEscolhidas.emplace_back(new CupimSoldado(coordsCarta, coordsInseto));
    } 
    else if (tipo == Tipo::Cigarra){
        cartasEscolhidas.emplace_back(new Cigarra(coordsCarta, coordsInseto));
    } 
    else if (tipo == Tipo::LouvaDeus){
        cartasEscolhidas.emplace_back(new LouvaDeus(coordsCarta, coordsInseto));
    } 
    else if (tipo == Tipo::Gafanhoto){
        cartasEscolhidas.emplace_back(new Gafanhoto(coordsCarta, coordsInseto));
    } 
    else if (tipo == Tipo::FormigaRainha){
        cartasEscolhidas.emplace_back(new FormigaRainha(coordsCarta, coordsInseto));
    } 
    else if (tipo == Tipo::FormigaZangao){
        cartasEscolhidas.emplace_back(new FormigaZangao(coordsCarta, coordsInseto));
    }
    delete temp;
}

Carta* Deck::get_carta_deck(int pos) const {
    if(pos >= 0 && pos < cartasEscolhidas.size()) {
        return cartasEscolhidas[pos];
    }
    throw std::out_of_range("Posição inválida no deck");
}