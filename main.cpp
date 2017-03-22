#include <iostream>
#include "Engine.hpp"


int main()
{
	Engine engine;
	bool exit = false;
	while (!exit)
	{
		engine.Loop();
		exit = engine.to_exit;
	}
    return 0;
}
