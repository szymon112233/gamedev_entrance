#include "Engine.hpp"

Engine::Engine()
{
	window.create(sf::VideoMode(500, 500), "Sth went terribly wrong here");
}

void Engine::Update()
{
	HandleEvent();

	std::cout<<std::to_string(frames)<<std::endl;
	frames++;

	Render();
}

void Engine::Render()
{
	if (window.isOpen())
	{
		window.clear();
		window.display();
	}
}

void Engine::HandleEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			to_exit = true;
		}
	}
}

