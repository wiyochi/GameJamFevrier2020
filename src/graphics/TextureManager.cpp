#include "TextureManager.hpp"

TextureManager* TextureManager::instance = nullptr;

TextureManager& TextureManager::getInstance()
{
    if (!instance)
        instance = new TextureManager();
    return *instance;
}

void TextureManager::deleteInstance()
{
    delete instance;
}

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
    deleteAllTextures();
    deleteAllFonts();
}

std::string TextureManager::getTexturePath(std::string const & textureName)
{
    return "resources/textures/" + textureName + ".png";
}

std::string TextureManager::getFontPath(std::string const & fontName)
{
    return "resources/fonts/" + fontName + ".png";
}

sf::Texture* TextureManager::getTexture(std::string const & textureName)
{
    if (_textures.find(textureName) == _textures.end())
    {
        sf::Texture* nTexture = new sf::Texture();
        if (nTexture->loadFromFile(getTexturePath(textureName)))
        {
            _textures[textureName] = { nTexture , 0};
        }
        else
        {
            delete nTexture;
            return nullptr;
        }
    }
    _textures[textureName]._count++;
    return _textures[textureName]._texture;
}

void TextureManager::deleteTexture(std::string const & textureName)
{
    auto it = _textures.find(textureName);
    if (it != _textures.end())
    {
        if (--(it->second._count) == 0)
        {
            delete it->second._texture;
            _textures.erase(it);
        }
    }
}

void TextureManager::deleteAllTextures()
{
    std::for_each(_textures.begin(), _textures.end(), [](std::pair<std::string, Texture> pair)
    {
        delete pair.second._texture;
    });
    _textures.clear();
}

sf::Font* TextureManager::getFont(std::string const & fontName)
{
    if (_fonts.find(fontName) == _fonts.end())
    {
        sf::Font* nFont = new sf::Font();
        if (nFont->loadFromFile(getFontPath( fontName)))
        {
            _fonts[fontName] = { nFont , 0};
        }
        else
        {
            delete nFont;
            return nullptr;
        }
    }
    _fonts[fontName]._count++;
    return _fonts[fontName]._font;
}

void TextureManager::deleteFont(std::string const & fontName)
{
    auto it = _fonts.find(fontName);
    if (it == _fonts.end())
    {
        if (--(it->second._count) == 0)
        {
            delete it->second._font;
            _fonts.erase(it);
        }
    }
}

void TextureManager::deleteAllFonts()
{
    std::for_each(_fonts.begin(), _fonts.end(), [](std::pair<std::string, Font> pair)
    {
        delete pair.second._font;
    });
    _fonts.clear();
}
