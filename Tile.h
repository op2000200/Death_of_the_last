#pragma once
#include "Structures.h"
#include "Enemy.h"
#include "Player.h"
#include "Wall.h"
class Tile
{
public:
	Tile();
	Tile(TileType tileType, int pos_x, int pos_y, int index_x, int index_y, int side, float diff, sf::Texture* bg, sf::Texture* bg2);
	~Tile();
	sf::RectangleShape getBody();
	sf::RectangleShape getHitbox();
	sf::Sprite getSprite();
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
	void spawnChallenge(float diff);
	void spawnReward(float diff);
	void spawnWalls(int up, int left, int down, int right, sf::Texture* bx);
	void createWallRow(int dir, sf::Vector2i index, int chance, sf::Texture* bx);
	Wall getWallById(sf::Vector2i ind);
	void delWallById(int id);
	void dmgWall(sf::Vector2i ind, int dmg);
	bool tickTile(Player* player, Tile tile);
	bool isEnemyWallHit(Enemy enemy, int speed);
	bool isEnemyEnemyHit(Enemy enemy, int speed);
	bool isPlayerWeaponHit(Player* player, RangedWeapon weapon);
	bool isPlayerWeaponHit(Player* player, MeleeWeapon weapon);
	bool isProjEnemyHit(Projectile proj, Enemy enemy, int speed);
	void damageEnemy(int i, int dmg);
	std::vector<sf::Vector2i> getWallsToDraw();
	bool isReachable(int startx, int starty, int finx, int finy, int len);
	void alert(int id, sf::Vector2i d);
	void move(sf::Vector2f delta);
	void setGreen();
	void setRed();
	void setYellow();
	std::vector<sf::Vector2i> makePath(Enemy en);
	std::vector<sf::Vector2i> makeLine(sf::Vector2i p1, sf::Vector2i p2);
	std::vector<sf::Vector2i> goAround(sf::Vector2i p1, sf::Vector2i p2, int dir);
	std::vector<sf::Vector2i> pathFind(sf::Vector2i p1, sf::Vector2i p2, int dir);
	bool makePoints(sf::Vector2i p1, sf::Vector2i p2, int len);

private:
	sf::RectangleShape body;
	sf::RectangleShape hitbox;
	sf::Sprite sprite;
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
	std::vector<sf::Vector2i> enemyPath;
};
