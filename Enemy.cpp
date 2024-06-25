#include "Enemy.h"

Enemy::Enemy(sf::Vector2f pos, sf::Texture* texture)
{
	sprite.setTexture(*texture);
	sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
	sprite.setPosition(pos);
}

Enemy::~Enemy()
{
}

sf::Sprite Enemy::getSprite()
{
	return sprite;
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
