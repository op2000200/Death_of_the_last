#include "Player.h"

Player::Player(int pos_x, int pos_y, int index_x, int index_y, int side, std::vector<sf::Texture*> textureHolder)
    : ranged(WeaponName::NoWeapon, sf::Vector2f(), side, textureHolder[0])
    , melee(WeaponName::Fist, sf::Vector2f(pos_x, pos_y), side, textureHolder[0])
{
    hitbox.setRadius(side / 40);
    hitbox.setOrigin(sf::Vector2f(hitbox.getRadius(), hitbox.getRadius()));
    hitbox.setPosition(sf::Vector2f(pos_x, pos_y));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.f);
    tileIndex.x = index_x;
    tileIndex.y = index_y;
    ranged.clear();
    health = 100;
    stamina = 100;
    armour = 0;
    armourTier = 0;
    bullet9mmCount = 0;
    bullet556mmCount = 0;
    bullet762mmCount = 0;
    bullet12gaugeCount = 0;
    repairKitCount = 0;
    healthKitCount = 0;
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
    melee.updatePos(hitbox.getPosition());
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
    if (melee.getName() == Fist)
    {
        melee = rng;
    }
    else
    {
        //create a weapon and drop it
    }
}

void Player::shoot(int side, sf::Vector2f dir)
{
    ranged.shoot(hitbox.getPosition(), side, dir);
}

void Player::tickProj(int i, int speed)
{
    ranged.tickProj(i, speed);
}

void Player::delProj(int i)
{
    ranged.delProj(i);
}

void Player::hit(int side, sf::Vector2f dir)
{
}

void Player::rotate(float deg)
{
    //rotate player sprite

    //rotate melee weapon hitbox
    melee.updateRotation(deg);
}

int Player::getHealth()
{
    return health;
}

int Player::getStamina()
{
    return stamina;
}

int Player::getArmour()
{
    return armour;
}

int Player::getArmourTier()
{
    return armourTier;
}

int Player::get9mm()
{
    return bullet9mmCount;
}

int Player::get556mm()
{
    return bullet556mmCount;
}

int Player::get762mm()
{
    return bullet762mmCount;
}

int Player::get12gauge()
{
    return bullet12gaugeCount;
}

int Player::getRepairKit()
{
    return repairKitCount;
}

int Player::getHealthKit()
{
    return healthKitCount;
}

void Player::setHealth(int buf)
{
    health = buf;
}

void Player::setStamina(int buf)
{
    health = buf;
}

void Player::setArmour(int buf)
{
    armour = buf;
}

void Player::setArmourTier(int buf)
{
    armourTier = buf;
}

void Player::set9mm(int buf)
{
    bullet9mmCount = buf;
}

void Player::set556mm(int buf)
{
    bullet556mmCount = buf;
}

void Player::set762mm(int buf)
{
    bullet762mmCount = buf;
}

void Player::set12gauge(int buf)
{
    bullet12gaugeCount = buf;
}

void Player::setRepairKit(int buf)
{
    repairKitCount = buf;
}

void Player::setHealthKit(int buf)
{
    healthKitCount = buf;
}
