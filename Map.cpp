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
    /*for (int i = 0; i< height; i++)
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
    }*/
    if (!layers_textures.empty())
    {
        for (sf::Texture tex : layers_textures)
        {
            temp_sprite.setTexture(tex);
            window.draw(temp_sprite);
        }
    }
}

void Map::LoadFromFile(std::string name)
{
    std::fstream file;
    std::string filename = "maps/" + name +".csv";


    file.open(filename, std::ios::in);
    while (file.good())
    {
        std::vector<int> tile_numbers;
        int width = 0;
        int height = 0;
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

            //Create layer texture
            sf::Texture temp_tex;
            temp_tex.create(width * tile_size, height * tile_size);
            for (int i = 0; i< height; i++)
            {
                for (int j = 0; j< width; j++)
                {
                    if (tile_numbers[i*width+j] >= 0)
                    {
                        sf::Image temp_image = resources.GetTileTexture(tileset_name, tile_numbers[i*width+j]).copyToImage();
                        temp_tex.update(temp_image, j * tile_size, i * tile_size);
                    }
                }
            }
            layers_textures.push_back(temp_tex);
        }
        file.close();

        int layer_number = stoi(filename.substr(filename.rfind("l") + 1 ,(filename.size() - 4) - (filename.rfind("l") + 1)));
        layer_number++;
        std::string temp_filename = filename.substr(0, filename.rfind("l") + 1) + std::to_string(layer_number) + ".csv";
        filename = temp_filename;
        file.open(filename, std::ios::in);
    }
    /*
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

        //Create layer texture
        sf::Texture temp_tex;
        temp_tex.create(width * tile_size, height * tile_size);
        for (int i = 0; i< height; i++)
        {
            for (int j = 0; j< width; j++)
            {
                if (tile_numbers[i*width+j] >= 0)
                {
                    sf::Image temp_image = resources.GetTileTexture(tileset_name, tile_numbers[i*width+j]).copyToImage();
                    temp_tex.update(temp_image, j * tile_size, i * tile_size);
                }
            }
        }
        layers_textures.push_back(temp_tex);
    }
    file.close();*/
}
