#include "MonteCarta.h"

MonteCarta::MonteCarta(){
    carta.carregar_carta_monte();
}

sf::Sprite MonteCarta::get_sprite(){
    return carta.get_sprite();
}