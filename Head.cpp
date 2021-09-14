#include "Head.h"

Head::Head(int startX, int startY) {
	position.x = startX;
	position.y = startY;

	headShape.setSize(sf::Vector2f(25, 25));
	headShape.setPosition(position);
	headShape.setFillColor(sf::Color::Green);
}

sf::FloatRect Head::getPosition() {
	return headShape.getGlobalBounds();
}

sf::RectangleShape Head::getShape() {
	return headShape;
}

void Head::update() {
	switch (dir) {
		case LEFT:
			position.x -= speed;
			break;
		case RIGHT:
			position.x += speed;
			break;
		case UP:
			position.y -= speed;
			break;
		case DOWN:
			position.y += speed;
			break;
	}
	headShape.setPosition(position);
}

void Head::setLeft() {
	if (dir != RIGHT) {
		dir = LEFT;
	}
}

void Head::setRight() {
	if (dir != LEFT) {
		dir = RIGHT;
	}
}

void Head::setUp() {
	if (dir != DOWN) {
		dir = UP;
	}
}

void Head::setDown() {
	if (dir != UP) {
		dir = DOWN;
	}
}

int Head::getX(){
	return position.x;
}

int Head::getY() {
	return position.y;
}

bool Head::checkWall(int windowWidth, int windowHeight) {
	bool inBounds = true;
	if (position.x < 0 || position.x > windowWidth) {
		inBounds = false;
	}
	else if (position.y < 0 || position.y > windowHeight) {
		inBounds = false;
	}
	return inBounds;
}