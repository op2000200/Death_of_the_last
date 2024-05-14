#pragma once
#include "SFML/Graphics.hpp"
class BasicMissleCold
{
public:
	BasicMissleCold();


private:
	sf::Sprite sprite;
	sf::Vector2f direction;
	float rotation;
	int health;
	int speed;
	int damageMP;
	int critRate;
	int critDamage;
};

