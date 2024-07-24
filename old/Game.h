#pragma once

#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"

#include "Config.h"
#include "Tile.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyMissle.h"
#include "BasicMissle.h"
#include "AimedMissle.h"
#include "ExplosiveMissle.h"
#include "FastMissle.h"
#include "Meteor.h"
#include "ManaStrike.h"
#include "SprayOrb.h"
#include "SprayOrbSmall.h"
#include "AOE.h"
#include "ForceField.h"
#include "StoneSkin.h"
#include "LiveShield.h"
#include "ManaShield.h"
#include "Sprint.h"
#include "DimensionalTravel.h"

#include "Structures.h"

class Game
{
public: //methods
	Game(Config startConfig);
	~Game();
	void run();
	bool isHover(sf::Vector2i mousePos, sf::Vector2f objectPos, sf::Vector2f objectSize);
	
		Type mainMenu();

			void renderMM();

			void loadingScreen();
				void loadingScreenReadUserData();
				void loadingScreenDraw();
				void loadingScreenReadInput();

			Type mainMenuScreen();
				void mainMenuScreenReadInput();
				void mainMenuScreenDraw();


			Type exitScreen();
				void exitScreenReadInput();
				void exitScreenDraw();


		Type settingsMenu();
			void renderSM();
			void settingsMenuReadInput();
			void settingsMenuDraw();


		Type playMenu();
			void renderPMMenu(); //mode selector and AM level selector
			void renderPMGame(); //AM run, pause, death and level up

			void modeSelector();
				void modeSelectorDraw();
				void modeSelectorReadInput();
				void AMLevelSelector();
					void AMLevelSelectorDraw();
					void AMLevelSelectorReadInput();
					void AMCharacterPrepare();
						void AMCharacterPrepareDraw();
						void AMCharacterPrepareReadInput();
						void AMSpellScreen();
							void AMSpellScreenDraw();
							void AMSpellScreenReadInput();
						void AMRun();
							void AMRunDraw();
							void AMRunReadInput();

							void AMRunCreateTexturesMap(int n);
							void AMRunCreateMap();

							void AMRunSpawn();
								void AMRunSpawnPlayer();
								void AMRunSpawnEnemy(sf::Vector2f pos, EnemyType type, Element element, Enemy* en);
								void AMRunSpawnEnemyMissle(sf::Vector2f pos, Element element, sf::Vector2f tar);
								void AMRunSpawnProjectiles();
								void AMRunSpawnEnvironment();


							void AMRunUpdate();
								void AMRunUpdatePlayer();
								void AMRunUpdateCamera();
								void AMRunUpdateEnemy();
									void AMRunUpdateBosses();
								void AMRunUpdateProjectiles();
								void AMRunUpdateCollisions();
								void AMRunUpdateEnvironment();

							void AMRunDestroyFarEntities();

					void AMPause();
						void AMPauseDraw();
						void AMPauseReadInput();
					void AMLevelUp();
					void AMDeath();


		Type archiveMenu();


private: 

public: //variables
	
private:
	sf::RenderWindow window;
	sf::ContextSettings settings;
	sf::View center;
	Config config;
	Type state;
	sf::Vector2f sizeMultiplier;
	sf::Font NataSans;
	sf::Texture* screenHolder;
	RenderList allMenus;

	//main menu state variables
	Type mainMenuState;

	//settings menu variables
	Type settingsMenuState;

	//play menu variables
	Type playMenuState;
	int diff;
	std::vector<Tile> map;
	sf::Texture* tileTextureHolder;
	sf::Image* image;
	std::vector<Commands> playerCommandStream;
	Player* player;
	std::vector<Enemy> enemyBuffer;
	std::vector<Enemy> enemyBuffer2;
	std::vector<EnemyMissle> enemyMissle;
	std::vector<EnemyMissle> enemyMissle2;
	sf::Texture* enemyTextureMissleFire;
	sf::Texture* enemyTextureMissleIce;
	sf::Texture* enemyTextureMissleElectricity;
	sf::Texture* enemyTextureMissleWater;
	sf::Texture* enemyTextureMissleStone;
	sf::Texture* enemyTextureMissleWind;
	sf::Texture* enemyTextureFire;
	sf::Texture* enemyTextureFireShtr;
	sf::Texture* enemyTextureFireKami;
	sf::Texture* enemyTextureIce;
	sf::Texture* enemyTextureIceShtr;
	sf::Texture* enemyTextureIceKami;
	sf::Texture* enemyTextureElectricity;
	sf::Texture* enemyTextureElectricityShtr;
	sf::Texture* enemyTextureElectricityKami;
	sf::Texture* enemyTextureWater;
	sf::Texture* enemyTextureWaterShtr;
	sf::Texture* enemyTextureWaterKami;
	sf::Texture* enemyTextureStone;
	sf::Texture* enemyTextureStoneShtr;
	sf::Texture* enemyTextureStoneKami;
	sf::Texture* enemyTextureWind;
	sf::Texture* enemyTextureWindShtr;
	sf::Texture* enemyTextureWindKami;
	sf::Texture* enemyTextureLight;
	sf::Texture* enemyTextureLightShtr;
	sf::Texture* enemyTextureLightKami;
	sf::Texture* enemyTextureDark;
	sf::Texture* enemyTextureDarkShtr;
	sf::Texture* enemyTextureDarkKami;
	sf::Texture* enemyTextureForce;
	sf::Texture* enemyTextureForceShtr;
	sf::Texture* enemyTextureForceKami;
	sf::Texture* enemyTexturePhys;
	sf::Texture* enemyTexturePhysShtr;
	sf::Texture* enemyTexturePhysKami;
	int enemyTimer;
	int autoCastCooldown;
	bool elementClicked;	//for amCharPrepScreen
	Element elementChoosen;
	int mainSpell;
	int* spellElem;
	bool enemyBufferReady;
	std::vector<BasicMissle> basicMissleBuffer;
	std::vector<BasicMissle> basicMissleBuffer2;
	bool basicMissleBufferReady;
	sf::Texture* basicFire;

	std::vector<AimedMissle> aimedMissleBuffer;
	std::vector<AimedMissle> aimedMissleBuffer2;
	bool aimedMissleBufferReady;
	sf::Texture* aimedFire;

	std::vector<ExplosiveMissle> explosiveMissleBuffer;
	std::vector<ExplosiveMissle> explosiveMissleBuffer2;
	bool explosiveMissleBufferReady;
	sf::Texture* explosiveFire;

	std::vector<FastMissle> fastMissleBuffer;
	std::vector<FastMissle> fastMissleBuffer2;
	bool fastMissleBufferReady;
	sf::Texture* fastFire;

	std::vector<Meteor> meteorBuffer;
	std::vector<Meteor> meteorBuffer2;
	bool meteorBufferReady;
	sf::Texture* meteorFire;

	std::vector<ManaStrike> manaStrikeBuffer;
	std::vector<ManaStrike> manaStrikeBuffer2;
	bool manaStrikeBufferReady;
	sf::Texture* manaStrikeFire;

	std::vector<SprayOrb> sprayOrbBuffer;
	std::vector<SprayOrb> sprayOrbBuffer2;
	bool sprayOrbBufferReady;
	sf::Texture* sprayOrbFire;

	std::vector<SprayOrbSmall> sprayOrbSmallBuffer;
	std::vector<SprayOrbSmall> sprayOrbSmallBuffer2;
	bool sprayOrbSmallBufferReady;

	std::vector<AOE> aoeBuffer;
	std::vector<AOE> aoeBuffer2;
	bool aoeBufferReady;
	sf::Texture* AOEFire;

};



//#include "button.h"
//#include "Bullet.h"
//#include "Enemy.h"
//#include "Player.h"
//#include "Mana.h"
//#include "CheckBox.h"
//#include "BasicMissleCold.h"
//#include "StandartEnemy.h"
//#include "Tile.h"
//class Game
//{
//public: //public methods
//	Game();
//	void run();
//private: //private methods
//	//general
//	//main menu
//	void mainMenu();
//	void drawMM();
//	void updateMM();
//	void readInputMM();
//	//arcade mode
//	void arcadeMode();
//	void arcadeModeRun(Player* player);
//	void arcadeModeRunUpdate();
//	void updatePlayer(sf::Time elapsedTime, Player* player);
//	void updateTiles(Player* player);
//	void updateMana(sf::Time elapsedTime, Player* player);
//	void updateBullets(sf::Time elapsedTime, Player* player);
//
//	void updateBasicMissle(sf::Time elapsedTime, Player* player);
//
//	void updateEnemies(sf::Time elapsedTime, Player* player);
//	void updateCollision(sf::Time elapsedTime, Player* player);
//	void updateLevel(sf::Time elapsedTime, Player* player);
//	void collectFarObjects(sf::Time elapsedTime, Player* player);
//	void arcadeModeRunDraw(Player* player);
//	void arcadeModeRunCreateBG();
//	void arcadeModePauseUpdate();
//	void arcadeModePause();
//	void arcadeModePauseDraw(sf::Sprite prevFrame);
//	void arcadeModeDeath();
//	void arcadeModeDeathDraw(std::string time);
//	void arcadeModeLevelUp(Player* player);
//	void arcadeModeLevelUpUpdate(sf::Time elapsedTime, Player* player);
//	void arcadeModeLevelUpDraw(sf::Sprite prevFrame);
//	void readInputAM();
//	//settings
//	void settings();
//	void settingsReadInput();
//	void settingsDraw(CheckBox checkBox);
//	void settingsUpdate(CheckBox checkBox);
//
//	//other
//	//void render();
//	//void processInput();
//private: //private variables
//	button buttonSM;
//	button buttonAM;
//	button buttonSettings;
//	button buttonExit;
//	button buttonArcadeModePauseMM;
//	button buttonArcadeModeUpCastSpeed;
//	button buttonArcadeModeUpSpeed;
//	button buttonArcadeModeHeal;
//	sf::Text labelButtonSM;
//	sf::Text labelButtonAM;
//	sf::Text labelbuttonSettings;
//	sf::Text labelbuttonExit;
//	sf::Text labelbuttonArcadeModePauseMM;
//	sf::Text labelbuttonArcadeModeUpCastSpeed;
//	sf::Text labelbuttonArcadeModeUpSpeed;
//	sf::Text labelbuttonArcadeModeHeal;
//	sf::Text labelStatistic;
//	sf::RenderWindow window;
//	sf::Font fontMM;
//	sf::Font fontMM2;
//	sf::Texture cursorTexture;
//	sf::Texture pausedScreen;
//	sf::Texture* playerTexture;
//	sf::Texture* enemyTexture;
//	sf::Texture* bulletTexture;
//	sf::Texture* bgTexture;
//	sf::Texture* manaTexture;
//	sf::Texture* BasicMissleColdTexture;
//	sf::Texture* StandartEnemyFireTexture;
//	sf::Clock timer;
//	sf::Clock timerHealth;
//	Player* player;
//	int castCooldown;
//	std::vector<Enemy> enemyBuffer;
//	int enemyCooldown;
//	int enemyTickCounter;
//	int enemyCounter;
//
//	std::vector<StandartEnemy> StandartEnemyFireBuffer;
//
//	std::vector<Bullet> bulletBuffer;
//	int bulletCounter;
//
//
//	std::vector<Mana> manaBuffer;
//	int manaCounter;
//	int manaTickCounter;
//
//	std::vector<BasicMissleCold> basicMissleColdBuffer;
//	int basicMissleColdCounter;
//	int basicMissleColdCooldown;
//
//
//	int settingState; //0 = video 1 = audio 2 = gameplay
//
//	int enemyCooldownVar;
//	int enemyCountVar;
//	int manaCountVar;
//
//	Tile** tileBuffer;
//
//	int playerState;
//	int playerDeath;
//	int levelUp;
//	int state; //0 - main menu; 1 - story mode; 2 - arcade mode; 3 - settings menu; 4 - exit
//	int paused;
//	int* inputs = new int[200];
//
//	/*
//	* 0 - esc
//	* 1 - w
//	* 2 - a
//	* 3 - s
//	* 4 - d
//	* 5 - lmb
//	* 6 -
//	* 7 -
//	* 8 -
//	* 9 -
//	* 10 -
//	*/
//};
//
