#include "ManaStrike.h"
ManaStrike::ManaStrike(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(4.0, 4.0));
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

ManaStrike::~ManaStrike()
{
}

sf::Sprite ManaStrike::getSprite()
{
	return sprite;
}

void ManaStrike::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void ManaStrike::setTar(sf::Vector2f pos)
{
	target = pos;
}

sf::Vector2f ManaStrike::getTar()
{
	return target;
}

SpellChar ManaStrike::getChar()
{
	return spellChar;
}

void ManaStrike::tickLength()
{
	spellChar.lengthCounter++;
}

void ManaStrike::resetLength()
{
	spellChar.lengthCounter = 0;
}

void ManaStrike::tickLifetime()
{
	spellChar.lifetime++;
}

SpellState ManaStrike::getState()
{
	return spellState;
}

void ManaStrike::setState(SpellState state)
{
	spellState = state;
}