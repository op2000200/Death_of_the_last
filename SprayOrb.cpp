#include "SprayOrb.h"
SprayOrb::SprayOrb(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
	srand(time(0));
	int buf = rand() % 2;
	if (buf == 0)
		buf = -1;
	sprite.setPosition(sf::Vector2f(
		pos.x + buf * (rand() % 200 + 500),
		pos.y + buf * (rand() % 200 + 500)));
	target = tar;
	spellChar.element = Element::Fire;
	spellChar.lifetime = 10000;
	spellChar.speed = 150;
	spellChar.number = 1;
}

SprayOrb::~SprayOrb()
{
}

sf::Sprite SprayOrb::getSprite()
{
	return sprite;
}

void SprayOrb::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void SprayOrb::setTar(sf::Vector2f pos)
{
	target = pos;
}

sf::Vector2f SprayOrb::getTar()
{
	return target;
}

SpellChar SprayOrb::getChar()
{
	return spellChar;
}

void SprayOrb::tickLength()
{
	spellChar.lengthCounter++;
}

void SprayOrb::resetLength()
{
	spellChar.lengthCounter = 0;
}

void SprayOrb::tickLifetime()
{
	spellChar.lifetime++;
}

SpellState SprayOrb::getState()
{
	return spellState;
}

void SprayOrb::setState(SpellState state)
{
	spellState = state;
}