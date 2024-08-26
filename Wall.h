#pragma once
#include "Structures.h"
class Wall
{
public:
	Wall();
	Wall(int pos_x, int pos_y, int side, sf::Texture* bx);
	~Wall();
	void damaged(int dmg);
	sf::RectangleShape getHitbox();
	sf::Sprite getSprite();
	int getHealth();
	int getHeight();
	void spawn();
	WallState getWS();
	void setWS(WallState st);

private:
	sf::RectangleShape hitbox;
	sf::Sprite sprite;
	int connections;
	int health;
	WallState ws;
	int height;
};


