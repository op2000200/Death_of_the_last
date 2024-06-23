#pragma once
#include "SFML/Graphics.hpp"
class Tile
{
public:
	Tile(int num, int numR);
	~Tile();

	sf::Sprite getSprite();
private:
	int type;
	int randNum;
	sf::Sprite sprite;
	sf::Texture* texture;
	sf::Image image;
	int state;
};

