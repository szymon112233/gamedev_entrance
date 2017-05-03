#include "GameplayState.hpp"
#include "Engine.hpp"

GameplayState::GameplayState(Engine& engine_ref) : BaseState(engine_ref)
{
    InitMaps();
    main_control = PlayerController(sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::S);

	test = Sprite(&main_control);
	test.SetSprite("sprites/stanie.png");
	objects.push_back(&test);
}

void GameplayState::Update()
{
    for (GameObject* it : objects)
    {
        it->Update();
    }
}

void GameplayState::Render(sf::RenderWindow& window)
{
    test_map.Render(window);
    test_map2.Render(window);
    for (GameObject* it : objects)
    {
        it->Render(window);
    }
}

void GameplayState::HandleEvents(sf::Event& event)
{
     main_control.HandleEvent(event);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Exit();
}


void GameplayState::InitMaps()
{
    test_map.LoadFromFile("river_l1");
    test_map2.LoadFromFile("river_l2");
}

void GameplayState::Exit()
{
    engine.to_exit = true;
}
