#pragma once
#include <SFML/Graphics.hpp>
#include "Structures.h"
class AimedMissle
{
public:
	AimedMissle(sf::Vector2f pos, sf::Texture* texture, sf::Vector2f tar);
	~AimedMissle();
	sf::Sprite getSprite();
	void setPos(sf::Vector2f pos);
	void setTar(sf::Vector2f pos);
	sf::Vector2f getTar();
	SpellChar getChar();
	void tickLength();
	void resetLength();
	void tickLifetime();
	SpellState getState();
	void setState(SpellState state);
private:
	SpellChar spellChar;
	SpellState spellState;
	sf::Sprite sprite;
	sf::Vector2f dir;
};

