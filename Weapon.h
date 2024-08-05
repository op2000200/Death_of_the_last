#pragma once
#include "Structures.h"
#include "Projectile.h"
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
	AmmoType getAmmo();
	sf::Time getCooldown();
	AttackPattern getPattern();
	std::vector<Projectile> getProjBuffer();
	void delProjBufElem(int i);
	void shoot(sf::Vector2f inPos, int side, sf::Vector2f dir);
	void clear();

private:
	std::vector<Projectile> projectileBuffer;
	AmmoType ammoType;
};

class MeleeWeapon : Weapon
{
public:
	MeleeWeapon();
	MeleeWeapon(WeaponName inName, sf::Vector2f inPos, int side);
	~MeleeWeapon();
	sf::CircleShape getPickUpHitbox();
	WeaponName getName();
	sf::Time getCooldown();
	AttackPattern getPattern();

private:
	sf::RectangleShape hitbox;
};

