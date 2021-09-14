#include <SFML/Graphics.hpp>

#include <cstdlib>

#include "Head.h"
#include "Fruit.h"

int main()
{
    int windowWidth = 600;
    int windowHeight = 600;

    int randX, randY;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake2D");

    sf::Clock clock;
    sf::Time elapsed;

    int score = 0;

    Head head(windowWidth / 2, windowHeight / 2);

    randX = (rand() % ((windowWidth - 1) / 25) + 1) * 25;
    randY = (rand() % ((windowHeight - 1) / 25) + 1) * 25;
    
    while (randX == head.getX() && randY == head.getY()) {
        randX = (rand() % ((windowWidth - 1) / 25) + 1) * 25;
        randY = (rand() % ((windowHeight - 1) / 25) + 1) * 25;
    }
    
    Fruit fruit(randX, randY);

    while (window.isOpen())
    {
        elapsed = clock.getElapsedTime();

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
        if (elapsed.asSeconds() >= 0.14) {
            head.update();
            clock.restart();
        }
        if (!head.checkWall(windowWidth, windowHeight)) {
            window.close();
        }
        if (head.getPosition() == fruit.getPosition()) {
            score++;
            randX = (rand() % ((windowWidth - 1) / 25) + 1) * 25;
            randY = (rand() % ((windowHeight - 1) / 25) + 1) * 25;
            while (randX == head.getX() && randY == head.getY()) {
                randX = (rand() % ((windowWidth - 1) / 25) + 1) * 25;
                randY = (rand() % ((windowHeight - 1) / 25) + 1) * 25;
            }
            fruit.update(randX,randY);
        }

        window.clear(sf::Color());
        window.draw(head.getShape());
        window.draw(fruit.getShape());
        window.display();
    }

    return 0;
}