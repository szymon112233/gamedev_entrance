#include "Engine.hpp"
#ifndef ENGINE_HPP_INCLUDED

void Engine::Update()
{
	std::cout<<std::to_string(frames)<<std::endl;
	frames++;
}

#endif // ENGINE_HPP_INCLUDED
