#include "ExplosiveMissle.h"
ExplosiveMissle::ExplosiveMissle(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(1.5, 1.5));
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

ExplosiveMissle::~ExplosiveMissle()
{
}

sf::Sprite ExplosiveMissle::getSprite()
{
	return sprite;
}

void ExplosiveMissle::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void ExplosiveMissle::setTar(sf::Vector2f pos)
{
	target = pos;
}

sf::Vector2f ExplosiveMissle::getTar()
{
	return target;
}

SpellChar ExplosiveMissle::getChar()
{
	return spellChar;
}

void ExplosiveMissle::tickLength()
{
	spellChar.lengthCounter++;
}

void ExplosiveMissle::resetLength()
{
	spellChar.lengthCounter = 0;
}

void ExplosiveMissle::tickLifetime()
{
	spellChar.lifetime++;
}

SpellState ExplosiveMissle::getState()
{
	return spellState;
}

void ExplosiveMissle::setState(SpellState state)
{
	spellState = state;
}