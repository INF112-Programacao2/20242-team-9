#include "MonteCarta.h"

MonteCarta::MonteCarta(){
    try{
        carta.carregar_carta_monte();
        std::cout << "CARREGOU O MONTE DE CARTAS" << std::endl;
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}

sf::Sprite MonteCarta::get_sprite(){
    return carta.get_sprite();
}