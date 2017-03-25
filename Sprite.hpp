#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED

#include "SFML/Graphics.hpp"
#include "GameObject.hpp"
#include "PlayerController.hpp"

class Sprite : public GameObject
{
public:
    Sprite();
    Sprite(PlayerController* ext_controller);
    void Update();
    void Render(sf::RenderWindow& window);
    void SetSprite(const sf::Sprite& new_sprite);
    void SetSprite(std::string filename);
    void Move(int x, int y);
    void Move(sf::Vector2i move_vector);
    PlayerController* controller;

private:
    sf::Sprite sprite;
    int speed;

};

#endif // SPRITE_HPP_INCLUDED

