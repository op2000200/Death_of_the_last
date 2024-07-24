#pragma once
#include <SFML/Graphics.hpp>
#include "Structures.h"

class Enemy
{
public:
	Enemy();
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
	void setType(EnemyType et);
	int getAbilC();
	int getAbilCC();
	void ticlAbilCC();
	void resAbilCC();

	int getBufSize();
	sf::Sprite getBufSprite(int index);
	void setBufDest(int index, sf::Vector2f pos);
	sf::Vector2f getBufDest(int index);
	void setBufPos(int index, sf::Vector2f pos);
	void addToBuf(Enemy en);
	void delFromBuf(int index);
	Characteristics getBufChar(int index);
private:
	sf::Sprite sprite;
	Characteristics characteristics;
	EnemyState enemyState;
	EnemyType enemyType;
	sf::Vector2f dest;
	int abilityCooldown;
	int abilityCooldownCounter;
	std::vector<Enemy> summonedBuffer;
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
