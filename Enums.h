#pragma once
#include "SFML/Graphics.hpp"

enum CommandName
{
	CreateTile,
	SpawnPlayer,
	Display,
	Close,
	MoveUp,
	MoveLeft,
	MoveDown,
	MoveRight
};

enum TileType
{
	Level,
	Central,
	CorridorV,
	CorridorH
};