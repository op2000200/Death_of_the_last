#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::Projectile(sf::Vector2f inPos, int side, AmmoType ammo, sf::Vector2f dir)
{
	if (ammo == MM9)
	{
		hitbox.setRadius(side / side);
		if (hitbox.getRadius() < 1)
		{
			hitbox.setRadius(1);
		}
		hitbox.setOrigin(sf::Vector2f(hitbox.getRadius(), hitbox.getRadius()));
	}
	if (ammo == MM556)
	{
		hitbox.setRadius(side / side);
		if (hitbox.getRadius() < 1)
		{
			hitbox.setRadius(1);
		}
		hitbox.setOrigin(sf::Vector2f(hitbox.getRadius(), hitbox.getRadius()));
	}
	if (ammo == MM762) 
	{
		hitbox.setRadius(side / side);
		if (hitbox.getRadius() < 1)
		{
			hitbox.setRadius(1);
		}
		hitbox.setOrigin(sf::Vector2f(hitbox.getRadius(), hitbox.getRadius()));
	}
	if (ammo == Gauge12)
	{
		hitbox.setRadius(side / (side / 2));
		if (hitbox.getRadius() < 2)
		{
			hitbox.setRadius(2);
		}
		hitbox.setOrigin(sf::Vector2f(hitbox.getRadius(), hitbox.getRadius()));
	}
	hitbox.setPosition(inPos);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(1.f);
}

Projectile::~Projectile()
{
}

sf::CircleShape Projectile::getHitbox()
{
	return hitbox;
}

sf::Vector2f Projectile::getDir()
{
	return direction;
}
