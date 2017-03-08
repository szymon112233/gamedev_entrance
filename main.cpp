#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine.hpp"


int main()
{
	Engine engine;
	sf::RenderWindow window(sf::VideoMode(200,200), "Hello windows!");
	bool exit = false;
	while (!exit)
	{
		if (window.isOpen())
		{
			engine.Update();
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
					exit = true;
				}

			}
			window.clear();
			window.display();
		}
	}
    return 0;
}
