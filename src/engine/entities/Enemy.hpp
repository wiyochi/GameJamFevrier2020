#pragma once

#include <vector>
#include <string>
#include <cstdarg>

#include "Entity.hpp"
#include "../../graphics/TextureManager.hpp"
#include "Shot.hpp"
#include "../Path.hpp"
#include "../Animated.hpp"

class Enemy : public Entity
{
private:
    static constexpr int max_dt = 30;

    std::vector<Shot *> _shots;
    int _shots_cpt;
    int _fire_speed;
    Path* _path;
    std::vector<sf::Vector3f> _model;
    bool _isAlive;
    Animated* _animation;

    int _lifeCounter;
    volatile int _life; 

public:
    Enemy(sf::Vector2f const &, std::string const &, int = 120);
    ~Enemy();
    void update() override;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;
    void setPath(Path * p) {_path = p;}
    void setShotPathModel(int i = 0, ...);
    std::vector<Shot *> getShots() {return _shots;}
    void hurt();
    void kill() {_isAlive = false;}
    bool isAlive() const {return _isAlive;}
    bool isDeletable() const {return !_isAlive && _shots.empty();}

};