#ifndef RESOURCES_MANAGER_HPP_INCLUDED
#define RESOURCES_MANAGER_HPP_INCLUDED

#include <map>
#include <vector>
#include "SFML/Graphics.hpp"

class ResourcesManager
{
public:
    ResourcesManager() {};
    void LoadTilesetFromFile(std::string name,const int tile_size);
    sf::Texture& GetTileTexture(const std::string tileset_name, const int number);

private:
    std::map<std::string, std::vector<sf::Texture>> tileset_textures;
};

#endif // RESOURCES_MANAGER_HPP_INCLUDED
