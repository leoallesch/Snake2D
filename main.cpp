#include <SFML/Graphics.hpp>

#include <cstdlib>

#include "Head.h"
#include "Fruit.h"

int main()
{
    int windowWidth = 1200;
    int windowHeight = 725;

    int randX, randY;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake2D");

    window.setFramerateLimit(60);

    sf::Clock clock;

    int score = 0;

    Head head(windowWidth / 2, windowHeight / 2);

    randX = rand() % windowWidth + 1;
    randY = rand() % windowHeight + 1;
    while (randX == head.getX() && randY == head.getY()) {
        randX = rand() % windowWidth + 1;
        randY = rand() % windowHeight + 1;
    }
    
    Fruit fruit(randX, randY);

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
        if (head.getPosition() == fruit.getPosition()) {
            randX = rand() % windowWidth + 1;
            randY = rand() % windowHeight + 1;
            while (randX == head.getX() && randY == head.getY()) {
                randX = rand() % windowWidth + 1;
                randY = rand() % windowHeight + 1;
            }
            fruit.update(randX,randY);
        }

        sf::Time time = clock.getElapsedTime();
        clock.restart().asSeconds();

        window.clear(sf::Color());
        window.draw(head.getShape());
        window.draw(fruit.getShape());
        window.display();
    }

    return 0;
}