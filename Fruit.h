#pragma once
#include <SFML/Graphics.hpp>

class Fruit {
private:
	sf::Vector2f position;

	sf::RectangleShape fruitShape;
public:
	Fruit(int startX, int startY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	void update(int randX,int randY);
};