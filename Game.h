#pragma once

#include <SFML/Graphics.hpp>

const int WIDTH = 650;
const int LENGTH = 500;
const sf::Time TimePerFrame = sf::seconds(0.1f / 60.f);

class Game {
public:
	Game();
	void run();
private:
	void processEvents();
	void update(sf::Time TimePerFrame);
	void render();

	void handleInput();
private:
	sf::RenderWindow mWindow;
	sf::RectangleShape mHead;

	enum Direction {STOP=0,UP,DOWN,LEFT,RIGHT};
	Direction dir = STOP;

	bool moveUp = false;
	bool moveDown = false;
	bool moveLeft = false;
	bool moveRight = false;

	sf::Vector2f movement;
	int speed = 25;
};