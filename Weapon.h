#pragma once
#include "Structures.h"
class Weapon
{
public:
	Weapon();
	~Weapon();

private:
	int damage;
	WeaponName name;
	sf::Time cooldown;
};

class RangedWeapon : Weapon
{
public:
	RangedWeapon();
	~RangedWeapon();

private:
	sf::CircleShape hitbox;
	AmmoType ammoType;
};

class MeleeWeapon : Weapon
{
public:
	MeleeWeapon();
	~MeleeWeapon();

private:
	sf::RectangleShape hitbox;
};

