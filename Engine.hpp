#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"

class Engine
{
public:
	Engine();
	void Update();
	void Loop();
	void Render();
	void HandleEvent();

	Settings settings;
	int frames = 0;
	int updates = 0;
	sf::RenderWindow window;
	sf::Clock game_time;
	bool to_exit = false;
	std::vector<Sprite> objects;

private:
	sf::Time previous;
	sf::Time lag;
	sf::Time fps_counter;
	const int MS_PER_UPDATE = 16;
};


#endif // ENGINE_HPP_INCLUDED

