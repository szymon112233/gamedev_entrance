#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <iostream>
#include <stack>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include "BaseState.hpp"
#include "GameplayState.hpp"


class Engine
{
public:
	Engine();
	void Update();
	void Loop();
	void Render();
	void HandleEvents();
	void PushState(BaseState& state);
	void PopState();

	Settings settings;
	int frames = 0;
	int updates = 0;
	sf::RenderWindow window;
	sf::Clock game_time;
	bool to_exit = false;

private:
    void InitWindow();

	sf::Time previous;
	sf::Time lag;
	sf::Time fps_counter;
	const int MS_PER_UPDATE = 16;

    std::stack<BaseState*> state_stack;
};


#endif // ENGINE_HPP_INCLUDED

