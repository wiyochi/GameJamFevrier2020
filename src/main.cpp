#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphics/TextureManager.hpp"
#include "graphics/menu/Menu.hpp"

void keskecestcommetouche();

#include "engine/World.hpp"

enum STATE { MENU, GAME, PAUSE};

int main()
{
    STATE state = MENU;
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!", sf::Style::Fullscreen);
    window.setFramerateLimit(120);
    World w;

    Menu m(sf::Vector2f(860, 350), sf::Vector2f(200, 40)); 

    sf::RectangleShape fog(sf::Vector2f(1920, 1080));
    fog.setFillColor(sf::Color(0, 0, 0, 125));

    m.addOption(L"Démarrer", [&](){ state = GAME;});
    m.addOption(L"rien", [](){ std::cout << "ouai Bouton 2" << std::endl; });
    m.addOption(L"rien", [](){ std::cout << "3" << std::endl; });
    m.addOption(L"Quitter", [](){ exit(0); });   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (state == GAME)
        {
            if ((sf::Joystick::isConnected(0) && sf::Joystick::isButtonPressed(0, 7)) || (!sf::Joystick::isConnected(0) && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
            {
                state = PAUSE;
                continue;
            }
            w.update();
        } 
        else if (state == MENU)
        {
            m.update();
        }
        else if (state == PAUSE)
        {
            if ((sf::Joystick::isConnected(0) && sf::Joystick::isButtonPressed(0, 1)) || (!sf::Joystick::isConnected(0) && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
            {
                state = GAME;
                continue;
            }
            else if ((sf::Joystick::isConnected(0) && sf::Joystick::isButtonPressed(0, 2)) || (!sf::Joystick::isConnected(0) && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
            {
                state = MENU;
                continue;
            }
        }
        

        window.clear();
        if (state == MENU)
        {
            window.draw(m);
        }
        else if (state == GAME)
        {
            window.draw(w);
        }
        else if (state == PAUSE)
        {
            window.draw(w);
            window.draw(fog);
        }
        
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