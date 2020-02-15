#ifndef ANIMATED_HPP
#define ANIMATED_HPP

#include <SFML/Graphics.hpp>
#include "../graphics/TextureManager.hpp"

class Animated
{
public:
    Animated(sf::RectangleShape & rect, std::string const & folder, unsigned frameNumber);
    ~Animated();

    void update();

private:
    static unsigned frameCounter;

    sf::RectangleShape& _shape;
    const unsigned _frameNumber;
    unsigned _textureFrame;
    std::string _folder;
};

#endif