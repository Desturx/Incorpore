
#include "juego.h"

juego::juego()
{
    window = new sf::RenderWindow(sf::VideoMode(800,600), "HUD");

    cargar_hud();

    gameloop();
}

void juego::gameloop()
{
    while(window->isOpen())
    {
        procesareventos();

        render();
    }
}

void juego::procesareventos()
{
    while(window->pollEvent(*evento))
    {
        switch(evento->type)
        {
            case sf::Event::KeyPressed:
                ///VIDA
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    hud_principal->modificar_vida(1,1);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    hud_principal->modificar_vida(1,2);
                }

                ///HABILIDADES
                //borrar todas las habilidades
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    hud_principal->borradoHabilidades();
                }
                //coger habilidades
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
                {
                    hud_principal->setHabilidad(1);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                {
                    hud_principal->setHabilidad(2);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
                {
                    hud_principal->setHabilidad(3);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                {
                    hud_principal->setHabilidad(4);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
                {
                    hud_principal->setHabilidad(5);
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                {
                    hud_principal->setHabilidad(6);
                }
            break;
        }
    }
}

void juego::cargar_hud()
{
    hud_principal = new hud;
    evento = new sf::Event;
}

void juego::render()
{
    window->clear();

    window->draw(hud_principal->getPiezaVida());
    window->draw(hud_principal->getPiezaHabilidades());

    window->draw(hud_principal->getTextoVida());

    for(int i = 0; i < hud_principal->getCantidadVida(); i++)
    {
        window->draw(hud_principal->getArrayVida().at(i));
    }

    for(int i = 0; i < hud_principal->getCantidadHabilidades(); i++)
    {
        window->draw(hud_principal->getArrayHabilidades().at(i));
    }

    window->display();
}
