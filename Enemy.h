#pragma once
#include <SFML/Graphics.hpp>
#include "Structures.h"

class Enemy
{
public:
	Enemy(sf::Vector2f pos, sf::Texture* texture, EnemyType type, Element element);
	~Enemy();

	sf::Sprite getSprite();
	Characteristics getChar();
	EnemyState getState();
	void setState(EnemyState st);
	sf::Vector2f getDest();
	void setDest(sf::Vector2f pos);
	void setPos(sf::Vector2f pos);
	EnemyType getType();
private:
	sf::Sprite sprite;
	Characteristics characteristics;
	EnemyState enemyState;
	EnemyType enemyType;
	sf::Vector2f dest;
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
