#include "Game.h"

Game::Game()
	:	window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Death of the last", sf::Style::Fullscreen)
{
    if (sf::VideoMode::getDesktopMode().width > sf::VideoMode::getDesktopMode().height)
    {
        side = sf::VideoMode::getDesktopMode().height / 1;
    }
    else
    {
        side = sf::VideoMode::getDesktopMode().width / 1;
    }
    tileCreated = new bool* [101];
    for (int i = 0; i < 101; i++)
    {
        tileCreated[i] = new bool[101];
        for (int j = 0; j < 101; j++)
        {
            tileCreated[i][j] = false;
        }
    }
    tileNumOffset = 50;
    timePerFrame = sf::seconds(1 / 100.f);  //update rate
    //timePerFrame2 = sf::seconds(1 / 75.f);  //display rate
    camera = window.getView();
    tileData = new Tile* [101];
    for (int i = 0; i < 101; i++)
    {
        tileData[i] = new Tile[101];
    }
    playerSpeed = 1000;
    NataSans.loadFromFile("assets/font/Nata_Sans_Typeface/ttf/NataSans-Regular.ttf");
    tileSetBg.loadFromFile("assets/textures/TileSet.png");
    ar10texture = new sf::Texture;
    ar10texture->loadFromFile("assets/textures/ar10.png");
    textureHolder.push_back(ar10texture);
    swmptexture = new sf::Texture;
    swmptexture->loadFromFile("assets/textures/swmp.png");
    textureHolder.push_back(swmptexture);
    vp70texture = new sf::Texture;
    vp70texture->loadFromFile("assets/textures/vp70.png");
    textureHolder.push_back(vp70texture);
    m88texture = new sf::Texture;
    m88texture->loadFromFile("assets/textures/m88.png");
    textureHolder.push_back(m88texture);
    mr133texture = new sf::Texture;
    mr133texture->loadFromFile("assets/textures/mr133.png");
    textureHolder.push_back(mr133texture);
    grozatexture = new sf::Texture;
    grozatexture->loadFromFile("assets/textures/groza.png");
    textureHolder.push_back(grozatexture);
    xm8texture = new sf::Texture;
    xm8texture->loadFromFile("assets/textures/xm-8.png");
    textureHolder.push_back(xm8texture);
    ar15texture = new sf::Texture;
    ar15texture->loadFromFile("assets/textures/ar15.png");
    textureHolder.push_back(ar15texture);
    difficulty = 0.01;
    dashTimer.restart();
    rangedAttackTimer.restart();
    meleeAttackTimer.restart();
    bulletsShot = 0;
    reloadTimer.restart();
    interactionTimer.restart();
    displayTimer.restart();
    roomsCount = 0;
    roomsVisited = 0;
}

Game::~Game()
{
}

void Game::run()
{
    sf::Clock frameTime;
    initial();
    while (window.isOpen())
    {
        frameTime.restart();
        events();
        commands();
        if (frameTime.getElapsedTime() < timePerFrame)
        {
            sf::sleep(sf::Time(timePerFrame - frameTime.getElapsedTime()));
        }
    }
}

void Game::initial()
{
    generateMap();
    spawnPlayer();
    //ui
    {
        overlay.floorProgress.setSize(sf::Vector2f(
            side / 10,
            side / 20
        ));
        overlay.floorProgress.setOrigin(sf::Vector2f(
            overlay.floorProgress.getSize().x / 2,
            overlay.floorProgress.getSize().y / 2
        ));
        overlay.floorProgress.setFillColor(sf::Color(100, 100, 100));
        overlay.floorProgress.setOutlineColor(sf::Color(60, 60, 60));
        overlay.floorProgress.setOutlineThickness(side / 400);

        overlay.floorProgressLabel.setFont(NataSans);
        overlay.floorProgressLabel.setFillColor(sf::Color::Black);
        overlay.floorProgressLabel.setCharacterSize(side / 40);
        overlay.floorProgressLabel.setOrigin(sf::Vector2f(
            overlay.floorProgress.getSize().x / 2 - side / 200,
            overlay.floorProgress.getSize().y / 2 - side / 100
        ));

        overlay.floorNum.setSize(sf::Vector2f(
            side / 10,
            side / 20
        ));
        overlay.floorNum.setOrigin(sf::Vector2f(
            overlay.floorNum.getSize().x / 2,
            overlay.floorNum.getSize().y / 2
        ));
        overlay.floorNum.setFillColor(sf::Color(100, 100, 100));
        overlay.floorNum.setOutlineColor(sf::Color(60, 60, 60));
        overlay.floorNum.setOutlineThickness(side / 400);

        overlay.armourSpriteEdge.setSize(sf::Vector2f(
            side / 20,
            side / 20
        ));
        overlay.armourSpriteEdge.setOrigin(sf::Vector2f(
            overlay.armourSpriteEdge.getSize().x / 2,
            overlay.armourSpriteEdge.getSize().y / 2
        ));
        overlay.armourSpriteEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.armourSpriteEdge.setOutlineColor(sf::Color(60, 60, 60));
        overlay.armourSpriteEdge.setOutlineThickness(side / 400);

        overlay.bullet9mmEdge.setSize(sf::Vector2f(
            side / 20,
            side / 20
        ));
        overlay.bullet9mmEdge.setOrigin(sf::Vector2f(
            overlay.bullet9mmEdge.getSize().x / 2,
            overlay.bullet9mmEdge.getSize().y / 2
        ));
        overlay.bullet9mmEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.bullet9mmEdge.setOutlineColor(sf::Color(60, 60, 60));
        overlay.bullet9mmEdge.setOutlineThickness(side / 400);

        overlay.bullet556mmEdge.setSize(sf::Vector2f(
            side / 20,
            side / 20
        ));
        overlay.bullet556mmEdge.setOrigin(sf::Vector2f(
            overlay.bullet556mmEdge.getSize().x / 2,
            overlay.bullet556mmEdge.getSize().y / 2
        ));
        overlay.bullet556mmEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.bullet556mmEdge.setOutlineColor(sf::Color(60, 60, 60));
        overlay.bullet556mmEdge.setOutlineThickness(side / 400);

        overlay.bullet762mmEdge.setSize(sf::Vector2f(
            side / 20,
            side / 20
        ));
        overlay.bullet762mmEdge.setOrigin(sf::Vector2f(
            overlay.bullet762mmEdge.getSize().x / 2,
            overlay.bullet762mmEdge.getSize().y / 2
        ));
        overlay.bullet762mmEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.bullet762mmEdge.setOutlineColor(sf::Color(60, 60, 60));
        overlay.bullet762mmEdge.setOutlineThickness(side / 400);

        overlay.bullet12gaugeEdge.setSize(sf::Vector2f(
            side / 20,
            side / 20
        ));
        overlay.bullet12gaugeEdge.setOrigin(sf::Vector2f(
            overlay.bullet12gaugeEdge.getSize().x / 2,
            overlay.bullet12gaugeEdge.getSize().y / 2
        ));
        overlay.bullet12gaugeEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.bullet12gaugeEdge.setOutlineColor(sf::Color(60, 60, 60));
        overlay.bullet12gaugeEdge.setOutlineThickness(side / 400);

        overlay.mainWeaponEdge.setSize(sf::Vector2f(
            side / 20,
            side / 20
        ));
        overlay.mainWeaponEdge.setOrigin(sf::Vector2f(
            overlay.mainWeaponEdge.getSize().x / 2,
            overlay.mainWeaponEdge.getSize().y / 2
        ));
        overlay.mainWeaponEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.mainWeaponEdge.setOutlineColor(sf::Color(60, 60, 60));
        overlay.mainWeaponEdge.setOutlineThickness(side / 400);

        overlay.secondaryWeaponEdge.setSize(sf::Vector2f(
            side / 20,
            side / 20
        ));
        overlay.secondaryWeaponEdge.setOrigin(sf::Vector2f(
            overlay.secondaryWeaponEdge.getSize().x / 2,
            overlay.secondaryWeaponEdge.getSize().y / 2
        ));
        overlay.secondaryWeaponEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.secondaryWeaponEdge.setOutlineColor(sf::Color(60, 60, 60));
        overlay.secondaryWeaponEdge.setOutlineThickness(side / 400);

        overlay.repairKitEdge.setSize(sf::Vector2f(
            side / 20,
            side / 20
        ));
        overlay.repairKitEdge.setOrigin(sf::Vector2f(
            overlay.repairKitEdge.getSize().x / 2,
            overlay.repairKitEdge.getSize().y / 2
        ));
        overlay.repairKitEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.repairKitEdge.setOutlineColor(sf::Color(60, 60, 60));
        overlay.repairKitEdge.setOutlineThickness(side / 400);

        overlay.healthKitEdge.setSize(sf::Vector2f(
            side / 20,
            side / 20
        ));
        overlay.healthKitEdge.setOrigin(sf::Vector2f(
            overlay.healthKitEdge.getSize().x / 2,
            overlay.healthKitEdge.getSize().y / 2
        ));
        overlay.healthKitEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.healthKitEdge.setOutlineColor(sf::Color(60, 60, 60));
        overlay.healthKitEdge.setOutlineThickness(side / 400);

        overlay.armourBarEdge.setSize(sf::Vector2f(
            side / 20 * 3 + (side / 15 - side / 20) * 2,
            side / 60
        ));
        overlay.armourBarEdge.setOrigin(sf::Vector2f(
            overlay.armourBarEdge.getSize().x / 2,
            overlay.armourBarEdge.getSize().y / 2
        ));
        overlay.armourBarEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.armourBarEdge.setOutlineColor(sf::Color(20, 20, 20));
        overlay.armourBarEdge.setOutlineThickness(side / 400);

        overlay.armourBarFill.setSize(sf::Vector2f(
            side / 20 * 3 + (side / 15 - side / 20) * 2,
            side / 60
        ));
        overlay.armourBarFill.setOrigin(sf::Vector2f(
            overlay.armourBarFill.getSize().x / 2,
            overlay.armourBarFill.getSize().y / 2
        ));
        overlay.armourBarFill.setFillColor(sf::Color(30, 43, 230));

        overlay.hpBarEdge.setSize(sf::Vector2f(
            side / 20 * 3 + (side / 15 - side / 20) * 2,
            side / 60
        ));
        overlay.hpBarEdge.setOrigin(sf::Vector2f(
            overlay.hpBarEdge.getSize().x / 2,
            overlay.hpBarEdge.getSize().y / 2
        ));
        overlay.hpBarEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.hpBarEdge.setOutlineColor(sf::Color(20, 20, 20));
        overlay.hpBarEdge.setOutlineThickness(side / 400);

        overlay.hpBarFill.setSize(sf::Vector2f(
            side / 20 * 3 + (side / 15 - side / 20) * 2,
            side / 60
        ));
        overlay.hpBarFill.setOrigin(sf::Vector2f(
            overlay.hpBarFill.getSize().x / 2,
            overlay.hpBarFill.getSize().y / 2
        ));
        overlay.hpBarFill.setFillColor(sf::Color(50, 230, 30));

        overlay.staminaBarEdge.setSize(sf::Vector2f(
            side / 20 * 3 + (side / 15 - side / 20) * 2,
            side / 60
        ));
        overlay.staminaBarEdge.setOrigin(sf::Vector2f(
            overlay.staminaBarEdge.getSize().x / 2,
            overlay.staminaBarEdge.getSize().y / 2
        ));
        overlay.staminaBarEdge.setFillColor(sf::Color(100, 100, 100));
        overlay.staminaBarEdge.setOutlineColor(sf::Color(20, 20, 20));
        overlay.staminaBarEdge.setOutlineThickness(side / 400);

        overlay.staminaBarFill.setSize(sf::Vector2f(
            side / 20 * 3 + (side / 15 - side / 20) * 2,
            side / 60
        ));
        overlay.staminaBarFill.setOrigin(sf::Vector2f(
            overlay.staminaBarFill.getSize().x / 2,
            overlay.staminaBarFill.getSize().y / 2
        ));
        overlay.staminaBarFill.setFillColor(sf::Color(30, 230, 230));
    }
}

void Game::generateMap()
{
    Tile tile(TileType::Central, sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, side, difficulty, textureHolder);
    tileCreated[0 + tileNumOffset][0 + tileNumOffset] = true;
    tileData[0 + tileNumOffset][0 + tileNumOffset] = tile;
    loadedTiles.push_back(sf::Vector2i(0 + tileNumOffset, 0 + tileNumOffset));
    roomsCount++;
    srand(time(0));
    if (!tileCreated[0 + tileNumOffset][-2 + tileNumOffset])
    {
        generateLevel(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, 1, 0);
    }
    if (!tileCreated[-2 + tileNumOffset][0 + tileNumOffset])
    {
        generateLevel(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, 2, 0);
    }
    if (!tileCreated[0 + tileNumOffset][2 + tileNumOffset])
    {
        generateLevel(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, 3, 0);
    }
    if (!tileCreated[2 + tileNumOffset][0 + tileNumOffset])
    {
        generateLevel(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, 4, 0);
    }
    for (int i = 0; i < loadedTiles.size(); i++)
    {
        if (tileData[loadedTiles[i].x][loadedTiles[i].y].getType() == LevelRegular)
        {
            int u = 0, l = 0, d = 0, r = 0;
            if (loadedTiles[i].x >= 1 and loadedTiles[i].x <= 98 and loadedTiles[i].y >= 1 and loadedTiles[i].y <= 98)
            {
                //up
                if (tileCreated[loadedTiles[i].x][loadedTiles[i].y - 1])
                {
                    if (tileData[loadedTiles[i].x][loadedTiles[i].y - 1].getType() == CorridorV)
                    {
                        u = 1;
                    }
                }
                //left
                if (tileCreated[loadedTiles[i].x - 1][loadedTiles[i].y])
                {
                    if (tileData[loadedTiles[i].x - 1][loadedTiles[i].y].getType() == CorridorH)
                    {
                        l = 1;
                    }
                }
                //down
                if (tileCreated[loadedTiles[i].x][loadedTiles[i].y + 1])
                {
                    if (tileData[loadedTiles[i].x][loadedTiles[i].y + 1].getType() == CorridorV)
                    {
                        d = 1;
                    }
                }
                //right
                if (tileCreated[loadedTiles[i].x + 1][loadedTiles[i].y])
                {
                    if (tileData[loadedTiles[i].x + 1][loadedTiles[i].y].getType() == CorridorH)
                    {
                        r = 1;
                    }
                }
            }
            tileData[loadedTiles[i].x][loadedTiles[i].y].spawnWalls(u, l, d, r);
        }
    }
}

void Game::generateLevel(int pos_x, int pos_y, int index_x, int index_y, int dir, int len)
{
    int tileSize = side;
    if (index_x > -46 and index_x < 46 and index_y > -46 and index_y < 46 and len < 15)
    {
        switch (dir)
        {
            case 1: //up
            {
                Tile tile(TileType::CorridorV, pos_x, pos_y - tileSize, index_x, index_y - 1, side, difficulty, textureHolder);
                tileCreated[index_x + tileNumOffset][index_y - 1 + tileNumOffset] = true;
                tileData[index_x + tileNumOffset][index_y - 1 + tileNumOffset] = tile;
                loadedTiles.push_back(sf::Vector2i(index_x + tileNumOffset, index_y - 1 + tileNumOffset));
                int type = rand() % 100; 
                TileType type2;
                if (type < 40)
                {
                    type2 = TileType::LevelRegular;
                }
                if (type > 39 and type < 55)
                {
                    type2 = TileType::LevelQizz;
                }
                if (type > 54 and type < 65)
                {
                    type2 = TileType::LevelReward;
                }
                if (type > 64 and type < 90)
                {
                    type2 = TileType::LevelEmpty;
                }
                if (type > 89 and type < 95)
                {
                    type2 = TileType::LevelStairs;
                }
                if (type > 94)
                {
                    type2 = TileType::LevelTeleport;
                }
                Tile tile2(type2, pos_x, pos_y - tileSize - tileSize, index_x, index_y - 2, side, difficulty, textureHolder);
                tileCreated[index_x + tileNumOffset][index_y - 2 + tileNumOffset] = true;
                tileData[index_x + tileNumOffset][index_y - 2 + tileNumOffset] = tile2;
                loadedTiles.push_back(sf::Vector2i(index_x + tileNumOffset, index_y - 2 + tileNumOffset));
                roomsCount++;
                int created = 0;
                int createdMax = rand() % 3 + 1;
                int counter = 0;
                while (created < createdMax and counter < 100)
                {
                    int newDir = rand() % 3 + 1;
                    switch (newDir)
                    {
                    case 1: //left
                    {
                        if (!tileCreated[index_x - 2 + tileNumOffset][index_y - 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y - tileSize - tileSize, index_x, index_y - 2, 2, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 2: //up
                    {
                        if (!tileCreated[index_x + tileNumOffset][index_y - 4 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y - tileSize - tileSize, index_x, index_y - 2, 1, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 3: //right
                    {
                        if (!tileCreated[index_x + 2 + tileNumOffset][index_y - 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y - tileSize - tileSize, index_x, index_y - 2, 4, len + 1);
                        }
                        counter++;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                difficulty += 0.001;
                break;
            }
            case 2: //left
            {
                Tile tile(TileType::CorridorH, pos_x - tileSize, pos_y, index_x - 1, index_y, side, difficulty, textureHolder);
                tileCreated[index_x - 1 + tileNumOffset][index_y + tileNumOffset] = true;
                tileData[index_x - 1 + tileNumOffset][index_y + tileNumOffset] = tile;
                loadedTiles.push_back(sf::Vector2i(index_x - 1 + tileNumOffset, index_y + tileNumOffset));
                int type = rand() % 6;
                TileType type2;
                if (type < 40)
                {
                    type2 = TileType::LevelRegular;
                }
                if (type > 39 and type < 55)
                {
                    type2 = TileType::LevelQizz;
                }
                if (type > 54 and type < 65)
                {
                    type2 = TileType::LevelReward;
                }
                if (type > 64 and type < 90)
                {
                    type2 = TileType::LevelEmpty;
                }
                if (type > 89 and type < 95)
                {
                    type2 = TileType::LevelStairs;
                }
                if (type > 94)
                {
                    type2 = TileType::LevelTeleport;
                }
                Tile tile2(type2, pos_x - tileSize - tileSize, pos_y, index_x - 2, index_y, side, difficulty, textureHolder);
                tileCreated[index_x - 2 + tileNumOffset][index_y + tileNumOffset] = true;
                tileData[index_x - 2 + tileNumOffset][index_y + tileNumOffset] = tile2;
                loadedTiles.push_back(sf::Vector2i(index_x - 2 + tileNumOffset, index_y + tileNumOffset));
                roomsCount++;
                int created = 0;
                int createdMax = rand() % 3 + 1;
                int counter = 0;
                while (created < createdMax and counter < 100)
                {
                    int newDir = rand() % 3 + 1;
                    switch (newDir)
                    {
                    case 1: //left
                    {
                        if (!tileCreated[index_x - 4 + tileNumOffset][index_y + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x - tileSize - tileSize, pos_y, index_x - 2, index_y, 2, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 2: //up
                    {
                        if (!tileCreated[index_x - 2 + tileNumOffset][index_y - 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x - tileSize - tileSize, pos_y, index_x - 2, index_y, 1, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 3: //down
                    {
                        if (!tileCreated[index_x - 2 + tileNumOffset][index_y + 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x - tileSize - tileSize, pos_y, index_x - 2, index_y, 3, len + 1);
                        }
                        counter++;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                difficulty += 0.001;
                break;
            }
            case 3: //down
            {
                Tile tile(TileType::CorridorV, pos_x, pos_y + tileSize, index_x, index_y + 1, side, difficulty, textureHolder);
                tileCreated[index_x + tileNumOffset][index_y + 1 + tileNumOffset] = true;
                tileData[index_x + tileNumOffset][index_y + 1 + tileNumOffset] = tile;
                loadedTiles.push_back(sf::Vector2i(index_x + tileNumOffset, index_y + 1 + tileNumOffset));
                int type = rand() % 6;
                TileType type2;
                if (type < 40)
                {
                    type2 = TileType::LevelRegular;
                }
                if (type > 39 and type < 55)
                {
                    type2 = TileType::LevelQizz;
                }
                if (type > 54 and type < 65)
                {
                    type2 = TileType::LevelReward;
                }
                if (type > 64 and type < 90)
                {
                    type2 = TileType::LevelEmpty;
                }
                if (type > 89 and type < 95)
                {
                    type2 = TileType::LevelStairs;
                }
                if (type > 94)
                {
                    type2 = TileType::LevelTeleport;
                }
                Tile tile2(type2, pos_x, pos_y + tileSize + tileSize, index_x, index_y + 2, side, difficulty, textureHolder);
                tileCreated[index_x + tileNumOffset][index_y + 2 + tileNumOffset] = true;
                tileData[index_x + tileNumOffset][index_y + 2 + tileNumOffset] = tile2;
                loadedTiles.push_back(sf::Vector2i(index_x + tileNumOffset, index_y + 2 + tileNumOffset));
                roomsCount++;
                int created = 0;
                int createdMax = rand() % 3 + 1;
                int counter = 0;
                while (created < createdMax and counter < 100)
                {
                    int newDir = rand() % 3 + 1;
                    switch (newDir)
                    {
                    case 1: //left
                    {
                        if (!tileCreated[index_x - 2 + tileNumOffset][index_y + 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y + tileSize + tileSize, index_x, index_y + 2, 2, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 2: //down
                    {
                        if (!tileCreated[index_x + tileNumOffset][index_y + 4 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y + tileSize + tileSize, index_x, index_y + 2, 3, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 3: //right
                    {
                        if (!tileCreated[index_x + 2 + tileNumOffset][index_y + 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y + tileSize + tileSize, index_x, index_y + 2, 4, len + 1);
                        }
                        counter++;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                difficulty += 0.001;
                break;
            }
            case 4: //right
            {
                Tile tile(TileType::CorridorH, pos_x + tileSize, pos_y, index_x + 1, index_y, side, difficulty, textureHolder);
                tileCreated[index_x + 1 + tileNumOffset][index_y + tileNumOffset] = true;
                tileData[index_x + 1 + tileNumOffset][index_y + tileNumOffset] = tile;
                loadedTiles.push_back(sf::Vector2i(index_x + 1 + tileNumOffset, index_y + tileNumOffset));
                int type = rand() % 6;
                TileType type2;
                if (type < 40)
                {
                    type2 = TileType::LevelRegular;
                }
                if (type > 39 and type < 55)
                {
                    type2 = TileType::LevelQizz;
                }
                if (type > 54 and type < 65)
                {
                    type2 = TileType::LevelReward;
                }
                if (type > 64 and type < 90)
                {
                    type2 = TileType::LevelEmpty;
                }
                if (type > 89 and type < 95)
                {
                    type2 = TileType::LevelStairs;
                }
                if (type > 94)
                {
                    type2 = TileType::LevelTeleport;
                }
                Tile tile2(type2, pos_x + tileSize + tileSize, pos_y, index_x + 2, index_y, side, difficulty, textureHolder);
                tileCreated[index_x + 2 + tileNumOffset][index_y + tileNumOffset] = true;
                tileData[index_x + 2 + tileNumOffset][index_y + tileNumOffset] = tile2;
                loadedTiles.push_back(sf::Vector2i(index_x + 2 + tileNumOffset, index_y + tileNumOffset));
                roomsCount++;
                int created = 0;
                int createdMax = rand() % 3 + 1;
                int counter = 0;
                while (created < createdMax and counter < 100)
                {
                    int newDir = rand() % 3 + 1;
                    switch (newDir)
                    {
                    case 1: //down
                    {
                        if (!tileCreated[index_x + 2 + tileNumOffset][index_y + 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x + tileSize + tileSize, pos_y, index_x + 2, index_y, 3, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 2: //up
                    {
                        if (!tileCreated[index_x + 2 + tileNumOffset][index_y - 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x + tileSize + tileSize, pos_y, index_x + 2, index_y, 1, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 3: //right
                    {
                        if (!tileCreated[index_x + 4 + tileNumOffset][index_y + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x + tileSize + tileSize, pos_y, index_x + 2, index_y, 4, len + 1);
                        }
                        counter++;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                }
                difficulty += 0.001;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

void Game::spawnPlayer()
{
    Command command;
    command.name = CommandName::SpawnPlayer;     //player
    command.attribute.int1 = sf::VideoMode::getDesktopMode().width / 2;
    command.attribute.int2 = sf::VideoMode::getDesktopMode().height / 2;
    command.attribute.int3 = 0;
    command.attribute.int4 = 0;
    commandQueue.push_back(command);
}

void Game::events()
{
    Command command;
    sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
        {
            command.name = CommandName::Close;
            commandQueue.push_back(command);
        }
        if (event.type == sf::Event::MouseMoved)
        {
            command.name = Rotate;
            commandQueue.push_back(command);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        command.name = CommandName::MoveUp;
        commandQueue.push_back(command);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        command.name = CommandName::MoveLeft;
        commandQueue.push_back(command);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        command.name = CommandName::MoveDown;
        commandQueue.push_back(command);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        command.name = CommandName::MoveRight;
        commandQueue.push_back(command);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) and interactionTimer.getElapsedTime() > sf::seconds(0.5))
    {
        interactionTimer.restart();
        command.name = CommandName::Interaction;
        commandQueue.push_back(command);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        command.name = CommandName::Close;
        commandQueue.push_back(command);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and dashTimer.getElapsedTime() > sf::seconds(0.5))
    {
        dashTimer.restart();
        command.name = CommandName::Dash;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            command.attribute.int1 = 1;
        else
            command.attribute.int1 = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            command.attribute.int2 = 1;
        else
            command.attribute.int2 = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            command.attribute.int3 = 1;
        else
            command.attribute.int3 = 0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            command.attribute.int4 = 1;
        else
            command.attribute.int4 = 0;
        commandQueue.push_back(command);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (player->getRanged().getName() != WeaponName::NoWeapon)
        {
            if (reloadTimer.getElapsedTime() > player->getRanged().getReloadTime())
            {
                if (player->getRanged().getCooldown() < rangedAttackTimer.getElapsedTime())
                {
                    rangedAttackTimer.restart();
                    command.name = CommandName::RangeAttack;
                    commandQueue.push_back(command);
                    bulletsShot++;
                    if (bulletsShot == player->getRanged().getCapacity())
                    {
                        bulletsShot = 0;
                        reloadTimer.restart();
                    }
                }
            }
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        if (player->getMelee().getCooldown() < meleeAttackTimer.getElapsedTime())
        {
            meleeAttackTimer.restart();
            command.name = CommandName::CloseAttack;
            commandQueue.push_back(command);
            //attack
        }
    }
    

    command.name = CommandName::TickTiles;
    commandQueue.push_back(command);

    //display always at the end
    //if (displayTimer.getElapsedTime() > timePerFrame2)
    //{
    //    displayTimer.restart();
        command.name = CommandName::UpdateOverlay;
        commandQueue.push_back(command);
        command.name = CommandName::Display;
        commandQueue.push_back(command);
    //}
}

void Game::commands()
{
    if (!commandQueue.empty())
    {
        for (int i = 0; i < commandQueue.size(); i++)
        {
            switch (commandQueue[i].name)
            {
                case CommandName::Close:
                {
                    window.close();
                    break;
                }
                case CommandName::Display:
                {
                    window.clear();
                    //draw world
                    {
                        if (!loadedTiles.empty())
                        {
                            for (int j = 0; j < loadedTiles.size(); j++)
                            {
                                if (abs(player->getIndex().x + tileNumOffset - loadedTiles[j].x) < 5 and abs(player->getIndex().y + tileNumOffset - loadedTiles[j].y) < 5)
                                {
                                    window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getBody());
                                    window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getHitbox());
                                    if (tileData[loadedTiles[j].x][loadedTiles[j].y].getType() == LevelRegular)
                                    {
                                        for (int k = 0; k < tileData[loadedTiles[j].x][loadedTiles[j].y].getWallsToDraw().size(); k++)
                                        {
                                            window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getWallById(tileData[loadedTiles[j].x][loadedTiles[j].y].getWallsToDraw()[k]).getHitbox());
                                        }
                                    }
                                    for (int k = 0; k < tileData[loadedTiles[j].x][loadedTiles[j].y].getEnemyBuffer().size(); k++)
                                    {
                                        window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getEnemyBuffer()[k].getHitbox());
                                        window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getEnemyBuffer()[k].getHpBar());
                                    }
                                    for (int k = 0; k < tileData[loadedTiles[j].x][loadedTiles[j].y].getRangedBuffer().size(); k++)
                                    {
                                        window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getRangedBuffer()[k].getPickUpHitbox());
                                        window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getRangedBuffer()[k].getSprite());
                                    }
                                    for (int k = 0; k < tileData[loadedTiles[j].x][loadedTiles[j].y].getMeleeBuffer().size(); k++)
                                    {
                                        window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getMeleeBuffer()[k].getPickUpHitbox());
                                    }
                                }
                            }
                        }
                    }
                    //draw attack
                    {
                        //for enemy


                        //for player
                        if (player->getRanged().getName() != NoWeapon)
                        {
                            for (int j = 0; j < player->getRanged().getProjBuffer().size(); j++)
                            {
                                window.draw(player->getRanged().getProjBuffer()[j].getHitbox());
                            }
                        }
                        window.draw(player->getMelee().getHitbox());
                    }
                    //draw player
                    {
                        if (player != nullptr)
                        {
                            window.draw(player->getHitbox());
                        }
                    }
                    //draw hud
                    {
                        //sf::Text text;
                        //text.setFont(NataSans);
                        //text.setFillColor(sf::Color::Red);
                        //text.setCharacterSize(20);
                        //text.setPosition(player->getHitbox().getPosition() + sf::Vector2f(0, 50));
                        //std::string str = std::to_string(player->getIndex().x) + " " + std::to_string(player->getIndex().y) + " " + std::to_string(player->getHitbox().getPosition().x - sf::VideoMode::getDesktopMode().width / 2 + side / 4) + " " + std::to_string(player->getHitbox().getPosition().y - side / 2 + side / 4) + " " + std::to_string(player->getMelee().getHitbox().getRotation());
                        //text.setString(str);
                        //window.draw(text);
                        window.draw(overlay.floorProgress);
                        window.draw(overlay.floorProgressLabel);
                        window.draw(overlay.floorNum);
                        window.draw(overlay.floorNumLabel);
                        window.draw(overlay.hpBarEdge);
                        window.draw(overlay.hpBarFill);
                        window.draw(overlay.staminaBarEdge);
                        window.draw(overlay.staminaBarFill);
                        window.draw(overlay.armourBarEdge);
                        window.draw(overlay.armourBarFill);
                        window.draw(overlay.armourSpriteEdge);
                        window.draw(overlay.bullet9mmEdge);
                        window.draw(overlay.bullet9mmLabel);
                        window.draw(overlay.bullet556mmEdge);
                        window.draw(overlay.bullet556mmLabel);
                        window.draw(overlay.bullet762mmEdge);
                        window.draw(overlay.bullet762mmLabel);
                        window.draw(overlay.bullet12gaugeEdge);
                        window.draw(overlay.bullet12gaugeLabel);
                        window.draw(overlay.mainWeaponEdge);
                        window.draw(overlay.mainWeaponFill);
                        window.draw(overlay.secondaryWeaponEdge);
                        window.draw(overlay.secondaryWeaponFill);
                        window.draw(overlay.repairKitEdge);
                        window.draw(overlay.repairKitFill);
                        window.draw(overlay.healthKitEdge);
                        window.draw(overlay.healthKitFill);
                    }
                    window.display();
                    break;
                }
                case CommandName::SpawnPlayer:
                {
                    player = new Player(commandQueue[i].attribute.int1, commandQueue[i].attribute.int2, commandQueue[i].attribute.int3, commandQueue[i].attribute.int4, side, textureHolder);
                    break;
                }
                case CommandName::Rotate:
                {
                    sf::Vector2f dir, center;
                    center = sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
                    dir.x = (sf::Mouse::getPosition().x - center.x) / (abs(sf::Mouse::getPosition().x - center.x) + abs(sf::Mouse::getPosition().y - center.y));
                    dir.y = (sf::Mouse::getPosition().y - center.y) / (abs(sf::Mouse::getPosition().x - center.x) + abs(sf::Mouse::getPosition().y - center.y));
                    player->rotate(((atan2(dir.y, dir.x)) / 3.14) * 180.f + 90.f);
                    break;
                }
                case CommandName::UpdateOverlay:
                {
                    overlay.floorProgress.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x - side / 2 + side / 15,
                        player->getHitbox().getPosition().y - side / 2 + side / 20
                    ));
                    overlay.floorProgressLabel.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x - side / 2 + side / 15,
                        player->getHitbox().getPosition().y - side / 2 + side / 20
                    ));
                    std::string str = std::to_string(roomsVisited) + " / " + std::to_string(roomsCount);
                    overlay.floorProgressLabel.setString(str);
                    overlay.floorNum.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 15,
                        player->getHitbox().getPosition().y - side / 2 + side / 20
                    ));
                    overlay.armourSpriteEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15 - side / 15
                    ));
                    overlay.bullet9mmEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15
                    ));
                    overlay.bullet556mmEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15
                    ));
                    overlay.bullet762mmEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15
                    ));
                    overlay.bullet12gaugeEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15
                    ));
                    overlay.mainWeaponEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20
                    ));
                    overlay.secondaryWeaponEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20
                    ));
                    overlay.repairKitEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20
                    ));
                    overlay.healthKitEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20,
                        player->getHitbox().getPosition().y + side / 2 - side / 20
                    ));
                    overlay.armourBarEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15 - side / 15 + side / 60
                    ));
                    overlay.armourBarFill.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15 - side / 15 + side / 60
                    ));
                    overlay.hpBarEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15 - side / 15 - side / 60 
                    ));
                    overlay.hpBarFill.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15 - side / 15 - side / 60 
                    ));
                    overlay.staminaBarEdge.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15 - side / 15
                    ));
                    overlay.staminaBarFill.setPosition(sf::Vector2f(
                        player->getHitbox().getPosition().x + side / 2 - side / 20 - side / 15 - side / 15,
                        player->getHitbox().getPosition().y + side / 2 - side / 20 - side / 15 - side / 15
                    ));
                    break;
                }
                case CommandName::RangeAttack:
                {
                    sf::Vector2f dir, center;
                    center = sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
                    dir.x = (sf::Mouse::getPosition().x - center.x) / (abs(sf::Mouse::getPosition().x - center.x) + abs(sf::Mouse::getPosition().y - center.y));
                    dir.y = (sf::Mouse::getPosition().y - center.y) / (abs(sf::Mouse::getPosition().x - center.x) + abs(sf::Mouse::getPosition().y - center.y));
                    player->shoot(side, dir);
                    break;
                }
                case CommandName::CloseAttack:
                {
                    for (int j = 0; j < tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getEnemyBuffer().size(); j++)
                    {
                        if (isMeleeEnemyHit(player->getMelee().getHitbox(), tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getEnemyBuffer()[j]))
                        {
                            tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].damageEnemy(j, player->getMelee().getDamage());
                        }
                    }
                    break;
                }
                case CommandName::TickTiles:
                {
                    //tile
                    if (!loadedTiles.empty())
                    {
                        for (int j = 0; j < loadedTiles.size(); j++)
                        {
                            if (abs(player->getIndex().x + tileNumOffset - loadedTiles[j].x) < 1 and abs(player->getIndex().y + tileNumOffset - loadedTiles[j].y) < 1)
                            {
                                if (tileData[loadedTiles[j].x][loadedTiles[j].y].tickTile(player, tileData[loadedTiles[j].x][loadedTiles[j].y]))
                                {
                                    roomsVisited++;
                                }
                            }
                        }
                    }
                    //player
                    if (player->getRanged().getName() != NoWeapon)
                    {
                        for (int j = 0; j < player->getRanged().getProjBuffer().size(); j++)
                        {
                            for (int k = 0; k < 100; k++)
                            {
                                if (!isProjWallHit(player->getRanged().getProjBuffer()[j], player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, player->getRanged().getProjBuffer()[j].getDir(), player->getRanged().getSpeed() - (player->getRanged().getSpeed() / 100) * k))
                                {
                                    player->tickProj(j, player->getRanged().getSpeed() - (player->getRanged().getSpeed() / 100) * k);
                                    break;
                                }
                                if (k == 99)
                                {
                                    player->delProj(j);
                                }
                            }
                        }
                    }

                    //evertTickThings
                    

                    break;
                }
                case CommandName::Interaction:
                {
                    bool interacted = false;
                    //interactables

                    //ranged weapons              
                    if (!tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getRangedBuffer().empty())
                    {
                        for (int k = 0; k < tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getRangedBuffer().size(); k++)
                        {
                            if (tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].isPlayerWeaponHit(player, tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getRangedBuffer()[k]))
                            {
                                player->swapWeapon(tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getRangedBuffer()[i]);
                                reloadTimer.restart();
                                tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].delRangedBufferElem(k);
                                interacted = true;
                                break;
                            }
                        }
                    }
                    if (interacted)
                    {
                        break;
                    }
                    //melee weapons             
                    if (!tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getMeleeBuffer().empty())
                    {
                        for (int k = 0; k < tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getMeleeBuffer().size(); k++)
                        {
                            if (tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].isPlayerWeaponHit(player, tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getMeleeBuffer()[k]))
                            {
                                player->swapWeapon(tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].getMeleeBuffer()[i]);
                                reloadTimer.restart();
                                tileData[player->getIndex().x + tileNumOffset][player->getIndex().y + tileNumOffset].delMeleeBufferElem(k);
                                interacted = true;
                                break;
                            }
                        }
                    }
                    if (interacted)
                    {
                        break;
                    }

                    break;
                }
                case CommandName::MoveUp:
                {
                    for (int j = 1; j < 10; j++)
                    {
                        if (!isPlayerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 1, playerSpeed /j) and !isPlayerInnerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 1, playerSpeed / j))
                        {
                            player->move(sf::Vector2f(0, (-1) * (playerSpeed /j) * (timePerFrame.asSeconds())));
                            camera.move(sf::Vector2f(0, (-1) * (playerSpeed /j) * (timePerFrame.asSeconds())));
                            window.setView(camera);
                            player->updateIndex(side);
                            break;
                        }
                    }
                    break;
                }
                case CommandName::MoveLeft:
                {
                    for (int j = 1; j < 10; j++)
                    {
                        if (!isPlayerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 2, playerSpeed /j) and !isPlayerInnerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 2, playerSpeed / j))
                        {
                            player->move(sf::Vector2f((-1) * (playerSpeed /j) * (timePerFrame.asSeconds()), 0));
                            camera.move(sf::Vector2f((-1) * (playerSpeed /j) * (timePerFrame.asSeconds()), 0));
                            window.setView(camera);
                            player->updateIndex(side);
                            break;
                        }
                    }
                    break;
                }
                case CommandName::MoveDown:
                {
                    for (int j = 1; j < 10; j++)
                    {
                        if (!isPlayerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 3, playerSpeed / j) and !isPlayerInnerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 3, playerSpeed / j))
                        {
                            player->move(sf::Vector2f(0, (1) * (playerSpeed / j) * (timePerFrame.asSeconds())));
                            camera.move(sf::Vector2f(0, (1) * (playerSpeed / j) * (timePerFrame.asSeconds())));
                            window.setView(camera);
                            player->updateIndex(side);
                            break;
                        }
                    }
                    break;
                }
                case CommandName::MoveRight:
                {
                    for (int j = 1; j < 10; j++)
                    {
                        if (!isPlayerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 4, playerSpeed /j) and !isPlayerInnerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 4, playerSpeed / j))
                        {
                            player->move(sf::Vector2f((playerSpeed /j) * (timePerFrame.asSeconds()), 0));
                            camera.move(sf::Vector2f((playerSpeed /j) * (timePerFrame.asSeconds()), 0));
                            window.setView(camera);
                            player->updateIndex(side);
                            break;
                        }
                    }
                    break;
                }
                case CommandName::Dash:
                {
                   if (commandQueue[i].attribute.int1 == 1)
                    {
                       for (int j = 1; j < 10; j++)
                        {
                           if (!isPlayerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 1, (playerSpeed * 100) /j))
                            {
                               player->move(sf::Vector2f(0, (-1) * ((playerSpeed * 10) / j)* (timePerFrame.asSeconds())));
                                camera.move(sf::Vector2f(0, (-1) * ((playerSpeed * 10) / j) * (timePerFrame.asSeconds())));
                                window.setView(camera);
                                player->updateIndex(side);
                                break;
                            }
                        }
                    }
                   if (commandQueue[i].attribute.int2 == 1)
                    {
                       for (int j = 1; j < 10; j++)
                        {
                           if (!isPlayerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 2, (playerSpeed * 100) /j))
                            {
                                player->move(sf::Vector2f((-1) * ((playerSpeed * 10) / j) * (timePerFrame.asSeconds()), 0));
                                camera.move(sf::Vector2f((-1) * ((playerSpeed * 10) / j) * (timePerFrame.asSeconds()), 0));
                                window.setView(camera);
                                player->updateIndex(side);
                                break;
                            }
                        }
                    }
                   if (commandQueue[i].attribute.int3 == 1)
                    {
                       for (int j = 1; j < 10; j++)
                        {
                           if (!isPlayerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 3, (playerSpeed * 100) /j))
                            {
                                player->move(sf::Vector2f(0, ((playerSpeed * 10) / j) * (timePerFrame.asSeconds())));
                                camera.move(sf::Vector2f(0, ((playerSpeed * 10) / j) * (timePerFrame.asSeconds())));
                                window.setView(camera);
                                player->updateIndex(side);
                                break;
                            }
                        }
                    }
                   if (commandQueue[i].attribute.int4 == 1)
                    {
                       for (int j = 1; j < 10; j++)
                        {
                           if (!isPlayerWallHit(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 4, (playerSpeed * 100) /j))
                            {
                                player->move(sf::Vector2f(((playerSpeed * 10) / j) * (timePerFrame.asSeconds()), 0));
                                camera.move(sf::Vector2f(((playerSpeed * 10) / j) * (timePerFrame.asSeconds()), 0));
                                window.setView(camera);
                                player->updateIndex(side);
                                break;
                            }
                        }
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
        commandQueue.clear();
    }
}

bool Game::isPlayerWallCollision(int index_x, int index_y, int dir)
{
    switch (dir)
    {
        case 1: //up
        {
            if (player->getHitbox().getPosition().y - player->getHitbox().getRadius() > tileData[index_x][index_y].getHitbox().getPosition().y - tileData[index_x][index_y].getHitbox().getSize().y / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().x - player->getHitbox().getRadius() > tileData[index_x][index_y - 1].getHitbox().getPosition().x - tileData[index_x][index_y - 1].getHitbox().getSize().x / 2
                    and player->getHitbox().getPosition().x + player->getHitbox().getRadius() < tileData[index_x][index_y - 1].getHitbox().getPosition().x + tileData[index_x][index_y - 1].getHitbox().getSize().x / 2
                    and (tileData[index_x][index_y].getState() == TileStatus::Cleared or tileData[index_x][index_y].getState() == TileStatus::Solved))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            break;
        }
        case 2: //left
        {
            if (player->getHitbox().getPosition().x - player->getHitbox().getRadius() > tileData[index_x][index_y].getHitbox().getPosition().x - tileData[index_x][index_y].getHitbox().getSize().x / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().y - player->getHitbox().getRadius() > tileData[index_x - 1][index_y].getHitbox().getPosition().y - tileData[index_x - 1][index_y].getHitbox().getSize().y / 2
                    and player->getHitbox().getPosition().y + player->getHitbox().getRadius() < tileData[index_x - 1][index_y].getHitbox().getPosition().y + tileData[index_x - 1][index_y].getHitbox().getSize().y / 2
                    and (tileData[index_x][index_y].getState() == TileStatus::Cleared or tileData[index_x][index_y].getState() == TileStatus::Solved))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            break;
        }
        case 3: //down
        {
            if (player->getHitbox().getPosition().y + player->getHitbox().getRadius() < tileData[index_x][index_y].getHitbox().getPosition().y + tileData[index_x][index_y].getHitbox().getSize().y / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().x - player->getHitbox().getRadius() > tileData[index_x][index_y + 1].getHitbox().getPosition().x - tileData[index_x][index_y + 1].getHitbox().getSize().x / 2
                    and player->getHitbox().getPosition().x + player->getHitbox().getRadius() < tileData[index_x][index_y + 1].getHitbox().getPosition().x + tileData[index_x][index_y + 1].getHitbox().getSize().x / 2
                    and (tileData[index_x][index_y].getState() == TileStatus::Cleared or tileData[index_x][index_y].getState() == TileStatus::Solved))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            break;
        }
        case 4: //right
        {
            if (player->getHitbox().getPosition().x + player->getHitbox().getRadius() < tileData[index_x][index_y].getHitbox().getPosition().x + tileData[index_x][index_y].getHitbox().getSize().x / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().y - player->getHitbox().getRadius() > tileData[index_x + 1][index_y].getHitbox().getPosition().y - tileData[index_x + 1][index_y].getHitbox().getSize().y / 2
                    and player->getHitbox().getPosition().y + player->getHitbox().getRadius() < tileData[index_x + 1][index_y].getHitbox().getPosition().y + tileData[index_x + 1][index_y].getHitbox().getSize().y / 2
                    and (tileData[index_x][index_y].getState() == TileStatus::Cleared or tileData[index_x][index_y].getState() == TileStatus::Solved))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

bool Game::isPlayerWallHit(int index_x, int index_y, int dir, int speed)
{
    switch (dir)
    {
        case 1: //up
        {
            if (player->getHitbox().getPosition().y - player->getHitbox().getRadius() - (speed * timePerFrame.asSeconds()) > tileData[index_x][index_y].getHitbox().getPosition().y - tileData[index_x][index_y].getHitbox().getSize().y / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().x - player->getHitbox().getRadius() > tileData[index_x][index_y - 1].getHitbox().getPosition().x - tileData[index_x][index_y - 1].getHitbox().getSize().x / 2
                    and player->getHitbox().getPosition().x + player->getHitbox().getRadius() < tileData[index_x][index_y - 1].getHitbox().getPosition().x + tileData[index_x][index_y - 1].getHitbox().getSize().x / 2
                    and (tileData[index_x][index_y].getState() == TileStatus::Cleared or tileData[index_x][index_y].getState() == TileStatus::Marked))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            break;
        }
        case 2: //left
        {
            if (player->getHitbox().getPosition().x - player->getHitbox().getRadius() - (speed * timePerFrame.asSeconds()) > tileData[index_x][index_y].getHitbox().getPosition().x - tileData[index_x][index_y].getHitbox().getSize().x / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().y - player->getHitbox().getRadius() > tileData[index_x - 1][index_y].getHitbox().getPosition().y - tileData[index_x - 1][index_y].getHitbox().getSize().y / 2
                    and player->getHitbox().getPosition().y + player->getHitbox().getRadius() < tileData[index_x - 1][index_y].getHitbox().getPosition().y + tileData[index_x - 1][index_y].getHitbox().getSize().y / 2
                    and (tileData[index_x][index_y].getState() == TileStatus::Cleared or tileData[index_x][index_y].getState() == TileStatus::Marked))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            break;
        }
        case 3: //down
        {
            if (player->getHitbox().getPosition().y + player->getHitbox().getRadius() + (speed * timePerFrame.asSeconds()) < tileData[index_x][index_y].getHitbox().getPosition().y + tileData[index_x][index_y].getHitbox().getSize().y / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().x - player->getHitbox().getRadius() > tileData[index_x][index_y + 1].getHitbox().getPosition().x - tileData[index_x][index_y + 1].getHitbox().getSize().x / 2
                    and player->getHitbox().getPosition().x + player->getHitbox().getRadius() < tileData[index_x][index_y + 1].getHitbox().getPosition().x + tileData[index_x][index_y + 1].getHitbox().getSize().x / 2
                    and (tileData[index_x][index_y].getState() == TileStatus::Cleared or tileData[index_x][index_y].getState() == TileStatus::Marked))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            break;
        }
        case 4: //right
        {
            if (player->getHitbox().getPosition().x + player->getHitbox().getRadius() + (speed * timePerFrame.asSeconds()) < tileData[index_x][index_y].getHitbox().getPosition().x + tileData[index_x][index_y].getHitbox().getSize().x / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().y - player->getHitbox().getRadius() > tileData[index_x + 1][index_y].getHitbox().getPosition().y - tileData[index_x + 1][index_y].getHitbox().getSize().y / 2
                    and player->getHitbox().getPosition().y + player->getHitbox().getRadius() < tileData[index_x + 1][index_y].getHitbox().getPosition().y + tileData[index_x + 1][index_y].getHitbox().getSize().y / 2
                    and (tileData[index_x][index_y].getState() == TileStatus::Cleared or tileData[index_x][index_y].getState() == TileStatus::Marked))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

bool Game::isProjWallHit(Projectile proj, int index_x, int index_y, sf::Vector2f dir, int speed)
{
    if (proj.getHitbox().getPosition().y - proj.getHitbox().getRadius() + (speed * 1 / 100.f * dir.y) < tileData[index_x][index_y].getHitbox().getPosition().y - tileData[index_x][index_y].getHitbox().getSize().y / 2)
    {
        return true;
    }
    if (proj.getHitbox().getPosition().x - proj.getHitbox().getRadius() + (speed * 1 / 100.f * dir.x) < tileData[index_x][index_y].getHitbox().getPosition().x - tileData[index_x][index_y].getHitbox().getSize().x / 2)
    {
        return true;
    }
    if (proj.getHitbox().getPosition().y + proj.getHitbox().getRadius() + (speed * 1 / 100.f * dir.y) > tileData[index_x][index_y].getHitbox().getPosition().y + tileData[index_x][index_y].getHitbox().getSize().y / 2)
    {
        return true;
    }
    if (proj.getHitbox().getPosition().x + proj.getHitbox().getRadius() + (speed * 1 / 100.f * dir.x) > tileData[index_x][index_y].getHitbox().getPosition().x + tileData[index_x][index_y].getHitbox().getSize().x / 2)
    {
        return true;
    }
    return false;
}

bool Game::isPlayerInnerWallHit(int index_x, int index_y, int dir, int speed)
{
    int indx, indy;
    for (int i = 0; i < 20; i++)
    {
        if (tileData[index_x][index_y].getHitbox().getPosition().x - tileData[index_x][index_y].getHitbox().getSize().x / 2 + (tileData[index_x][index_y].getHitbox().getSize().x / 20) * (i + 1) > player->getHitbox().getPosition().x)
        {
            indx = i;
            break;
        }
        if (i == 19)
        {
            indx = 19;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        if (tileData[index_x][index_y].getHitbox().getPosition().y - tileData[index_x][index_y].getHitbox().getSize().y / 2 + (tileData[index_x][index_y].getHitbox().getSize().y / 20) * (i + 1) > player->getHitbox().getPosition().y)
        {
            indy = i;
            break;
        }
        if (i == 19)
        {
            indy = 19;
        }
    }
    switch (dir)
    {
    case 1: //up
    {
        for (int i = 0; i < tileData[index_x][index_y].getWallsToDraw().size(); i++)
        {
            if (indx == tileData[index_x][index_y].getWallsToDraw()[i].x and indy - 1 == tileData[index_x][index_y].getWallsToDraw()[i].y)
            {
                if (tileData[index_x][index_y].getHitbox().getPosition().y - tileData[index_x][index_y].getHitbox().getSize().y / 2 + (tileData[index_x][index_y].getHitbox().getSize().y / 20) * (indy - 1 + 1) > player->getHitbox().getPosition().y - player->getHitbox().getRadius() - (speed * timePerFrame.asSeconds()))
                {
                    return true;
                }
            }
        }
        break;
    }
    case 2: //left
    {
        for (int i = 0; i < tileData[index_x][index_y].getWallsToDraw().size(); i++)
        {
            if (indx - 1 == tileData[index_x][index_y].getWallsToDraw()[i].x and indy == tileData[index_x][index_y].getWallsToDraw()[i].y)
            {
                if (tileData[index_x][index_y].getHitbox().getPosition().x - tileData[index_x][index_y].getHitbox().getSize().x / 2 + (tileData[index_x][index_y].getHitbox().getSize().x / 20) * (indx - 1 + 1) > player->getHitbox().getPosition().x - player->getHitbox().getRadius() - (speed * timePerFrame.asSeconds()))
                {
                    return true;
                }
            }
        }
        break;
    }
    case 3: //down
    {
        for (int i = 0; i < tileData[index_x][index_y].getWallsToDraw().size(); i++)
        {
            if (indx == tileData[index_x][index_y].getWallsToDraw()[i].x and indy + 1 == tileData[index_x][index_y].getWallsToDraw()[i].y)
            {
                if (tileData[index_x][index_y].getHitbox().getPosition().y - tileData[index_x][index_y].getHitbox().getSize().y / 2 + (tileData[index_x][index_y].getHitbox().getSize().y / 20) * (indy + 1) < player->getHitbox().getPosition().y + player->getHitbox().getRadius() + (speed * timePerFrame.asSeconds()))
                {
                    return true;
                }
            }
        }
        break;
    }
    case 4: //right
    {
        for (int i = 0; i < tileData[index_x][index_y].getWallsToDraw().size(); i++)
        {
            if (indx + 1 == tileData[index_x][index_y].getWallsToDraw()[i].x and indy == tileData[index_x][index_y].getWallsToDraw()[i].y)
            {
                if (tileData[index_x][index_y].getHitbox().getPosition().x - tileData[index_x][index_y].getHitbox().getSize().x / 2 + (tileData[index_x][index_y].getHitbox().getSize().x / 20) * (indx + 1) < player->getHitbox().getPosition().x + player->getHitbox().getRadius() + (speed * timePerFrame.asSeconds()))
                {
                    return true;
                }
            }
        }
        break;
    }
    default:
    {
        break;
    }
    }
    return false;
}

bool Game::isMeleeEnemyHit(sf::RectangleShape hitbox, Enemy enemy)
{
    sf::Vector2f dir, center;
    float deg, ctr;
    center = sf::Vector2f(player->getHitbox().getPosition().x, player->getHitbox().getPosition().y);
    dir.x = (enemy.getHitbox().getPosition().x - center.x) / (abs(enemy.getHitbox().getPosition().x - center.x) + abs(enemy.getHitbox().getPosition().y - center.y));
    dir.y = (enemy.getHitbox().getPosition().y - center.y) / (abs(enemy.getHitbox().getPosition().x - center.x) + abs(enemy.getHitbox().getPosition().y - center.y));
    deg = (atan2(dir.y, dir.x) / 3.14) * 180.f + 90;
    if (deg < 0)
    {
        deg = 360 + deg;
    }
    if (abs(hitbox.getRotation() - deg) < 60)
    {
        float dest = sqrt(pow((player->getHitbox().getPosition().x - enemy.getHitbox().getPosition().x), 2) + pow((player->getHitbox().getPosition().y - enemy.getHitbox().getPosition().y), 2));
        if (dest > 1 and dest < player->getHitbox().getRadius() * 3)
        {
            return true;
        }
    }
    return false;
}
