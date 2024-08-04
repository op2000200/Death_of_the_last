#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(TileType tileType, int pos_x, int pos_y, int index_x, int index_y, int side, float diff)
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
            spawnEnemies(diff, side, pos_x, pos_y);
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
            body.setFillColor(sf::Color::Black);
            body.setSize(sf::Vector2f(tileSize, tileSize));
            body.setOrigin(sf::Vector2f(tileSize / 2, tileSize / 2));
            hitbox.setSize(sf::Vector2f(tileSize - 2, tileSize - 2));
            hitbox.setOrigin(sf::Vector2f((tileSize - 2) / 2, (tileSize - 2) / 2));
            goal = LevelGoal::No;
            type = tileType;
            RangedWeapon ranged(WeaponName::VP70, sf::Vector2f(pos_x, pos_y), side);
            rangedBuffer.push_back(ranged);
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

std::vector<Enemy> Tile::getEnemyBuffer()
{
    return enemyBuffer;
}

std::vector<RangedWeapon> Tile::getRangedBuffer()
{
    return rangedBuffer;
}

void Tile::delRangedBufferElem(int i)
{
    rangedBuffer.erase(rangedBuffer.begin() + i);
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

void Tile::tickTile(Player* player, Tile tile)
{
    if (goal == LevelGoal::No)
    {

    }
    if (type == TileType::LevelRegular)
    {
        if (!enemyBuffer.empty())
        {
            for (int i = 0; i < enemyBuffer.size(); i++)
            {
                if (enemyBuffer[i].getBehav() == EnemyBehavior::Stand)
                {
                    if (index.x == player->getIndex().x and index.y == player->getIndex().y)
                    {
                        int buf = rand() % 100;
                        if (buf > enemyBuffer[i].getHealth())
                        {
                            enemyBuffer[i].setBehav(EnemyBehavior::Backing);
                        }
                        else
                        {
                            enemyBuffer[i].setBehav(EnemyBehavior::Attacking);
                        }
                    }
                }
                else
                {
                    if (enemyBuffer[i].getBehav() == EnemyBehavior::Backing)
                    {
                        if (enemyBuffer[i].getState() == EnemyState::Standing)
                        {
                            enemyBuffer[i].setState(EnemyState::Moving);
                            int x, y;
                            if (player->getHitbox().getPosition().x > enemyBuffer[i].getHitbox().getPosition().x)
                                x = rand() % int(hitbox.getSize().x / 3 + hitbox.getSize().x / 6) - hitbox.getSize().x / 6;
                            else
                                x = rand() % int(hitbox.getSize().x / 3) + hitbox.getSize().x / 6;
                            if (player->getHitbox().getPosition().y > enemyBuffer[i].getHitbox().getPosition().y)
                                y = rand() % int(hitbox.getSize().x / 3 + hitbox.getSize().x / 6) - hitbox.getSize().x / 6;
                            else
                                y = rand() % int(hitbox.getSize().x / 3) + hitbox.getSize().x / 6;
                            enemyBuffer[i].setDest(sf::Vector2f(enemyBuffer[i].getHitbox().getPosition().x + x, enemyBuffer[i].getHitbox().getPosition().y + y));
                        }
                        else
                        {
                            if (enemyBuffer[i].getState() == EnemyState::Moving)
                            {
                                int x, y;
                                x = abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x);
                                y = abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y);
                                if (x > enemyBuffer[i].getHitbox().getRadius() and y > enemyBuffer[i].getHitbox().getRadius())
                                {
                                    //check collision and move
                                    for (int j = 1; j < 10; j++)
                                    {
                                        if (!isEnemyWallHit(enemyBuffer[i], 100 / j))
                                        {
                                            if (!isEnemyEnemyHit(enemyBuffer[i], 100 / j))
                                            {
                                                enemyBuffer[i].move(sf::Vector2f(
                                                    ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (250 / j) * (1 / 60.f),
                                                    ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (250 / j) * (1 / 60.f)
                                                ));
                                                break;
                                            }
                                        }
                                        if (j == 9)
                                        {
                                            enemyBuffer[i].setState(EnemyState::Standing);
                                            enemyBuffer[i].setBehav(EnemyBehavior::Stand);
                                        }
                                    }
                                    if (isEnemyEnemyHit(enemyBuffer[i], (450 / 10)))
                                    {
                                        enemyBuffer[i].move(sf::Vector2f(
                                            ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / 10) * (1 / 60.f),
                                            ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / 10) * (1 / 60.f)
                                        ));
                                    }
                                }
                                else
                                {
                                    enemyBuffer[i].setState(EnemyState::Standing);
                                    enemyBuffer[i].setBehav(EnemyBehavior::Stand);
                                }
                            }
                        }
                    }
                    else
                    {
                        if (enemyBuffer[i].getBehav() == EnemyBehavior::Attacking)
                        {
                            if (enemyBuffer[i].getState() == EnemyState::Standing)
                            {
                                enemyBuffer[i].setState(EnemyState::Moving);
                                int x, y;
                                x = player->getHitbox().getPosition().x;
                                y = player->getHitbox().getPosition().y;
                                x = x + (rand() % int(enemyBuffer[i].getHitbox().getRadius()) - enemyBuffer[i].getHitbox().getRadius() / 2);
                                y = y + (rand() % int(enemyBuffer[i].getHitbox().getRadius()) - enemyBuffer[i].getHitbox().getRadius() / 2);
                                enemyBuffer[i].setDest(sf::Vector2f(x, y));
                                enemyBuffer[i].move(sf::Vector2f(
                                    ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (100) * (1 / 60.f),
                                    ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (100) * (1 / 60.f)
                                ));
                            }
                            else
                            {
                                if (enemyBuffer[i].getState() == EnemyState::Moving)
                                {
                                    int x, y;
                                    x = player->getHitbox().getPosition().x;
                                    y = player->getHitbox().getPosition().y;
                                    x = x + (rand() % int(enemyBuffer[i].getHitbox().getRadius()) - enemyBuffer[i].getHitbox().getRadius() / 2);
                                    y = y + (rand() % int(enemyBuffer[i].getHitbox().getRadius()) - enemyBuffer[i].getHitbox().getRadius() / 2);
                                    enemyBuffer[i].setDest(sf::Vector2f(x, y));
                                    x = abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x);
                                    y = abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y);
                                    if (x > enemyBuffer[i].getHitbox().getRadius() and y > enemyBuffer[i].getHitbox().getRadius())
                                    {
                                        for (int j = 1; j < 10; j++)
                                        {
                                            if (!isEnemyWallHit(enemyBuffer[i], 100 / j))
                                            {
                                                if (!isEnemyEnemyHit(enemyBuffer[i], 100 / j))
                                                {
                                                    enemyBuffer[i].move(sf::Vector2f(
                                                        ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / j) * (1 / 60.f),
                                                        ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / j) * (1 / 60.f)
                                                    ));
                                                    break;
                                                }
                                            }
                                            if (j == 9)
                                            {
                                                enemyBuffer[i].setState(EnemyState::Standing);
                                                enemyBuffer[i].setBehav(EnemyBehavior::Stand);
                                            }
                                        }
                                        if (isEnemyEnemyHit(enemyBuffer[i], (450 / 10)))
                                        {
                                            enemyBuffer[i].move(sf::Vector2f(
                                                ((enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / 10)* (1 / 60.f),
                                                ((enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y) / (abs(enemyBuffer[i].getDest().x - enemyBuffer[i].getHitbox().getPosition().x) + abs(enemyBuffer[i].getDest().y - enemyBuffer[i].getHitbox().getPosition().y))) * (450 / 10)* (1 / 60.f)
                                            ));
                                        }
                                    }
                                    else
                                    {
                                        enemyBuffer[i].setState(EnemyState::Standing);
                                        enemyBuffer[i].setBehav(EnemyBehavior::Backing);
                                    }
                                }
                            }
                        }
                    }
                }
                //check player hitboxes for attack and recieve damage and check for death

                //enemyBuffer[i].getDamage(1);
                //if (enemyBuffer[i].getHealth() <= 0)
                //{
                //    enemyBuffer.erase(enemyBuffer.begin() + i);
                //    if (enemyBuffer.empty())
                //    {
                //        waveTimer.restart();
                //    }
                //}

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
                clear();
            }
        }
    }
    if (goal == LevelGoal::Qizz)
    {

    }
    if (goal == LevelGoal::Reward)
    {

    }
}

bool Tile::isEnemyWallHit(Enemy enemy, int speed)
{

    if (enemy.getHitbox().getPosition().y - enemy.getHitbox().getRadius() - (speed * 1 / 60.f) < hitbox.getPosition().y - hitbox.getSize().y / 2)
    {
        return true;
    }
    if (enemy.getHitbox().getPosition().x - enemy.getHitbox().getRadius() - (speed * 1 / 60.f) < hitbox.getPosition().x - hitbox.getSize().x / 2)
    {
        return true;
    }
    if (enemy.getHitbox().getPosition().y + enemy.getHitbox().getRadius() + (speed * 1 / 60.f) > hitbox.getPosition().y + hitbox.getSize().y / 2)
    {
        return true;
    }
    if (enemy.getHitbox().getPosition().x + enemy.getHitbox().getRadius() + (speed * 1 / 60.f) > hitbox.getPosition().x + hitbox.getSize().x / 2)
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
            if (enemy.getHitbox().getRadius() * 2 + (speed * 1 / 60.f) > sqrt(pow((enemyBuffer[i].getHitbox().getPosition().x - enemy.getHitbox().getPosition().x), 2) + pow((enemyBuffer[i].getHitbox().getPosition().y - enemy.getHitbox().getPosition().y), 2)))
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