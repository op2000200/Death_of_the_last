#pragma once
#include "Structures.h"
class Tile
{
public:
	Tile();
	Tile(TileType tileType, int pos_x, int pos_y, int index_x, int index_y, int side);
	~Tile();
	sf::RectangleShape getBody();
	sf::RectangleShape getHitbox();
	sf::Vector2i getIndex();

private:
	sf::RectangleShape body;
	sf::RectangleShape hitbox;
	sf::Vector2i index;
};
