#pragma once
#include "Structures.h"
class Wall
{
public:
	Wall();
	Wall(int pos_x, int pos_y, int side);
	~Wall();
	void damaged(int dmg);
	sf::RectangleShape getHitbox();
	int getHealth();
	int getHeight();
	void spawn();
	WallState getWS();
	void setWS(WallState st);

private:
	sf::RectangleShape hitbox;
	int connections;
	int health;
	WallState ws;
	int height;
};


