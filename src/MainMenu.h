#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.h"
#include "Game.h"

class MainMenu : public Engine::State
{

private:
	std::shared_ptr<Context> m_context;
	sf::Text m_gameTitle;
public:
	MainMenu(std::shared_ptr<Context>& context);
	~MainMenu();

	virtual void Init() = 0;
	virtual void ProcessInput() = 0;
	virtual void Update(sf::Time deltaTime) = 0;
	virtual void Draw() = 0;
};

