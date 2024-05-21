#include "BasicMissleCold.h"
BasicMissleCold::BasicMissleCold()
{

}

BasicMissleCold::BasicMissleCold(sf::Vector2f pos, sf::Texture* texture)
	: sprite(*texture)
{
	BasicMissleCold::sprite.setPosition(pos);
	//BasicMissleCold::sprite.setScale(sf::Vector2f(5.f,5.f));
	health = 600;
	speed = 600;
	damageMP = 50;
	critRate = 10;
	critDamage = 150;
}

BasicMissleCold::~BasicMissleCold()
{

}

void BasicMissleCold::setPosition(sf::Vector2f pos)
{
	BasicMissleCold::sprite.setPosition(pos);
}

void BasicMissleCold::setDirection(sf::Vector2f dir)
{
	BasicMissleCold::direction = dir;
}

void BasicMissleCold::setRotation(float rot)
{
	//BasicMissleCold::rotation = rot;
	BasicMissleCold::sprite.setRotation(rot);
}


void BasicMissleCold::setHealth(int num)
{
	BasicMissleCold::health = num;
}

sf::Sprite BasicMissleCold::getSprite()
{
	return BasicMissleCold::sprite;
}

sf::Vector2f BasicMissleCold::getDirection()
{
	return BasicMissleCold::direction;
}

float BasicMissleCold::getRotation()
{
	return BasicMissleCold::sprite.getRotation();
}

int BasicMissleCold::getHealth()
{
	return BasicMissleCold::health;
}

int BasicMissleCold::getSpeed()
{
	return BasicMissleCold::speed;
}

int BasicMissleCold::getDamageMP()
{
	return BasicMissleCold::damageMP;
}

int BasicMissleCold::getCritRate()
{
	return BasicMissleCold::critRate;
}

int BasicMissleCold::getCritDamage()
{
	return BasicMissleCold::critDamage;
}

