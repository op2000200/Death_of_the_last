#include "Wall.h"

Wall::Wall()
{
}

Wall::Wall(int pos_x, int pos_y, int side)
{
    hitbox.setSize(sf::Vector2f(side / 20, side / 20));
    hitbox.setOrigin(sf::Vector2f(side / 40, side / 40));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.f);
    hitbox.setPosition(sf::Vector2f(pos_x, pos_y));
    health = 100;
}

Wall::~Wall()
{
}

void Wall::damaged(int dmg)
{
    health -= dmg;
}

sf::RectangleShape Wall::getHitbox()
{
	return hitbox;
}

int Wall::getHealth()
{
	return health;
}
