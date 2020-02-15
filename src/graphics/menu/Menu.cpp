#include "Menu.hpp"

bool Menu::z_pressed = false;
bool Menu::s_pressed = false;
bool Menu::enter_pressed = false;

Menu::Menu(sf::Vector2f const & pos, sf::Vector2f const & size) :
    _selection(-1),
    _pos(pos),
    _size(size)
{
}

Menu::~Menu()
{
    for (auto &&b : _buttons)
    {
        delete b;
    }
}

void Menu::update()
{
    if (sf::Joystick::isConnected(0))
    {
        if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 0 && !s_pressed)
        {
            s_pressed = true;
            _buttons[_selection]->unselect();
            _selection = (_selection + 1) >= _buttons.size() ? 0 : _selection + 1;
            _buttons[_selection]->select();
        }
        else if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < 0 && !z_pressed)
        {
            z_pressed = true;
            _buttons[_selection]->unselect();
            _selection = (_selection - 1) < 0 ? _buttons.size() - 1 : _selection - 1;
            _buttons[_selection]->select();
        }
        if (sf::Joystick::isButtonPressed(0, 0) && !enter_pressed)
        {
            enter_pressed = true;
            _buttons[_selection]->execute();
        }

        if (z_pressed && !(sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < 0))
            z_pressed = false;
        if (s_pressed && !(sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > 0))
            s_pressed = false;
        if (enter_pressed && !sf::Joystick::isButtonPressed(0, 0))
            enter_pressed = false;
    }
    else
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !z_pressed)
        {
            z_pressed = true;
            _buttons[_selection]->unselect();
            _selection = (_selection - 1) < 0 ? _buttons.size() - 1 : _selection - 1;
            _buttons[_selection]->select();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !s_pressed)
        {
            s_pressed = true;
            _buttons[_selection]->unselect();
            _selection = (_selection + 1) >= _buttons.size() ? 0 : _selection + 1;
            _buttons[_selection]->select();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !enter_pressed)
        {
            enter_pressed = true;
            _buttons[_selection]->execute();
        }

        if (z_pressed && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            z_pressed = false;
        if (s_pressed && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            s_pressed = false;
        if (enter_pressed && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            enter_pressed = false;
    }
}

void Menu::addOption(std::string const & name, std::function<void()> func)
{
    _selection = 0;
    _buttons.push_back(new Button(sf::Vector2f(_pos.x, _pos.y + (_size.y + 20) * _buttons.size()), _size, name, func));
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto &&b : _buttons)
    {
        target.draw(*b, states);
    }
}