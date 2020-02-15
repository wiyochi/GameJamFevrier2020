#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphics/TextureManager.hpp"
#include "graphics/menu/Menu.hpp"

void keskecestcommetouche();

#include "engine/World.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!"/*, sf::Style::Fullscreen*/);
    window.setFramerateLimit(120);
    World w;

    Menu m(sf::Vector2f(100, 10), sf::Vector2f(200, 40)); 

    m.addOption("rien", [](){ std::cout << "Bouton 1" << std::endl; });
    m.addOption("rien", [](){ std::cout << "ouai Bouton 2" << std::endl; });
    m.addOption("rien", [](){ std::cout << "3" << std::endl; });
    m.addOption("rien", [](){ std::cout << "Bouton 212546" << std::endl; });   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        w.update();
        m.update();

        window.clear();
        window.draw(m);
        window.draw(w);
        window.display();
    }

    return 0;
}

void keskecestcommetouche()
{
    if (sf::Joystick::isConnected(0))
    {
        for (unsigned i = 0; i < sf::Joystick::getButtonCount(0); i++)
        {
            if (sf::Joystick::isButtonPressed(0, i))
            {
                std::cout << "JOYSTICK: " << i << std::endl;
            }
        }
        if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)) > 50)
            std::cout << "X" << std::endl;
        if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y)) > 50)
            std::cout << "Y" << std::endl;
        if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U)) > 50)
            std::cout << "U" << std::endl;
        if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V)) > 50)
            std::cout << "V" << std::endl;
        if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX)) > 50)
            std::cout << "PovX: " << sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) << std::endl;
        if (std::abs(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY)) > 50)
            std::cout << "PovY: " << sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) << std::endl;
    }
}