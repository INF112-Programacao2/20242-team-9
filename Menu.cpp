#include "Menu.h"

sf::Color darkYellow(139, 120, 0);
sf::Color darkGreen(0, 100, 0);

Menu::Menu(sf::RenderWindow* janela) 
    : window(janela), pos(2), escolhido(false), selecionado(false), estadoAtual(EstadoJogo::Menu) {
        try{
            carrega_fonte();
            carrega_fundoRegras();
            carrega_fundoMenu();
            carrega_spriteSetas();
        } catch(std::runtime_error &e){
            std::cout << e.what() << std::endl;
        } catch(std::exception &e){
            std::cout << e.what() << std::endl;
        }
        inicializa_menu();
}

bool Menu::is_setaDir_on_click(float x, float y){
    return setaDir.getGlobalBounds().contains(x, y);
}
bool Menu::is_setaEsq_on_click(float x, float y){
    return setaDir.getGlobalBounds().contains(x, y);
}
void Menu::carrega_fonte(){
    fonte = new sf::Font();
    if (!fonte->loadFromFile("assets/fonts/fonte_menu.ttf")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }
}

void Menu::carrega_fundoRegras(){
    if (!texturaRegras1.loadFromFile("assets/backgrounds/regras_background.png")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    fundoRegras1.setTexture(texturaRegras1);
    fundoRegras1.setPosition(0, 0);
}

void Menu::carrega_fundoMenu(){
    if(!texturaMenu.loadFromFile("assets/backgrounds/menu_background.png")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    fundoMenu.setTexture(texturaMenu);
    fundoMenu.setPosition(0,0);
}

Menu::~Menu() {
    delete fonte;
}

void Menu::carrega_spriteSetas(){
    if(!txtSetaDir.loadFromFile("assets/icons/seta_dir.png")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    if(!txtSetaEsq.loadFromFile("assets/icons/seta_esquerda.png")){
        throw std::runtime_error("Erro ao carregar a textura!");
    }
    setaDir.setTexture(txtSetaDir);
    setaEsq.setTexture(txtSetaEsq);
    setaDir.setPosition(1200, 700);
    setaEsq.setPosition(168, 700);
}

void Menu::inicializa_menu() {
    opcoes = {"INSECTTLE", "INSECTTLE", "Jogar", "Jogar", "Opcoes", "Opcoes", "Regras", "Regras", "Sair", "Sair"};
    textos.resize(10);
    coordsTexto = {{546, 43},{543, 40}, {613, 194},{610, 191}, {603, 285},{600, 282}, {603, 373},{600, 370}, {626,460},{623, 457}};
    tamTexto = {30, 30, 24, 24, 24, 24, 24, 24, 24, 24};
    
    for(std::size_t i = 0; i < textos.size(); i++) {
        textos[i].setFont(*fonte);
        textos[i].setString(opcoes[i]);
        textos[i].setCharacterSize(tamTexto[i]);        
        textos[i].setPosition(coordsTexto[i]);
        
        if(i == 0) {
            textos[i].setFillColor(sf::Color(135, 115, 199));  // Purple
        } else if(i == 1) {
            textos[i].setFillColor(sf::Color::Cyan);
        } else if(i == 2 || i == 3) {
            textos[i].setFillColor(i % 2 == 0 ? darkGreen : sf::Color::Green);
        } else {
            textos[i].setFillColor(i % 2 == 0 ? darkYellow : sf::Color::Yellow);
        }
    }
}

void Menu::run_menu() {
    estadoAtual = EstadoJogo::Menu;
    while(window->isOpen() && estadoAtual == EstadoJogo::Menu) {
        loop_eventos();
        desenhar();
    }
}


void Menu::loop_eventos(){
    sf::Event evento;
    while(window->pollEvent(evento)){
        if(evento.type == sf::Event::Closed){
            window->close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !selecionado){
            if(pos<8){
                pos+=2;
                selecionado = true;
                textos[pos].setFillColor(darkGreen);
                textos[pos+1].setFillColor(sf::Color::Green);
                if(pos-1!=1 && pos-2!=0){
                    textos[pos-2].setFillColor(darkYellow);
                    textos[pos-1].setFillColor(sf::Color::Yellow);
                }
                selecionado = false;
                escolhido = false;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !selecionado){
            if(pos>3){
                pos-=2;
                selecionado = true;
                textos[pos+1].setFillColor(sf::Color::Green);
                textos[pos].setFillColor(darkGreen);

                textos[pos + 2].setFillColor(darkYellow);
                textos[pos + 3].setFillColor(sf::Color::Yellow);
                selecionado = false;
                escolhido = false;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !escolhido){
            escolhido = true;
            if(pos == 8){
                estadoAtual = EstadoJogo::Menu;
                window->close();
            }
            else if(pos == 2){
                estadoAtual = EstadoJogo::Jogando;
            } else if(pos == 4){
                estadoAtual = EstadoJogo::Opcoes;
            }
            else if(pos ==6){
                estadoAtual = EstadoJogo::Regras;
            }
        }
    }
}

void Menu::desenhar(){
    window->clear();
    window->draw(fundoMenu);
    for(auto t : textos){
        window->draw(t);
    }
    window->display();
}

bool Menu::is_jogar_selecionado(){
    return estadoAtual == EstadoJogo::Jogando;
}

bool Menu::is_opcoes_selecionado(){
    return estadoAtual == EstadoJogo::Opcoes;
}

bool Menu::is_regras_selecionado(){
    return estadoAtual == EstadoJogo::Regras;
}