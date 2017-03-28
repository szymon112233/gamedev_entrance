#include "Map.hpp"

Map::Map()
{
    tileset_name = "test_tileset";
    tile_size = 32;
    resources.LoadTilesetFromFile("test_tileset", 32);
}
Map::Map(std::string tileset_name, int tile_size)
{
    this->tileset_name = tileset_name;
    this->tile_size = tile_size;
    resources.LoadTilesetFromFile(tileset_name, tile_size);
}

void Map::Update()
{

}
void Map::Render(sf::RenderWindow& window)
{
    sf::Sprite temp_sprite;
    for (int i = 0; i< height; i++)
    {
        for (int j = 0; j< width; j++)
        {
            if (tile_numbers[i*width+j] >= 0)
            {
                temp_sprite.setTexture(resources.GetTileTexture(tileset_name, tile_numbers[i*width+j]));
                temp_sprite.setPosition(j * tile_size, i * tile_size);
                window.draw(temp_sprite);
            }
        }
    }
}
void Map::LoadFromFile(std::string name)
{
    std::fstream file;
    std::string filename = "maps/" + name +".csv";

    file.open(filename, std::ios::in);
    if(file.is_open())
    {
        std::string line;
        int rows = 0;

        while(getline(file, line))
        {
            rows++;
            int collumns = 0;

            int prev_pos = 0;
            int curr_pos = 0;
            do
            {
                collumns++;
                curr_pos = line.find(",", prev_pos);
                int number = std::stoi(line.substr(prev_pos, curr_pos - prev_pos));
                tile_numbers.push_back(number);
                prev_pos = ++curr_pos;
            }
            while(line.find(",", prev_pos) != std::string::npos);

            if (width < collumns)
                width = collumns;

        }
        height = rows;
    }
    file.close();
}
