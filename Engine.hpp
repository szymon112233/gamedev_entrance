#include "Settings.hpp"
#include <iostream>

class Engine
{
public:
	Engine() {}
	void Update();
	void Render();

	Settings settings;
	int frames = 0;


};
