#ifndef SPRITE_HPP_INCLUDED
#define SPRITE_HPP_INCLUDED
#include "SFML/Graphics.hpp"
#include "GameObject.hpp"

class Sprite : public GameObject
{
public:
    void Update();
    void Render(sf::RenderWindow& window);
    void SetSprite(const sf::Sprite& new_sprite);
    void SetSprite(std::string filename);

private:
    sf::Sprite sprite;

};

#endif // SPRITE_HPP_INCLUDED

