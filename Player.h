#pragma once
#include "Structures.h"
#include "Weapon.h"
class Player
{
public:
	Player(int pos_x, int pos_y, int index_x, int index_y, int side);
	~Player();
	sf::CircleShape getHitbox();
	sf::Vector2i getIndex();
	void move(sf::Vector2f delta);
	void updateIndex(int side);
	void swapWeapon(RangedWeapon rng);
	RangedWeapon getRanged();
	MeleeWeapon getMelee();
	void swapWeapon(MeleeWeapon rng);
	void shoot(int side, sf::Vector2f dir);
	void tickProj(int i, int speed);
	void delProj(int i);
	void hit(int side, sf::Vector2f dir);
	void rotate(float deg);
	sf::RectangleShape getHpBar();
	sf::RectangleShape getArmorBar();

private:
	sf::CircleShape hitbox;
	sf::Vector2i tileIndex;
	RangedWeapon ranged;
	MeleeWeapon melee;
	sf::RectangleShape hpBar;
	sf::RectangleShape armorBar;
	int health;
	int stamina;
	int armour;
	int armourTier; //0-5
	int bullet9mmCount;
	int bullet556mmCount;
	int bullet762mmCount;
	int bullet12gaugeCount;
	int repairKitCount;
	int healthKitCount;
};
