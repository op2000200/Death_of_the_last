#pragma once
#include "Structures.h"
#include "Tile.h"
class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	~TileMap();

	void create(sf::Texture texture, int tileSize, Tile** tileData, int x, int y);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray* tiles;
	int size;
	sf::Texture txture;
};

