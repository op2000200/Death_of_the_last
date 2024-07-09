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
	struct ArcadeModeCharacterPrepareScreen
	{
		sf::RectangleShape background;
		sf::RectangleShape backBody;
		sf::Text backLabel;
		sf::RectangleShape classBody;
		sf::Sprite classImage;
		sf::Texture classImageTexture;
		sf::RectangleShape elementBorder;
		sf::Sprite elementImage;
		sf::Texture elementTextureFire;
		sf::Texture elementTextureIce;
		sf::Texture elementTextureStone;
		sf::Texture elementTextureElec;
		sf::Texture elementTextureWater;
		sf::Texture elementTextureWind;
		sf::Texture elementTextureLight;
		sf::Texture elementTextureDark;
		sf::RectangleShape fireBody;
		sf::RectangleShape iceBody;
		sf::RectangleShape stoneBody;
		sf::RectangleShape elecBody;
		sf::RectangleShape waterBody;
		sf::RectangleShape windBody;
		sf::RectangleShape lightBody;
		sf::RectangleShape darkBody;
		sf::Text fireLabel;
		sf::Text iceLabel;
		sf::Text stoneLabel;
		sf::Text elecLabel;
		sf::Text waterLabel;
		sf::Text windLabel;
		sf::Text lightLabel;
		sf::Text darkLabel;
		sf::RectangleShape playBody;
		sf::Text playLabel;
		sf::RectangleShape castSettings;
		sf::Text castLabel;
	};
	struct ArcadeModeSpellScreen
	{
		sf::RectangleShape background;
		sf::RectangleShape backBody;
		sf::Text backLabel;
		//toggled
		sf::RectangleShape spell1IsMain;
		sf::RectangleShape spell2IsMain;
		sf::RectangleShape spell3IsMain;
		sf::RectangleShape spell4IsMain;
		//basic
		sf::RectangleShape spell1Back;
		sf::Texture spell1Texture;
		sf::Sprite spell1Sprite;
		sf::RectangleShape spell1elem1;
		sf::RectangleShape spell1elem2;
		sf::RectangleShape spell1elem3;
		sf::RectangleShape spell1elem4;
		sf::RectangleShape spell1elem5;
		sf::RectangleShape spell1elem6;
		sf::RectangleShape spell1elem7;
		sf::RectangleShape spell1elem8;
		sf::RectangleShape spell1elem9;
		sf::RectangleShape spell1elem10;
		//aimed
		sf::RectangleShape spell2Back;
		sf::Texture spell2Texture;
		sf::Sprite spell2Sprite;
		sf::RectangleShape spell2elem1;
		sf::RectangleShape spell2elem2;
		sf::RectangleShape spell2elem3;
		sf::RectangleShape spell2elem4;
		sf::RectangleShape spell2elem5;
		sf::RectangleShape spell2elem6;
		sf::RectangleShape spell2elem7;
		sf::RectangleShape spell2elem8;
		sf::RectangleShape spell2elem9;
		sf::RectangleShape spell2elem10;
		//explosive
		sf::RectangleShape spell3Back;
		sf::Texture spell3Texture;
		sf::Sprite spell3Sprite;
		sf::RectangleShape spell3elem1;
		sf::RectangleShape spell3elem2;
		sf::RectangleShape spell3elem3;
		sf::RectangleShape spell3elem4;
		sf::RectangleShape spell3elem5;
		sf::RectangleShape spell3elem6;
		sf::RectangleShape spell3elem7;
		sf::RectangleShape spell3elem8;
		sf::RectangleShape spell3elem9;
		sf::RectangleShape spell3elem10;
		//fast
		sf::RectangleShape spell4Back;
		sf::Texture spell4Texture;
		sf::Sprite spell4Sprite;
		sf::RectangleShape spell4elem1;
		sf::RectangleShape spell4elem2;
		sf::RectangleShape spell4elem3;
		sf::RectangleShape spell4elem4;
		sf::RectangleShape spell4elem5;
		sf::RectangleShape spell4elem6;
		sf::RectangleShape spell4elem7;
		sf::RectangleShape spell4elem8;
		sf::RectangleShape spell4elem9;
		sf::RectangleShape spell4elem10;
		//meteor
		sf::RectangleShape spell5Back;
		sf::Texture spell5Texture;
		sf::Sprite spell5Sprite;
		sf::RectangleShape spell5elem1;
		sf::RectangleShape spell5elem2;
		sf::RectangleShape spell5elem3;
		sf::RectangleShape spell5elem4;
		sf::RectangleShape spell5elem5;
		sf::RectangleShape spell5elem6;
		sf::RectangleShape spell5elem7;
		sf::RectangleShape spell5elem8;
		sf::RectangleShape spell5elem9;
		sf::RectangleShape spell5elem10;
		//mana collumn
		sf::RectangleShape spell6Back;
		sf::Texture spell6Texture;
		sf::Sprite spell6Sprite;
		sf::RectangleShape spell6elem1;
		sf::RectangleShape spell6elem2;
		sf::RectangleShape spell6elem3;
		sf::RectangleShape spell6elem4;
		sf::RectangleShape spell6elem5;
		sf::RectangleShape spell6elem6;
		sf::RectangleShape spell6elem7;
		sf::RectangleShape spell6elem8;
		sf::RectangleShape spell6elem9;
		sf::RectangleShape spell6elem10;
		//spray orb
		sf::RectangleShape spell7Back;
		sf::Texture spell7Texture;
		sf::Sprite spell7Sprite;
		sf::RectangleShape spell7elem1;
		sf::RectangleShape spell7elem2;
		sf::RectangleShape spell7elem3;
		sf::RectangleShape spell7elem4;
		sf::RectangleShape spell7elem5;
		sf::RectangleShape spell7elem6;
		sf::RectangleShape spell7elem7;
		sf::RectangleShape spell7elem8;
		sf::RectangleShape spell7elem9;
		sf::RectangleShape spell7elem10;
		//spray orb small
		sf::RectangleShape spell8Back;
		sf::Texture spell8Texture;
		sf::Sprite spell8Sprite;
		sf::RectangleShape spell8elem1;
		sf::RectangleShape spell8elem2;
		sf::RectangleShape spell8elem3;
		sf::RectangleShape spell8elem4;
		sf::RectangleShape spell8elem5;
		sf::RectangleShape spell8elem6;
		sf::RectangleShape spell8elem7;
		sf::RectangleShape spell8elem8;
		sf::RectangleShape spell8elem9;
		sf::RectangleShape spell8elem10;
		//aoe
		sf::RectangleShape spell9Back;
		sf::Texture spell9Texture;
		sf::Sprite spell9Sprite;
		sf::RectangleShape spell9elem1;
		sf::RectangleShape spell9elem2;
		sf::RectangleShape spell9elem3;
		sf::RectangleShape spell9elem4;
		sf::RectangleShape spell9elem5;
		sf::RectangleShape spell9elem6;
		sf::RectangleShape spell9elem7;
		sf::RectangleShape spell9elem8;
		sf::RectangleShape spell9elem9;
		sf::RectangleShape spell9elem10;
		//force field
		sf::RectangleShape spell10Back;
		sf::Texture spell10Texture;
		sf::Sprite spell10Sprite;
		//stone skin
		sf::RectangleShape spell11Back;
		sf::Texture spell11Texture;
		sf::Sprite spell11Sprite;
		//live shield
		sf::RectangleShape spell12Back;
		sf::Texture spell12Texture;
		sf::Sprite spell12Sprite;
		//mana shield
		sf::RectangleShape spell13Back;
		sf::Texture spell13Texture;
		sf::Sprite spell13Sprite;
		sf::RectangleShape spell13elem1;
		sf::RectangleShape spell13elem2;
		sf::RectangleShape spell13elem3;
		sf::RectangleShape spell13elem4;
		sf::RectangleShape spell13elem5;
		sf::RectangleShape spell13elem6;
		sf::RectangleShape spell13elem7;
		sf::RectangleShape spell13elem8;
		sf::RectangleShape spell13elem9;
		sf::RectangleShape spell13elem10;
		//sprint
		sf::RectangleShape spell14Back;
		sf::Texture spell14Texture;
		sf::Sprite spell14Sprite;
		//dimensional travel
		sf::RectangleShape spell15Back;
		sf::Texture spell15Texture;
		sf::Sprite spell15Sprite;

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
	ArcadeModeCharacterPrepareScreen amCharPrepareScreen;
	ArcadeModeRunScreen amRunScreen;
	ArcadeModePauseScreen amPauseScreen;
	ArcadeModeLevelUpScreen amLevelUpScreen;
	ArcadeModeDeathScreen amDeathScreen;
	ArcadeModeSpellScreen amSpellScreen;
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

	Element element;
};