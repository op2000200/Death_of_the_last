#pragma once
#include <SFML/Graphics.hpp>
class Bullet
{
public:
    Bullet();
    Bullet(sf::Vector2f pos, sf::Texture* texture);
    ~Bullet();
public:
    sf::Sprite getSprite();
    sf::Vector2f getPos();
    int getHealth();
    int getSpeed();

    void setPos(sf::Vector2f coord);
    void setHealth(int num);
    void setSpeed(int num);
private:
    sf::Sprite sprite;
    sf::Vector2f pos;
    int health;
    int speed;
};

