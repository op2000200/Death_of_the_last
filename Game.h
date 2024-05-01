#pragma once
#include <SFML/Graphics.hpp>
#include "button.h"
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
	void arcadeModeRun();
	void arcadeModeRunDraw();
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
	int state; //0 - main menu; 1 - story mode; 2 - arcade mode; 3 - settings menu; 4 - exit
	int paused;
};

