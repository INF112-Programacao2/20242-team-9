#include "Gafanhoto.h"

Gafanhoto::Gafanhoto(sf::Vector2f coordsCarta, sf::Vector2f coordsInseto): Carta(coordsCarta){
    dano = 12;       
    vida = 30;
    vidaOriginal = 30;       
    velocidade = 40;  
    efeito = 10;     // Efeito 10: Pode pular o ataque do oponente uma vez por partida
    efeitoGafanhotoUsado = false;
    caminho = "assets/insects/gafanhoto.png";
    carrega_icone_inseto(coordsInseto, caminho);
    carregar_carta_frente(coordsCarta);
}