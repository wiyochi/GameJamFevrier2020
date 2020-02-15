#include "Button.hpp"

Button::Button(sf::Vector2f const & pos, sf::Vector2f const & size, std::string const & name, std::function<void()> func) :
    _function(func)
{
    _shape.setPosition(pos);
    _shape.setSize(size);
    _shape.setTexture(TextureManager::getInstance().getTexture("buttons/frame_blue"));
    _shape.setOutlineColor(sf::Color::Red);

    _text.setFont(*TextureManager::getInstance().getFont("Roboto-Thin"));
    _text.setFillColor(sf::Color::White);
    _text.setStyle(sf::Text::Bold);
    _text.setCharacterSize(20);
    _text.setString(name);

    sf::Vector2f p;
    p.x = pos.x + (size.x - _text.getGlobalBounds().width) / 2;
    p.y = pos.y + (size.y - _text.getGlobalBounds().height) / 2;
    _text.setPosition(p);
}

Button::~Button()
{
}

void Button::select()
{
    _selected = true;
    _shape.setOutlineThickness(2);
}

void Button::unselect()
{
    _selected = false;
    _shape.setOutlineThickness(0);
}

void Button::execute()
{
    _function();
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(_shape, states);
    target.draw(_text, states);
}