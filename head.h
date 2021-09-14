#pragma once
#include <SFML/Graphics.hpp>

class Head {
private:
	sf::Vector2f position;

	sf::RectangleShape headShape;

	enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
	direction dir = STOP;

	int speed = 25;
public:
	Head(int startX, int startY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	int getX();
	int getY();

	void setLeft();
	void setRight();
	void setUp();
	void setDown();
	void update();

	bool checkWall(int windowWidth, int windowHeight);
};