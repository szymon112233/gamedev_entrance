#include "ResourcesManager.hpp"

void ResourcesManager::LoadTilesetFromFile(std::string name,const int tile_size)
{
    sf::Image tileset;
    std::string filename = "sprites/tiles/" + name + ".png";
    if (tileset.loadFromFile(filename))
    {
        tileset_textures.emplace(name, std::vector<sf::Texture>());
        int size_x = tileset.getSize().x / tile_size;
        int size_y = tileset.getSize().y / tile_size;
        sf::Texture temp_tex;
        for (int i = 0 ; i < size_y ; i++)
        {
            for (int j = 0 ; j < size_x ; j++)
            {
                temp_tex.loadFromImage(tileset, sf::Rect<int>(j * tile_size, i * tile_size, tile_size, tile_size));
                tileset_textures[name].push_back(temp_tex);
            }
        }

    }
}

sf::Texture& ResourcesManager::GetTileTexture(const std::string tileset_name, const int number)
{
    auto found = tileset_textures.find(tileset_name);
    if (found != tileset_textures.end())
    {
        return tileset_textures[tileset_name][number];
    }
}
