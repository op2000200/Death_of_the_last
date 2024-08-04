#pragma once
#include "Structures.h"
#include "Enemy.h"
#include "Player.h"
class Tile
{
public:
	Tile();
	Tile(TileType tileType, int pos_x, int pos_y, int index_x, int index_y, int side, float diff);
	~Tile();
	sf::RectangleShape getBody();
	sf::RectangleShape getHitbox();
	sf::Vector2i getIndex();
	void clear();
	void solve();
	LevelGoal getGoal();
	TileStatus getState();
	std::vector<Enemy> getEnemyBuffer();
	void spawnEnemies(float diff, int side, int pos_x, int pos_y);
	void spawnEnemiesWave(int side);
	void spawnChallenge(float diff);
	void spawnReward(float diff);
	void tickTile(Player* player, Tile tile);
	bool isEnemyWallHit(Enemy enemy, int speed);
	bool isEnemyEnemyHit(Enemy enemy, int speed);

private:
	sf::RectangleShape body;
	sf::RectangleShape hitbox;
	sf::Vector2i index;
	TileStatus tileStatus;
	LevelGoal goal;
	TileType type;
	std::vector<Enemy> enemyBuffer;
	int remainigSpawns;
};
