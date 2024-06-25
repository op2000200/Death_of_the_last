#pragma once
#include "SFML/Graphics.hpp"
#include "Enums.h"

struct RenderList
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
		sf::RectangleShape buttonBlock;
		sf::RectangleShape backBody;
		sf::Text backLabel;
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
			sf::Text resolution;
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
			sf::Text Version;
			sf::Text Author;
		};
		TabVideo tabVideo;
		TabAudio tabAudio;
		TabGame tabGame;
		TabOther tabOther;
	};
	struct ModeSelectorScreen
	{
		sf::RectangleShape background;
		sf::RectangleShape backBody;
		sf::Text backLabel;
		sf::RectangleShape amBody;
		sf::Text amLabel;
		sf::RectangleShape smBody;
		sf::Text smLabel;
	};
	struct ArcadeModeLevelSelectorScreen
	{
		sf::RectangleShape background;
		sf::RectangleShape backBody;
		sf::Text backLabel;
		sf::RectangleShape left; //replace in future with triange
		sf::Text leftLabel;
		sf::RectangleShape right; //also replace
		sf::Text rightLabel;
		//make a comtainer for location thimbnails
		sf::RectangleShape easyBody;
		sf::Text easyLabel;
		sf::RectangleShape mediumBody;
		sf::Text mediumLabel;
		sf::RectangleShape hardBody;
		sf::Text hardLabel;
		sf::RectangleShape infiniteBody;
		sf::Text infiniteLabel;
		sf::RectangleShape diffDescBody;
		sf::Text diffDesc;
		sf::RectangleShape playBody;
		sf::Text playLabel;
	};
	struct ArcadeModeRunScreen
	{

	};
	struct ArcadeModePauseScreen
	{

	};
	struct ArcadeModeLevelUpScreen
	{

	};
	struct ArcadeModeDeathScreen
	{

	};
	LoadingScreen loadingScreen;
	MainMenuScreen mainMenuScreen;
	ExitScreen exitScreen;
	SettingsScreen settingsScreen;
	ModeSelectorScreen modeSelectorScreen;
	ArcadeModeLevelSelectorScreen amLevelSelectorScreen;
	ArcadeModeRunScreen amRunScreen;
	ArcadeModePauseScreen amPauseScreen;
	ArcadeModeLevelUpScreen amLevelUpScreen;
	ArcadeModeDeathScreen amDeathScreen;
};

struct Commands
{
	CommandType command;
	float* numbers = new float[5];
};

struct Characteristics
{
	//main
	float atk;	//attack
	float def;	//defence
	float agl;	//agility
	float vit;	//vitality
	float knw;	//knowledge
	//secondary
	float atkMul;
	float critChance;

	float defMul;
	float resistAll;
	float resistElement;

	float speed;
	float evasionChance;

	float healthMax;
	float healthCurrent;
	float healthRegen;
	float sprintLongevity;

	float atkSpeed;
	float manaMax;
	float manaReserved;
	float manaUsage;
	float manaRegen;
};