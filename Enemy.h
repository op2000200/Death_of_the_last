#pragma once
#include "Structures.h"
class Enemy
{
public:
	Enemy(int pos_x, int pos_y, int side, int x, int y);
	~Enemy();
	sf::CircleShape getHitbox();
	void move(sf::Vector2f delta);
	EnemyState getState();
	void setState(EnemyState st);
	EnemyBehavior getBehav();
	void setBehav(EnemyBehavior bv);
	int getHealth();
	void setHealth(int buf);
	sf::Vector2i getDest();
	void setDest(sf::Vector2i buf);
	sf::Vector2i getInd();
	void setInd(sf::Vector2i buf);
	sf::Vector2i getPoint();
	void setPoint(sf::Vector2i buf);
	void getDamage(int dmg);
	sf::RectangleShape getHpBar();

private:
	sf::CircleShape hitbox;
	sf::RectangleShape hpBar;
	EnemyState state;
	EnemyBehavior behav;
	sf::Vector2i dest;
	sf::Vector2i ind;
	sf::Vector2i point;

	int health;
};
