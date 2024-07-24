#include "Meteor.h"
Meteor::Meteor(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(2.5, 2.5));
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

Meteor::~Meteor()
{
}

sf::Sprite Meteor::getSprite()
{
	return sprite;
}

void Meteor::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void Meteor::setTar(sf::Vector2f pos)
{
	target = pos;
}

sf::Vector2f Meteor::getTar()
{
	return target;
}

SpellChar Meteor::getChar()
{
	return spellChar;
}

void Meteor::tickLength()
{
	spellChar.lengthCounter++;
}

void Meteor::resetLength()
{
	spellChar.lengthCounter = 0;
}

void Meteor::tickLifetime()
{
	spellChar.lifetime++;
}

SpellState Meteor::getState()
{
	return spellState;
}

void Meteor::setState(SpellState state)
{
	spellState = state;
}