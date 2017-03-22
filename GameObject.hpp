#ifndef GAMEOBJECT_HPP_INCLUDED
#define GAMEOBJECT_HPP_INCLUDED
#include "SFML/Graphics.hpp"

class GameObject
{
public:
    virtual void Update() = 0;
    virtual void Render(sf::RenderWindow& window) = 0;
};

#endif // GAMEOBJECT_HPP_INCLUDED
