#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(sf::Vector2f pos, sf::Texture* texture);
	~Enemy();

	sf::Sprite getSprite();

private:
	sf::Sprite sprite;
};


//class Enemy
//{
//public:
//    Enemy();
//    Enemy(sf::Texture* texture, sf::Vector2f pos);
//    ~Enemy();
//public:
//	sf::Sprite getSprite();
//	sf::Vector2f getPos();
//	int getHealth();
//	int getSpeed();
//
//	void setPos(sf::Vector2f coord);
//	void setHealth(int num);
//	void setSpeed(int num);
//private:
//	sf::Sprite sprite;
//	sf::Vector2f pos;
//	int health;
//	int speed;
//};
//
