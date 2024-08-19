#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Structures.h"
#include "Player.h"
#include "Tile.h"
#include "Projectile.h"
#include <vector>

class Game
{
public:
	Game();
	~Game();
	void run();
	void initial();
	void generateMap();
	void generateLevel(int pos_x, int pos_y, int index_x, int index_y, int dir, int len);
	void spawnPlayer();
	void events();
	void commands();
	bool isPlayerWallCollision(int index_x, int index_y, int dir);
	bool isPlayerWallHit(int index_x, int index_y, int dir, int speed);
	bool isProjWallHit(Projectile proj, int index_x, int index_y, sf::Vector2f dir, int speed);
	bool isPlayerInnerWallHit(int index_x, int index_y, int dir, int speed);
	bool isMeleeEnemyHit(sf::RectangleShape hitbox, Enemy enemy);
	bool isMeleeWallHit(sf::RectangleShape hitbox, Wall wall);
private:
	sf::RenderWindow window;
	int side;
	std::vector<Command> commandQueue;
	Player* player;
	std::vector<Projectile> projectileBuffer;
	std::vector<sf::Vector2i> loadedTiles;
	Tile** tileData;
	Tile** tileDataMini;
	InterfaceElements hud;
	bool** tileCreated;
	int tileNumOffset;
	sf::Time timePerFrame;
	sf::Time timePerFrame2;
	sf::View camera;
	int playerSpeed;
	sf::Font NataSans;
	sf::Texture tileSetBg;
	sf::Texture* ar10texture;
	sf::Texture* swmptexture;
	sf::Texture* vp70texture;
	sf::Texture* m88texture;
	sf::Texture* mr133texture;
	sf::Texture* grozatexture;
	sf::Texture* xm8texture;
	sf::Texture* ar15texture;
	std::vector<sf::Texture*> textureHolder;
	float difficulty;
	sf::Clock dashTimer;
	sf::Clock rangedAttackTimer;
	sf::Clock meleeAttackTimer;
	sf::Clock reloadTimer;
	sf::Clock interactionTimer;
	sf::Clock displayTimer;
	int bulletsShot;	//to count when to reload
	Overlay overlay;
	int roomsCount;
	int roomsVisited;
	int floor;
	bool mapShow;
	bool sneak;
	bool sprint;
};