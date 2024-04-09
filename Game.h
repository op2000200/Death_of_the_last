#pragma once
#include <SFML/Graphics.hpp>
class Game
{
public: //public methods
	Game();
	void run();
private: //private methods
	void render();
	void mainMenu();
private: //private variables
	sf::RenderWindow window;
};

