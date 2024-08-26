#pragma once
#include "Structures.h"
class Enemy
{
public:
	Enemy(int pos_x, int pos_y, int side, int x, int y);
	~Enemy();
	sf::CircleShape getHitbox();
	void setColor(sf::Color clr);
	void move(sf::Vector2f delta);
	EnemyState getState();
	void setState(EnemyState st);
	EnemyBehavior getBehav();
	void setBehav(EnemyBehavior bv);
	int getHealth();
	void setHealth(int buf);
	sf::Vector2i getDest();
	void setDest(sf::Vector2i buf);
	sf::Vector2f getInd();
	void setInd(sf::Vector2f buf);
	sf::Vector2i getPoint();
	void setPoint(sf::Vector2i buf);
	void getDamage(int dmg);
	sf::RectangleShape getHpBar();
	void restart();
	sf::Time getTime();
	void alert(sf::Vector2i d);
	sf::Vector2i getNextPoint();
	std::vector<sf::Vector2i> getPoints();
	void delFrstPoint();
	void addPoints(std::vector<sf::Vector2i> pt);


private:
	sf::CircleShape hitbox;
	sf::RectangleShape hpBar;
	EnemyState state;
	EnemyBehavior behav;
	sf::Vector2i dest;
	sf::Vector2f ind;
	sf::Vector2i point;
	std::vector<sf::Vector2i> points;
	sf::Clock timer;

	int health;
};
