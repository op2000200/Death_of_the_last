#include "Player.h"

Player::Player(sf::Texture *texture)
	:sprite(*texture)
{
	level = 0;
	exp = 0;
	expCap = 1000;
	health = 100;
	speed = 200;
	castSpeed = 500;
}

sf::Sprite Player::getSprite()
{
	return Player::sprite;
}
w
void Player::setPos(sf::Vector2f pos)
{
	Player::sprite.setPosition(pos);
}

void Player::setTexture(sf::Texture texture)
{
	Player::sprite.setTexture(texture);
}

int Player::getSpeed()
{
	return Player::speed;
}

int Player::getCastSpeed()
{
	return Player::castSpeed;
}

void Player::setSpeed(int num)
{
	Player::speed = num;
}

void Player::setCastSpeed(int num)
{
	Player::castSpeed = num;
}

void Player::setHealth(int num)
{
	Player::health = num;
}

int Player::getHealth()
{
	return Player::health;
}

void Player::setExpCap(int num)
{
	Player::expCap = num;
}

int Player::getExpCap()
{
	return Player::expCap;
}

void Player::setExp(int num)
{
	Player::exp = num;
}

int Player::getExp()
{
	return Player::exp;
}

void Player::setLevel(int num)
{
	Player::level = num;
}

int Player::getLevel()
{
	return Player::level;
}