#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.hpp"

class Menu : public sf::Drawable
{
public:
    Menu(sf::Vector2f const & pos, sf::Vector2f const & size);
    ~Menu();

    void addOption(std::string const & name, std::function<void()> func);
    void update();

private:
    static bool z_pressed;
    static bool s_pressed;
    static bool enter_pressed;

    std::vector<Button*> _buttons;
    int _selection;
    sf::Vector2f _pos;
    sf::Vector2f _size;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif