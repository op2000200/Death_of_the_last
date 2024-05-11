#pragma once
#include "SFML/Graphics.hpp"
class CheckBox
{
public:
	CheckBox(sf::Vector2f pos, sf::Vector2f size);
	void clicked();
	sf::RectangleShape getRect();
	sf::CircleShape getCirc();
	int getState();
private:
	sf::RectangleShape out;
	sf::CircleShape in;
	int state;
};

