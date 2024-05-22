#pragma once
#include <SFML/Graphics.hpp>
class StandartEnemy
{
public:
	StandartEnemy();
	StandartEnemy(sf::Texture* texture, sf::Vector2f pos, float time);
	~StandartEnemy();

	sf::Sprite getSprite();
	int getHealth();
	int getDamage();
	int getSpeed();
	int getResist();
	int getManaValue();

	void setPosition(sf::Vector2f pos);
	void setHealth(int num);
	void setDamage(int num);
	void setSpeed(int num);
	void setResist(int num);
	void setManaValue(int num);

private:
	sf::Sprite sprite;
	int health;
	int damage;
	int speed;
	int resist;
	int manaValue;
};

