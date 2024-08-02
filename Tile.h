#pragma once
#include "Structures.h"
#include "Enemy.h"
class Tile
{
public:
	Tile();
	Tile(TileType tileType, int pos_x, int pos_y, int index_x, int index_y, int side);
	~Tile();
	sf::RectangleShape getBody();
	sf::RectangleShape getHitbox();
	sf::Vector2i getIndex();
	void clear();
	LevelGoal getGoal();
	std::vector<Enemy> getEnemyBuffer();
	void spawnEnemies();
	void spawnChallenge();
	void spawnReward();

private:
	sf::RectangleShape body;
	sf::RectangleShape hitbox;
	sf::Vector2i index;
	TileStatus tileStatus;
	LevelGoal goal;
	std::vector<Enemy> enemyBuffer;
};
