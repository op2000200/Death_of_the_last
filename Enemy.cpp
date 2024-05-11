#include "Enemy.h"
#include "SFML/Graphics.hpp"

Enemy::Enemy()
{

}

Enemy::Enemy(sf::Texture* texture, sf::Vector2f pos)
	:	sprite(*texture)
{
	Enemy::sprite.setPosition(pos);
	health = 100;
	speed = 100;
}

Enemy::~Enemy()
{

}

sf::Sprite Enemy::getSprite()
{
	return Enemy::sprite;
}

void Enemy::setPos(sf::Vector2f coord)
{
	Enemy::sprite.setPosition(coord);
}

int Enemy::getSpeed()
{
	return Enemy::speed;
}

