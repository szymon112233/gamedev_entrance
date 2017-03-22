#include "Engine.hpp"
#include "Sprite.hpp"

Engine::Engine()
{
	window.create(sf::VideoMode(500, 500), "Sth went terribly wrong here");
	previous = game_time.getElapsedTime();

	Sprite test;
	test.SetSprite("sprites/stanie.png");
	objects.push_back(test);
}

void Engine::Loop()
{
	sf::Time current = game_time.getElapsedTime();
	sf::Time elapsed = current - previous;
	previous = current;

	lag += elapsed;
	fps_counter += elapsed;

	HandleEvent();

    while(lag.asMilliseconds() >= MS_PER_UPDATE)
    {
        Update();
        lag -= sf::milliseconds(MS_PER_UPDATE);
    }


    frames++;
    if(fps_counter.asSeconds() >= 1.0f)
    {
        std::cout<<"Updates: "<<std::to_string(updates)<<std::endl;
        std::cout<<"FPS: "<<std::to_string(frames/fps_counter.asSeconds())<<std::endl;
        fps_counter = sf::seconds(0);
        frames = 0;
        updates = 0;
    }

	Render();
}

void Engine::Update()
{
    updates++;
    for (GameObject& it : objects)
    {
        it.Update();
    }
}

void Engine::Render()
{
	if (window.isOpen())
	{
		window.clear();
		for (GameObject& it : objects)
        {
            it.Render(window);
        }
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

