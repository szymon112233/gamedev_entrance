#ifndef BASESTATE_HPP_INCLUDED
#define BASESTATE_HPP_INCLUDED

#include "SFML/Graphics.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "PlayerController.hpp"
#include "Map.hpp"

class Engine;

class BaseState
{
public:
    BaseState(Engine& engine_ref) : engine(engine_ref) {}
    virtual void Update() = 0;
    virtual void Render(sf::RenderWindow& window) = 0;
    virtual void HandleEvents(sf::Event& event) = 0;
protected:
    Engine& engine;
};


#endif // BASESTATE_HPP_INCLUDED
