#pragma once
#include "SFML/Graphics.hpp"
class Mana
{
public:
    Mana();
    Mana(sf::Vector2f pos, sf::Texture* texture);
    ~Mana();
public:
    sf::Sprite getSprite();
    int getValue();

    void setPos(sf::Vector2f coord);
private:
    sf::Sprite sprite;
    int value;
};

