#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <fstream>
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

class Map
{
public:
    Map();
    void Update();
    void Render(sf::RenderWindow& window);
    void LoadFromFile(std::string filename);

private:
    std::vector<sf::Texture> tiles_textures;
    std::vector<sf::Sprite> tiles;
    int width = 0;
    int height = 0;

};

#endif // MAP_HPP_INCLUDED
