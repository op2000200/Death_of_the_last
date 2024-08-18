#pragma once
#include "Structures.h"
#include "Enemy.h"
#include "Player.h"
#include "Wall.h"
class Tile
{
public:
	Tile();
	Tile(TileType tileType, int pos_x, int pos_y, int index_x, int index_y, int side, float diff, std::vector<sf::Texture*> textureHolder);
	~Tile();
	sf::RectangleShape getBody();
	sf::RectangleShape getHitbox();
	sf::Vector2i getIndex();
	void clear();
	void solve();
	LevelGoal getGoal();
	TileStatus getState();
	TileType getType();
	std::vector<Enemy> getEnemyBuffer();
	std::vector<RangedWeapon> getRangedBuffer();
	std::vector<MeleeWeapon> getMeleeBuffer();
	void delRangedBufferElem(int i);
	void delMeleeBufferElem(int i);
	void spawnEnemies(float diff, int side, int pos_x, int pos_y);
	void spawnEnemiesWave(int side);
	void spawnChallenge(float diff);
	void spawnReward(float diff);
	void spawnWalls(int up, int left, int down, int right);
	void createWallRow(int dir, sf::Vector2i index, int chance);
	Wall getWallById(sf::Vector2i ind);
	bool tickTile(Player* player, Tile tile);
	bool isEnemyWallHit(Enemy enemy, int speed);
	bool isEnemyEnemyHit(Enemy enemy, int speed);
	bool isPlayerWeaponHit(Player* player, RangedWeapon weapon);
	bool isPlayerWeaponHit(Player* player, MeleeWeapon weapon);
	bool isProjEnemyHit(Projectile proj, Enemy enemy, int speed);
	void damageEnemy(int i, int dmg);
	std::vector<sf::Vector2i> getWallsToDraw();
	bool isReachable(int startx, int starty, int finx, int finy, int len);

private:
	sf::RectangleShape body;
	sf::RectangleShape hitbox;
	sf::Vector2i index;
	TileStatus tileStatus;
	LevelGoal goal;
	TileType type;
	std::vector<Enemy> enemyBuffer;
	int remainingSpawns;
	sf::Clock waveTimer;
	std::vector<RangedWeapon> rangedBuffer;
	std::vector<MeleeWeapon> meleeBuffer;
	Wall** walls;
	std::vector<sf::Vector2i> nonEmptyWalls;
	std::vector<sf::Vector2i> wallsToDraw;
};
