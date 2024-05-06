#include "Mana.h"

Mana::Mana()
{

}

Mana::Mana(sf::Vector2f pos, sf::Texture* texture)
	:	sprite(*texture)
{
	Mana::sprite.setPosition(pos);
	Mana::value = 100;
}

Mana::~Mana()
{

}

sf::Sprite Mana::getSprite()
{
	return Mana::sprite;
}

int Mana::getValue()
{
	return Mana::value;
}

void Mana::setPos(sf::Vector2f coord)
{
	Mana::sprite.setPosition(coord);
}