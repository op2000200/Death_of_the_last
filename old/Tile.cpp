#include "Tile.h"

Tile::Tile(int num, int numR, sf::Vector2f pos, sf::Texture* tex, int x, int y)
	:	sprite(sf::Texture(), sf::IntRect(0, 0, 2000, 2000))
{
	state = 0;
	type = num;
	randNum = numR;
	srand(randNum);
	if (type == 0)	//empty
	{
		sprite.setTexture(tex[rand() % 5]);
		sprite.setPosition(pos);
	}
	if (type == 1)	//normal
	{
		sprite.setTexture(tex[rand() % 5]);
		sprite.setPosition(pos);
		//int rockNum = rand() % 50;
		//int rockCreated = 0;
		//int o = 1;
		//while (rockCreated <= rockNum)
		//{
		//	if (rand() % o == 0)
		//	{
		//		int rockType = rand() % 3;
		//		int coordX, coordY;
		//		coordX = rand() % 2001;
		//		coordY = rand() % 2001;
		//		sf::Sprite rock(tex[rockType + 5]);
		//		rock.setOrigin(sf::Vector2f(tex[rockType + 5].getSize().x / 2, tex[rockType + 5].getSize().y / 2));
		//		rock.setPosition(sf::Vector2f(2000 * x + coordX - 100000, 2000 * y + coordY - 100000));
		//		rock.setRotation(rand());
		//		rocks.push_back(rock);
		//		o++;
		//	}
		//	else
		//	{
		//		break;
		//	}
		//	rockCreated++;
		//}

	}
	if (type == 2)	//lava
	{
		sprite.setTexture(tex[rand() % 5]);
		sprite.setPosition(pos);
	}
	if (type == 3)	//rocks
	{
		sprite.setTexture(tex[rand() % 5]);
		sprite.setPosition(pos);
	}
	if (type == 4)	//big rock
	{
		sprite.setTexture(tex[rand() % 5]);
		sprite.setPosition(pos);
	}
}

Tile::~Tile()
{

}

sf::Sprite Tile::getSprite()
{
	return Tile::sprite;
}

int Tile::rockNum()
{
	return rocks.size();
}

sf::Sprite Tile::getRock(int i)
{
	return rocks[i];
}

int Tile::getRand()
{
	return randNum;
}

bool Tile::isBlocked(sf::Vector2f pos)
{
	return false;
}

