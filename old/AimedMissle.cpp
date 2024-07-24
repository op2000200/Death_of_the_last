#include "AimedMissle.h"
AimedMissle::AimedMissle(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(0.7, 0.7));
	sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
	srand(time(0));
	//int buf = rand() % 2;
	//if (buf == 0)
	//	buf = -1;
	//sprite.setPosition(sf::Vector2f(
	//	pos.x + buf * (rand() % 200 + 500),
	//	pos.y + buf * (rand() % 200 + 500)));

	sprite.setPosition(pos);
	dir = tar;
	spellChar.element = Element::Fire;
	spellChar.lifetime = 1000;
	spellChar.speed = 150;
	spellChar.number = 1;
}

AimedMissle::~AimedMissle()
{
}

sf::Sprite AimedMissle::getSprite()
{
	return sprite;
}

void AimedMissle::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos); 
	double rot1 = (std::acos((-1 * dir.y) / (std::sqrt(dir.x * dir.x + dir.y * dir.y))) * (180.0 / 3.14));
	if (dir.x < 0)
	{
		rot1 = 360.f - rot1;
	}
	sprite.setRotation(rot1);
}

void AimedMissle::setTar(sf::Vector2f pos)
{
	dir = pos;
}

sf::Vector2f AimedMissle::getTar()
{
	return dir;
}

SpellChar AimedMissle::getChar()
{
	return spellChar;
}

void AimedMissle::tickLength()
{
	spellChar.lengthCounter++;
}

void AimedMissle::resetLength()
{
	spellChar.lengthCounter = 0;
}

void AimedMissle::tickLifetime()
{
	spellChar.lifetime--;
}

SpellState AimedMissle::getState()
{
	return spellState;
}

void AimedMissle::setState(SpellState state)
{
	spellState = state;
}