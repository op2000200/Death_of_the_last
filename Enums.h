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
	MoveRight,
	TickTiles
};

enum TileType
{
	Level,
	LevelEmpty,
	LevelQizz,
	LevelRegular,
	LevelReward,
	LevelStairs,
	LevelTeleport,
	Central,
	CorridorV,
	CorridorH
};

enum TileStatus
{
	NotCleared,
	Cleared
};

enum LevelGoal
{
	No,
	Death,
	Qizz,
	Reward
};