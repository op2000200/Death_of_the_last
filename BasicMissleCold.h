#pragma once
#include "SFML/Graphics.hpp"
class BasicMissleCold
{
public:
	BasicMissleCold();
	BasicMissleCold(sf::Vector2f pos, sf::Texture* texture);
	~BasicMissleCold();

	void setPosition(sf::Vector2f pos);
	void setDirection(sf::Vector2f dir);
	void setRotation(float rot);
	void setHealth(int num);

	sf::Sprite getSprite();
	sf::Vector2f getDirection();
	float getRotation();
	int getHealth();
	int getSpeed();
	int getDamageMP();
	int getCritRate();
	int getCritDamage();

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