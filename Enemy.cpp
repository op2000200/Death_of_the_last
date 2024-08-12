#include "Enemy.h"

Enemy::Enemy(int pos_x, int pos_y, int side)
{
	hitbox.setRadius(side / 50);
	hitbox.setOrigin(sf::Vector2f(hitbox.getRadius(), hitbox.getRadius()));
	hitbox.setPosition(sf::Vector2f(pos_x, pos_y));
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(1.f);
	behav = EnemyBehavior::Stand;
	state = EnemyState::Standing;
	health = 100;
	hpBar.setSize(sf::Vector2f(
		side / 20,
		side / 100
	));
	hpBar.setOrigin(sf::Vector2f(
		side / 50,
		side / 50 + side / 50
	));
	hpBar.setPosition(sf::Vector2f(pos_x, pos_y));
	hpBar.setFillColor(sf::Color::Green);
}

Enemy::~Enemy()
{
}

sf::CircleShape Enemy::getHitbox()
{
	return hitbox;
}

void Enemy::move(sf::Vector2f delta)
{
	hitbox.move(delta);
	hpBar.setPosition(hitbox.getPosition());
}

EnemyState Enemy::getState()
{
	return state;
}

void Enemy::setState(EnemyState st)
{
	state = st;
}

EnemyBehavior Enemy::getBehav()
{
	return behav;
}

void Enemy::setBehav(EnemyBehavior bv)
{
	behav = bv;
}

int Enemy::getHealth()
{
	return health;
}

void Enemy::setHealth(int buf)
{
	hpBar.setSize(sf::Vector2f(
		(hpBar.getSize().x / health) * buf,
		hpBar.getSize().y
	));
	health = buf;
}

sf::Vector2f Enemy::getDest()
{
	return dest;
}

void Enemy::setDest(sf::Vector2f buf)
{
	dest = buf;
}

void Enemy::getDamage(int dmg)
{
	hpBar.setSize(sf::Vector2f(
		(hpBar.getSize().x / health) * (health - dmg),
		hpBar.getSize().y
	));
	health -= dmg;
}

sf::RectangleShape Enemy::getHpBar()
{
	return hpBar;
}
