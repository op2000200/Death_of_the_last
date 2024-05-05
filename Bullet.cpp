#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, sf::Texture* texture)
	:	sprite(*texture)
{
	Bullet::sprite.setPosition(pos);
	speed = 500;
	health = 500;
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
	Bullet::sprite.setPosition(pos);
}


void Bullet::setDir(sf::Vector2f pos)
{
	Bullet::direction = pos;
}

sf::Vector2f Bullet::getDir()
{
	return Bullet::direction;
}