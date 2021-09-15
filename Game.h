#pragma once

#include <SFML/Graphics.hpp>
const int WIDTH = 650;
const int LENGTH = 500;

class Game {
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();
private:
	sf::RenderWindow mWindow;
	sf::RectangleShape mHead;
};