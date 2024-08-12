#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(TileType tileType, int pos_x, int pos_y, int index_x, int index_y, int side, float diff, std::vector<sf::Texture*> textureHolder)
{
    int tileSize = side;
    switch (tileType)
    {
        case TileType::LevelRegular:
        {
            body.setFillColor(sf::Color::White);
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            //spawnEnemies(diff, side, pos_x, pos_y);
            goal = LevelGoal::Death;
            type = tileType;
            break;
        }
        case TileType::LevelQizz:
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
            body.setFillColor(sf::Color::Yellow);
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            spawnReward(diff);
            goal = LevelGoal::Reward;
            type = tileType;
            break;
        }
        case TileType::LevelEmpty:
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
        case TileType::LevelStairs:
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
        case TileType::LevelTeleport:
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
            body.setFillColor(sf::Color::White);
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            RangedWeapon ranged(WeaponName::VP70, sf::Vector2f(pos_x, pos_y), side, textureHolder[2]);
            rangedBuffer.push_back(ranged);
            MeleeWeapon melee(Knife, sf::Vector2f(pos_x + side / 20, pos_y), side, textureHolder[0]);
            meleeBuffer.push_back(melee);
            break;
        }
        case TileType::CorridorV:
        {
            body.setFillColor(sf::Color::White);
            body.setSize(sf::Vector2f(tileSize / 3, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 6, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize / 3 - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize / 3 - 2) / 2, (tileSize - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            break;
        }
        case TileType::CorridorH:
        {
            body.setFillColor(sf::Color::White);
            body.setSize(sf::Vector2f(tileSize, tileSize / 3));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 6));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize / 3 - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize / 3 - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
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

sf::Vector2i Tile::getIndex()
{
    return index;
}

void Tile::clear()
{
    tileStatus = TileStatus::Cleared;
    body.setFillColor(sf::Color(100,100,100));
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
    int x, y, count;
    count = rand() % int(diff * 1000) + 1;
    //count = 21;
    if (count > 20)
    {
        remainingSpawns = count - 20;
        count = 20;
    }
    else
    {
        remainingSpawns = -1;
    }
    for (int i = 0; i < count; i++)
    {
        x = rand() % int(hitbox.getSize().x - hitbox.getSize().x / 5) + int(hitbox.getSize().x / 10);
        y = rand() % int(hitbox.getSize().x - hitbox.getSize().x / 5) + int(hitbox.getSize().x / 10);
        Enemy enemy(x + pos_x - hitbox.getSize().x / 2, y + pos_y - hitbox.getSize().x / 2, side);
        enemyBuffer.push_back(enemy);
    }
}

void Tile::spawnEnemiesWave(int side)
{
    if (waveTimer.getElapsedTime() > sf::seconds(2))
    {
        int x, y, count;
        count = remainingSpawns;
        if (count > 20)
        {
            remainingSpawns -= 20;
            count = 20;
        }
        else
        {
            remainingSpawns = -1;
        }
        for (int i = 0; i < count; i++)
        {
            x = rand() % int(hitbox.getSize().x - hitbox.getSize().x / 5) + int(hitbox.getSize().x / 10);
            y = rand() % int(hitbox.getSize().x - hitbox.getSize().x / 5) + int(hitbox.getSize().x / 10);
            Enemy enemy(x + hitbox.getPosition().x - hitbox.getSize().x / 2, y + hitbox.getPosition().y - hitbox.getSize().x / 2, side);
            enemyBuffer.push_back(enemy);
        }
    }
}

void Tile::spawnChallenge(float diff)
{
}

void Tile::spawnReward(float diff)
{
}

void Tile::spawnWalls(int up, int left, int down, int right)
{
    walls = new sf::RectangleShape*[20];
    for (int i = 0; i < 20; i++)
    {
        walls[i] = new sf::RectangleShape[20];
    }
    if (up == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 7; j < 13; j++)
            {
                nonEmptyWalls.push_back(sf::Vector2i(i, j));
            }
        }
    }
    if (left == 1)
    {
        for (int i = 7; i < 13; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                nonEmptyWalls.push_back(sf::Vector2i(i, j));
            }
        }
    }
    if (down == 1)
    {
        for (int i = 16; i < 20; i++)
        {
            for (int j = 7; j < 13; j++)
            {
                nonEmptyWalls.push_back(sf::Vector2i(i, j));
            }
        }
    }
    if (right == 1)
    {
        for (int i = 7; i < 13; i++)
        {
            for (int j = 16; j < 20; j++)
            {
                nonEmptyWalls.push_back(sf::Vector2i(i, j));
            }
        }
    }
    int wallPoints = rand() % 16 + 8;
    int created = 0;
    while (created < wallPoints)
    {
        int x = rand() % 20;
        int y = rand() % 20;
        for (int i = 0; i < nonEmptyWalls.size(); i++)
        {
            if (x == nonEmptyWalls[i].x and y == nonEmptyWalls[i].y)
            {
                break;
            }
            if (i == nonEmptyWalls.size() - 1)
            {
                created++;
                sf::RectangleShape wall;
                wall.setSize(sf::Vector2f(hitbox.getSize().x / 20, hitbox.getSize().x / 20));
                wall.setOrigin(sf::Vector2f(hitbox.getSize().x / 40, hitbox.getSize().x / 40));
                wall.setFillColor(sf::Color(200, 100, 100));
                wall.setOutlineColor(sf::Color::Red);
                wall.setOutlineThickness(1.f);
                wall.setPosition(sf::Vector2f(
                    hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (x),
                    hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (y)
                ));
                walls[x][y] = wall;
                wallsToDraw.push_back(sf::Vector2i(x, y));
                createWallRow(rand() % 4, sf::Vector2i(x, y), 100);
            }
        }
    }

}

void Tile::createWallRow(int dir, sf::Vector2i index, int chance)
{
    switch (dir)
    {
    case 0:
    {
        if (index.x != 0 and index.x != 19 and index.y != 0 and index.y != 19)
        {
            sf::RectangleShape wall;
            wall.setSize(sf::Vector2f(hitbox.getSize().x / 20, hitbox.getSize().x / 20));
            wall.setOrigin(sf::Vector2f(hitbox.getSize().x / 40, hitbox.getSize().x / 40));
            wall.setFillColor(sf::Color(200, 100, 100));
            wall.setOutlineColor(sf::Color::Red);
            wall.setOutlineThickness(1.f);
            wall.setPosition(sf::Vector2f(
                hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y - 1)
            ));
            walls[index.x][index.y - 1] = wall;
            wallsToDraw.push_back(sf::Vector2i(index.x, index.y - 1));
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
                createWallRow(direction, sf::Vector2i(index.x, index.y - 1), chance - 5);
            }
        }
        break;
    }
    case 1:
    {
        if (index.x != 0 and index.x != 19 and index.y != 0 and index.y != 19)
        {
            sf::RectangleShape wall;
            wall.setSize(sf::Vector2f(hitbox.getSize().x / 20, hitbox.getSize().x / 20));
            wall.setOrigin(sf::Vector2f(hitbox.getSize().x / 40, hitbox.getSize().x / 40));
            wall.setFillColor(sf::Color(200, 100, 100));
            wall.setOutlineColor(sf::Color::Red);
            wall.setOutlineThickness(1.f);
            wall.setPosition(sf::Vector2f(
                hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x - 1),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y)
            ));
            walls[index.x - 1][index.y] = wall;
            wallsToDraw.push_back(sf::Vector2i(index.x - 1, index.y));
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
                createWallRow(direction, sf::Vector2i(index.x - 1, index.y), chance - 5);
            }
        }
        break;
    }
    case 2:
    {
        if (index.x != 0 and index.x != 19 and index.y != 0 and index.y != 19)
        {
            sf::RectangleShape wall;
            wall.setSize(sf::Vector2f(hitbox.getSize().x / 20, hitbox.getSize().x / 20));
            wall.setOrigin(sf::Vector2f(hitbox.getSize().x / 40, hitbox.getSize().x / 40));
            wall.setFillColor(sf::Color(200, 100, 100));
            wall.setOutlineColor(sf::Color::Red);
            wall.setOutlineThickness(1.f);
            wall.setPosition(sf::Vector2f(
                hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y + 1)
            ));
            walls[index.x][index.y + 1] = wall;
            wallsToDraw.push_back(sf::Vector2i(index.x, index.y + 1));
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
                createWallRow(direction, sf::Vector2i(index.x, index.y + 1), chance - 5);
            }
        }
        break;
    }
    case 3:
    {
        if (index.x != 0 and index.x != 19 and index.y != 0 and index.y != 19)
        {
            sf::RectangleShape wall;
            wall.setSize(sf::Vector2f(hitbox.getSize().x / 20, hitbox.getSize().x / 20));
            wall.setOrigin(sf::Vector2f(hitbox.getSize().x / 40, hitbox.getSize().x / 40));
            wall.setFillColor(sf::Color(200, 100, 100));
            wall.setOutlineColor(sf::Color::Red);
            wall.setOutlineThickness(1.f);
            wall.setPosition(sf::Vector2f(
                hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x + 1),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y)
            ));
            walls[index.x + 1][index.y] = wall;
            wallsToDraw.push_back(sf::Vector2i(index.x + 1, index.y));
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
                createWallRow(direction, sf::Vector2i(index.x + 1, index.y), chance - 5);
            }
        }
        break;
    }
    default:
        break;
    }
}

sf::RectangleShape Tile::getWallById(sf::Vector2i ind)
{
    return walls[ind.x][ind.y];
}

bool Tile::tickTile(Player* player, Tile tile)
{
    if (type == TileType::LevelRegular)
    {
        if (!enemyBuffer.empty())
        {
            for (int i = 0; i < enemyBuffer.size(); i++)
            {
                //if (enemyBuffer[i].getBehav() == EnemyBehavior::Stand)
                //{
                //    if (index.x == player->getIndex().x and index.y == player->getIndex().y)
                //    {
                //        int buf = rand() % 100;
                //        if (buf > enemyBuffer[i].getHealth())
                //        {
                //            enemyBuffer[i].setBehav(EnemyBehavior::Backing);
                //        }
                //        else
                //        {
                //            enemyBuffer[i].setBehav(EnemyBehavior::Attacking);
                //        }
                //    }
                //}
                //else
                //{
                //    if (enemyBuffer[i].getBehav() == EnemyBehavior::Backing)
                //    {
                //        if (enemyBuffer[i].getState() == EnemyState::Standing)
                //        {
                //            enemyBuffer[i].setState(EnemyState::Moving);
                //            int x, y;
                //            if (player->getHitbox().getPosition().x > enemyBuffer[i].getHitbox().getPosition().x)
                //                x = rand() % int(hitbox.getSize().x / 3 + hitbox.getSize().x / 6) - hitbox.getSize().x / 6;
                //            else
                //                x = rand() % int(hitbox.getSize().x / 3) + hitbox.getSize().x / 6;
                //            if (player->getHitbox().getPosition().y > enemyBuffer[i].getHitbox().getPosition().y)
                //                y = rand() % int(hitbox.getSize().x / 3 + hitbox.getSize().x / 6) - hitbox.getSize().x / 6;
                //            else
                //                y = rand() % int(hitbox.getSize().x / 3) + hitbox.getSize().x / 6;
                //            enemyBuffer[i].setDest(sf::Vector2f(enemyBuffer[i].getHitbox().getPosition().x + x, enemyBuffer[i].getHitbox().getPosition().y + y));
                //        }
                //        else
                //        {
                //            if (enemyBuffer[i].getState() == EnemyState::Moving)
                //            {
                //                int x, y;
                //                x = abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x);
                //                y = abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y);
                //                if (x > enemyBuffer[i].getHitbox().getRadius() and y > enemyBuffer[i].getHitbox().getRadius())
                //                {
                //                    //check collision and move
                //                    for (int j = 1; j < 10; j++)
                //                    {
                //                        if (!isEnemyWallHit(enemyBuffer[i], 100 / j))
                //                        {
                //                            if (!isEnemyEnemyHit(enemyBuffer[i], 100 / j))
                //                            {
                //                                enemyBuffer[i].move(sf::Vector2f(
                //                                    ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (250 / j) * (1 / 100.f),
                //                                    ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (250 / j) * (1 / 100.f)
                //                                ));
                //                                break;
                //                            }
                //                        }
                //                        if (j == 9)
                //                        {
                //                            enemyBuffer[i].setState(EnemyState::Standing);
                //                            enemyBuffer[i].setBehav(EnemyBehavior::Stand);
                //                        }
                //                    }
                //                    if (isEnemyEnemyHit(enemyBuffer[i], (450 / 10)))
                //                    {
                //                        enemyBuffer[i].move(sf::Vector2f(
                //                            ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / 10) * (1 / 100.f),
                //                            ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / 10) * (1 / 100.f)
                //                        ));
                //                    }
                //                }
                //                else
                //                {
                //                    enemyBuffer[i].setState(EnemyState::Standing);
                //                    enemyBuffer[i].setBehav(EnemyBehavior::Stand);
                //                }
                //            }
                //        }
                //    }
                //    else
                //    {
                //        if (enemyBuffer[i].getBehav() == EnemyBehavior::Attacking)
                //        {
                //            if (enemyBuffer[i].getState() == EnemyState::Standing)
                //            {
                //                enemyBuffer[i].setState(EnemyState::Moving);
                //                int x, y;
                //                x = player->getHitbox().getPosition().x;
                //                y = player->getHitbox().getPosition().y;
                //                x = x + (rand() % int(enemyBuffer[i].getHitbox().getRadius()) - enemyBuffer[i].getHitbox().getRadius() / 2);
                //                y = y + (rand() % int(enemyBuffer[i].getHitbox().getRadius()) - enemyBuffer[i].getHitbox().getRadius() / 2);
                //                enemyBuffer[i].setDest(sf::Vector2f(x, y));
                //                enemyBuffer[i].move(sf::Vector2f(
                //                    ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (100) * (1 / 100.f),
                //                    ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (100) * (1 / 100.f)
                //                ));
                //            }
                //            else
                //            {
                //                if (enemyBuffer[i].getState() == EnemyState::Moving)
                //                {
                //                    int x, y;
                //                    x = player->getHitbox().getPosition().x;
                //                    y = player->getHitbox().getPosition().y;
                //                    x = x + (rand() % int(enemyBuffer[i].getHitbox().getRadius()) - enemyBuffer[i].getHitbox().getRadius() / 2);
                //                    y = y + (rand() % int(enemyBuffer[i].getHitbox().getRadius()) - enemyBuffer[i].getHitbox().getRadius() / 2);
                //                    enemyBuffer[i].setDest(sf::Vector2f(x, y));
                //                    x = abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x);
                //                    y = abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y);
                //                    if (x > enemyBuffer[i].getHitbox().getRadius() and y > enemyBuffer[i].getHitbox().getRadius())
                //                    {
                //                        for (int j = 1; j < 10; j++)
                //                        {
                //                            if (!isEnemyWallHit(enemyBuffer[i], 100 / j))
                //                            {
                //                                if (!isEnemyEnemyHit(enemyBuffer[i], 100 / j))
                //                                {
                //                                    enemyBuffer[i].move(sf::Vector2f(
                //                                        ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / j) * (1 / 100.f),
                //                                        ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / j) * (1 / 100.f)
                //                                    ));
                //                                    break;
                //                                }
                //                            }
                //                            if (j == 9)
                //                            {
                //                                enemyBuffer[i].setState(EnemyState::Standing);
                //                                enemyBuffer[i].setBehav(EnemyBehavior::Stand);
                //                            }
                //                        }
                //                        if (isEnemyEnemyHit(enemyBuffer[i], (450 / 10)))
                //                        {
                //                            enemyBuffer[i].move(sf::Vector2f(
                //                                ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / 10)* (1 / 100.f),
                //                                ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / 10)* (1 / 100.f)
                //                            ));
                //                        }
                //                    }
                //                    else
                //                    {
                //                        enemyBuffer[i].setState(EnemyState::Standing);
                //                        enemyBuffer[i].setBehav(EnemyBehavior::Backing);
                //                    }
                //                }
                //            }
                //        }
                //    }
                //}
                //check player hitboxes for attack and recieve damage and check for death

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
                

                //attack if has ammo and weapon (check for ranged weapon and ammo, else atk by melee)
            }
        }
        else
        {
            if (remainingSpawns > 0)
            {
                spawnEnemiesWave(tile.getHitbox().getSize().x);
            }
            else
            {
                if (tileStatus != Marked)
                {
                    clear();
                }
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
