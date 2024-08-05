#include "Player.h"

Player::Player(int pos_x, int pos_y, int index_x, int index_y, int side)
    : ranged(WeaponName::NoWeapon, sf::Vector2f(), side)
    , melee(WeaponName::Fist, sf::Vector2f(), side)
{
    hitbox.setRadius(side / 20);
    hitbox.setOrigin(sf::Vector2f(hitbox.getRadius(), hitbox.getRadius()));
    hitbox.setPosition(sf::Vector2f(pos_x, pos_y));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.f);
    tileIndex.x = index_x;
    tileIndex.y = index_y;
    ranged.clear();
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
    if (hitbox.getPosition().y - sf::VideoMode::getDesktopMode().height / 2 + side / 2 > 0)
    {
        tileIndex.y = (hitbox.getPosition().y - sf::VideoMode::getDesktopMode().height / 2 + side / 2) / side;
    }
    else
    {
        tileIndex.y = (hitbox.getPosition().y - sf::VideoMode::getDesktopMode().height / 2 + side / 2) / side;
        tileIndex.y--;
    }
}

void Player::swapWeapon(RangedWeapon rng)
{
    if (ranged.getName() == WeaponName::NoWeapon)
    {
        ranged = rng;
    }
    else
    {
        //create a weapon in hand and drop it
    }
}

RangedWeapon Player::getRanged()
{
    return ranged;
}

MeleeWeapon Player::getMelee()
{
    return melee;
}

void Player::swapWeapon(MeleeWeapon rng)
{
}

void Player::shoot(int side, sf::Vector2f dir)
{
    ranged.shoot(hitbox.getPosition(), side, dir);
}

void Player::hit(int side, sf::Vector2f dir)
{
}
