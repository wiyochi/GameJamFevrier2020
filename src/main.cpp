#include <vector>
#include <SFML/Graphics.hpp>
#include "graphics/TextureManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    TextureManager tm = TextureManager::getInstance();
    std::vector<sf::Sprite*> sprites;
    sprites.push_back(new sf::Sprite(*tm.getTexture("tests/1")));
    sprites.push_back(new sf::Sprite(*tm.getTexture("tests/1")));
    sprites.push_back(new sf::Sprite(*tm.getTexture("tests/1")));

    tm.deleteTexture("tests/1");
    tm.deleteTexture("tests/1");
    tm.deleteTexture("tests/1");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (auto &&sprite : sprites)
        {
            window.draw(*sprite);
        }
        window.display();
    }

    return 0;
}