#pragma once
#include "Structures.h"
class Player
{
public:
	Player(int pos_x, int pos_y, int index_x, int index_y);
	~Player();
	sf::RectangleShape getHitbox();
	sf::Vector2i getIndex();
	void move(sf::Vector2f delta);
	void updateIndex(int side);

private:
	sf::RectangleShape hitbox;
	sf::Vector2i tileIndex;
};
