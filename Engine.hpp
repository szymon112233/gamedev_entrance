#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Settings.hpp"

class Engine
{
public:
	Engine();
	void Update();
	void Render();
	void HandleEvent();

	Settings settings;
	int frames = 0;
	sf::RenderWindow window;
	bool to_exit = false;

};


#endif // ENGINE_HPP_INCLUDED

