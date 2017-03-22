#include "Sprite.hpp"

void Sprite::Update()
{
    sprite.move(1,1);
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
