#include "Sprite.hpp"

Sprite::Sprite(PlayerController& ext_controller) :
    controller(ext_controller)
{
    speed = 5;
}

void Sprite::Update()
{
    if (controller.left_pressed)
        Move(-speed,0);
    if (controller.right_pressed)
        Move(speed,0);
    if (controller.up_pressed)
        Move(0,-speed);
    if (controller.down_pressed)
        Move(0,speed);
}

void Sprite::Render(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Sprite::SetSprite(const sf::Sprite& new_sprite)
{
    sprite = new_sprite;
}

void Sprite::SetSprite(std::string filename)
{
    sf::Texture temp_tex;
    temp_tex.loadFromFile(filename);

    sprite.setTexture(temp_tex);

    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
}

void Sprite::Move(int x, int y)
{
    sprite.move(x, y);
}
void Sprite::Move(sf::Vector2i move_vector)
{
    sprite.move(move_vector.x, move_vector.y);
}
