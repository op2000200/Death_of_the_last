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
	Projectile proj(inPos, side, ammoType, dir, damage);
	projectileBuffer.push_back(proj);
}

void RangedWeapon::clear()
{
	projectileBuffer.clear();
}

int RangedWeapon::getSpeed()
{
	return speed;
}

void RangedWeapon::tickProj(int i, int speed)
{
	projectileBuffer[i].move(sf::Vector2f(
		projectileBuffer[i].getDir().x * speed * (1/300.f),
		projectileBuffer[i].getDir().y * speed * (1/300.f)
	));
}

void RangedWeapon::delProj(int i)
{
	if (!projectileBuffer.empty())
	{
		projectileBuffer.erase(projectileBuffer.begin() + i);
	}
}

int RangedWeapon::getCapacity()
{
	return capacity;
}

sf::Time RangedWeapon::getReloadTime()
{
	return reloadTime;
}

int RangedWeapon::getDamage()
{
	return damage;
}

sf::Sprite RangedWeapon::getSprite()
{
	return sprite;
}

RangedWeapon::RangedWeapon()
{
}

RangedWeapon::RangedWeapon(WeaponName inName, sf::Vector2f inPos, int side, sf::Texture* texture)
{
	pickUpHitbox.setRadius(side / 40);
	pickUpHitbox.setOrigin(sf::Vector2f(pickUpHitbox.getRadius(), pickUpHitbox.getRadius()));
	pickUpHitbox.setPosition(inPos);
	pickUpHitbox.setFillColor(sf::Color::Transparent);
	pickUpHitbox.setOutlineColor(sf::Color::Red);
	pickUpHitbox.setOutlineThickness(1.f);
	name = inName;
	sprite.setTexture(*texture);
	sprite.setOrigin(sf::Vector2f(sprite.getTexture()->getSize().x / 2, sprite.getTexture()->getSize().y / 2));
	sprite.setPosition(inPos);
	switch (name)
	{
		case VP70:
		{
			pattern = AttackPattern::Auto;
			damage = 10;
			cooldown = sf::seconds(0.1);
			reloadTime = sf::seconds(4.f);
			capacity = 18;
			ammoType = AmmoType::MM9;
			speed = (side / 10) * 360;
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

MeleeWeapon::MeleeWeapon(WeaponName inName, sf::Vector2f inPos, int side, sf::Texture* texture)
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
			pattern = SemiAuto;
			damage = 30;
			cooldown = sf::seconds(0.5);
			speed = (side / 10) * 7;
			hitbox.setSize(sf::Vector2f(
				side / 200,
				side / 40
			));
			hitbox.setOrigin(sf::Vector2f(
				side / 400,
				side / 25 + side / 40
			));
			break;
		}
		case Fist:
		{
			pattern = Auto;
			damage = 100; //default = 5
			cooldown = sf::seconds(0.3);
			speed = (side / 10) * 7;
			hitbox.setSize(sf::Vector2f(
				side / 20,
				side / 50
			));
			hitbox.setOrigin(sf::Vector2f(
				side / 40,
				side / 25 + side / 40
			));
			break;
		}
		default:
		{
			break;
		};
	}
	hitbox.setPosition(inPos);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(1.f);
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

sf::RectangleShape MeleeWeapon::getHitbox()
{
	return hitbox;
}

void MeleeWeapon::updateRotation(float deg)
{
	hitbox.setRotation(deg);
}

void MeleeWeapon::updatePos(sf::Vector2f pos)
{
	hitbox.setPosition(pos);
}

int MeleeWeapon::getDamage()
{
	return damage;
}
