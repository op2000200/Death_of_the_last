#pragma once
#include "Structures.h"
#include "Weapon.h"
class Player
{
public:
	Player(int pos_x, int pos_y, int index_x, int index_y, int side, std::vector<sf::Texture*> textureHolder);
	~Player();
	sf::CircleShape getHitbox();
	sf::CircleShape getSound();
	void setRad(int r);
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
	int getHealth();
	float getStamina();
	int getArmour();
	int getArmourTier();
	int get9mm();
	int get556mm();
	int get762mm();
	int get12gauge();
	int getRepairKit();
	int getHealthKit();
	void setHealth(int buf);
	void setStamina(float buf);
	void setArmour(int buf);
	void setArmourTier(int buf);
	void set9mm(int buf);
	void set556mm(int buf);
	void set762mm(int buf);
	void set12gauge(int buf);
	void setRepairKit(int buf);
	void setHealthKit(int buf);

private:
	sf::CircleShape hitbox;
	sf::CircleShape sound;
	sf::Vector2i tileIndex;
	RangedWeapon ranged;
	MeleeWeapon melee;
	int health;
	float stamina;
	int armour;
	int armourTier; //0-5
	int bullet9mmCount;
	int bullet556mmCount;
	int bullet762mmCount;
	int bullet12gaugeCount;
	int repairKitCount;
	int healthKitCount;
};
