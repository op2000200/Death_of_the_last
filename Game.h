#pragma once
#include <SFML/Graphics.hpp>
#include "button.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
class Game
{
public: //public methods
	Game();
	void run();
private: //private methods
	//general
	//main menu
	void mainMenu();
	void drawMM();
	void updateMM();
	void readInputMM();
	//arcade mode
	void arcadeMode();
	void arcadeModeRun(Player* player);
	void arcadeModeRunUpdate();
	void updatePlayer(sf::Time elapsedTime, Player* player);
	void updateBullets(sf::Time elapsedTime, Player* player);
	void updateEnemies(sf::Time elapsedTime, Player* player);
	void updateCollision(sf::Time elapsedTime, Player* player);
	void arcadeModeRunDraw(Player* player);
	void arcadeModePauseUpdate();
	void arcadeModePause();
	void arcadeModePauseDraw(sf::Sprite prevFrame);
	void readInputAM();
	//other
	void render();
	void processInput();
private: //private variables
	button buttonSM;
	button buttonAM;
	button buttonSettings;
	button buttonExit;
	button buttonArcadeModePauseMM;
	sf::Text labelButtonSM;
	sf::Text labelButtonAM;
	sf::Text labelbuttonSettings;
	sf::Text labelbuttonExit;
	sf::Text labelbuttonArcadeModePauseMM;
	sf::RenderWindow window;
	sf::Font fontMM;
	sf::Font fontMM2;
	sf::Texture cursorTexture;
	sf::Texture pausedScreen;
	sf::Texture* playerTexture;
	Player* player;
	int playerState;
	int state; //0 - main menu; 1 - story mode; 2 - arcade mode; 3 - settings menu; 4 - exit
	int paused;
	int* inputs = new int[200];
	int enemyCooldown;
	int enemyTickCounter;
	int enemyCounter;
	/*
	* 0 - esc
	* 1 - w
	* 2 - a
	* 3 - s
	* 4 - d
	* 5 - lmb
	* 6 -
	* 7 -
	* 8 -
	* 9 -
	* 10 -
	*/
};

