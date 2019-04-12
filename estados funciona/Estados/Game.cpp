#include "Game.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "maquina estados");
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}


Game::Game()
{
this->initWindow();
this->initKeys();
this->initStates();

}

Game::~Game()
{
    delete this->window;

    while(!this->states.empty())
    {

      delete this->states.top();
    this->states.pop();
    }
}

void Game::initKeys()
{
    this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
    this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
    this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
    this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
    this->supportedKeys.emplace("S", sf::Keyboard::Key::S);
  //  this->supportedKeys.emplace("Space", sf::Keyboard::Key::Space);

}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys));
    //pushea el primer estado del juego
    //this->states.push(new GameState(this->window, &this->supportedKeys));
}

void Game::updateDt()
{
//actualiazr la variable dt que es tiempo delta, que es el tiempo que tarda en renderizar 1 frame
   // this->updateSFMLEvents();
   this->dt = this->dtClock.restart().asSeconds();

}


void Game::updateSFMLEvents()
{
    while(this->window->pollEvent(this->sfEvent))
    {
        if(this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();

         if(!this->states.empty())
         {
                this->states.top()->update(this->dt);
                if(this->states.top()->getQuit())
                {
                    //en stacks el top es el ultimo insertado en el vector
                    this->states.top()->endState();
                    delete this->states.top();
                    this->states.pop();
                }
            }
            //acaba el programa
            else
            {
                this->endApplication();
                this->window->close();
            }
}


void Game::render()
{
    this->window->clear();

            if(!this->states.empty())
                this->states.top()->render();

    this->window->display();
}

void Game::run()
{
    while(this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }

}
void Game::endApplication()
{
    std::cout <<"Acabando juego" << "\n";
}

