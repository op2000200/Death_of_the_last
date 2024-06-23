#include "Tile.h"

Tile::Tile(int num, int numR)
	:	sprite(*texture, sf::IntRect(0, 0, 2000, 2000))
{
	state = 0;
	type = num;
	randNum = numR;
	srand(randNum);
	sf::Color* palette = new sf::Color[5];
	palette[0] = sf::Color(79, 25, 16);
	palette[1] = sf::Color(74, 25, 17);
	palette[2] = sf::Color(94, 36, 26);
	palette[3] = sf::Color(71, 22, 14);
	palette[4] = sf::Color(64, 23, 16);
	image.create(2000, 2000, palette[rand() % 5]);
	texture = new sf::Texture;
	texture->loadFromImage(image);
	sprite.setTexture(*texture);
}

Tile::~Tile()
{

}

sf::Sprite Tile::getSprite()
{
	return Tile::sprite;
}

