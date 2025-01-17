#include "Deck.h"

Carta Deck::sortear_carta(){
    std::srand(std::time(0));
    int numeroSorteado = std::rand() % numCartas;
    return cartasPossiveis[numeroSorteado];
}

void Deck::sortear_tipos(){
    std::vector<Tipo> tipos = {
        Tipo::Abelha, Tipo::Barata, Tipo::Besouro, Tipo::Cupim, 
        Tipo::Cigarra, Tipo::LouvaDeus, Tipo::Gafanhoto, Tipo::Formiga
    };

    // Configura o gerador de números aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());

    // Embaralha os tipos
    std::shuffle(tipos.begin(), tipos.end(), gen);

    // Seleciona os 5 primeiros após o embaralhamento
    std::vector<Tipo> sorteados(tipos.begin(), tipos.begin() + 5);
}