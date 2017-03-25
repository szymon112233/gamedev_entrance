#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

#include "SFML/System.hpp"
#include <iostream>
#include <fstream>
#include <string>

class Settings
{
public:
	Settings();
	Settings(unsigned int x,unsigned int y);
	sf::Vector2i GetWindowSize() const;
	void SetWindowSize(sf::Vector2i new_size);
	void LoadFromFile(std::string filename);

private:
	sf::Vector2i window_size;
};

#endif // SETTINGS_HPP_INCLUDED
