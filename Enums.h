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
	Interaction,
	RangeAttack,
	CloseAttack,
	Rotate,
	UpdateOverlay
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
	Solved,
	Marked
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
	Regular,
	Fight,
	Check
};

enum AmmoType
{
	MM9,
	MM556,
	MM762,
	Gauge12
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

enum WallState
{
	Empty,
	Walled,
	Enemied
};