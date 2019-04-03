#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#ifndef BULLET_H
#define BULLET_H


class Bullet
{

public:

    sf::CircleShape shape;
    sf::Vector2f currVelocity;
    float maxSpeed;

    Bullet(float radius = 5.f): currVelocity(0.f,0.f), maxSpeed(15.f)

    {
        this-> shape.setRadius(radius);
        this-> shape.setFillColor(sf::Color::Red);
    }
};

#endif // BULLET_H
