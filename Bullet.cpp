#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, sf::Texture* texture)
	:	sprite(*texture)
{
	speed = 10;
	health = 100;
}

Bullet::~Bullet()
{

}

sf::Sprite Bullet::getSprite()
{
	return Bullet::sprite;
}

void Bullet::setHealth(int num)
{
	health = num;
}

int Bullet::getHealth()
{
	return Bullet::health;
}

int Bullet::getSpeed()
{
	return Bullet::speed;
}

void Bullet::setPos(sf::Vector2f pos)
{
	Bullet::pos = pos;
}

sf::Vector2f Bullet::getPos()
{
	return Bullet::pos;
}