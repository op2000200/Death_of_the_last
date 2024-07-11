#include "EnemyMissle.h"

EnemyMissle::EnemyMissle(sf::Vector2f pos, sf::Texture* texture, Element element, sf::Vector2f tar)
{
	sprite.setTexture(*texture);
	sprite.setScale(sf::Vector2f(3, 3));
	sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
	sprite.setPosition(pos);
	sprite.setRotation(rand());
	target = tar;
	characterisctics.speed = 200;
	characterisctics.healthCurrent = 10000;
	dir = sf::Vector2f(((tar.x - pos.x) / (abs(tar.x - pos.x) + abs(tar.y - pos.y))), ((tar.y - pos.y) / (abs(tar.x - pos.x) + abs(tar.y - pos.y))));
}

EnemyMissle::~EnemyMissle()
{
	;
}

sf::Sprite EnemyMissle::getSprite()
{
	return sprite;
}

Characteristics EnemyMissle::getChar()
{
	return characterisctics;
}

sf::Vector2f EnemyMissle::getDest()
{
	return target;
}

void EnemyMissle::setDest(sf::Vector2f pos)
{
	target = pos;
}

void EnemyMissle::setDir(sf::Vector2f pos)
{
	dir = pos;
}

sf::Vector2f EnemyMissle::getDir()
{
	return dir;
}

void EnemyMissle::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void EnemyMissle::setHealth(float num)
{
	characterisctics.healthCurrent = num;
}
