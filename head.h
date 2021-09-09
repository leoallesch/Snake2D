#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Head {
private:
	sf::Vector2i position;

	sf::RectangleShape headShape;
public:
	Head(int startX, int startY);

};