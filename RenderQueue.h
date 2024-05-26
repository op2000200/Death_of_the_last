#pragma once
#include <SFML/Graphics.hpp>

class RenderQueue
{
public:
	RenderQueue();
	~RenderQueue();

	void backgroundHolderPush(sf::Sprite sprite);
	sf::Sprite backgroundHolderGet(int i);
	int backgroundHolderGetSize();
	void backgroundHolderErase(int i);
	void backgroundHolderClear();

	void projectileHolderPush(sf::Sprite sprite);
	sf::Sprite projectileHolderGet(int i);
	int projectileHolderGetSize();
	void projectileHolderErase(int i);
	void projectileHolderClear();

	void enemyHolderPush(sf::Sprite sprite);
	sf::Sprite enemyHolderGet(int i);
	int enemyHolderGetSize();
	void enemyHolderErase(int i);
	void enemyHolderClear();

	void playerHolderPush(sf::Sprite sprite);
	sf::Sprite playerHolderGet(int i);
	int playerHolderGetSize();
	void playerHolderErase(int i);
	void playerHolderClear();

	void spriteHolderPush(sf::Sprite sprite);
	sf::Sprite spriteHolderGet(int i);
	int spriteHolderGetSize();
	void spriteHolderErase(int i);
	void spriteHolderClear();

private:
	std::vector<sf::Sprite> backgroundHolder;
	std::vector<sf::Sprite> projectileHolder;
	std::vector<sf::Sprite> enemyHolder;
	std::vector<sf::Sprite> playerHolder;
	std::vector<sf::Sprite> spriteHolder;
};

