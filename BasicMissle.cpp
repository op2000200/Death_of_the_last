#include "BasicMissle.h"

BasicMissle::BasicMissle(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(1.0, 1.0));
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

BasicMissle::~BasicMissle()
{
}

sf::Sprite BasicMissle::getSprite()
{
	return sprite;
}

void BasicMissle::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void BasicMissle::setTar(sf::Vector2f pos)
{
	target = pos;
}

sf::Vector2f BasicMissle::getTar()
{
	return target;
}

SpellChar BasicMissle::getChar()
{
	return spellChar;
}

void BasicMissle::tickLength()
{
	spellChar.lengthCounter++;
}

void BasicMissle::resetLength()
{
	spellChar.lengthCounter = 0;
}

void BasicMissle::tickLifetime()
{
	spellChar.lifetime++;
}

SpellState BasicMissle::getState()
{
	return spellState;
}

void BasicMissle::setState(SpellState state)
{
	spellState = state;
}
