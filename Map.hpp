#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <fstream>
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "ResourcesManager.hpp"

extern ResourcesManager resources;

class Map
{
public:
    Map();
    Map(std::string tileset_name, int tile_size);
    void Update();
    void Render(sf::RenderWindow& window);
    void LoadFromFile(std::string filename);

private:
    std::vector<sf::Texture> layers_textures;
    std::string tileset_name;
    int tile_size;

};

#endif // MAP_HPP_INCLUDED
