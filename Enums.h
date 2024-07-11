#pragma once

enum class SpellState
{
	Alive,
	Waiting,
	Dead,
	Diactivated,
	Activated
};

enum class PlayerState
{
	NotDefined,
	Alive,
	Dead
};

enum class EnemyState
{
	Standing,
	Moving,
	Following,
	Chasing
};

enum class EnemyType
{
	Standart,
	Summoner,
	Summoned,
	Kamikaze,
	Shooter
};

enum class Element
{
	Fire,
	Ice,
	Electricity,
	Water,
	Stone,
	Wind,
	Light,
	Dark,
	Force,
	Phys
};

enum class CommandType
{
	MovedUpRight,
	MovedUp,
	MovedUpLeft,
	MovedLeft,
	MovedDownLeft,
	MovedDown,
	MovedDownRight,
	MovedRight,
	LUAttack,
	LUDefence,
	LUAgility,
	LUVitality,
	LUKnowledge,
	Damaged,
	Healed,
	Created
};

enum class Type
{
	MainMenu,
	MainMenuFirstLaunch,
	MainMenuLoading,
	MainMenuLoaded,
	MainMenuGeneral,
	MainMenuExit,
	PlayMenu,
	PlayMenuModeSelector,
	PlayMenuArcadeModeLevelSelector,
	PlayMenuArcadeModeCharacterPrepare,
	PlayMenuArcadeModeSpell,
	PlayMenuArcadeModeRun,
	PlayMenuArcadeModePause,
	PlayMenuArcadeModeLevelUp,
	PlayMenuArcadeModeDeath,
	SettingsMenu,
	SMVideo,
	SMAudio,
	SMGame,
	SMOther,
	ArchiveMenu,

	Exit,

	Blank
};