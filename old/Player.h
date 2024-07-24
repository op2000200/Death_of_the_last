#pragma once
#include <SFML/Graphics.hpp>

#include "Structures.h"

class Player
{
public:
	Player();
	~Player();

	bool processCommand(Commands command);
	sf::Sprite getSprite();
	PlayerState getState();
	Characteristics getChar();

	int* getSpellLevel();
	int* getSpellCooldown();
	int* getSpellCooldownCounter();
	void tickSpellCC(int i);
	void resetSpellCC(int i);

private:
	sf::Sprite sprite;
	sf::Texture* texture;
	PlayerState playerState;
	//hitbox
	Characteristics characteristics;
	int* spellLevel;
	int* spellCooldown;
	int* spellCooldownCounter;
};


//public:
//	Player();
//	Player(sf::Texture* texture);
//	//~Player();
//public:
//	sf::Sprite getSprite();
//	int getLevel();
//	int getExp();
//	int getExpCap();
//
//	void setLevel(int num);
//	void setExp(int num);
//	void setExpCap(int num);
//	void setPos(sf::Vector2f pos);
//	void setTexture(sf::Texture texture);
//
//	void setAttack(int num);
//	void setDefence(int num);
//	void setVitality(int num);
//	void setAgility(int num);
//	void setKnowledge(int num);
//	void setBaseAttack(int num);
//	void setCritChance(int num);
//	void setResist(int num);
//	void setHealthCur(int num);
//	void setHealth(int num);
//	void setHealthRecover(int num);
//	void setSpeed(int num);
//	void setCastSpeed(int num);
//	void setMana(int num);
//	void setManaRecover(int num);
//	void setManaUsage(int num);
//
//	int getAttack();
//	int getDefence();
//	int getVitality();
//	int getAgility();
//	int getKnowledge();
//	int getBaseAttack();
//	int getCritChance();
//	int getResist();
//	int getHealthCur();
//	int getHealth();
//	int getHealthRecover();
//	int getSpeed();
//	int getCastSpeed();
//	int getMana();
//	int getManaRecover();
//	int getManaUsage();
//private:
//	sf::Sprite sprite;
//	//old
//	int level;
//	int exp;
//	int expCap;
//
//	//new
//	//main
//	int attack;
//	int defence;
//	int vitality;
//	int agility;
//	int knowledge;
//	//secondary
//	int baseAttack;
//	int critChance;
//
//	//int shieldCoef;
//	int resist;
//
//	int healthCur;
//	int health;
//	int healthRecover;
//
//	int speed;
//	int castSpeed;
//
//	int mana;
//	int manaRecover;
//
//	int manaUsage;
//};
//
