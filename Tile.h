#pragma once
#include "SFML/Graphics.hpp"
class Tile
{
public:
	Tile(int num, int numR, sf::Vector2f pos, sf::Texture* tex, int x, int y);
	~Tile();

	sf::Sprite getSprite();

	int rockNum();
	sf::Sprite getRock(int i);
	int getRand();

	bool isBlocked(sf::Vector2f pos);
private:
	int type;
	int randNum;
	sf::Sprite sprite;
	sf::Texture* texture;
	sf::Image image;
	std::vector<sf::Sprite> rocks;
	std::vector<sf::Sprite> lava;
	int state;
};

