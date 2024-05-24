//#include "StandartEnemy.h"
//StandartEnemy::StandartEnemy()
//{
//
//}
//StandartEnemy::StandartEnemy(sf::Texture* texture, sf::Vector2f pos, float time)
//	:sprite(*texture)
//{
//	StandartEnemy::sprite.setPosition(pos);
//	if (time > 120)
//	{
//		health = 250;
//		speed = 85;
//		resist = 2;
//		damage = 12;
//		manaValue = 11;
//		if (time > 120)
//		{
//			health = 300;
//			speed = 90;
//			resist = 4;
//			damage = 14;
//			manaValue = 12;
//			if (time > 240)
//			{
//				health = 350;
//				speed = 95;
//				resist = 6;
//				damage = 16;
//				manaValue = 13;
//				if (time > 360)
//				{
//					health = 400;
//					speed = 100;
//					resist = 8;
//					damage = 18;
//					manaValue = 14;
//					if (time > 480)
//					{
//						health = 500;
//						speed = 105;
//						resist = 10;
//						damage = 20;
//						manaValue = 15;
//						if (time > 600)
//						{
//							health = 600;
//							speed = 110;
//							resist = 12;
//							damage = 22;
//							manaValue = 16;
//							if (time > 720)
//							{
//								health = 700;
//								speed = 115;
//								resist = 14;
//								damage = 24;
//								manaValue = 17;
//								if (time > 840)
//								{
//									health = 800;
//									speed = 120;
//									resist = 16;
//									damage = 26;
//									manaValue = 18;
//									if (time > 960)
//									{
//										health = 900;
//										speed = 125;
//										resist = 18;
//										damage = 28;
//										manaValue = 19;
//										if (time > 1080)
//										{
//											health = 1000;
//											speed = 130;
//											resist = 20;
//											damage = 30;
//											manaValue = 20;
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	else //default
//	{
//		health = 200;
//		speed = 80;
//		resist = 0;
//		damage = 10;
//		manaValue = 10;
//	}
//}
//StandartEnemy::~StandartEnemy()
//{
//
//}
//
//sf::Sprite StandartEnemy::getSprite()
//{
//	return StandartEnemy::sprite;
//}
//int StandartEnemy::getHealth()
//{
//	return StandartEnemy::health;
//}
//int StandartEnemy::getDamage()
//{
//	return StandartEnemy::damage;
//}
//int StandartEnemy::getSpeed()
//{
//	return StandartEnemy::speed;
//}
//int StandartEnemy::getResist()
//{
//	return StandartEnemy::resist;
//}
//int StandartEnemy::getManaValue()
//{
//	return StandartEnemy::manaValue;
//}
//
//void StandartEnemy::setPosition(sf::Vector2f pos)
//{
//	StandartEnemy::sprite.setPosition(pos);
//}
//void StandartEnemy::setHealth(int num)
//{
//	StandartEnemy::health = num;
//}
//void StandartEnemy::setDamage(int num)
//{
//	StandartEnemy::damage = num;
//}
//void StandartEnemy::setSpeed(int num)
//{
//	StandartEnemy::speed = num;
//}
//void StandartEnemy::setResist(int num)
//{
//	StandartEnemy::resist = num;
//}
//void StandartEnemy::setManaValue(int num)
//{
//	StandartEnemy::manaValue = num;
//}