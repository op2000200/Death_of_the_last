#include "RenderQueue.h"

RenderQueue::RenderQueue()
{
}

RenderQueue::~RenderQueue()
{
	spriteHolder.clear();
	spriteHolder.~vector();
	circleHolder.clear();
	circleHolder.~vector();
	rectHolder.clear();
	rectHolder.~vector();
	convexHolder.clear();
	convexHolder.~vector();
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

void RenderQueue::circleHolderPush(sf::CircleShape circle)
{
	circleHolder.push_back(circle);
}

sf::CircleShape RenderQueue::circleHolderGet(int i)
{
	return circleHolder[i];
}

int RenderQueue::circleHolderGetSize()
{
	return circleHolder.size();
}

void RenderQueue::circleHolderErase(int i)
{
	circleHolder.erase(circleHolder.begin() + i);
}

void RenderQueue::circleHolderClear()
{
	circleHolder.clear();
}

void RenderQueue::rectHolderPush(sf::RectangleShape rect)
{
	rectHolder.push_back(rect);
}

sf::RectangleShape RenderQueue::rectHolderGet(int i)
{
	return rectHolder[i];
}

int RenderQueue::rectHolderGetSize()
{
	return rectHolder.size();
}

void RenderQueue::rectHolderErase(int i)
{
	rectHolder.erase(rectHolder.begin() + i);
}

void RenderQueue::rectHolderClear()
{
	rectHolder.clear();
}

void RenderQueue::convexHolderPush(sf::ConvexShape convex)
{
	convexHolder.push_back(convex);
}

sf::ConvexShape RenderQueue::convexHolderGet(int i)
{
	return convexHolder[i];
}

int RenderQueue::convexHolderGetSize()
{
	return convexHolder.size();
}

void RenderQueue::convexHolderErase(int i)
{
	convexHolder.erase(convexHolder.begin() + i);
}

void RenderQueue::convexHolderClear()
{
	convexHolder.clear();
}
