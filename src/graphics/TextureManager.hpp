#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <map>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>

class TextureManager
{
private:
    static TextureManager* instance;
public:
    static TextureManager& getInstance();
    static void deleteInstance();

    TextureManager();
    ~TextureManager();

    sf::Texture* getTexture(std::string const & textureName);
    void removeTexture(std::string const & textureName);
    void deleteTexture(std::string const & textureName);
    void deleteAllTextures();

    sf::Font* getFont(std::string const & fontName);
    void removeFont(std::string const & fontName);
    void deleteFont(std::string const & fontName);
    void deleteAllFonts();

private:
    std::string getTexturePath(std::string const & textureName);
    std::string getFontPath(std::string const & fontName);

    struct Texture
    {
        sf::Texture*    _texture;
        unsigned        _count;
    };

    struct Font
    {
        sf::Font*   _font;
        unsigned    _count;
    };

    std::map<std::string, Texture>  _textures;
    std::map<std::string, Font>     _fonts;
};

#endif