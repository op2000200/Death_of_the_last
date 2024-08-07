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
	int speed;
	sf::Sprite sprite;
};

class RangedWeapon : Weapon
{
public:
	RangedWeapon();
	RangedWeapon(WeaponName inName, sf::Vector2f inPos, int side, sf::Texture* texture);
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
	int getSpeed();
	void tickProj(int i, int speed);
	void delProj(int i);
	int getCapacity();
	sf::Time getReloadTime();
	int getDamage();
	sf::Sprite getSprite();

private:
	std::vector<Projectile> projectileBuffer;
	AmmoType ammoType;
	sf::Time reloadTime;
	int capacity;
};

class MeleeWeapon : Weapon
{
public:
	MeleeWeapon();
	MeleeWeapon(WeaponName inName, sf::Vector2f inPos, int side, sf::Texture* texture);
	~MeleeWeapon();
	sf::CircleShape getPickUpHitbox();
	WeaponName getName();
	sf::Time getCooldown();
	AttackPattern getPattern();
	sf::RectangleShape getHitbox();
	void updateRotation(float deg);
	void updatePos(sf::Vector2f pos);
	int getDamage();

private:
	sf::RectangleShape hitbox;
};

