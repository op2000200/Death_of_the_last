#include "Game.h"
Game::Game()
	: window(sf::VideoMode(1920, 1080), "Death of the last", sf::Style::Fullscreen)
{

}

void Game::run()
{
	while (window.isOpen())
	{
		mainMenu();
	}
}

void Game::render()
{
	window.clear();
}

void Game::mainMenu()
{
	sf::RectangleShape background;
	background.setPosition(sf::Vector2f(0,0));
	background.setSize(sf::Vector2f(1920, 1080));
	background.setFillColor(sf::Color::Color(105,105,105));
	window.clear();
	window.draw(background);
	sf::Font fontMainMenu;
	fontMainMenu.loadFromFile("assets/font/Humane-ExtraBold.ttf");
	sf::Text name1;
	name1.setFont(fontMainMenu);
	name1.setString("DEATH OF THE LAST");
	name1.setPosition(sf::Vector2f(40, 50));
	name1.setFillColor(sf::Color::Color(140,120,120));
	name1.setCharacterSize(500);
	window.draw(name1);
	window.display();
}