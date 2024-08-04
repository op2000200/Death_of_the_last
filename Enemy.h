#pragma once
#include "Structures.h"
class Enemy
{
public:
	Enemy(int pos_x, int pos_y, int side);
	~Enemy();
	sf::CircleShape getHitbox();
	void move(sf::Vector2f delta);
	EnemyState getState();
	void setState(EnemyState st);
	EnemyBehavior getBehav();
	void setBehav(EnemyBehavior bv);
	int getHealth();
	void setHealth(int buf);
	sf::Vector2f getDest();
	void setDest(sf::Vector2f buf);
	void getDamage(int dmg);

private:
	sf::CircleShape hitbox;
	EnemyState state;
	EnemyBehavior behav;
	sf::Vector2f dest;
	int health;
};
