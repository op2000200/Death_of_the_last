#include "Wall.h"

Wall::Wall()
{
    ws = Empty;
}

Wall::Wall(int pos_x, int pos_y, int side, sf::Texture* bx)
{
    hitbox.setSize(sf::Vector2f(side / 20, side / 20));
    hitbox.setOrigin(sf::Vector2f(side / 40, side / 40));
    hitbox.setOutlineColor(sf::Color(32, 32, 32));
    hitbox.setOutlineThickness(1.f);
    hitbox.setPosition(sf::Vector2f(pos_x, pos_y));
    ws = Walled;
    if (rand() % 2 == 0)
    {
        height = 0;
        health = 30;
        hitbox.setFillColor(sf::Color(153,76,0));
        sprite.setTexture(*bx);
        sprite.setOrigin(sf::Vector2f(
            (bx->getSize().x / 2),
            (bx->getSize().y / 2)
        ));
        sprite.setPosition(sf::Vector2f(pos_x, pos_y));
        sprite.setScale(sf::Vector2f(
            (side / 20.f) / bx->getSize().x,
            (side / 20.f) / bx->getSize().y
        ));
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

sf::Sprite Wall::getSprite()
{
    return sprite;
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
