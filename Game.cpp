#include "Game.h"
#include <iostream>

Game::Game()
	: mWindow(sf::VideoMode(WIDTH, LENGTH), "Snake")
	, mHead() 
{
	mHead.setSize(sf::Vector2f(25.f,25.f));
	mHead.setPosition(WIDTH / 2, LENGTH / 2);
	mHead.setFillColor(sf::Color::Green);
}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen()) {
		processEvents();
		handleInput();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			handleInput();
			update(TimePerFrame);
		}
		render();
	}
}
void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code) {
				case sf::Keyboard::W:
					if (dir != DOWN)
						dir = UP;
					break;
				case sf::Keyboard::S:
					if (dir != UP)
						dir = DOWN;
					break;
				case sf::Keyboard::A:
					if (dir != RIGHT)
						dir = LEFT;
					break;
				case sf::Keyboard::D:
					if (dir != LEFT)
						dir = RIGHT;
					break;
				default:
					break;
			}
		}
	}
}

void Game::handleInput() {
	switch (dir) {
		case UP:
			moveUp = true;
			moveDown = false;
			moveLeft = false;
			moveRight = false;
			break;
		case DOWN:
			moveUp = false;
			moveDown = true;
			moveLeft = false;
			moveRight = false;
			break;
		case LEFT:
			moveUp = false;
			moveDown = false;
			moveLeft = true;
			moveRight = false;
			break;
		case RIGHT:
			moveUp = false;
			moveDown = false;
			moveLeft = false;
			moveRight = true;
			break;
	}
	std::cout << moveUp << " " << moveDown << " " << moveLeft << " " << moveRight << std::endl;
}

void Game::update(sf::Time TimePerFrame) {
	movement = sf::Vector2f(0.f, 0.f);
	if (moveUp)
		movement.y -= speed;
	else if (moveDown)
		movement.y += speed;
	else if (moveLeft)
		movement.x -= speed;
	else if (moveRight)
		movement.x += speed;

	mHead.move(movement * TimePerFrame.asSeconds());

}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mHead);
	mWindow.display();
}