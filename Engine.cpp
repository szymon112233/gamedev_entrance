#include "Engine.hpp"

Engine::Engine()
{
	InitWindow();
	previous = game_time.getElapsedTime();
	state_stack.push(new GameplayState(*this));

}

void Engine::Loop()
{
	sf::Time current = game_time.getElapsedTime();
	sf::Time elapsed = current - previous;
	previous = current;

	lag += elapsed;
	fps_counter += elapsed;

	HandleEvents();

    while(lag.asMilliseconds() >= MS_PER_UPDATE)
    {
        Update();
        lag -= sf::milliseconds(MS_PER_UPDATE);
    }


    frames++;
    if(fps_counter.asSeconds() >= 1.0f)
    {
        //std::cout<<"Updates: "<<std::to_string(updates)<<std::endl;
        //std::cout<<"FPS: "<<std::to_string(frames/fps_counter.asSeconds())<<std::endl;
        fps_counter = sf::seconds(0);
        frames = 0;
        updates = 0;
    }

	Render();
}

void Engine::Update()
{
    if (!state_stack.empty())
        state_stack.top()->Update();
    updates++;

}

void Engine::Render()
{

	if (window.isOpen())
	{
		window.clear();
		if (!state_stack.empty())
            state_stack.top()->Render(window);
        window.display();
	}
}

void Engine::HandleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
	    if (!state_stack.empty())
            state_stack.top()->HandleEvents(event);
		if (event.type == sf::Event::Closed)
		{
			window.close();
			to_exit = true;
		}
	}
}

void Engine::InitWindow()
{
    window.create(sf::VideoMode(settings.GetWindowSize().x, settings.GetWindowSize().y), "Sth went terribly wrong here");
}



