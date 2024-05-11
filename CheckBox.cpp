#include "CheckBox.h"
CheckBox::CheckBox(sf::Vector2f pos, sf::Vector2f size)
{
	out.setPosition(pos);
	out.setSize(size);
	in.setPosition(pos + sf::Vector2f(5,5));
	in.setRadius((size.x) / 2 - 5);
	out.setFillColor(sf::Color(0,0,0,0));
	out.setOutlineColor(sf::Color::Black);
	out.setOutlineThickness(3.f);
	in.setFillColor(sf::Color::Black);
	state = 1;
}

void CheckBox::clicked()
{
	if (CheckBox::getState() == 1)
	{
		CheckBox::state = 0;
	}
	else
	{
		CheckBox::state = 1;
	}
}

sf::RectangleShape CheckBox::getRect()
{
	return CheckBox::out;
}

sf::CircleShape CheckBox::getCirc()
{
	return CheckBox::in;
}

int CheckBox::getState()
{
	return CheckBox::state;
}