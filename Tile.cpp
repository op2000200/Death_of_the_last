#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(TileType tileType, int pos_x, int pos_y, int index_x, int index_y, int side, float diff, sf::Texture* bg, sf::Texture* bg2)
{
    int tileSize = side;
    sprite.setTexture(*bg);
    sprite.setOrigin(sf::Vector2f(
        (bg->getSize().x / 2),
        (bg->getSize().y / 2)
    ));
    sprite.setPosition(sf::Vector2f(pos_x, pos_y));
    switch (tileType)
    {
        case TileType::LevelRegular:
        {
            body.setFillColor(sf::Color(175,175,175));
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            //spawnEnemies(diff, side, pos_x, pos_y);
            goal = LevelGoal::Death;
            type = tileType;
            sprite.setScale(sf::Vector2f(
                (side / 1.f) / (bg->getSize().x - 40),
                (side / 1.f) / (bg->getSize().y - 40)
            ));
            break;
        }
        case TileType::LevelQizz: //get rid of it
        {
            body.setFillColor(sf::Color::Blue);
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            spawnChallenge(diff);
            goal = LevelGoal::Qizz;
            type = tileType;
            break;
        }
        case TileType::LevelReward:
        {
            body.setFillColor(sf::Color(175, 175, 175));
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            spawnReward(diff);
            goal = LevelGoal::Reward;
            type = tileType;
            break;
        }
        case TileType::LevelEmpty: //get rid of it
        {
            body.setFillColor(sf::Color::Green);
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            break;
        }
        case TileType::LevelStairs: //get rid of it
        {
            body.setFillColor(sf::Color::Cyan);
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            break;
        }
        case TileType::LevelTeleport: //get rid of it
        {
            body.setFillColor(sf::Color::Magenta);
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            break;
        }
        case TileType::Central:
        {
            body.setFillColor(sf::Color(175, 175, 175));
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            sprite.setScale(sf::Vector2f(
                (side / 1.f) / (bg->getSize().x - 40),
                (side / 1.f) / (bg->getSize().y - 40)
            ));
            //RangedWeapon ranged(WeaponName::VP70, sf::Vector2f(pos_x, pos_y), side, textureHolder[2]);
            //rangedBuffer.push_back(ranged);
            //MeleeWeapon melee(Knife, sf::Vector2f(pos_x + side / 20, pos_y), side, textureHolder[0]);
            //meleeBuffer.push_back(melee);
            break;
        }
        case TileType::CorridorV:
        {
            body.setFillColor(sf::Color(175, 175, 175));
            body.setSize(sf::Vector2f(tileSize / 3, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 6, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize / 3 - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize / 3 - 2) / 2, (tileSize - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            sprite.setTexture(*bg2);
            sprite.setOrigin(sf::Vector2f(
                (bg2->getSize().x / 2),
                (bg2->getSize().y / 2)
            ));
            sprite.setPosition(sf::Vector2f(pos_x, pos_y));
            sprite.setScale(sf::Vector2f(
                (side / 1.f) / (bg2->getSize().x),
                (side / 3.f) / (bg2->getSize().y - 40)
            ));
            //sprite.setRotation(0);
            break;
        }
        case TileType::CorridorH:
        {
            body.setFillColor(sf::Color(175, 175, 175));
            body.setSize(sf::Vector2f(tileSize, tileSize / 3));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 6));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize / 3 - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize / 3 - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            sprite.setTexture(*bg2);
            sprite.setOrigin(sf::Vector2f(
                (bg2->getSize().x / 2),
                (bg2->getSize().y / 2)
            ));
            sprite.setPosition(sf::Vector2f(pos_x, pos_y));
            sprite.setScale(sf::Vector2f(
                (side / 1.f) / (bg2->getSize().x),
                (side / 3.f) / (bg2->getSize().y - 40)
            ));
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
    tileStatus = TileStatus::NotCleared;
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

sf::Sprite Tile::getSprite()
{
    return sprite;
}

sf::Vector2i Tile::getIndex()
{
    return index;
}

void Tile::clear()
{
    tileStatus = TileStatus::Cleared;
    //body.setFillColor(sf::Color(100,100,100));
}

void Tile::solve()
{
    tileStatus = TileStatus::Solved;
}

LevelGoal Tile::getGoal()
{
    return goal;
}

TileStatus Tile::getState()
{
    return tileStatus;
}

TileType Tile::getType()
{
    return type;
}

std::vector<Enemy> Tile::getEnemyBuffer()
{
    return enemyBuffer;
}

std::vector<RangedWeapon> Tile::getRangedBuffer()
{
    return rangedBuffer;
}

std::vector<MeleeWeapon> Tile::getMeleeBuffer()
{
    return meleeBuffer;
}

void Tile::delRangedBufferElem(int i)
{
    rangedBuffer.erase(rangedBuffer.begin() + i);
}

void Tile::delMeleeBufferElem(int i)
{
    meleeBuffer.erase(meleeBuffer.begin() + i);
}

void Tile::spawnEnemies(float diff, int side, int pos_x, int pos_y)
{
    int x, y, count, created = 0;
    count = rand() % 10 + 1;
    while (created < 1)
    {
        x = rand() % 20;
        y = rand() % 20;
        if (walls[x][y].getWS() == Empty)
        {
            Enemy enemy(pos_x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + (hitbox.getSize().x / 20) * x, pos_y - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + (hitbox.getSize().x / 20) * y, side, x, y);
            enemyBuffer.push_back(enemy);
            walls[x][y].spawn();
            created++;
        }
    }
}

void Tile::spawnChallenge(float diff)
{
}

void Tile::spawnReward(float diff)
{
}

void Tile::spawnWalls(int up, int left, int down, int right, sf::Texture* bx)
{
    walls = new Wall*[20];
    for (int i = 0; i < 20; i++)
    {
        walls[i] = new Wall[20];
    }
    if (up == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 7; j < 13; j++)
            {
                nonEmptyWalls.push_back(sf::Vector2i(j, i));
            }
        }
    }
    if (left == 1)
    {
        for (int i = 7; i < 13; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                nonEmptyWalls.push_back(sf::Vector2i(j, i));
            }
        }
    }
    if (down == 1)
    {
        for (int i = 16; i < 20; i++)
        {
            for (int j = 7; j < 13; j++)
            {
                nonEmptyWalls.push_back(sf::Vector2i(j, i));
            }
        }
    }
    if (right == 1)
    {
        for (int i = 7; i < 13; i++)
        {
            for (int j = 16; j < 20; j++)
            {
                nonEmptyWalls.push_back(sf::Vector2i(j, i));
            }
        }
    }
    int wallPoints = /*rand() % 1 + */ 160;
    int created = 0;
    int tries = 0;
    while (created < wallPoints and tries < 1000)
    {
        int x = rand() % 18 + 1;
        int y = rand() % 18 + 1;
        tries++;
        for (int i = 0; i < nonEmptyWalls.size(); i++)
        {
            if (x == nonEmptyWalls[i].x and y == nonEmptyWalls[i].y)
            {
                break;
            }
            if (i == nonEmptyWalls.size() - 1)
            {
                if (walls[x][y - 1].getWS() != Walled and walls[x - 1][y].getWS() != Walled and walls[x][y + 1].getWS() != Walled and walls[x + 1][y].getWS() != Walled and walls[x - 1][y - 1].getWS() != Walled and walls[x + 1][y - 1].getWS() != Walled and walls[x - 1][y + 1].getWS() != Walled and walls[x + 1][y + 1].getWS() != Walled and walls[x][y].getWS() != Walled)
                {
                    created++;
                    Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (x),
                        hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (y),
                        hitbox.getSize().x,
                        bx
                    );
                    walls[x][y] = wall;
                    wallsToDraw.push_back(sf::Vector2i(x, y));
                }

                createWallRow(rand() % 4, sf::Vector2i(x, y), 100, bx);
            }
        }
    }
    for (int i = 1; i < 19; i++)
    {
        for (int j = 1; j < 19; j++)
        {
            if (walls[i][j].getWS() != Walled)
            {
                int ctr = 0;
                bool u = false, l = false, d = false, r = false;
                if (walls[i][j - 1].getWS() == Walled)
                {
                    ctr++;
                    u = true;
                }
                if (walls[i - 1][j].getWS() == Walled)
                {
                    ctr++;
                    l = true;
                }
                if (walls[i][j + 1].getWS() == Walled)
                {
                    ctr++;
                    d = true;
                }
                if (walls[i + 1][j].getWS() == Walled)
                {
                    ctr++;
                    r = true;
                }
                if (ctr > 2)
                {
                    if (u)
                    {
                        walls[i][j - 1] = Wall();
                        for (int k = 0; k < wallsToDraw.size(); k++)
                        {
                            if (wallsToDraw[k].x == i and wallsToDraw[k].y == j - 1)
                            {
                                wallsToDraw.erase(wallsToDraw.begin() + k);
                            }
                        }
                    }
                    else
                    {
                        if (l)
                        {
                            walls[i - 1][j] = Wall();
                            for (int k = 0; k < wallsToDraw.size(); k++)
                            {
                                if (wallsToDraw[k].x == i - 1 and wallsToDraw[k].y == j)
                                {
                                    wallsToDraw.erase(wallsToDraw.begin() + k);
                                }
                            }
                        }
                        else
                        {
                            if (d)
                            {
                                walls[i][j + 1] = Wall();
                                for (int k = 0; k < wallsToDraw.size(); k++)
                                {
                                    if (wallsToDraw[k].x == i and wallsToDraw[k].y == j + 1)
                                    {
                                        wallsToDraw.erase(wallsToDraw.begin() + k);
                                    }
                                }
                            }
                            else
                            {
                                if (r)
                                {
                                    walls[i + 1][j] = Wall();
                                    for (int k = 0; k < wallsToDraw.size(); k++)
                                    {
                                        if (wallsToDraw[k].x == i + 1 and wallsToDraw[k].y == j)
                                        {
                                            wallsToDraw.erase(wallsToDraw.begin() + k);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Tile::createWallRow(int dir, sf::Vector2i index, int chance, sf::Texture* bx)
{
    switch (dir)
    {
    case 0:
    {
        if (index.x != 1 and index.x != 18 and index.y != 1 and index.y != 18)
        {
            Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y - 1),
                hitbox.getSize().x,
                bx
            );
            int roll = rand() % 100;
            int direction;
            if (roll < 50)
            {
                direction = 0;
            }
            else
            {
                if (roll < 76)
                {
                    direction = 1;
                }
                else
                {
                    direction = 3;
                }
            }
            roll = rand() % 100;
            if (roll < chance)
            {
                for (int i = 0; i < nonEmptyWalls.size(); i++)
                {
                    if (index.x == nonEmptyWalls[i].x and index.y - 1 == nonEmptyWalls[i].y)
                    {
                        break;
                    }
                    if (i == nonEmptyWalls.size() - 1)
                    {
                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y - 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y - 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y - 1));

                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y));

                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y + 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y + 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y + 1));
                        walls[index.x][index.y - 1] = wall;
                        wallsToDraw.push_back(sf::Vector2i(index.x, index.y - 1));
                        createWallRow(direction, sf::Vector2i(index.x, index.y - 1), chance - 5, bx);
                    }
                }
            }
        }
        break;
    }
    case 1:
    {
        if (index.x != 1 and index.x != 18 and index.y != 1 and index.y != 18)
        {
            Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x - 1),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y),
                hitbox.getSize().x,
                bx
            );
            int roll = rand() % 100;
            int direction;
            if (roll < 50)
            {
                direction = 1;
            }
            else
            {
                if (roll < 76)
                {
                    direction = 0;
                }
                else
                {
                    direction = 2;
                }
            }
            roll = rand() % 100;
            if (roll < chance)
            {
                for (int i = 0; i < nonEmptyWalls.size(); i++)
                {
                    if (index.x - 1 == nonEmptyWalls[i].x and index.y == nonEmptyWalls[i].y)
                    {
                        break;
                    }
                    if (i == nonEmptyWalls.size() - 1)
                    {
                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y - 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y - 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y - 1));

                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y));

                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y + 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y + 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y + 1));
                        walls[index.x - 1][index.y] = wall;
                        wallsToDraw.push_back(sf::Vector2i(index.x - 1, index.y));
                        createWallRow(direction, sf::Vector2i(index.x - 1, index.y), chance - 5, bx);
                    }
                }
            }
        }
        break;
    }
    case 2:
    {
        if (index.x != 1 and index.x != 18 and index.y != 1 and index.y != 18)
        {
            Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y + 1),
                hitbox.getSize().x,
                bx
            );
            int roll = rand() % 100;
            int direction;
            if (roll < 50)
            {
                direction = 2;
            }
            else
            {
                if (roll < 76)
                {
                    direction = 1;
                }
                else
                {
                    direction = 3;
                }
            }
            roll = rand() % 100;
            if (roll < chance)
            {
                for (int i = 0; i < nonEmptyWalls.size(); i++)
                {
                    if (index.x == nonEmptyWalls[i].x and index.y + 1 == nonEmptyWalls[i].y)
                    {
                        break;
                    }
                    if (i == nonEmptyWalls.size() - 1)
                    {
                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y - 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y - 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y - 1));

                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y));

                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y + 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y + 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y + 1));
                        walls[index.x][index.y + 1] = wall;
                        wallsToDraw.push_back(sf::Vector2i(index.x, index.y + 1));
                        createWallRow(direction, sf::Vector2i(index.x, index.y + 1), chance - 5, bx);
                    }
                }
            }
        }
        break;
    }
    case 3:
    {
        if (index.x != 1 and index.x != 18 and index.y != 1 and index.y != 18)
        {
            Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x + 1),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y),
                hitbox.getSize().x,
                bx
            );
            int roll = rand() % 100;
            int direction;
            if (roll < 50)
            {
                direction = 3;
            }
            else
            {
                if (roll < 76)
                {
                    direction = 0;
                }
                else
                {
                    direction = 2;
                }
            }
            roll = rand() % 100;
            if (roll < chance)
            {
                for (int i = 0; i < nonEmptyWalls.size(); i++)
                {
                    if (index.x + 1 == nonEmptyWalls[i].x and index.y == nonEmptyWalls[i].y)
                    {
                        break;
                    }
                    if (i == nonEmptyWalls.size() - 1)
                    {
                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y - 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y - 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y - 1));

                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y));

                        nonEmptyWalls.push_back(sf::Vector2i(index.x - 1, index.y + 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x, index.y + 1));
                        nonEmptyWalls.push_back(sf::Vector2i(index.x + 1, index.y + 1));
                        walls[index.x + 1][index.y] = wall;
                        wallsToDraw.push_back(sf::Vector2i(index.x + 1, index.y));
                        createWallRow(direction, sf::Vector2i(index.x + 1, index.y), chance - 5, bx);
                    }
                }
            }
        }
        break;
    }
    default:
        break;
    }
}

Wall Tile::getWallById(sf::Vector2i ind)
{
    return walls[ind.x][ind.y];
}

void Tile::delWallById(int id)
{
    walls[wallsToDraw[id].x][wallsToDraw[id].y].setWS(Empty);
    wallsToDraw.erase(wallsToDraw.begin() + id);
}

void Tile::dmgWall(sf::Vector2i ind, int dmg)
{
    walls[ind.x][ind.y].damaged(dmg);
}

bool Tile::tickTile(Player* player, Tile tile)
{
    if (type == TileType::LevelRegular)
    {
        if (!enemyBuffer.empty())
        {
            for (int i = 0; i < enemyBuffer.size(); i++)
            {
                //checking for bullets
                for (int j = 0; j < player->getRanged().getProjBuffer().size(); j++)
                {
                    for (int k = 1; k < 10; k++)
                    {
                        if (isProjEnemyHit(player->getRanged().getProjBuffer()[j], enemyBuffer[i], (player->getRanged().getSpeed() / 10) * k))
                        {
                            enemyBuffer[i].getDamage(player->getRanged().getDamage());
                            if (enemyBuffer[i].getHealth() <= 0)
                            {
                                enemyBuffer.erase(enemyBuffer.begin() + i);
                                if (enemyBuffer.empty())
                                {
                                    waveTimer.restart();
                                }
                            }
                            break; 
                        }
                    }
                }

                //patrol
                if (enemyBuffer[i].getBehav() == Regular)
                {
                    enemyBuffer[i].setColor(sf::Color::Green);
                    //if in dest
                    if (enemyBuffer[i].getPoints().empty())
                    {
                        //choose a new dest and point

                        //roll for new dest
                        int tries = 10;
                        while (tries > 0)
                        {
                            int x, y;
                            x = rand() % 18 + 1;
                            y = rand() % 18 + 1;

                            if (walls[x][y].getWS() != Walled)
                            {
                                enemyBuffer[i].setDest(sf::Vector2i(x, y));
                                enemyBuffer[i].addPoints(makePath(enemyBuffer[i]));
                                if (!enemyBuffer[i].getPoints().empty())
                                {
                                    tries = 0;
                                    break;
                                }
                            }
                            tries--;
                        }
                    }
                    else
                    {
                        if (abs(enemyBuffer[i].getPoints()[0].x - enemyBuffer[i].getInd().x + 0.5) < 0.1 and abs(enemyBuffer[i].getPoints()[0].y - enemyBuffer[i].getInd().y + 0.5) < 0.1)
                        {
                            enemyBuffer[i].delFrstPoint();
                        }
                        else
                        {
                            //move
                            sf::Vector2f course;
                            sf::Vector2f st;
                            sf::Vector2f fn;
                            st.x = enemyBuffer[i].getHitbox().getPosition().x;
                            st.y = enemyBuffer[i].getHitbox().getPosition().y;
                            fn.x = hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + ((hitbox.getSize().x / 20) * enemyBuffer[i].getPoints()[0].x);
                            fn.y = hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().y / 40 + ((hitbox.getSize().y / 20) * enemyBuffer[i].getPoints()[0].y);
                            enemyBuffer[i].move(sf::Vector2f(
                                250.f * (1.f/ 100.f) * ((fn.x-st.x)/(abs(fn.x - st.x)+abs(fn.y - st.y))),
                                250.f * (1.f/ 100.f) * ((fn.y-st.y)/(abs(fn.x - st.x)+abs(fn.y - st.y)))
                            ));
                            float indx, indy;
                            indx = (enemyBuffer[i].getHitbox().getPosition().x - (hitbox.getPosition().x - hitbox.getSize().x / 2)) / (hitbox.getSize().x / 20);
                            indy = (enemyBuffer[i].getHitbox().getPosition().y - (hitbox.getPosition().y - hitbox.getSize().y / 2)) / (hitbox.getSize().y / 20);

                            enemyBuffer[i].setInd(sf::Vector2f(indx, indy));

                            //enemyBuffer[i].setPos(sf::Vector2f(
                            //    ((enemyBuffer[i].getDest().x - enemyBuffer[i].getSprite().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getSprite().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getSprite().getPosition().y))),
                            //    ((enemyBuffer[i].getDest().y - enemyBuffer[i].getSprite().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getSprite().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getSprite().getPosition().y)))
                            //));
                        }
                    }
                }

                //has been alerted and checks the dest
                if (enemyBuffer[i].getBehav() == Check)
                {
                    enemyBuffer[i].setBehav(Regular);
                }

                //fighting
                if (enemyBuffer[i].getBehav() == Fight)
                {
                    enemyBuffer[i].setColor(sf::Color::Red);
                }
            }
        }
        else
        {
            if (tileStatus != Marked)
            {
                clear();
            }
        }
        if (tileStatus == Cleared)
        {
            tileStatus = Marked;
            return true;
        }
    }
    if (type == TileType::LevelQizz)
    {
        if (player->getIndex().x == index.x and player->getIndex().y == index.y and tileStatus != Marked)
        {
            clear();
        }
        if (tileStatus == Cleared)
        {
            tileStatus = Marked;
            return true;
        }
    }
    if (type == TileType::LevelEmpty)
    {
        if (player->getIndex().x == index.x and player->getIndex().y == index.y and tileStatus != Marked)
        {
            clear();
        }
        if (tileStatus == Cleared)
        {
            tileStatus = Marked;
            return true;
        }
    }
    if (type == TileType::LevelReward)
    {
        if (player->getIndex().x == index.x and player->getIndex().y == index.y and tileStatus != Marked)
        {
            clear();
        }
        if (tileStatus == Cleared)
        {
            tileStatus = Marked;
            return true;
        }
    }
    if (type == TileType::LevelStairs)
    {
        if (player->getIndex().x == index.x and player->getIndex().y == index.y and tileStatus != Marked)
        {
            clear();
        }
        if (tileStatus == Cleared)
        {
            tileStatus = Marked;
            return true;
        }
    }
    if (type == TileType::LevelTeleport)
    {
        if (player->getIndex().x == index.x and player->getIndex().y == index.y and tileStatus != Marked)
        {
            clear();
        }
        if (tileStatus == Cleared)
        {
            tileStatus = Marked;
            return true;
        }
    }
    if (type == TileType::Central)
    {
        if (player->getIndex().x == index.x and player->getIndex().y == index.y and tileStatus != Marked)
        {
            clear();
        }
        if (tileStatus == Cleared)
        {
            tileStatus = Marked;
            return true;
        }
    }
    if (type == TileType::CorridorH or type == TileType::CorridorV)
    {
        if (player->getIndex().x == index.x and player->getIndex().y == index.y and tileStatus != Marked)
        {
            clear();
        }
        if (tileStatus == Cleared)
        {
            tileStatus = Marked;
            return false;
        }
    }
    return false;
}

bool Tile::isEnemyWallHit(Enemy enemy, int speed)
{
    if (enemy.getHitbox().getPosition().y - enemy.getHitbox().getRadius() - (speed * 1 / 100.f) < hitbox.getPosition().y - hitbox.getSize().y / 2)
    {
        return true;
    }
    if (enemy.getHitbox().getPosition().x - enemy.getHitbox().getRadius() - (speed * 1 / 100.f) < hitbox.getPosition().x - hitbox.getSize().x / 2)
    {
        return true;
    }
    if (enemy.getHitbox().getPosition().y + enemy.getHitbox().getRadius() + (speed * 1 / 100.f) > hitbox.getPosition().y + hitbox.getSize().y / 2)
    {
        return true;
    }
    if (enemy.getHitbox().getPosition().x + enemy.getHitbox().getRadius() + (speed * 1 / 100.f) > hitbox.getPosition().x + hitbox.getSize().x / 2)
    {
        return true;
    }
    return false;
}

bool Tile::isEnemyEnemyHit(Enemy enemy, int speed)
{
    for (int i = 0; i < enemyBuffer.size(); i++)
    {
        if (enemyBuffer[i].getHitbox().getPosition() == enemy.getHitbox().getPosition())
            return false;
        else
        {
            if (enemy.getHitbox().getRadius() * 2 + (speed * 1 / 100.f) > sqrt(pow((enemyBuffer[i].getHitbox().getPosition().x - enemy.getHitbox().getPosition().x), 2) + pow((enemyBuffer[i].getHitbox().getPosition().y - enemy.getHitbox().getPosition().y), 2)))
            {
                return true;
            }
        }
    }
    return false;
}

bool Tile::isPlayerWeaponHit(Player* player, RangedWeapon weapon)
{
    if (weapon.getPickUpHitbox().getRadius() * 2 > sqrt(pow((player->getHitbox().getPosition().x - weapon.getPickUpHitbox().getPosition().x), 2) + pow((player->getHitbox().getPosition().y - weapon.getPickUpHitbox().getPosition().y), 2)))
    {
        return true;
    }
    return false;
}

bool Tile::isPlayerWeaponHit(Player* player, MeleeWeapon weapon)
{
    if (weapon.getPickUpHitbox().getRadius() * 2 > sqrt(pow((player->getHitbox().getPosition().x - weapon.getPickUpHitbox().getPosition().x), 2) + pow((player->getHitbox().getPosition().y - weapon.getPickUpHitbox().getPosition().y), 2)))
    {
        return true;
    }
    return false;
}

bool Tile::isProjEnemyHit(Projectile proj, Enemy enemy, int speed)
{
    if (enemy.getHitbox().getRadius() > sqrt(pow((enemy.getHitbox().getPosition().x - proj.getHitbox().getPosition().x + speed * (1/300.f) * proj.getDir().x), 2) + pow((enemy.getHitbox().getPosition().y - proj.getHitbox().getPosition().y + speed * (1 / 100.f) * proj.getDir().y), 2)))
    {
        return true;
    }
    return false;
}

void Tile::damageEnemy(int i, int dmg)
{
    enemyBuffer[i].getDamage(dmg);
    if (enemyBuffer[i].getHealth() <= 0)
    {
        enemyBuffer.erase(enemyBuffer.begin() + i);
        if (enemyBuffer.empty())
        {
            waveTimer.restart();
        }
    }
}

std::vector<sf::Vector2i> Tile::getWallsToDraw()
{
    return wallsToDraw;
}

bool Tile::isReachable(int startx, int starty, int finx, int finy, int len)
{
    if (startx == finx and starty == finy)
    {
        return true;
    }
    if (len > 40)
    {
        return false;
    }
    int rnd = rand() % 4;
    if (startx == 0 and rnd == 1)
    {
        rnd = 3;
    }
    if (startx == 19 and rnd == 3)
    {
        rnd = 1;
    }
    if (starty == 0 and rnd == 0)
    {
        rnd = 2;
    }
    if (starty == 19 and rnd == 2)
    {
        rnd = 0;
    }
    switch (rnd)
    {
    case 0: //up
    {
        if (walls[startx][starty-1].getWS() != Walled)
        {
            return isReachable(startx, starty-1, finx, finy, len + 1);
        }
        break;
    }
    case 1: //left
    {
        if (walls[startx-1][starty].getWS() != Walled)
        {
            return isReachable(startx-1, starty, finx, finy, len + 1);
        }
        break;
    }
    case 2: //down
    {
        if (walls[startx][starty+1].getWS() != Walled)
        {
            return isReachable(startx, starty+1, finx, finy, len + 1);
        }
        break;
    }
    case 3: //right
    {
        if (walls[startx+1][starty].getWS() != Walled)
        {
            return isReachable(startx+1, starty, finx, finy, len + 1);
        }
        break;
    }
    default:
        break;
    }
    return isReachable(startx, starty, finx, finy, len + 10);
}

void Tile::alert(int id, sf::Vector2i d)
{
    enemyBuffer[id].alert(d);
}

void Tile::move(sf::Vector2f delta)
{
    hitbox.move(delta);
    body.move(delta);
}

void Tile::setGreen()
{
    body.setFillColor(sf::Color::Green);
}

void Tile::setRed()
{
    body.setFillColor(sf::Color::Red);
}

void Tile::setYellow()
{
    body.setFillColor(sf::Color::Yellow);
}

std::vector<sf::Vector2i> Tile::makePath(Enemy en)
{
    std::vector<sf::Vector2i> result;
    std::vector<sf::Vector2i> buffer;
    enemyPath.clear();
    enemyPath.push_back(sf::Vector2i((en.getInd())));
    if (makePoints(sf::Vector2i(en.getInd()), en.getDest(), 0))
    {
        enemyPath.push_back(en.getDest());
        for (int i = 0; i < enemyPath.size() - 1; i++)
        {
            //result.push_back(enemyPath[i]);
            buffer = makeLine(enemyPath[i], enemyPath[i + 1]);
            for (int i = 0; i < buffer.size(); i++)
            {
                result.push_back(buffer[i]);
            }
        }
        result.push_back(enemyPath[enemyPath.size() - 1]);
    }
    else
    {
        result.clear();
    }
    return result;
}

std::vector<sf::Vector2i> Tile::makeLine(sf::Vector2i p1, sf::Vector2i p2)
{
    std::vector<sf::Vector2i> result;
    std::vector<sf::Vector2i> buffer;
    std::vector<sf::Vector2i> buffer2;
    result.clear();
    buffer.clear();
    buffer2.clear();
    //input is two point on same line
    //needed to make a path from one to another
    if (p1.x == p2.x and p1.y == p2.y)
    {
        return result;
    }
    else
    {
        result.push_back(p1);
        //vertical
        if (p1.x == p2.x)
        {
            //up
            if (p1.y > p2.y)
            {
                if (walls[p1.x][p1.y - 1].getWS() != Walled)
                {
                    buffer = makeLine(sf::Vector2i(p1.x,p1.y - 1), p2);
                    for (int i = 0; i < buffer.size(); i++)
                    {
                        result.push_back(buffer[i]);
                    }
                }
                else
                {
                    buffer = goAround(p1, p2, 0);
                    for (int i = 0; i < buffer.size(); i++)
                    {
                        result.push_back(buffer[i]);
                    }
                    buffer2 = makeLine(result[result.size() - 1], p2);
                    for (int i = 0; i < buffer2.size(); i++)
                    {
                        result.push_back(buffer2[i]);
                    }
                }
            }
            //down
            if (p1.y < p2.y)
            {
                if (walls[p1.x][p1.y + 1].getWS() != Walled)
                {
                    buffer = makeLine(sf::Vector2i(p1.x, p1.y + 1), p2);
                    for (int i = 0; i < buffer.size(); i++)
                    {
                        result.push_back(buffer[i]);
                    }
                }
                else
                {
                    buffer = goAround(p1, p2, 0);
                    for (int i = 0; i < buffer.size(); i++)
                    {
                        result.push_back(buffer[i]);
                    }
                    buffer2 = makeLine(result[result.size() - 1], p2);
                    for (int i = 0; i < buffer2.size(); i++)
                    {
                        result.push_back(buffer2[i]);
                    }
                }
            }
        }
        //horisontal

        if (p1.y == p2.y)
        {
            //left
            if (p1.x > p2.x)
            {
                if (walls[p1.x - 1][p1.y].getWS() != Walled)
                {
                    buffer = makeLine(sf::Vector2i(p1.x - 1, p1.y), p2);
                    for (int i = 0; i < buffer.size(); i++)
                    {
                        result.push_back(buffer[i]);
                    }
                }
                else
                {
                    buffer = goAround(p1, p2, 1);
                    for (int i = 0; i < buffer.size(); i++)
                    {
                        result.push_back(buffer[i]);
                    }
                    buffer2 = makeLine(result[result.size() - 1], p2);
                    for (int i = 0; i < buffer2.size(); i++)
                    {
                        result.push_back(buffer2[i]);
                    }
                }
            }
            //right
            if (p1.x < p2.x)
            {
                if (walls[p1.x + 1][p1.y].getWS() != Walled)
                {
                    buffer = makeLine(sf::Vector2i(p1.x + 1, p1.y), p2);
                    for (int i = 0; i < buffer.size(); i++)
                    {
                        result.push_back(buffer[i]);
                    }
                }
                else
                {
                    buffer = goAround(p1, p2, 1);
                    for (int i = 0; i < buffer.size(); i++)
                    {
                        result.push_back(buffer[i]);
                    }
                    buffer2 = makeLine(result[result.size() - 1], p2);
                    for (int i = 0; i < buffer2.size(); i++)
                    {
                        result.push_back(buffer2[i]);
                    }
                }
            }
        }
    }
    return result;
}

std::vector<sf::Vector2i> Tile::goAround(sf::Vector2i p1, sf::Vector2i p2, int dir)
{
    switch (dir)
    {
        //ver
    case 0:
    {
        std::vector<sf::Vector2i> left;
        std::vector<sf::Vector2i> right;
        left = pathFind(p1, p2, 1);
        right = pathFind(p1, p2, 3);
        if (left.size() < right.size())
        {
            return left;
        }
        else
        {
            return right;
        }
        break;
    }
    //hor
    case 1:
    {
        std::vector<sf::Vector2i> up;
        std::vector<sf::Vector2i> down;
        up = pathFind(p1, p2, 0);
        down = pathFind(p1, p2, 2);
        if (up.size() < down.size())
        {
            return up;
        }
        else
        {
            return down;
        }
        break;
    }
    default:
        break;
    }
}

std::vector<sf::Vector2i> Tile::pathFind(sf::Vector2i p1, sf::Vector2i p2, int dir)
{
    sf::Vector2i original;
    original.x = p1.x;
    original.y = p1.y;
    int len = 0;
    std::vector<sf::Vector2i> result;
    std::vector<sf::Vector2i> visited;
    switch (dir)
    {
        //up
    case 0:
    {
        bool moved = false;
        //go up
        visited.push_back(p1);
        p1.y = p1.y - 1;
        result.push_back(p1);
        len++;
        if (p1.x > p2.x)
        {
            while (len < 30)
            {
                moved = false;
                //check wall in order down left up right 

                //if down is clear
                if (p1.y < 19)
                {
                    if (walls[p1.x][p1.y + 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go down
                                visited.push_back(p1);
                                p1.y = p1.y + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if left is clear
                if (p1.x > 0)
                {
                    if (walls[p1.x - 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go left
                                visited.push_back(p1);
                                p1.x = p1.x - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if up is clear
                if (p1.y > 0)
                {
                    if (walls[p1.x][p1.y - 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go up
                                visited.push_back(p1);
                                p1.y = p1.y - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if right is clear
                if (p1.x < 19)
                {
                    if (walls[p1.x + 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go right
                                visited.push_back(p1);
                                p1.x = p1.x + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                len++;
                if (p1.y == p2.y)
                {
                    if (original.x > p2.x)
                    {
                        if (p1.x > original.x)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    else
                    {
                        if (p1.x < original.x)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            while (len < 30)
            {
                moved = false;
                //check wall in order down right up left 

                //if down is clear
                if (p1.y < 19)
                {
                    if (walls[p1.x][p1.y + 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go down
                                visited.push_back(p1);
                                p1.y = p1.y + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if right is clear
                if (p1.x < 19)
                {
                    if (walls[p1.x + 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go right
                                visited.push_back(p1);
                                p1.x = p1.x + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if up is clear
                if (p1.y > 0)
                {
                    if (walls[p1.x][p1.y - 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go up
                                visited.push_back(p1);
                                p1.y = p1.y - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if left is clear
                if (p1.x > 0)
                {
                    if (walls[p1.x - 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go left
                                visited.push_back(p1);
                                p1.x = p1.x - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                len++;
                if (p1.y == p2.y)
                {
                    if (original.x > p2.x)
                    {
                        if (p1.x > original.x)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    else
                    {
                        if (p1.x < original.x)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    break;
                }
            }
        }
        return result;
        break;
    }
    //left
    case 1:
    {
        bool moved = false;
        //go right
        visited.push_back(p1);
        p1.x = p1.x - 1;
        result.push_back(p1);
        len++;


        if (p1.y > p2.y)
        {
            while (len < 30)
            {
                moved = false;
                //check wall in order right up left down

                //if right is clear
                if (p1.x < 19)
                {
                    if (walls[p1.x + 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go right
                                visited.push_back(p1);
                                p1.x = p1.x + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if up is clear
                if (p1.y > 0)
                {
                    if (walls[p1.x][p1.y - 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go up
                                visited.push_back(p1);
                                p1.y = p1.y - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if left is clear
                if (p1.x > 0)
                {
                    if (walls[p1.x - 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go left
                                visited.push_back(p1);
                                p1.x = p1.x - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if down is clear
                if (p1.y < 19)
                {
                    if (walls[p1.x][p1.y + 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go down
                                visited.push_back(p1);
                                p1.y = p1.y + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }

                len++;
                if (p1.x == p2.x)
                {
                    if (original.y > p2.y)
                    {
                        if (p1.y > original.y)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    else
                    {
                        if (p1.y < original.y)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            while (len < 30)
            {
                moved = false;
                //check wall in order right down left up 

                //if right is clear
                if (p1.x < 19)
                {
                    if (walls[p1.x + 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go right
                                visited.push_back(p1);
                                p1.x = p1.x + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if down is clear
                if (p1.y < 19)
                {
                    if (walls[p1.x][p1.y + 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go down
                                visited.push_back(p1);
                                p1.y = p1.y + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if left is clear
                if (p1.x > 0)
                {
                    if (walls[p1.x - 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go left
                                visited.push_back(p1);
                                p1.x = p1.x - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if up is clear
                if (p1.y > 0)
                {
                    if (walls[p1.x][p1.y - 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go up
                                visited.push_back(p1);
                                p1.y = p1.y - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                len++;
                if (p1.x == p2.x)
                {
                    if (original.y > p2.y)
                    {
                        if (p1.y > original.y)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    else
                    {
                        if (p1.y < original.y)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    break;
                }
            }
        }
        return result;
        break;
    }
    //down
    case 2:
    {
        bool moved = false;
        //go down
        visited.push_back(p1);
        p1.y = p1.y + 1;
        result.push_back(p1);
        len++;
        if (p1.x > p2.x)
        {
            while (len < 30)
            {
                moved = false;
                //check wall in order up left down right 

                //if up is clear
                if (p1.y > 0)
                {
                    if (walls[p1.x][p1.y - 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go up
                                visited.push_back(p1);
                                p1.y = p1.y - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if left is clear
                if (p1.x > 0)
                {
                    if (walls[p1.x - 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go left
                                visited.push_back(p1);
                                p1.x = p1.x - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if down is clear
                if (p1.y < 19)
                {
                    if (walls[p1.x][p1.y + 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go down
                                visited.push_back(p1);
                                p1.y = p1.y + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if right is clear
                if (p1.x < 19)
                {
                    if (walls[p1.x + 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go right
                                visited.push_back(p1);
                                p1.x = p1.x + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                len++;
                if (p1.y == p2.y)
                {
                    if (original.x > p2.x)
                    {
                        if (p1.x > original.x)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    else
                    {
                        if (p1.x < original.x)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            while (len < 30)
            {
                moved = false;
                //check wall in order up right down left 

                //if up is clear
                if (p1.y > 0)
                {
                    if (walls[p1.x][p1.y - 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go up
                                visited.push_back(p1);
                                p1.y = p1.y - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if right is clear
                if (p1.x < 19)
                {
                    if (walls[p1.x + 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go right
                                visited.push_back(p1);
                                p1.x = p1.x + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if down is clear
                if (p1.y < 19)
                {
                    if (walls[p1.x][p1.y + 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go down
                                visited.push_back(p1);
                                p1.y = p1.y + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if left is clear
                if (p1.x > 0)
                {
                    if (walls[p1.x - 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go left
                                visited.push_back(p1);
                                p1.x = p1.x - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                len++;
                if (p1.y == p2.y)
                {
                    if (original.x > p2.x)
                    {
                        if (p1.x > original.x)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    else
                    {
                        if (p1.x < original.x)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    break;
                }
            }
        }
        return result;
        break;
    }
    //right
    case 3:
    {
        bool moved = false;
        //go left
        visited.push_back(p1);
        p1.x = p1.x - 1;
        result.push_back(p1);
        len++;

        if (p1.y > p2.y)
        {
            while (len < 30)
            {
                moved = false;
                //check wall in order left up right down 

                //if left is clear
                if (p1.x > 0)
                {
                    if (walls[p1.x - 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go left
                                visited.push_back(p1);
                                p1.x = p1.x - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if up is clear
                if (p1.y > 0)
                {
                    if (walls[p1.x][p1.y - 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go up
                                visited.push_back(p1);
                                p1.y = p1.y - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if right is clear
                if (p1.x < 19)
                {
                    if (walls[p1.x + 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go right
                                visited.push_back(p1);
                                p1.x = p1.x + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if down is clear
                if (p1.y < 19)
                {
                    if (walls[p1.x][p1.y + 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go down
                                visited.push_back(p1);
                                p1.y = p1.y + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }

                len++;
                if (p1.x == p2.x)
                {
                    if (original.y > p2.y)
                    {
                        if (p1.y > original.y)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    else
                    {
                        if (p1.y < original.y)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            while (len < 30)
            {
                moved = false;
                //check wall in order left down right up 

                //if left is clear
                if (p1.x > 0)
                {
                    if (walls[p1.x - 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go left
                                visited.push_back(p1);
                                p1.x = p1.x - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if down is clear
                if (p1.y < 19)
                {
                    if (walls[p1.x][p1.y + 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go down
                                visited.push_back(p1);
                                p1.y = p1.y + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if right is clear
                if (p1.x < 19)
                {
                    if (walls[p1.x + 1][p1.y].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go right
                                visited.push_back(p1);
                                p1.x = p1.x + 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                //if up is clear
                if (p1.y > 0)
                {
                    if (walls[p1.x][p1.y - 1].getWS() != Walled and !moved)
                    {
                        for (int i = 0; i < visited.size(); i++)
                        {
                            if (visited[i].x == p1.x and visited[i].y == p1.y)
                            {
                                break;
                            }
                            if (i == visited.size() - 1)
                            {
                                //go up
                                visited.push_back(p1);
                                p1.y = p1.y - 1;
                                result.push_back(p1);
                                moved = true;
                                break;
                            }
                        }
                    }
                }
                len++;
                if (p1.x == p2.x)
                {
                    if (original.y > p2.y)
                    {
                        if (p1.y > original.y)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    else
                    {
                        if (p1.y < original.y)
                        {
                            for (int i = 0; i < 100; i++)
                            {
                                result.push_back(p1);
                            }
                        }
                    }
                    break;
                }
            }
        }
        return result;
        break;
    }
    default:
        break;
    }
    visited.clear();
}

bool Tile::makePoints(sf::Vector2i p1, sf::Vector2i p2, int len)
{
    if (len > 100)
    {
        return false;
    }
    if (walls[p2.x][p1.y].getWS() != Walled)
    {
        enemyPath.push_back(sf::Vector2i(p2.x, p1.y));
    }
    else
    {
        if (walls[p1.x][p2.y].getWS() != Walled)
        {
            enemyPath.push_back(sf::Vector2i(p1.x, p2.y));
        }
        else
        {
            int x, y;
            if (p2.x > p1.x) //to right
            {
                int i = 1;
                while (i < 20)
                {
                    if (walls[p2.x - i][p1.y].getWS() != Walled)
                    {
                        enemyPath.push_back(sf::Vector2i(p2.x - i, p1.y));
                        x = p2.x - i;
                        break;
                    }
                    else
                    {
                        i++;
                    }
                }
                if (p2.y < p1.y) //up
                {
                    i = 1;
                    while (i < 20)
                    {
                        if (walls[p2.x][p1.y - i].getWS() != Walled)
                        {
                            y = p1.y - i;
                            break; 
                        }
                        else
                        {
                            i++;
                        }
                    }
                }
                if (p2.y > p1.y) //down
                {
                    i = 1;
                    while (i < 20)
                    {
                        if (walls[p2.x][p1.y + i].getWS() != Walled)
                        {
                            y = p1.y + i;
                            break;
                        }
                        else
                        {
                            i++;
                        }
                    }
                }
                sf::Vector2i p3(x, p1.y);
                sf::Vector2i p4(p2.x, y);
                sf::Vector2i p5(p2.x, y);
                makePoints(p3, p4, len + 1);
                p5.x = p2.x;
                p5.y = y;
                enemyPath.push_back(p5);
                return true;
            }
            if (p2.x < p1.x) //to left
            {
                int i = 1;
                while (i < 20)
                {
                    if (walls[p2.x + i][p1.y].getWS() != Walled)
                    {
                        enemyPath.push_back(sf::Vector2i(p2.x + i, p1.y));
                        x = p2.x + i;
                        break;
                    }
                    else
                    {
                        i++;
                    }
                }
                if (p2.y < p1.y) //up
                {
                    i = 1;
                    while (i < 20)
                    {
                        if (walls[p2.x][p1.y - i].getWS() != Walled)
                        {
                            y = p1.y - i;
                            break;
                        }
                        else
                        {
                            i++;
                        }
                    }
                }
                if (p2.y > p1.y) //down
                {
                    i = 1;
                    while (i < 20)
                    {
                        if (walls[p2.x][p1.y + i].getWS() != Walled)
                        {
                            y = p1.y + i;
                            break;
                        }
                        else
                        {
                            i++;
                        }
                    }
                }
                sf::Vector2i p3(x, p1.y);
                sf::Vector2i p4(p2.x, y);
                sf::Vector2i p5(p2.x, y);
                makePoints(p3, p4, len + 1);
                p5.x = p2.x;
                p5.y = y;
                enemyPath.push_back(p5);
                return true;
            }
        }
    }
    return true;
}
