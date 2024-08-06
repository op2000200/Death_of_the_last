#pragma once
#include "Structures.h"
class Projectile
{
public:
	Projectile();
	Projectile(sf::Vector2f inPos, int side, AmmoType ammo, sf::Vector2f dir, int damage);
	~Projectile();
	sf::CircleShape getHitbox();
	sf::Vector2f getDir();
	void move(sf::Vector2f delta);

private:
	sf::Vector2f direction;
	sf::CircleShape hitbox;
};
