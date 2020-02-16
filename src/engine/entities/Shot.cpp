#include "Shot.hpp"

Shot::Shot(sf::Vector2f const & pos, std::string const & texture) : Entity(sf::Vector2f(50, 30)), _path(nullptr)
{  
    _sprite.setPosition(pos);
    _sprite.setTexture(TextureManager::getInstance().getTexture(texture));
}

void Shot::update()
{
    if (_path != nullptr)
        _path->update();
    else 
        move(Shot::speed, 0);
}