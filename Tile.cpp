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
            body.setFillColor(sf::Color::White);
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            //RangedWeapon ranged(WeaponName::VP70, sf::Vector2f(pos_x, pos_y), side, textureHolder[2]);
            //rangedBuffer.push_back(ranged);
            //MeleeWeapon melee(Knife, sf::Vector2f(pos_x + side / 20, pos_y), side, textureHolder[0]);
            //meleeBuffer.push_back(melee);
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
    int x, y, count, created = 0;
    count = rand() % 10 + 1;
    while (created < count)
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

void Tile::spawnWalls(int up, int left, int down, int right)
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
                Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (x),
                    hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (y),
                    hitbox.getSize().x
                    );
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
            Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y - 1),
                hitbox.getSize().x
            );
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
                for (int i = 0; i < nonEmptyWalls.size(); i++)
                {
                    if (index.x == nonEmptyWalls[i].x and index.y - 1 == nonEmptyWalls[i].y)
                    {
                        break;
                    }
                    if (i == nonEmptyWalls.size() - 1)
                    {
                        createWallRow(direction, sf::Vector2i(index.x, index.y - 1), chance - 5);
                    }
                }
            }
        }
        break;
    }
    case 1:
    {
        if (index.x != 0 and index.x != 19 and index.y != 0 and index.y != 19)
        {
            Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x - 1),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y),
                hitbox.getSize().x
            );
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
                for (int i = 0; i < nonEmptyWalls.size(); i++)
                {
                    if (index.x - 1 == nonEmptyWalls[i].x and index.y == nonEmptyWalls[i].y)
                    {
                        break;
                    }
                    if (i == nonEmptyWalls.size() - 1)
                    {
                        createWallRow(direction, sf::Vector2i(index.x - 1, index.y), chance - 5);
                    }
                }
            }
        }
        break;
    }
    case 2:
    {
        if (index.x != 0 and index.x != 19 and index.y != 0 and index.y != 19)
        {
            Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y + 1),
                hitbox.getSize().x
            );
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
                for (int i = 0; i < nonEmptyWalls.size(); i++)
                {
                    if (index.x == nonEmptyWalls[i].x and index.y + 1 == nonEmptyWalls[i].y)
                    {
                        break;
                    }
                    if (i == nonEmptyWalls.size() - 1)
                    {
                        createWallRow(direction, sf::Vector2i(index.x, index.y + 1), chance - 5);
                    }
                }
            }
        }
        break;
    }
    case 3:
    {
        if (index.x != 0 and index.x != 19 and index.y != 0 and index.y != 19)
        {
            Wall wall(hitbox.getPosition().x - hitbox.getSize().x / 2 + hitbox.getSize().x / 40 + hitbox.getSize().x / 20 * (index.x + 1),
                hitbox.getPosition().y - hitbox.getSize().y / 2 + hitbox.getSize().x / 40 + hitbox.getSize().y / 20 * (index.y),
                hitbox.getSize().x
            );
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
                for (int i = 0; i < nonEmptyWalls.size(); i++)
                {
                    if (index.x + 1 == nonEmptyWalls[i].x and index.y == nonEmptyWalls[i].y)
                    {
                        break;
                    }
                    if (i == nonEmptyWalls.size() - 1)
                    {
                        createWallRow(direction, sf::Vector2i(index.x + 1, index.y), chance - 5);
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

                //patrol
                if (enemyBuffer[i].getBehav() == Regular)
                {
                    //if in dest
                    if (enemyBuffer[i].getInd() == enemyBuffer[i].getPoint() and enemyBuffer[i].getPoint() == enemyBuffer[i].getDest())
                    {
                        //choose a new dest and point

                        //roll for new dest
                        while (true)
                        {
                            int x, y;
                            x = rand() % 18 + 1;
                            y = rand() % 18 + 1;

                            if (walls[x][y].getWS() != Walled)
                            {
                                if (walls[x - 1][y].getWS() != Walled and walls[x + 1][y].getWS() != Walled and walls[x][y - 1].getWS() != Walled and walls[x][y + 1].getWS() != Walled)
                                {
                                    if (isReachable(enemyBuffer[i].getInd().x, enemyBuffer[i].getInd().y, x, y, 0))
                                    {
                                        enemyBuffer[i].setDest(sf::Vector2i(x, y)); 
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        //if in point
                        if (enemyBuffer[i].getInd() == enemyBuffer[i].getPoint())
                        {
                            //choose new point
                            int* distance = new int[4];
                            for (int j = 0; j < 4; j++)
                            {
                                distance[j] = 100;
                            }
                            if (enemyBuffer[i].getInd().y - 1 > -1)
                            {
                                if (walls[enemyBuffer[i].getInd().x][enemyBuffer[i].getInd().y - 1].getWS() != Walled)
                                {
                                    distance[0] = sqrt(pow((enemyBuffer[i].getInd().x - enemyBuffer[i].getDest().x), 2) + pow((enemyBuffer[i].getInd().y - 1 - enemyBuffer[i].getDest().y), 2));
                                }
                            }
                            if (enemyBuffer[i].getInd().x - 1 > -1)
                            {
                                if (walls[enemyBuffer[i].getInd().x - 1][enemyBuffer[i].getInd().y].getWS() != Walled)
                                {
                                    distance[1] = sqrt(pow((enemyBuffer[i].getInd().x - 1 - enemyBuffer[i].getDest().x), 2) + pow((enemyBuffer[i].getInd().y - enemyBuffer[i].getDest().y), 2));
                                }
                            }
                            if (enemyBuffer[i].getInd().y + 1 < 20)
                            {
                                if (walls[enemyBuffer[i].getInd().x][enemyBuffer[i].getInd().y + 1].getWS() != Walled)
                                {
                                    distance[2] = sqrt(pow((enemyBuffer[i].getInd().x - enemyBuffer[i].getDest().x), 2) + pow((enemyBuffer[i].getInd().y + 1 - enemyBuffer[i].getDest().y), 2));
                                }
                            }
                            if (enemyBuffer[i].getInd().x + 1 < 20)
                            {
                                if (walls[enemyBuffer[i].getInd().x + 1][enemyBuffer[i].getInd().y].getWS() != Walled)
                                {
                                    distance[3] = sqrt(pow((enemyBuffer[i].getInd().x + 1 - enemyBuffer[i].getDest().x), 2) + pow((enemyBuffer[i].getInd().y - enemyBuffer[i].getDest().y), 2));
                                }
                            }
                            if (distance[0] == distance[1]) //up left
                            {
                                if (walls[enemyBuffer[i].getInd().x - 1][enemyBuffer[i].getInd().y - 1].getWS() != Walled)
                                {
                                    //set point
                                    enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x - 1, enemyBuffer[i].getInd().y - 1));
                                }
                                else
                                {
                                    int rnd = rand() % 2;
                                    if (rnd == 0)
                                    {
                                        //set first
                                        enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x, enemyBuffer[i].getInd().y - 1));
                                    }
                                    else
                                    {
                                        //set last
                                        enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x - 1, enemyBuffer[i].getInd().y));
                                    }
                                }
                            }
                            if (distance[2] == distance[1]) //down left
                            {
                                if (walls[enemyBuffer[i].getInd().x - 1][enemyBuffer[i].getInd().y + 1].getWS() != Walled)
                                {
                                    enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x - 1, enemyBuffer[i].getInd().y + 1));
                                }
                                else
                                {
                                    int rnd = rand() % 2;
                                    if (rnd == 0)
                                    {
                                        //set first
                                        enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x, enemyBuffer[i].getInd().y + 1));
                                    }
                                    else
                                    {
                                        //set last
                                        enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x - 1, enemyBuffer[i].getInd().y));
                                    }
                                }
                            }
                            if (distance[2] == distance[3]) //down right
                            {
                                if (walls[enemyBuffer[i].getInd().x - 1][enemyBuffer[i].getInd().y + 1].getWS() != Walled)
                                {
                                    enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x + 1, enemyBuffer[i].getInd().y + 1));
                                }
                                else
                                {
                                    int rnd = rand() % 2;
                                    if (rnd == 0)
                                    {
                                        //set first
                                        enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x, enemyBuffer[i].getInd().y + 1));
                                    }
                                    else
                                    {
                                        //set last
                                        enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x + 1, enemyBuffer[i].getInd().y));
                                    }
                                }
                            }
                            if (distance[0] == distance[3]) //up right
                            {
                                if (walls[enemyBuffer[i].getInd().x + 1][enemyBuffer[i].getInd().y - 1].getWS() != Walled)
                                {
                                    enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x + 1, enemyBuffer[i].getInd().y - 1));
                                }
                                else
                                {
                                    int rnd = rand() % 2;
                                    if (rnd == 0)
                                    {
                                        //set first
                                        enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x, enemyBuffer[i].getInd().y - 1));
                                    }
                                    else
                                    {
                                        //set last
                                        enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x + 1, enemyBuffer[i].getInd().y));
                                    }
                                }
                            }
                            if (distance[0] < distance[1] and distance[0] < distance[2] and distance[0] < distance[3])
                            {
                                enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x, enemyBuffer[i].getInd().y - 1));
                            }
                            if (distance[1] < distance[0] and distance[1] < distance[2] and distance[1] < distance[3])
                            {
                                enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x - 1, enemyBuffer[i].getInd().y));
                            }
                            if (distance[2] < distance[1] and distance[2] < distance[0] and distance[2] < distance[3])
                            {
                                enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x, enemyBuffer[i].getInd().y + 1));
                            }
                            if (distance[3] < distance[1] and distance[3] < distance[2] and distance[3] < distance[0])
                            {
                                enemyBuffer[i].setPoint(sf::Vector2i(enemyBuffer[i].getInd().x + 1, enemyBuffer[i].getInd().y));
                            }
                        }
                        else
                        {
                            //moving to point

                            //check hitboxes and distance to point, then move and update index


                        }
                    }
                }

                //has been alerted and checks the dest
                if (enemyBuffer[i].getBehav() == Check)
                {
                    //if in dest
                    if (enemyBuffer[i].getInd() == enemyBuffer[i].getPoint() and enemyBuffer[i].getPoint() == enemyBuffer[i].getDest())
                    {
                        //choose a new dest and point
                    }
                    else
                    {
                        //if in point
                        if (true)
                        {
                            //choose new point
                        }
                        else
                        {
                            //moving to point
                        }
                    }
                }

                //fighting
                if (enemyBuffer[i].getBehav() == Fight)
                {

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
    return isReachable(startx, starty, finx, finy, len + 1);
}
