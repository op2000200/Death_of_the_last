#include "Includes.h"

int WinMain()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Death of the last");
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(800, 600));
    background.setFillColor(sf::Color(100, 100, 100));
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(background);
        window.display();
    }
}