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
	void swapWeapon(MeleeWeapon rng);

private:
	sf::CircleShape hitbox;
	sf::Vector2i tileIndex;
	RangedWeapon ranged;
	MeleeWeapon melee;
};
