#include <SFML/Graphics.hpp>

#include "engine/World.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.setFramerateLimit(120);
    World w;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        w.update();



        window.clear();
        window.draw(w);
        window.display();
    }

    return 0;
}