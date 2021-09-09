#pragma once
#include <SFML/Graphics.hpp>

class Head {
private:
	sf::Vector2f position;

	sf::RectangleShape headShape;

	float speed = 0.3f;
public:
	Head(int startX, int startY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void update();
};