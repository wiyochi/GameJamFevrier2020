#include "Animated.hpp"

unsigned Animated::frameCounter = 0;

Animated::Animated(sf::RectangleShape & rect, std::string const & folder, unsigned frameNumber) :
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
    frameCounter++;

    if (frameCounter % 10 == 0)
    {
        _textureFrame = _textureFrame + 1 > _frameNumber ? 1 : _textureFrame + 1;
        _shape.setTexture(TextureManager::getInstance().getTexture(_folder + "/" + std::to_string(_textureFrame)));
    }
}
