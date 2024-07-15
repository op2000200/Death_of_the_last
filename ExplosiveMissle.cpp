#include "ExplosiveMissle.h"
ExplosiveMissle::ExplosiveMissle(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(1.5, 1.5));
	sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
	srand(time(0));
	sprite.setPosition(pos);
	target = tar;
	spellChar.element = Element::Fire;
	spellChar.lifetime = 1000;
	spellChar.speed = 150;
	spellChar.number = 1;
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
	double rot1 = (std::acos((-1 * target.y) / (std::sqrt(target.x * target.x + target.y * target.y))) * (180.0 / 3.14));
	if (target.x < 0)
	{
		rot1 = 360.f - rot1;
	}
	sprite.setRotation(rot1);
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