#ifndef JUGADOR_H
#define JUGADOR_H
#include <SFML/Graphics.hpp>

class Jugador
{
    public:
        Jugador();
        virtual ~Jugador();
        void dibujar(sf::RenderWindow w);
        void mover(int x, int y,sf::Clock c);
        sf::Sprite getSprite();
        float *getPos();

    protected:

    private:
        sf::Texture *textura;
        sf::Sprite *sprite;
        float pos[2];
};

#endif // JUGADOR_H