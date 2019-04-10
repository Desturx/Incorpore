
#include "menu.h"

menu::menu()
{
    fuente = new sf::Font;
    fuente->loadFromFile("src/manaspc.ttf");
    jugar = new sf::Text;
    opciones = new sf::Text;
    salir = new sf::Text;

    //titulo
    titulofuente = new sf::Font;
    titulofuente->loadFromFile("src/never.ttf");
    titulo = new sf::Text;
    titulo->setFont(*titulofuente);
    titulo->setString("INCORPORE");
    titulo->setCharacterSize(150);
    //titulo->setPosition({500,50});
    titulo->setPosition({500,100});
    titulo->setScale(0.9,0.9);
    titulo->setColor(sf::Color::White);

    //fuente
    jugar->setFont(*fuente);
    opciones->setFont(*fuente);
    salir->setFont(*fuente);

    //color
    jugar->setColor(sf::Color::White);
    opciones->setColor(sf::Color::White);
    salir->setColor(sf::Color::White);

    //strings
    jugar->setString("Jugar");
    opciones->setString("Opciones");
    salir->setString("Salir");

    //fondo
    texfondo = new sf::Texture();
    //texfondo->loadFromFile("src/menu2.jpeg");
    texfondo->loadFromFile("src/fondoMenu.png");
    sprfondo = new sf::Sprite;
    sprfondo->setTexture(*texfondo);
    sprfondo->setOrigin(sprfondo->getGlobalBounds().width/2,sprfondo->getGlobalBounds().height/2);
    sprfondo->setPosition(1280/2,720/2);

    //fondo opciones
    texopciones = new sf::Texture();
    texopciones->loadFromFile("src/controles.png");
    spropciones = new sf::Sprite;
    spropciones->setTexture(*texopciones);

    //posicion
    /*
    jugar->setPosition({1280/2-35,350});
    opciones->setPosition({1280/2- 35,450});
    salir->setPosition({1280/2-35,550});
    */
    jugar->setPosition({1280/2-35,350});
    opciones->setPosition({1280/2-35,450});
    salir->setPosition({1280/2-35,550});

    botones = new std::vector<sf::Text>;
    for(int i = 0; i < 3; i++)
    {
        if(i ==0)
        botones->push_back(*jugar);

        if(i ==1)
        botones->push_back(*opciones);

        if(i ==2)
        botones->push_back(*salir);
    }
}


///GETTERS
sf::Sprite menu::getFondo()
{
    return *sprfondo;
}

sf::Sprite menu::getFondOpciones()
{
    return *spropciones;
}

sf::Text menu::getTitulo()
{
    return *titulo;
}

std::vector<sf::Text> menu::getOpciones()
{
    return *botones;
}

int menu::opcion_seleccionada()
{
    return seleccion;
}

///SETTERS
void menu::setOpcionMenu(int num)
{
    if(num == 0)
    {
       seleccion = 0;
    }
    if(num == 1)
    {
       seleccion = 1;
    }
    if(num == 2)
    {
       seleccion = 2;
    }
}

void menu::setColorOp()
{
    botones->clear();

    if(seleccion ==0)
    {
        jugar->setColor(sf::Color::Red);
        jugar->setScale(1.4,1.4);
       opciones->setColor(sf::Color::White);
       opciones->setScale(1,1);
       salir->setColor(sf::Color::White);
       salir->setScale(1,1);
    }
    else if(seleccion ==1)
    {
        jugar->setColor(sf::Color::White);
        jugar->setScale(1,1);
       opciones->setColor(sf::Color::Red);
       opciones->setScale(1.4,1.4);
       salir->setColor(sf::Color::White);
         salir->setScale(1,1);
    }
    else if(seleccion ==2)
    {
        jugar->setColor(sf::Color::White);
        jugar->setScale(1,1);
       opciones->setColor(sf::Color::White);
       opciones->setScale(1,1);
       salir->setColor(sf::Color::Red);
        salir->setScale(1.4,1.4);

    }

    for(int i = 0; i < 3; i++)
    {
        if(i ==0)
        botones->push_back(*jugar);

        if(i ==1)
        botones->push_back(*opciones);

        if(i ==2)
        botones->push_back(*salir);
    }
}

void menu::setPosicion(int num, int x, int y)
{
    if(num == 0)
    {
        jugar->setPosition({x,y});
    }
    if(num == 1)
    {
        opciones->setPosition({x,y});
    }
    if(num == 2)
    {
        salir->setPosition({x,y});
    }
}






