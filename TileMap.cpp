#include "TileMap.h"

TileMap::TileMap()
{
}

TileMap::~TileMap()
{
}

void TileMap::create(sf::Texture texture, int tileSize, Tile** tileData, int x, int y)
{
	tiles = new sf::VertexArray[y];
	for (int i = -y; i <= y; i++)
	{
		tiles[i+y].setPrimitiveType(sf::Quads);
		tiles[i+y].resize(x * 4);
	}

	for (int i = -y; i <= y; i++)
	{
		for (int j = -x; j <= x; j++)
		{
			sf::Vertex* quad = &tiles[i + y][(j + x) * 4];

			quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
			quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
			quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
			quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

			//quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			//quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			//quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			//quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			quad[0].texCoords = sf::Vector2f(0, 0);
			quad[1].texCoords = sf::Vector2f(tileSize, 0);
			quad[2].texCoords = sf::Vector2f(tileSize, tileSize);
			quad[3].texCoords = sf::Vector2f(0, tileSize);
		}
	}
	txture = texture;
	size = 2 * y + 1;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &txture;
	for (int i = 0; i < size; i++)
	{
		target.draw(tiles[i], states);
	}
}
