#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

#include "SFML/System.hpp"

class Settings
{
public:
	Settings();
	Settings(unsigned int x,unsigned int y);
	sf::Vector2i GetWindowSize() const;

private:
	sf::Vector2i window_size;
};

#endif // SETTINGS_HPP_INCLUDED
