#include "Map.hpp"

Map::Map()
{
    int tile_number = 0;
    std::string tile_filename = "sprites/tiles/" + std::to_string(tile_number) + ".png";
    sf::Texture temp_tex;
    while (temp_tex.loadFromFile(tile_filename))
    {
        tiles_textures.push_back(temp_tex);
        tile_number++;
        tile_filename = "sprites/tiles/" + std::to_string(tile_number) + ".png";
    }
}

void Map::Update()
{

}
void Map::Render(sf::RenderWindow& window)
{
    for (sf::Sprite& tile : tiles)
    {
        window.draw(tile);
    }
}
void Map::LoadFromFile(std::string filename)
{
    std::fstream file;

    file.open(filename, std::ios::in);
    if(file.is_open())
    {
        std::string line;
        int rows = 0;
        while(getline(file, line))
        {
            std::cout<<line<<std::endl;
            if(line[0] != '#')
            {
                for(int i = 0; i < line.size(); i++)
                {
                    int texture_number = (int)line[i] - 48;

                    tiles.push_back(sf::Sprite(tiles_textures[texture_number]));
                    tiles.back().setPosition(i*32,rows * 32);
                }
                rows++;
            }
        }
    }

    file.close();
}
