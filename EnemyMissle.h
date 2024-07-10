#pragma once
#include <SFML/Graphics.hpp>
#include "Structures.h"
class EnemyMissle
{
public:
	EnemyMissle(sf::Vector2f pos, sf::Texture* texture, Element element, sf::Vector2f tar);
	~EnemyMissle();
	sf::Sprite getSprite();
	Characteristics getChar();
	sf::Vector2f getDest();
	void setDest(sf::Vector2f pos);
	void setDir(sf::Vector2f pos);
	sf::Vector2f getDir();
	void setPos(sf::Vector2f pos);
	void setHealth(float num);
private:
	sf::Sprite sprite;
	sf::Vector2f target;
	sf::Vector2f dir;
	Characteristics characterisctics;
};

//#include <SFML/Graphics.hpp>
//class Bullet
//{
//public:
//    Bullet();
//    Bullet(sf::Vector2f pos, sf::Texture* texture);
//    ~Bullet();
//public:
//    sf::Sprite getSprite();
//    sf::Vector2f getDir();
//    int getHealth();
//    int getSpeed();
//
//    void setDir(sf::Vector2f coord);
//    void setPos(sf::Vector2f coord);
//    void setHealth(int num);
//    void setSpeed(int num);
//private:
//    sf::Sprite sprite;
//    sf::Vector2f direction;
//    int health;
//    int speed;
//};
//