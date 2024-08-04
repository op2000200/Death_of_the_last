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
	TickTiles,
	Dash
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
	Cleared,
	Solved
};

enum LevelGoal
{
	No,
	Death,
	Qizz,
	Reward
};

enum EnemyState
{
	Standing,
	Moving
};

enum EnemyBehavior
{
	Stand,
	Attacking,
	Backing
};

enum AmmoType
{
	No
};

enum WeaponName
{
	Knife,
	Dagger,
	Fist
};