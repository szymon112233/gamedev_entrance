#ifndef GAMEPLAYSTATE_HPP_INCLUDED
#define GAMEPLAYSTATE_HPP_INCLUDED

#include "BaseState.hpp"

class GameplayState : public BaseState
{
public:
    GameplayState(Engine& engine_ref);
    virtual void Update();
    virtual void Render(sf::RenderWindow& window);
    virtual void HandleEvents(sf::Event& event);
    void Exit();
private:
    void InitMaps();

    Sprite test;
	Map test_map;
	Map test_map2;
	PlayerController main_control;
	std::vector<GameObject*> objects;
};


#endif // GAMEPLAYSTATE_HPP_INCLUDED

