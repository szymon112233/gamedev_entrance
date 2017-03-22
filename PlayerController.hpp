#ifndef PLAYERCONTROLLER_HPP_INCLUDED
#define PLAYERCONTROLLER_HPP_INCLUDED
#include "SFML/Window.hpp"

class PlayerController
{
public:
    PlayerController() {}
    PlayerController(
        sf::Keyboard::Key left_key,
        sf::Keyboard::Key right_key,
        sf::Keyboard::Key up_key,
        sf::Keyboard::Key down_key);

    void HandleEvent(sf::Event event);
    bool left_pressed = false;
    bool right_pressed = false;
    bool up_pressed = false;
    bool down_pressed = false;

private:
    sf::Keyboard::Key left_key;
    sf::Keyboard::Key right_key;
    sf::Keyboard::Key up_key;
    sf::Keyboard::Key down_key;
};

#endif // PLAYERCONTROLLER_HPP_INCLUDED
