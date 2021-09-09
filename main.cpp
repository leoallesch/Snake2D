#include <SFML/Graphics.hpp>

#include "Head.h"

int main()
{
    int windowWidth = 1024;
    int windowHeight = 720;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake2D");

    int score = 0;

    Head head(windowWidth / 2, windowHeight / 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            head.setLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            head.setRight();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            head.setUp();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            head.setDown();
        }
        head.update();

        window.clear(sf::Color());
        window.draw(head.getShape());
        window.display();
    }

    return 0;
}