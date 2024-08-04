#pragma once
#include "Structures.h"
class Weapon
{
public:
	Weapon();
	~Weapon();
protected:
	int damage;
	WeaponName name;
	sf::Time cooldown;
	sf::CircleShape pickUpHitbox;
	AttackPattern pattern;
};

class RangedWeapon : Weapon
{
public:
	RangedWeapon();
	RangedWeapon(WeaponName inName, sf::Vector2f inPos, int side);
	~RangedWeapon();
	sf::CircleShape getPickUpHitbox();
	WeaponName getName();

private:
	sf::CircleShape hitbox;
	AmmoType ammoType;
};

class MeleeWeapon : Weapon
{
public:
	MeleeWeapon();
	MeleeWeapon(WeaponName inName, sf::Vector2f inPos, int side);
	~MeleeWeapon();
	sf::CircleShape getPickUpHitbox();

private:
	sf::RectangleShape hitbox;
};

