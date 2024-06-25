#pragma once

enum class PlayerState
{
	NotDefined,
	Alive,
	Dead
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