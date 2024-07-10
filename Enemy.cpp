#include "Enemy.h"

Enemy::Enemy(sf::Vector2f pos, sf::Texture* texture, EnemyType type, Element element, Enemy *en)
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
		sprite.setTexture(*texture);
		sprite.setScale(sf::Vector2f(5, 5));
		sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
		sprite.setPosition(pos);
		sprite.setRotation(rand());

		dest = pos;

		enemyState = EnemyState::Standing;

		enemyType = type;

		characteristics.element = element;

		abilityCooldown = 5000;

		abilityCooldownCounter = rand() % 5000;

		if (element == Element::Fire)
		{
			characteristics.speed = 75;
		}
		if (element == Element::Ice)
		{
			characteristics.speed = 75;
		}
		if (element == Element::Electricity)
		{
			characteristics.speed = 112.5;
		}
		if (element == Element::Stone)
		{
			characteristics.speed = 37.5;
		}
		if (element == Element::Water)
		{
			characteristics.speed = 112.5;
		}
		if (element == Element::Wind)
		{
			characteristics.speed = 150;
		}
	}
	if (type == EnemyType::Kamikaze)
	{
		sprite.setTexture(*texture);
		sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
		sprite.setPosition(pos);
		sprite.setRotation(rand());

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
	if (type == EnemyType::Shooter)
	{
		sprite.setTexture(*texture);
		sprite.setScale(sf::Vector2f(2, 2));
		sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
		sprite.setPosition(pos);
		sprite.setRotation(rand());

		dest = pos;

		enemyState = EnemyState::Standing;

		enemyType = type;

		characteristics.element = element;

		abilityCooldown = 2500;

		abilityCooldownCounter = rand() % 2500;

		if (element == Element::Fire)
		{
			characteristics.speed = 75;
		}
		if (element == Element::Ice)
		{
			characteristics.speed = 75;
		}
		if (element == Element::Electricity)
		{
			characteristics.speed = 112.5;
		}
		if (element == Element::Stone)
		{
			characteristics.speed = 37.5;
		}
		if (element == Element::Water)
		{
			characteristics.speed = 112.5;
		}
		if (element == Element::Wind)
		{
			characteristics.speed = 150;
		}
	}
	if (type == EnemyType::Summoned)
	{
		sprite.setTexture(*texture);
		sprite.setOrigin(sf::Vector2f(texture[0].getSize().x / 2, texture[0].getSize().y / 2));
		sprite.setPosition(pos);
		sprite.setRotation(rand());

		dest = pos;

		enemyState = EnemyState::Standing;

		enemyType = type;

		characteristics.element = element;

		par = en;

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
void Enemy::setType(EnemyType et)
{
	enemyType = et;
}
Enemy* Enemy::getPar()
{
	return par;
}

sf::Vector2f Enemy::getParPos()
{
	return par->sprite.getPosition();
}

int Enemy::getAbilC()
{
	return abilityCooldown;
}
int Enemy::getAbilCC()
{
	return abilityCooldownCounter;
}
void Enemy::ticlAbilCC()
{
	abilityCooldownCounter++;
}
void Enemy::resAbilCC()
{
	abilityCooldownCounter = 0;
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
