#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(TileType tileType, int pos_x, int pos_y, int index_x, int index_y, int side)
{
    switch (tileType)
    {
        case TileType::Level:
        {
            body.setFillColor(sf::Color::Blue);
            body.setSize(sf::Vector2f(side, side));
            body.setOrigin(sf::Vector2f(side / 2, side / 2));
            hitbox.setSize(sf::Vector2f(side - 2, side - 2));
            hitbox.setOrigin(sf::Vector2f((side - 2) / 2, (side - 2) / 2));
            break;
        }
        case TileType::Central:
        {
            body.setFillColor(sf::Color::Yellow);
            body.setSize(sf::Vector2f(side, side));
            body.setOrigin(sf::Vector2f(side / 2, side / 2));
            hitbox.setSize(sf::Vector2f(side - 2, side - 2));
            hitbox.setOrigin(sf::Vector2f((side - 2) / 2, (side - 2) / 2));
            break;
        }
        case TileType::CorridorV:
        {
            body.setFillColor(sf::Color::Green);
            body.setSize(sf::Vector2f(side / 3, side));
            body.setOrigin(sf::Vector2f(side / 6, side / 2));
            hitbox.setSize(sf::Vector2f(side / 3 - 2, side - 2));
            hitbox.setOrigin(sf::Vector2f((side / 3 - 2) / 2, (side - 2) / 2));
            break;
        }
        case TileType::CorridorH:
        {
            body.setFillColor(sf::Color::Green);
            body.setSize(sf::Vector2f(side, side / 3));
            body.setOrigin(sf::Vector2f(side / 2, side / 6));
            hitbox.setSize(sf::Vector2f(side - 2, side / 3 - 2));
            hitbox.setOrigin(sf::Vector2f((side - 2) / 2, (side / 3 - 2) / 2));
            break;
        }
        default:
        {
            break;
        }
    }
    body.setPosition(sf::Vector2f(pos_x, pos_y));
    hitbox.setPosition(sf::Vector2f(pos_x, pos_y));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.f);
    index.x = index_x;
    index.y = index_y;
}

Tile::~Tile()
{
}

sf::RectangleShape Tile::getBody()
{
    return body;
}

sf::RectangleShape Tile::getHitbox()
{
    return hitbox;
}

sf::Vector2i Tile::getIndex()
{
    return index;
}
