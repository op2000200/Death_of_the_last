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