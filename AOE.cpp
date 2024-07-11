#include "AOE.h"
AOE::AOE(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(5.0, 5.0));
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

AOE::~AOE()
{
}

sf::Sprite AOE::getSprite()
{
	return sprite;
}

void AOE::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void AOE::setTar(sf::Vector2f pos)
{
	target = pos;
}

sf::Vector2f AOE::getTar()
{
	return target;
}

SpellChar AOE::getChar()
{
	return spellChar;
}

void AOE::tickLength()
{
	spellChar.lengthCounter++;
}

void AOE::resetLength()
{
	spellChar.lengthCounter = 0;
}

void AOE::tickLifetime()
{
	spellChar.lifetime++;
}

SpellState AOE::getState()
{
	return spellState;
}

void AOE::setState(SpellState state)
{
	spellState = state;
}