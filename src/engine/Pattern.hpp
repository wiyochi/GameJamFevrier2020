#ifndef PATTERN_HPP
#define PATTERN_HPP

#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include "Builder.hpp"
#include "entities/Enemy.hpp"

class Pattern
{
private:
    static std::mt19937 gen;
    static std::uniform_int_distribution<> dist;
public:
    static int getPattern(int type, std::vector<Enemy*>& enemis);
    static int getRandomPattern(std::vector<Enemy*>& enemis);
};

#endif