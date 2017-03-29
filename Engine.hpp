#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"
#include "PlayerController.hpp"
#include "Map.hpp"

class Engine
{
public:
	Engine();
	void Update();
	void Loop();
	void Render();
	void HandleEvents();

	Settings settings;
	int frames = 0;
	int updates = 0;
	sf::RenderWindow window;
	sf::Clock game_time;
	bool to_exit = false;
	std::vector<GameObject*> objects;
	PlayerController main_control;


private:
    void InitWindow();
    void InitMap();

	sf::Time previous;
	sf::Time lag;
	sf::Time fps_counter;
	const int MS_PER_UPDATE = 16;
	Sprite test;
	Map test_map;
	Map test_map2;
};


#endif // ENGINE_HPP_INCLUDED

