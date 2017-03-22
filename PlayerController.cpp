#include "PlayerController.hpp"

PlayerController::PlayerController(
    sf::Keyboard::Key left_key,
    sf::Keyboard::Key right_key,
    sf::Keyboard::Key up_key,
    sf::Keyboard::Key down_key)
{
    this->left_key = left_key;
    this->right_key = right_key;
    this->up_key = up_key;
    this->down_key = down_key;
}

void PlayerController::HandleEvent(sf::Event event)
{
    left_pressed = sf::Keyboard::isKeyPressed(left_key);
    right_pressed = sf::Keyboard::isKeyPressed(right_key);
    up_pressed = sf::Keyboard::isKeyPressed(up_key);
    down_pressed = sf::Keyboard::isKeyPressed(down_key);
}
