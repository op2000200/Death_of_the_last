#include "Wall.h"

Wall::Wall()
{
    ws = Empty;
}

Wall::Wall(int pos_x, int pos_y, int side)
{
    hitbox.setSize(sf::Vector2f(side / 20, side / 20));
    hitbox.setOrigin(sf::Vector2f(side / 40, side / 40));
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.f);
    hitbox.setPosition(sf::Vector2f(pos_x, pos_y));
    ws = Walled;
    if (rand() % 2 == 0)
    {
        height = 0;
        health = 30;
        hitbox.setFillColor(sf::Color(153,76,0));
    }
    else
    {
        height = 1;
        health = 100;
        hitbox.setFillColor(sf::Color(32,32,32));
    }
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

int Wall::getHeight()
{
    return height;
}

void Wall::spawn()
{
    ws = Enemied;
}

WallState Wall::getWS()
{
    return ws;
}

void Wall::setWS(WallState st)
{
    ws = st;
}
