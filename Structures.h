#pragma once
#include "Enums.h"

struct CommandAttributes
{
	int int1;
	int int2;
	int int3;
	int int4;
	float float1;
	float float2;
	TileType tileType;
};

struct Command
{
	CommandName name;
	CommandAttributes attribute;
};

struct InterfaceElements
{
	sf::RectangleShape background;
};

struct Overlay
{
	sf::RectangleShape floorProgress;
	sf::Text floorProgressLabel;
	sf::RectangleShape floorNum;
	sf::Text floorNumLabel;
	sf::RectangleShape hpBarFill;
	sf::RectangleShape hpBarEdge;
	sf::RectangleShape staminaBarFill;
	sf::RectangleShape staminaBarEdge;
	sf::RectangleShape armourBarFill;
	sf::RectangleShape armourBarEdge;
	sf::RectangleShape armourSpriteEdge;
	sf::RectangleShape bullet9mmEdge;
	sf::Sprite bullet9mmSprite;
	sf::Text bullet9mmLabel;
	sf::RectangleShape bullet556mmEdge;
	sf::Sprite bullet556mmSprite;
	sf::Text bullet556mmLabel;
	sf::RectangleShape bullet762mmEdge;
	sf::Sprite bullet762mmSprite;
	sf::Text bullet762mmLabel;
	sf::RectangleShape bullet12gaugeEdge;
	sf::Sprite bullet12gaugeSprite;
	sf::Text bullet12gaugeLabel;
	sf::RectangleShape mainWeaponEdge;
	sf::RectangleShape mainWeaponFill;
	sf::RectangleShape secondaryWeaponEdge;
	sf::RectangleShape secondaryWeaponFill;
	sf::RectangleShape repairKitEdge;
	sf::RectangleShape repairKitFill;
	sf::RectangleShape healthKitEdge;
	sf::RectangleShape healthKitFill;
};