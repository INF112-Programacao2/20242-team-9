#include "AbelhaOperaria.h"

AbelhaOperaria::AbelhaOperaria(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Abelha(coordsCarta){
    nome = "Abelha Operaria";
    dano = 5;
    vida = 30;
    velocidade = 25;
    efeito = 0;
    caminho = "assets/insects/abelha_operaria.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}

// Definição do método fora do construtor
void AbelhaOperaria::aplicar_efeito_pos_ataque(Carta* inimigo) {
    std::cout << "ENTROU APLICAR EFEITO POS ABELHA OPERARIA" << std::endl;
    vida += 1;
    std::cout << nome << " recuperou 1 ponto de vida (Vida atual: " << vida << ")." << std::endl;
}