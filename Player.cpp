#include "Player.h"

Player::Player(int pos_x, int pos_y, int index_x, int index_y, int side)
{
    hitbox.setRadius(side / 40);
    hitbox.setOrigin(sf::Vector2f(hitbox.getRadius(), hitbox.getRadius()));
    hitbox.setPosition(sf::Vector2f(pos_x, pos_y));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.f);
    tileIndex.x = index_x;
    tileIndex.y = index_y;
}

Player::~Player()
{
}

sf::CircleShape Player::getHitbox()
{
	return hitbox;
}

sf::Vector2i Player::getIndex()
{
	return tileIndex;
}

void Player::move(sf::Vector2f delta)
{
    hitbox.move(delta);
}

void Player::updateIndex(int side)
{
    if (hitbox.getPosition().x - sf::VideoMode::getDesktopMode().width / 2 + side / 2 > 0)
    {
        tileIndex.x = (hitbox.getPosition().x - sf::VideoMode::getDesktopMode().width / 2 + side / 2) / side;
    }
    else
    {
        tileIndex.x = (hitbox.getPosition().x - sf::VideoMode::getDesktopMode().width / 2 + side / 2) / side;
        tileIndex.x--;
    }
    if (hitbox.getPosition().y - side + side / 2 > 0)
    {
        tileIndex.y = (hitbox.getPosition().y - side + side / 2) / side;
    }
    else
    {
        tileIndex.y = (hitbox.getPosition().y - side + side / 2) / side;
        tileIndex.y--;
    }
}
