#include "Settings.hpp"

Settings::Settings()
{
	window_size = sf::Vector2i(800, 600);
	LoadFromFile("settings");
}

Settings::Settings(unsigned int x,unsigned int y)
{
	window_size = sf::Vector2i(x, y);
}

sf::Vector2i Settings::GetWindowSize() const
{
	return window_size;
}

void Settings::SetWindowSize(sf::Vector2i new_size)
{
    if(new_size.x >= 0 && new_size.y >= 0)
        window_size = new_size;
}

void Settings::LoadFromFile(std::string filename)
{
    std::fstream file;

    file.open(filename, std::ios::in);
    if(file.is_open())
    {
        std::string line;
        int setting_number = 0;
        int x = 0;
        int y = 0;
        while(getline(file, line))
        {
            if(line[0] != '#')
            {
                switch(setting_number)
                {
                case 0:
                    x = std::stoi(line);
                break;
                case 1:
                    y = std::stoi(line);
                break;
                }
                setting_number++;
            }
        }
        window_size = sf::Vector2i(x, y);
        std::cout<<std::to_string(x)<<", "<<std::to_string(y)<<std::endl;
    }

    file.close();
}


