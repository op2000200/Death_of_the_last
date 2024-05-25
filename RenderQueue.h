#pragma once
#include <SFML/Graphics.hpp>

class RenderQueue
{
public:
	RenderQueue();
	~RenderQueue();

	void spriteHolderPush(sf::Sprite sprite);
	sf::Sprite spriteHolderGet(int i);
	int spriteHolderGetSize();
	void spriteHolderErase(int i);
	void spriteHolderClear();

	void circleHolderPush(sf::CircleShape circle);
	sf::CircleShape circleHolderGet(int i);
	int circleHolderGetSize();
	void circleHolderErase(int i);
	void circleHolderClear();

	void rectHolderPush(sf::RectangleShape rect);
	sf::RectangleShape rectHolderGet(int i);
	int rectHolderGetSize();
	void rectHolderErase(int i);
	void rectHolderClear();

	void convexHolderPush(sf::ConvexShape convex);
	sf::ConvexShape convexHolderGet(int i);
	int convexHolderGetSize();
	void convexHolderErase(int i);
	void convexHolderClear();
private:
	std::vector<sf::Sprite> spriteHolder;
	std::vector<sf::CircleShape> circleHolder;
	std::vector<sf::RectangleShape> rectHolder;
	std::vector<sf::ConvexShape> convexHolder;
};

