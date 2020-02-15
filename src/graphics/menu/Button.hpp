#ifndef BUTTON_HPP
#define BUUTON_HPP

#include <SFML/Graphics.hpp>
#include "../TextureManager.hpp"

class Button : public sf::Drawable
{
public:
    Button(sf::Vector2f const & pos, sf::Vector2f const & size, std::string const & name, std::function<void()> func);
    ~Button();

    void select();
    void unselect();

    void execute();

private:
    sf::RectangleShape _shape;
    sf::Text _text;
    bool _selected;
    std::function<void()> _function;

    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};

#endif