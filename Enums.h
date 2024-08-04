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
	Dash,
	Interaction
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
	MM9,
	MM556,
	MM762,
	MM12
};

enum WeaponName
{
	Knife,
	Fist,
	VP70,
	SWMP,
	AR10,
	XM8,
	G36,
	Groza,
	MR133,
	M88,
	NoWeapon
};

enum AttackPattern
{
	Auto,
	SemiAuto
};