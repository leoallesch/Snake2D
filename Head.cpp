#include "Head.h"

Head::Head(int startX, int startY) {
	position.x = startX;
	position.y = startY;

	headShape.setSize(sf::Vector2f(5, 5));
	headShape.setPosition(position);
}

sf::FloatRect Head::getPosition() {
	return headShape.getGlobalBounds();
}

sf::RectangleShape Head::getShape() {
	return headShape;
}

void Head::moveLeft() {
	position.x -= speed;
}

void Head::moveRight() {
	position.x += speed;
}

void Head::moveUp() {
	position.y += speed;
}

void Head::moveDown() {
	position.y -= speed;
}

void Head::update() {
	headShape.setPosition(position);
}