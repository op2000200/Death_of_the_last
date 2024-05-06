#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:
	Player();
	Player(sf::Texture* texture);
	//~Player();
public:
	sf::Sprite getSprite();
	int getHealth();
	int getSpeed();
	int getCastSpeed();
	int getLevel();
	int getExp();
	int getExpCap();

	void setHealth(int num);
	void setSpeed(int num);
	void setCastSpeed(int num);
	void setLevel(int num);
	void setExp(int num);
	void setExpCap(int num);
	void setPos(sf::Vector2f pos);
	void setTexture(sf::Texture texture);
private:
	sf::Sprite sprite;
	int level;
	int exp;
	int expCap;
	int health;
	int speed;
	int castSpeed;
};

