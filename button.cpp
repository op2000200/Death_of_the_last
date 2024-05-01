#include "button.h"

button::button()
{
	body.setPosition(800, 800);
	body.setSize(sf::Vector2f(200, 200));
	body.setFillColor(sf::Color::Black);
}

button::button(sf::Vector2f size, sf::Vector2f pos, sf::Color color, sf::Color outlineColor, float outlineThickness)
{
	body.setSize(size);
	body.setPosition(pos);
	body.setFillColor(color);
	body.setOutlineColor(outlineColor);
	body.setOutlineThickness(outlineThickness);
}

sf::RectangleShape button::getBody()
{
	return body;
}