#pragma once

#include <iostream>
#include <thread>

#include <SFML/Graphics.hpp>
#include "SFML/System.hpp"

#include "Config.h"



enum class Type
{
	MainMenu,
	MainMenuFirstLaunch,
	MainMenuLoading,
	MainMenuLoaded,
	MainMenuGeneral,
	MainMenuExit,
	PlayMenu,
	PlayMenuModeSelector,
	PlayMenuArcadeModeLevelSelector,
	PlayMenuArcadeModeRun,
	PlayMenuArcadeModePause,
	PlayMenuArcadeModeLevelUp,
	PlayMenuArcadeModeDeath,
	SettingsMenu,
	ArchiveMenu,
	Exit,
	Blank
};

struct MainMenuRender
{
public:
	struct LoadingScreen
	{
		sf::RectangleShape background;
		sf::ConvexShape leftBlock;
		sf::RectangleShape rightBlock;
		sf::Text title;
		sf::Text loading;
	};
	struct MainMenuScreen
	{
		sf::RectangleShape background;
		sf::ConvexShape leftBlock;
		sf::RectangleShape rightBlock;
		sf::Text title;
		sf::RectangleShape playBody;
		sf::RectangleShape archiveBody;
		sf::RectangleShape settingsBody;
		sf::RectangleShape exitBody;
		sf::Text playText;
		sf::Text archiveText;
		sf::Text settingsText;
		sf::Text exitText;
	};
	struct ExitScreen
	{
		sf::Sprite prevScreen;
		sf::RectangleShape shade;
		sf::RectangleShape exitWindow;
		sf::RectangleShape exitYes;
		sf::RectangleShape exitNo;
		sf::Text exitWindowText;
		sf::Text exitYesText;
		sf::Text exitNoText;
	};
	struct SettingsScreen
	{
		sf::RectangleShape background;
		sf::RectangleShape videoBody;
		sf::Text videoLabel;
		sf::RectangleShape audioBody;
		sf::Text audioLabel;
		sf::RectangleShape gameBody;
		sf::Text gameLabel;
		sf::RectangleShape otherBody;
		sf::Text otherLabel;
		struct TabVideo
		{
			sf::Text resolutionLabel;
			//add dropdown list to resolution
			sf::Text verticalSync;
			//add checkbox to VSync
			sf::Text framerate;
			//add dropdown list to framerate
			sf::Text showFPS;
			//add checkbox to showFPS
		};
		struct TabAudio
		{
			sf::Text placeholder;
		};
		struct TabGame
		{
			sf::Text threadsNumber;
			//add dropdown list to threadnumber
		};
		struct TabOther
		{
			sf::Text VersionLabel;
			sf::Text VersionNum;
			sf::Text AuthorLabel;
			sf::Text AuthorName;
		};
		TabVideo tabVideo;
		TabAudio tabAudio;
		TabGame tabGame;
		TabOther tabOther;
	};
	LoadingScreen loadingScreen;
	MainMenuScreen mainMenuScreen;
	ExitScreen exitScreen;
	SettingsScreen settingsScreen;
};

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
	void settingsMenuReadInput();
	void settingsMenuDraw();


	Type playMenu();
	void playMenuRenderMenu();
	void playMenuRenderGame();


	void renderArcadeMode();


	Type archiveMenu();


private: 

public: //variables
	
private:
	sf::RenderWindow window;
	Config config;
	Type state;
	sf::Vector2f sizeMultiplier;
	RenderQueue renderQueue;
	sf::Font NataSans;
	sf::Texture* screenHolder;

	//main menu state variables
	Type mainMenuState;
	MainMenuRender mainMenuRender;


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
