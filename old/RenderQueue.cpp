#include "RenderQueue.h"

RenderQueue::RenderQueue()
{
}

RenderQueue::~RenderQueue()
{
	backgroundHolder.clear();
	backgroundHolder.~vector();
	projectileHolder.clear();
	projectileHolder.~vector();
	enemyHolder.clear();
	enemyHolder.~vector();
	playerHolder.clear();
	playerHolder.~vector();
	spriteHolder.clear();
	spriteHolder.~vector();
}

void RenderQueue::backgroundHolderPush(sf::Sprite sprite)
{
	backgroundHolder.push_back(sprite);
}

sf::Sprite RenderQueue::backgroundHolderGet(int i)
{
	return backgroundHolder[i];
}

int RenderQueue::backgroundHolderGetSize()
{
	return backgroundHolder.size();
}

void RenderQueue::backgroundHolderErase(int i)
{
	backgroundHolder.erase(backgroundHolder.begin() + i);
}

void RenderQueue::backgroundHolderClear()
{
	backgroundHolder.clear();
}

void RenderQueue::projectileHolderPush(sf::Sprite sprite)
{
	projectileHolder.push_back(sprite);
}

sf::Sprite RenderQueue::projectileHolderGet(int i)
{
	return projectileHolder[i];
}

int RenderQueue::projectileHolderGetSize()
{
	return projectileHolder.size();
}

void RenderQueue::projectileHolderErase(int i)
{
	projectileHolder.erase(projectileHolder.begin() + i);
}

void RenderQueue::projectileHolderClear()
{
	projectileHolder.clear();
}

void RenderQueue::enemyHolderPush(sf::Sprite sprite)
{
	enemyHolder.push_back(sprite);
}

sf::Sprite RenderQueue::enemyHolderGet(int i)
{
	return enemyHolder[i];
}

int RenderQueue::enemyHolderGetSize()
{
	return enemyHolder.size();
}

void RenderQueue::enemyHolderErase(int i)
{
	enemyHolder.erase(enemyHolder.begin() + i);
}

void RenderQueue::enemyHolderClear()
{
	enemyHolder.clear();
}

void RenderQueue::playerHolderPush(sf::Sprite sprite)
{
	playerHolder.push_back(sprite);
}

sf::Sprite RenderQueue::playerHolderGet(int i)
{
	return playerHolder[i];
}

int RenderQueue::playerHolderGetSize()
{
	return playerHolder.size();
}

void RenderQueue::playerHolderErase(int i)
{
	playerHolder.erase(playerHolder.begin() + i);
}

void RenderQueue::playerHolderClear()
{
	playerHolder.clear();
}

void RenderQueue::spriteHolderPush(sf::Sprite sprite)
{
	spriteHolder.push_back(sprite);
}

sf::Sprite RenderQueue::spriteHolderGet(int i)
{
	return spriteHolder[i];
}

int RenderQueue::spriteHolderGetSize()
{
	return spriteHolder.size();
}

void RenderQueue::spriteHolderErase(int i)
{
	spriteHolder.erase(spriteHolder.begin() + i);
}

void RenderQueue::spriteHolderClear()
{
	spriteHolder.clear();
}