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
private:
	sf::RenderWindow window;
	int side;
	std::vector<Command> commandQueue;
	Player* player;
	std::vector<Projectile> projectileBuffer;
	std::vector<sf::Vector2i> loadedTiles;
	Tile** tileData;
	InterfaceElements hud;
	bool** tileCreated;
	int tileNumOffset;
	sf::Time timePerFrame;
	sf::View camera;
	int playerSpeed;
	sf::Font NataSans;
	sf::Texture tileSetBg;
	float difficulty;
	sf::Clock dashTimer;
	sf::Clock rangedAttackTimer;
	sf::Clock meleeAttackTimer;
};