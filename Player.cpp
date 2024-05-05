#include "Player.h"

Player::Player(sf::Texture *texture)
	:sprite(*texture)
{
	level = 0;
	exp = 0;
	health = 100;
	speed = 500;
	castSpeed = 1;
}

sf::Sprite Player::getSprite()
{
	return Player::sprite;
}

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