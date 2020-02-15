#include "Animated.hpp"

Animated::Animated(sf::RectangleShape & rect, std::string const & folder, unsigned frameNumber) :
    _frameCounter(0),
    _shape(rect),
    _frameNumber(frameNumber),
    _textureFrame(0),
    _folder(folder)
{
    _shape.setTexture(TextureManager::getInstance().getTexture(_folder + "/1"));
}

Animated::~Animated()
{
}

void Animated::update()
{
    _frameCounter++;

    if (_frameCounter % 10 == 0)
    {
        _textureFrame = _textureFrame + 1 > _frameNumber ? 1 : _textureFrame + 1;
        _shape.setTexture(TextureManager::getInstance().getTexture(_folder + "/" + std::to_string(_textureFrame)));
    }
}
