#include "Enemy.h"

Enemy::Enemy(sf::Vector2f pos, sf::Texture* texture, EnemyType type, Element element)
{
	if (type == EnemyType::Standart)
	{
		sprite.setTexture(*texture);
		sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
		sprite.setPosition(pos);
		sprite.setRotation(rand());
		int scale = rand() % 3 + 1;
		//sprite.setScale(sf::Vector2f(scale / 2, scale / 2));

		dest = pos;

		enemyState = EnemyState::Standing;

		enemyType = type;

		characteristics.element = element;

		if (element == Element::Fire)
		{
			characteristics.speed = 100;
		}
		if (element == Element::Ice)
		{
			characteristics.speed = 100;
		}
		if (element == Element::Electricity)
		{
			characteristics.speed = 150;
		}
		if (element == Element::Stone)
		{
			characteristics.speed = 50;
		}
		if (element == Element::Water)
		{
			characteristics.speed = 150;
		}
		if (element == Element::Wind)
		{
			characteristics.speed = 200;
		}
	}
	if (type == EnemyType::Summoner)
	{

	}
	if (type == EnemyType::Kamikaze)
	{

	}
	if (type == EnemyType::Shooter)
	{

	}

}

Enemy::~Enemy()
{
}

sf::Sprite Enemy::getSprite()
{
	return sprite;
}
Characteristics Enemy::getChar()
{
	return characteristics;
}
EnemyState Enemy::getState()
{
	return enemyState;
}
void Enemy::setState(EnemyState st)
{
	enemyState = st;
}
sf::Vector2f Enemy::getDest()
{
	return dest;
}
void Enemy::setDest(sf::Vector2f pos)
{
	dest = pos;
}
void Enemy::setPos(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}
EnemyType Enemy::getType()
{
	return enemyType;
}
//#include "SFML/Graphics.hpp"
//
//Enemy::Enemy()
//{
//
//}
//
//Enemy::Enemy(sf::Texture* texture, sf::Vector2f pos)
//	:	sprite(*texture)
//{
//	Enemy::sprite.setPosition(pos);
//	health = 300;
//	speed = 80;
//}
//
//Enemy::~Enemy()
//{
//
//}
//
//sf::Sprite Enemy::getSprite()
//{
//	return Enemy::sprite;
//}
//
//void Enemy::setPos(sf::Vector2f coord)
//{
//	Enemy::sprite.setPosition(coord);
//}
//
//int Enemy::getSpeed()
//{
//	return Enemy::speed;
//}
//
//void Enemy::setHealth(int num)
//{
//	Enemy::health = num;
//}
//
//int Enemy::getHealth()
//{
//	return Enemy::health;
//}
