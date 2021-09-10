#include "Fruit.h"

Fruit::Fruit(int startX, int startY) {
	position.x = startX;
	position.y = startY;

	fruitShape.setSize(sf::Vector2f(25, 25));
	fruitShape.setPosition(position);
	fruitShape.setFillColor(sf::Color::Red);
}

sf::FloatRect Fruit::getPosition() {
	return fruitShape.getGlobalBounds();
}

sf::RectangleShape Fruit::getShape() {
	return fruitShape;
}

void Fruit::update(int randX, int randY) {
	position.x = randX;
	position.y = randY;

	fruitShape.setPosition(position);
}