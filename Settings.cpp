#include "Settings.hpp"

Settings::Settings()
{
	window_size = sf::Vector2i(500, 500);
}

Settings::Settings(unsigned int x,unsigned int y)
{
	window_size = sf::Vector2i(x, y);
}

sf::Vector2i Settings::GetWindowSize() const
{
	return window_size;
}


