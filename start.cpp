#include <SFML/Graphics.hpp>
#include "Game.h"

int WinMain()
{
	Config config;
	config.loadFromFIle("data/config.txt");
	Game game(config);
	config.~Config();
	game.run();
	game.~Game();
	sf::sleep(sf::Time(sf::seconds(20)));
}
