#include "Weapon.h"


Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

sf::CircleShape RangedWeapon::getPickUpHitbox()
{
	return pickUpHitbox;
}

WeaponName RangedWeapon::getName()
{
	return name;
}

RangedWeapon::RangedWeapon()
{
}

RangedWeapon::RangedWeapon(WeaponName inName, sf::Vector2f inPos, int side)
{
	pickUpHitbox.setRadius(side / 40);
	pickUpHitbox.setOrigin(sf::Vector2f(pickUpHitbox.getRadius(), pickUpHitbox.getRadius()));
	pickUpHitbox.setPosition(inPos);
	pickUpHitbox.setFillColor(sf::Color::Transparent);
	pickUpHitbox.setOutlineColor(sf::Color::Red);
	pickUpHitbox.setOutlineThickness(1.f);
	name = inName;
	switch (name)
	{
		case VP70:
		{
			pattern = AttackPattern::Auto;
			damage = 10;
			cooldown = sf::seconds(1);	//change
			ammoType = AmmoType::MM9;
			break;
		}
		case SWMP:
		{
			break;
		};
		case AR10:
		{
			break;
		};
		case XM8:
		{
			break;
		};
		case G36:
		{
			break;
		};
		case Groza:
		{
			break;
		};
		case MR133:
		{
			break;
		};
		case M88:
		{
			break;
		};
		default:
		{
			break;
		}
	}
}

RangedWeapon::~RangedWeapon()
{
}

MeleeWeapon::MeleeWeapon()
{
}

MeleeWeapon::MeleeWeapon(WeaponName inName, sf::Vector2f inPos, int side)
{
	pickUpHitbox.setRadius(side / 40);
	pickUpHitbox.setOrigin(sf::Vector2f(pickUpHitbox.getRadius(), pickUpHitbox.getRadius()));
	pickUpHitbox.setPosition(inPos);
	pickUpHitbox.setFillColor(sf::Color::Transparent);
	pickUpHitbox.setOutlineColor(sf::Color::Red);
	pickUpHitbox.setOutlineThickness(1.f);
	name = inName;
	switch (name)
	{
		case Knife:
		{
			
			break;
		}
		case Fist:
		{
			
			break;
		};
		default:
		{
			break;
		};
	}
}

MeleeWeapon::~MeleeWeapon()
{
}

sf::CircleShape MeleeWeapon::getPickUpHitbox()
{
	return pickUpHitbox;
}
