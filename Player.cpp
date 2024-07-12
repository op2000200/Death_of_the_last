#include "Player.h"

Player::Player()
{
	playerState = PlayerState::NotDefined;
	texture = new sf::Texture;
	characteristics.atk = 0;
	characteristics.def = 0;
	characteristics.agl = 0;
	characteristics.vit = 0;
	characteristics.knw = 0;
	characteristics.atkMul = 0;
	characteristics.critChance = 0;
	characteristics.defMul = 0;
	characteristics.resistAll = 0;
	characteristics.resistElement = 0;
	characteristics.speed = 204;
	characteristics.evasionChance = 0;
	characteristics.healthMax = 0;
	characteristics.healthCurrent = 0;
	characteristics.healthRegen = 0;
	characteristics.sprintLongevity = 0;
	characteristics.atkSpeed = 0;
	characteristics.manaMax = 0;
	characteristics.manaReserved = 0;
	characteristics.manaUsage = 0;
	characteristics.manaRegen = 0;
	characteristics.element = Element::Fire;
	spellLevel = new int[16];
	spellLevel[1] = 0;
	spellLevel[2] = 1;
	spellLevel[3] = 0;
	spellLevel[4] = 0;
	spellLevel[5] = 0;
	spellLevel[6] = 0;
	spellLevel[7] = 0;
	spellLevel[8] = 0;
	spellLevel[9] = 1;
	spellLevel[10] = 0;
	spellLevel[11] = 0;
	spellLevel[12] = 0;
	spellLevel[13] = 0;
	spellLevel[14] = 0;
	spellLevel[15] = 0;
	spellCooldown = new int[16];
	spellCooldown[1] = 3000;
	spellCooldown[2] = 3000;
	spellCooldown[3] = 3000;
	spellCooldown[4] = 3000;
	spellCooldown[5] = 10000;
	spellCooldown[6] = 20000;
	spellCooldown[7] = 500;
	spellCooldown[8] = 500;
	spellCooldown[9] = 1000;
	spellCooldown[14] = 30000;
	spellCooldown[15] = 30000;
	spellCooldownCounter = new int[16];
	srand(time(0));
	for (int i = 1; i < 16; i++)
	{
		spellCooldownCounter[i] = rand() % 2000 + 1000;
	}
}

Player::~Player()
{
}

bool Player::processCommand(Commands command)
{
	if (command.command == CommandType::Created)
	{
		sprite.setOrigin(sf::Vector2f(50,50));
		sprite.setPosition(sf::Vector2f(command.numbers[0] / 2, command.numbers[1] / 2));
		texture[0].loadFromFile("assets/textures/playerNew.png");
		sprite.setTexture(*texture);
		playerState = PlayerState::Alive;
	}
	if (command.command == CommandType::MovedUp)
	{
		sprite.setPosition(sf::Vector2f(
			sprite.getPosition().x,
			sprite.getPosition().y - characteristics.speed * (1.f/1000.f)
		));
	}
	if (command.command == CommandType::MovedLeft)
	{
		sprite.setPosition(sf::Vector2f(
			sprite.getPosition().x - characteristics.speed * (1.f / 1000.f),
			sprite.getPosition().y
		));
	}
	if (command.command == CommandType::MovedRight)
	{
		sprite.setPosition(sf::Vector2f(
			sprite.getPosition().x + characteristics.speed * (1.f / 1000.f),
			sprite.getPosition().y
		));
	}
	if (command.command == CommandType::MovedDown)
	{
		sprite.setPosition(sf::Vector2f(
			sprite.getPosition().x,
			sprite.getPosition().y + characteristics.speed * (1.f / 1000.f)
		));
	}
	return true;
}

sf::Sprite Player::getSprite()
{
	return sprite;
}

PlayerState Player::getState()
{
	return playerState;
}

Characteristics Player::getChar()
{
	return characteristics;
}

int* Player::getSpellLevel()
{
	return spellLevel;
}

int* Player::getSpellCooldown()
{
	return spellCooldown;
}

int* Player::getSpellCooldownCounter()
{
	return spellCooldownCounter;
}

void Player::tickSpellCC(int i)
{
	spellCooldownCounter[i]++;
}

void Player::resetSpellCC(int i)
{
	spellCooldownCounter[i] = 0;
}


//
//Player::Player(sf::Texture *texture)
//	:sprite(*texture)
//{
//	level = 0;
//	exp = 0;
//	expCap = 100;
//
//
//	attack = 1;
//	defence = 1;
//	vitality = 1;
//	agility = 1;
//	knowledge = 1;
//	//secondary
//	baseAttack = 55;
//	critChance = 0;
//
//	//int shieldCoef;
//	resist = 0;
//
//	healthCur = 55;
//	health = 55;
//	healthRecover = 1;
//
//	speed = 104;
//	castSpeed = 50;
//
//	mana = 100;
//	manaRecover = 1;
//
//	manaUsage = 0;
//}
//
//sf::Sprite Player::getSprite()
//{
//	return Player::sprite;
//}
//
//void Player::setPos(sf::Vector2f pos)
//{
//	Player::sprite.setPosition(pos);
//}
//
//void Player::setTexture(sf::Texture texture)
//{
//	Player::sprite.setTexture(texture);
//}
//
//void Player::setExpCap(int num)
//{
//	Player::expCap = num;
//}
//
//int Player::getExpCap()
//{
//	return Player::expCap;
//}
//
//void Player::setExp(int num)
//{
//	Player::exp = num;
//}
//
//int Player::getExp()
//{
//	return Player::exp;
//}
//
//void Player::setLevel(int num)
//{
//	Player::level = num;
//}
//
//int Player::getLevel()
//{
//	return Player::level;
//}
//
//void Player::setAttack(int num)
//{
//	Player::attack = num;
//}
//
//void Player::setDefence(int num)
//{
//	Player::defence = num;
//}
//
//void Player::setVitality(int num)
//{
//	Player::vitality = num;
//
//}
//void Player::setAgility(int num)
//{
//	Player::agility = num;
//}
//
//void Player::setKnowledge(int num)
//{
//	Player::knowledge = num;
//}
//
//void Player::setBaseAttack(int num)
//{
//	Player::baseAttack = num;
//}
//
//void Player::setCritChance(int num)
//{
//	Player::critChance = num;
//}
//
//void Player::setResist(int num)
//{
//	Player::resist = num;
//}
//
//void Player::setHealthCur(int num)
//{
//	Player::healthCur = num;
//}
//
//void Player::setHealth(int num)
//{
//	Player::health = num;
//}
//
//void Player::setHealthRecover(int num)
//{
//	Player::healthRecover = num;
//}
//
//void Player::setSpeed(int num)
//{
//	Player::speed = num;
//}
//
//void Player::setCastSpeed(int num)
//{
//	Player::castSpeed = num;
//}
//
//void Player::setMana(int num)
//{
//	Player::mana = num;
//}
//
//void Player::setManaRecover(int num)
//{
//	Player::manaRecover = num;
//}
//
//void Player::setManaUsage(int num)
//{
//	Player::manaUsage = num;
//}
// 
//int Player::getAttack()
//{
//	return Player::attack;
//}
//
//int Player::getDefence()
//{
//	return Player::defence;
//}
//
//int Player::getVitality()
//{
//	return Player::vitality;
//}
//
//int Player::getAgility()
//{
//	return Player::agility;
//}
//
//int Player::getKnowledge()
//{
//	return Player::knowledge;
//}
//
//int Player::getBaseAttack()
//{
//	return Player::baseAttack;
//}
//
//int Player::getCritChance()
//{
//	return Player::critChance;
//}
//
//int Player::getResist()
//{
//	return Player::resist;
//}
//
//int Player::getHealth()
//{
//	return Player::health;
//}
//
//int Player::getHealthCur()
//{
//	return Player::healthCur;
//}
//
//int Player::getHealthRecover()
//{
//	return Player::healthRecover;
//}
//
//int Player::getSpeed()
//{
//	return Player::speed;
//}
//
//int Player::getCastSpeed()
//{
//	return Player::castSpeed;
//}
//
//int Player::getMana()
//{
//	return Player::mana;
//}
//
//int Player::getManaRecover()
//{
//	return Player::manaRecover;
//}
//
//int Player::getManaUsage()
//{
//	return Player::manaUsage;
//}