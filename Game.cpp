#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(WIDTH, LENGTH), "Snake")
	, mHead() 
{
	mHead.setSize(sf::Vector2f(25.f,25.f));
	mHead.setPosition(WIDTH / 2, LENGTH / 2);
	mHead.setFillColor(sf::Color::Green);
}

void Game::run() {
	while (mWindow.isOpen()) {
		processEvents();
		update();
		render();
	}
}
void Game::processEvents() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
	}
}

void Game::update() {

}

void Game::render() {
	mWindow.clear();
	mWindow.draw(mHead);
	mWindow.display();
}