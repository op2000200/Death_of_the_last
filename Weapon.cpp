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

AmmoType RangedWeapon::getAmmo()
{
	return ammoType;
}

sf::Time RangedWeapon::getCooldown()
{
	return cooldown;
}

AttackPattern RangedWeapon::getPattern()
{
	return pattern;
}

std::vector<Projectile> RangedWeapon::getProjBuffer()
{
	return projectileBuffer;
}

void RangedWeapon::delProjBufElem(int i)
{
	projectileBuffer.erase(projectileBuffer.begin() + i);
}

void RangedWeapon::shoot(sf::Vector2f inPos, int side, sf::Vector2f dir)
{
	Projectile proj(inPos, side, ammoType, dir);
	projectileBuffer.push_back(proj);
}

void RangedWeapon::clear()
{
	projectileBuffer.clear();
}

RangedWeapon::RangedWeapon()
{
}

RangedWeapon::RangedWeapon(WeaponName inName, sf::Vector2f inPos, int side)
{
	pickUpHitbox.setRadius(side / 20);
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
			pattern = AttackPattern::SemiAuto;
			damage = 15;
			cooldown = sf::seconds(1);	//change
			ammoType = AmmoType::MM9;
			break;
		};
		case AR10:
		{
			pattern = AttackPattern::Auto;
			damage = 10;
			cooldown = sf::seconds(1);	//change
			ammoType = AmmoType::MM762;
			break;
		};
		case XM8:
		{
			pattern = AttackPattern::Auto;
			damage = 10;
			cooldown = sf::seconds(1);	//change
			ammoType = AmmoType::MM9;
			break;
		};
		case G36:
		{
			pattern = AttackPattern::Auto;
			damage = 10;
			cooldown = sf::seconds(1);	//change
			ammoType = AmmoType::MM9;
			break;
		};
		case Groza:
		{
			pattern = AttackPattern::Auto;
			damage = 10;
			cooldown = sf::seconds(1);	//change
			ammoType = AmmoType::MM762;
			break;
		};
		case MR133:
		{
			pattern = AttackPattern::SemiAuto;
			damage = 5;
			cooldown = sf::seconds(1);	//change
			ammoType = AmmoType::Gauge12;
			break;
		};
		case M88:
		{
			pattern = AttackPattern::SemiAuto;
			damage = 5;
			cooldown = sf::seconds(1);	//change
			ammoType = AmmoType::Gauge12;
			break;
		};
		default:
		{
			break;
		}
	}
	projectileBuffer.clear();
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

WeaponName MeleeWeapon::getName()
{
	return name;
}

sf::Time MeleeWeapon::getCooldown()
{
	return cooldown;
}

AttackPattern MeleeWeapon::getPattern()
{
	return pattern;
}
