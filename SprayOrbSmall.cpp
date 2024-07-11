#include "SprayOrbSmall.h"
SprayOrbSmall::SprayOrbSmall(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(0.7, 0.7));
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
}

SprayOrbSmall::~SprayOrbSmall()
{
}

sf::Sprite SprayOrbSmall::getSprite()
{
	return sprite;
}

void SprayOrbSmall::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void SprayOrbSmall::setTar(sf::Vector2f pos)
{
	target = pos;
}

sf::Vector2f SprayOrbSmall::getTar()
{
	return target;
}

SpellChar SprayOrbSmall::getChar()
{
	return spellChar;
}

void SprayOrbSmall::tickLength()
{
	spellChar.lengthCounter++;
}

void SprayOrbSmall::resetLength()
{
	spellChar.lengthCounter = 0;
}

void SprayOrbSmall::tickLifetime()
{
	spellChar.lifetime++;
}

SpellState SprayOrbSmall::getState()
{
	return spellState;
}

void SprayOrbSmall::setState(SpellState state)
{
	spellState = state;
}