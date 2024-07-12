#include "FastMissle.h"
FastMissle::FastMissle(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
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
	spellChar.lifetime = 10000;
	spellChar.speed = 150;
	spellChar.number = 1;
}

FastMissle::~FastMissle()
{
}

sf::Sprite FastMissle::getSprite()
{
	return sprite;
}

void FastMissle::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void FastMissle::setTar(sf::Vector2f pos)
{
	target = pos;
}

sf::Vector2f FastMissle::getTar()
{
	return target;
}

SpellChar FastMissle::getChar()
{
	return spellChar;
}

void FastMissle::tickLength()
{
	spellChar.lengthCounter++;
}

void FastMissle::resetLength()
{
	spellChar.lengthCounter = 0;
}

void FastMissle::tickLifetime()
{
	spellChar.lifetime++;
}

SpellState FastMissle::getState()
{
	return spellState;
}

void FastMissle::setState(SpellState state)
{
	spellState = state;
}