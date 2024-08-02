#include "Game.h"

Game::Game()
	:	window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Death of the last", sf::Style::Fullscreen)
{
    if (sf::VideoMode::getDesktopMode().width > sf::VideoMode::getDesktopMode().height)
    {
        side = sf::VideoMode::getDesktopMode().height / 100;
    }
    else
    {
        side = sf::VideoMode::getDesktopMode().width / 100;
    }
    tileCreated = new bool* [1001];
    for (int i = 0; i < 1001; i++)
    {
        tileCreated[i] = new bool[1001];
        for (int j = 0; j < 1001; j++)
        {
            tileCreated[i][j] = false;
        }
    }
    tileNumOffset = 500;
    timePerFrame = sf::seconds(1 / 60.f);  //100 frames per second
    window.setVerticalSyncEnabled(true);
    camera = window.getView();
    tileData = new Tile* [1001];
    for (int i = 0; i < 1001; i++)
    {
        tileData[i] = new Tile[1001];
    }
    playerSpeed = 500;
    NataSans.loadFromFile("assets/font/Nata_Sans_Typeface/ttf/NataSans-Regular.ttf");
    tileSetBg.loadFromFile("assets/textures/TileSet.png");
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
}

void Game::generateMap()
{
    Tile tile(TileType::Central, sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, side / 2);
    tileCreated[0 + tileNumOffset][0 + tileNumOffset] = true;
    tileData[0 + tileNumOffset][0 + tileNumOffset] = tile;
    loadedTiles.push_back(sf::Vector2i(0 + tileNumOffset, 0 + tileNumOffset));
    srand(time(0));
    generateLevel(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, 1, 0);
    generateLevel(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, 2, 0);
    generateLevel(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, 3, 0);
    generateLevel(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2, 0, 0, 4, 0);
}

void Game::generateLevel(int pos_x, int pos_y, int index_x, int index_y, int dir, int len)
{
    if (index_x > -496 and index_x < 496 and index_y > -496 and index_y < 496 and len < 500)
    {
        switch (dir)
        {
            case 1: //up
            {
                Tile tile(TileType::CorridorV, pos_x, pos_y - side / 2, index_x, index_y - 1, side / 2);
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
                Tile tile2(type2, pos_x, pos_y - side / 2 - side / 2, index_x, index_y - 2, side / 2);
                tileCreated[index_x + tileNumOffset][index_y - 2 + tileNumOffset] = true;
                tileData[index_x + tileNumOffset][index_y - 2 + tileNumOffset] = tile2;
                loadedTiles.push_back(sf::Vector2i(index_x + tileNumOffset, index_y - 2 + tileNumOffset));
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
                            generateLevel(pos_x, pos_y - side / 2 - side / 2, index_x, index_y - 2, 2, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 2: //up
                    {
                        if (!tileCreated[index_x + tileNumOffset][index_y - 4 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y - side / 2 - side / 2, index_x, index_y - 2, 1, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 3: //right
                    {
                        if (!tileCreated[index_x + 2 + tileNumOffset][index_y - 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y - side / 2 - side / 2, index_x, index_y - 2, 4, len + 1);
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
                break;
            }
            case 2: //left
            {
                Tile tile(TileType::CorridorH, pos_x - side / 2, pos_y, index_x - 1, index_y, side / 2);
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
                Tile tile2(type2, pos_x - side / 2 - side / 2, pos_y, index_x - 2, index_y, side / 2);
                tileCreated[index_x - 2 + tileNumOffset][index_y + tileNumOffset] = true;
                tileData[index_x - 2 + tileNumOffset][index_y + tileNumOffset] = tile2;
                loadedTiles.push_back(sf::Vector2i(index_x - 2 + tileNumOffset, index_y + tileNumOffset));
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
                        if (!tileCreated[index_x - 2 + tileNumOffset][index_y + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x - side / 2 - side / 2, pos_y, index_x - 2, index_y, 2, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 2: //up
                    {
                        if (!tileCreated[index_x - 2 + tileNumOffset][index_y - 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x - side / 2 - side / 2, pos_y, index_x - 2, index_y, 1, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 3: //down
                    {
                        if (!tileCreated[index_x - 2 + tileNumOffset][index_y + 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x - side / 2 - side / 2, pos_y, index_x - 2, index_y, 3, len + 1);
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
                break;
            }
            case 3: //down
            {
                Tile tile(TileType::CorridorV, pos_x, pos_y + side / 2, index_x, index_y + 1, side / 2);
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
                Tile tile2(type2, pos_x, pos_y + side / 2 + side / 2, index_x, index_y + 2, side / 2);
                tileCreated[index_x + tileNumOffset][index_y + 2 + tileNumOffset] = true;
                tileData[index_x + tileNumOffset][index_y + 2 + tileNumOffset] = tile2;
                loadedTiles.push_back(sf::Vector2i(index_x + tileNumOffset, index_y + 2 + tileNumOffset));
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
                            generateLevel(pos_x, pos_y + side / 2 + side / 2, index_x, index_y + 2, 2, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 2: //down
                    {
                        if (!tileCreated[index_x + tileNumOffset][index_y + 4 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y + side / 2 + side / 2, index_x, index_y + 2, 1, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 3: //right
                    {
                        if (!tileCreated[index_x + 2 + tileNumOffset][index_y + 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x, pos_y + side / 2 + side / 2, index_x, index_y + 2, 4, len + 1);
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
                break;
            }
            case 4: //right
            {
                Tile tile(TileType::CorridorH, pos_x + side / 2, pos_y, index_x + 1, index_y, side / 2);
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
                Tile tile2(type2, pos_x + side / 2 + side / 2, pos_y, index_x + 2, index_y, side / 2);
                tileCreated[index_x + 2 + tileNumOffset][index_y + tileNumOffset] = true;
                tileData[index_x + 2 + tileNumOffset][index_y + tileNumOffset] = tile2;
                loadedTiles.push_back(sf::Vector2i(index_x + 2 + tileNumOffset, index_y + tileNumOffset));
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
                            generateLevel(pos_x + side / 2 + side / 2, pos_y, index_x + 2, index_y, 2, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 2: //up
                    {
                        if (!tileCreated[index_x + 2 + tileNumOffset][index_y - 2 + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x + side / 2 + side / 2, pos_y, index_x + 2, index_y, 1, len + 1);
                        }
                        counter++;
                        break;
                    }
                    case 3: //right
                    {
                        if (!tileCreated[index_x + 4 + tileNumOffset][index_y + tileNumOffset])
                        {
                            created++;
                            generateLevel(pos_x + side / 2 + side / 2, pos_y, index_x + 2, index_y, 4, len + 1);
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

    command.name = CommandName::TickTiles;
    commandQueue.push_back(command);

    //display always at the end
    command.name = CommandName::Display;
    commandQueue.push_back(command);
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
                                if (abs(player->getIndex().x + tileNumOffset - loadedTiles[j].x) < 500 and abs(player->getIndex().y + tileNumOffset - loadedTiles[j].y) < 500)
                                {
                                    window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getBody());
                                    //window.draw(tileData[loadedTiles[j].x][loadedTiles[j].y].getHitbox());
                                }
                            }
                        }
                    }
                    //draw enemy
                    {
                        
                    }
                    //draw projectiles
                    {

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
                        //std::string str = std::to_string(player->getIndex().x) + " " + std::to_string(player->getIndex().y) + " " + std::to_string(player->getHitbox().getPosition().x - sf::VideoMode::getDesktopMode().width / 2 + side / 4) + " " + std::to_string(player->getHitbox().getPosition().y - side / 2 + side / 4);
                        //text.setString(str);
                        //window.draw(text);
                    }
                    window.display();
                    break;
                }
                case CommandName::SpawnPlayer:
                {
                    player = new Player(commandQueue[i].attribute.int1, commandQueue[i].attribute.int2, commandQueue[i].attribute.int3, commandQueue[i].attribute.int4);
                    break;
                }
                case CommandName::TickTiles:
                {
                    for (int i = -2; i < 3; i++)
                    {
                        for (int j = -2; j < 3; j++)
                        {

                        }
                    }
                    break;
                }
                case CommandName::MoveUp:
                {
                    if (!isPlayerWallCollision(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 1))
                    {
                        player->move(sf::Vector2f(0, (-1) * (playerSpeed) * (timePerFrame.asSeconds())));
                        camera.move(sf::Vector2f(0, (-1) * (playerSpeed) * (timePerFrame.asSeconds())));
                        window.setView(camera);
                        player->updateIndex(side / 2);
                    }
                    break;
                }
                case CommandName::MoveLeft:
                {
                    if (!isPlayerWallCollision(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 2))
                    {
                        player->move(sf::Vector2f((-1) * (playerSpeed) * (timePerFrame.asSeconds()), 0));
                        camera.move(sf::Vector2f((-1) * (playerSpeed) * (timePerFrame.asSeconds()), 0));
                        window.setView(camera);
                        player->updateIndex(side / 2);
                    }
                    break;
                }
                case CommandName::MoveDown:
                {
                    if (!isPlayerWallCollision(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 3))
                    {
                        player->move(sf::Vector2f(0, (playerSpeed) * (timePerFrame.asSeconds())));
                        camera.move(sf::Vector2f(0, (playerSpeed) * (timePerFrame.asSeconds())));
                        window.setView(camera);
                        player->updateIndex(side / 2);
                    }
                    break;
                }
                case CommandName::MoveRight:
                {
                    if (!isPlayerWallCollision(player->getIndex().x + tileNumOffset, player->getIndex().y + tileNumOffset, 4))
                    {
                        player->move(sf::Vector2f((playerSpeed) * (timePerFrame.asSeconds()), 0));
                        camera.move(sf::Vector2f((playerSpeed) * (timePerFrame.asSeconds()), 0));
                        window.setView(camera);
                        player->updateIndex(side / 2);
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
            if (player->getHitbox().getPosition().y - player->getHitbox().getSize().y / 2 > tileData[index_x][index_y].getHitbox().getPosition().y - tileData[index_x][index_y].getHitbox().getSize().y / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().x - player->getHitbox().getSize().x / 2 > tileData[index_x][index_y - 1].getHitbox().getPosition().x - tileData[index_x][index_y - 1].getHitbox().getSize().x / 2
                    and player->getHitbox().getPosition().x + player->getHitbox().getSize().x / 2 < tileData[index_x][index_y - 1].getHitbox().getPosition().x + tileData[index_x][index_y - 1].getHitbox().getSize().x / 2)
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
            if (player->getHitbox().getPosition().x - player->getHitbox().getSize().x / 2 > tileData[index_x][index_y].getHitbox().getPosition().x - tileData[index_x][index_y].getHitbox().getSize().x / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().y - player->getHitbox().getSize().y / 2 > tileData[index_x - 1][index_y].getHitbox().getPosition().y - tileData[index_x - 1][index_y].getHitbox().getSize().y / 2
                    and player->getHitbox().getPosition().y + player->getHitbox().getSize().y / 2 < tileData[index_x - 1][index_y].getHitbox().getPosition().y + tileData[index_x - 1][index_y].getHitbox().getSize().y / 2)
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
            if (player->getHitbox().getPosition().y + player->getHitbox().getSize().y / 2 < tileData[index_x][index_y].getHitbox().getPosition().y + tileData[index_x][index_y].getHitbox().getSize().y / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().x - player->getHitbox().getSize().x / 2 > tileData[index_x][index_y + 1].getHitbox().getPosition().x - tileData[index_x][index_y + 1].getHitbox().getSize().x / 2
                    and player->getHitbox().getPosition().x + player->getHitbox().getSize().x / 2 < tileData[index_x][index_y + 1].getHitbox().getPosition().x + tileData[index_x][index_y + 1].getHitbox().getSize().x / 2)
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
            if (player->getHitbox().getPosition().x + player->getHitbox().getSize().x / 2 < tileData[index_x][index_y].getHitbox().getPosition().x + tileData[index_x][index_y].getHitbox().getSize().x / 2)
            {
                return false;
            }
            else
            {
                if (player->getHitbox().getPosition().y - player->getHitbox().getSize().y / 2 > tileData[index_x + 1][index_y].getHitbox().getPosition().y - tileData[index_x + 1][index_y].getHitbox().getSize().y / 2
                    and player->getHitbox().getPosition().y + player->getHitbox().getSize().y / 2 < tileData[index_x + 1][index_y].getHitbox().getPosition().y + tileData[index_x + 1][index_y].getHitbox().getSize().y / 2)
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
