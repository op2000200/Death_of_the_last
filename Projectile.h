#pragma once
#include "Structures.h"
class Projectile
{
public:
	Projectile();
	Projectile(sf::Vector2f inPos, int side, AmmoType ammo, sf::Vector2f dir);
	~Projectile();
	sf::CircleShape getHitbox();
	sf::Vector2f getDir();

private:
	sf::Vector2f direction;
	sf::CircleShape hitbox;
};
