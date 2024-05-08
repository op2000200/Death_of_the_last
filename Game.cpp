#include "Game.h"
Game::Game()
	//windows
	: window(sf::VideoMode(1920, 1080), "Death of the last", sf::Style::None)
	//fonts
	, fontMM()
	, fontMM2()
	//buttons main menu
	, buttonSM(sf::Vector2f(600, 200), sf::Vector2f(650, 570), sf::Color::Color(60, 60, 60), sf::Color::Color(180, 180, 180), 10.f)
	, buttonAM(sf::Vector2f(600, 200), sf::Vector2f(1300, 570), sf::Color::Color(60, 60, 60), sf::Color::Color(180, 180, 180), 10.f)
	, buttonSettings(sf::Vector2f(600, 200), sf::Vector2f(650, 820), sf::Color::Color(60, 60, 60), sf::Color::Color(180, 180, 180), 10.f)
	, buttonExit(sf::Vector2f(600, 200), sf::Vector2f(1300, 820), sf::Color::Color(60, 60, 60), sf::Color::Color(180, 180, 180), 10.f)
	//buttons arcade mode
	, buttonArcadeModePauseMM(sf::Vector2f(320, 100), sf::Vector2f(800, 490), sf::Color::Color(60, 60, 60), sf::Color::Color(180, 180, 180), 5.f)
	//buttons level up
	, buttonArcadeModeHeal(sf::Vector2f(320, 100), sf::Vector2f(460, 490), sf::Color::Color(60, 60, 60), sf::Color::Color(180, 180, 180), 5.f)
	, buttonArcadeModeUpCastSpeed(sf::Vector2f(320, 100), sf::Vector2f(800, 490), sf::Color::Color(60, 60, 60), sf::Color::Color(180, 180, 180), 5.f)
	, buttonArcadeModeUpSpeed(sf::Vector2f(320, 100), sf::Vector2f(1140, 490), sf::Color::Color(60, 60, 60), sf::Color::Color(180, 180, 180), 5.f)
{
	window.setMouseCursorVisible(false);
	fontMM.loadFromFile("assets/font/Humane-ExtraBold.ttf");
	fontMM2.loadFromFile("assets/font/Humane-Light.ttf");
	state = 0;
	paused = 0;
	cursorTexture.loadFromFile("assets/textures/cursor.png");
	playerTexture = new sf::Texture;
	playerTexture->loadFromFile("assets/textures/player.png");
	enemyTexture = new sf::Texture;
	enemyTexture->loadFromFile("assets/textures/enemy.png");
	bulletTexture = new sf::Texture;
	bulletTexture->loadFromFile("assets/textures/bullet.png");
	bgTexture = new sf::Texture;
	bgTexture->setRepeated(true);
	bgTexture->loadFromFile("assets/textures/bg2.jpg");
	manaTexture = new sf::Texture;
	manaTexture->loadFromFile("assets/textures/manaOrb1.png");
	manaTickCounter = 0;
	playerState = 0;
	for (int i = 0; i < 200; i++)
	{
		inputs[i] = 0;
	}
	enemyCooldown = 0;
	enemyTickCounter = 0;
	enemyCounter = 0;
	bulletCounter = 0;
	castCooldown = 0;
	manaCounter = 0;
	playerDeath = 0;
	levelUp = 0;
}

void Game::run()
{
	while (true)
	{
		if (state == 0) //main menu
		{
			mainMenu();
		}
		if (state == 1) //story mode
		{
			state = 0;
		}
		if (state == 2) //arcade mode
		{
			arcadeMode();
		}
		if (state == 3) //settings
		{
			state = 0;
		}
		if (state == 4) //exit
		{
			window.close();
			break;
		}
	}
}

void Game::render()
{
}

void Game::mainMenu()
{
	sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	sf::Time start, elapsed;
	sf::Clock clock;
	int bufState;
	while (window.isOpen())
	{
		clock.restart();
		bufState = state;
		readInputMM();
		window.clear();
		drawMM();
		window.display();
		if (bufState != state)
		{
			return;
		}
		while (clock.getElapsedTime() < TimePerFrame)
		{
			;
		}

	}
}

void Game::drawMM()
{
	sf::View view = window.getView();
	view.setCenter(1920 / 2, 1080 / 2);
	window.setView(view);
	sf::RectangleShape background;
	background.setPosition(sf::Vector2f(0, 0));
	background.setSize(sf::Vector2f(1920, 1080));
	background.setFillColor(sf::Color::Color(105, 105, 105));
	window.draw(background);
	sf::Text name1;
	name1.setFont(fontMM);
	name1.setString("DEATH OF THE \nLAST");
	name1.setPosition(sf::Vector2f(40, -60));
	name1.setFillColor(sf::Color::Color(120, 120, 120));
	name1.setCharacterSize(500);
	name1.setLetterSpacing(2.f);
	labelButtonSM.setFont(fontMM);
	labelButtonSM.setString("STORY	MODE");
	labelButtonSM.setPosition(buttonSM.getBody().getPosition().x + 25, buttonSM.getBody().getPosition().y - 15);
	labelButtonSM.setFillColor(sf::Color::Color(180, 180, 180));
	labelButtonSM.setCharacterSize(180);
	labelButtonSM.setLetterSpacing(1.5);
	labelButtonAM.setFont(fontMM);
	labelButtonAM.setString("ARCADE  MODE");
	labelButtonAM.setPosition(buttonAM.getBody().getPosition().x + 25, buttonAM.getBody().getPosition().y - 15);
	labelButtonAM.setFillColor(sf::Color::Color(180, 180, 180));
	labelButtonAM.setCharacterSize(180);
	labelButtonAM.setLetterSpacing(1.5);
	labelbuttonSettings.setFont(fontMM);
	labelbuttonSettings.setString("SETTINGS");
	labelbuttonSettings.setPosition(buttonSettings.getBody().getPosition().x + 115, buttonSettings.getBody().getPosition().y - 15);
	labelbuttonSettings.setFillColor(sf::Color::Color(180, 180, 180));
	labelbuttonSettings.setCharacterSize(180);
	labelbuttonSettings.setLetterSpacing(1.5);
	labelbuttonExit.setFont(fontMM);
	labelbuttonExit.setString("EXIT");
	labelbuttonExit.setPosition(buttonExit.getBody().getPosition().x + 220, buttonExit.getBody().getPosition().y - 15);
	labelbuttonExit.setFillColor(sf::Color::Color(180, 180, 180));
	labelbuttonExit.setCharacterSize(180);
	labelbuttonExit.setLetterSpacing(1.5);
	sf::Sprite cursor;
	cursor.setTexture(cursorTexture);
	cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition().x-5, sf::Mouse::getPosition().y-5));
	cursor.setScale(sf::Vector2f(5, 5));
	window.draw(name1);
	//window.draw(buttonSM.getBody());
	//window.draw(labelButtonSM);
	window.draw(buttonAM.getBody());
	window.draw(labelButtonAM);
	//window.draw(buttonSettings.getBody());
	//window.draw(labelbuttonSettings);
	window.draw(buttonExit.getBody());
	window.draw(labelbuttonExit);
	window.draw(cursor);
}

void Game::updateMM()
{

}

void Game::readInputMM()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		//if (event.type == sf::Event::KeyPressed)
		//{
		//	if (event.key.code == sf::Keyboard::Escape)
		//	{
		//		window.close();
		//	}
		//}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			//story mode pressed
			if (event.mouseButton.button == sf::Mouse::Left and (sf::Mouse::getPosition().x > 650 and sf::Mouse::getPosition().x < 1250 and sf::Mouse::getPosition().y > 570 and sf::Mouse::getPosition().y < 770))
			{
				state = 1;
			}
			//arcade pressed
			if (event.mouseButton.button == sf::Mouse::Left and (sf::Mouse::getPosition().x > 1300 and sf::Mouse::getPosition().x < 1900 and sf::Mouse::getPosition().y > 570 and sf::Mouse::getPosition().y < 770))
			{
				state = 2;
			}
			//settings pressed
			if (event.mouseButton.button == sf::Mouse::Left and (sf::Mouse::getPosition().x > 650 and sf::Mouse::getPosition().x < 1250 and sf::Mouse::getPosition().y > 820 and sf::Mouse::getPosition().y < 1020))
			{
				state = 3;
			}
			//exit pressed
			if (event.mouseButton.button == sf::Mouse::Left and (sf::Mouse::getPosition().x > 1300 and sf::Mouse::getPosition().x < 1900 and sf::Mouse::getPosition().y > 820 and sf::Mouse::getPosition().y < 1020))
			{
				state = 4;
			}
		}
	}
}

void Game::arcadeMode()
{
	if (playerState == 0)
	{
		player = new Player(playerTexture);
		playerState = 1;
		enemyCooldown = 0;
		enemyTickCounter = 0;
		enemyCounter = 0;
		bulletCounter = 0;
		castCooldown = 0;
		manaCounter = 0;
		playerDeath = 0;
		manaTickCounter = 0;
		timer.restart();
		enemyBuffer.clear();
		manaBuffer.clear();
		bulletBuffer.clear();
	}
	while (true)
	{
		if (playerDeath == 1)
		{
			arcadeModeDeath();
			return;
		}
		else
		{
			if (levelUp == 1)
			{
				arcadeModeLevelUp(player);
				return;
			}
			else
			{
				if (paused == 0)
				{
					arcadeModeRun(player);
					return;
				}
				if (paused == 1)
				{
					arcadeModePause();
					return;
				}
			}
		}
	}
}

void Game::arcadeModeRun(Player* player)
{
	sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	int bufState, bufPaused, bufDeath, bufLevel;
	while (window.isOpen())
	{
		clock.restart();
		bufState = state;
		bufPaused = paused;
		bufDeath = playerDeath;
		bufLevel = player[0].getLevel();

		readInputAM();//checking what stupid human do

		updatePlayer(TimePerFrame, player);
		updateMana(TimePerFrame, player);
		updateEnemies(TimePerFrame, player);
		updateBullets(TimePerFrame, player);
		updateCollision(TimePerFrame, player);
		updateLevel(TimePerFrame, player);
		collectFarObjects(TimePerFrame, player);

		window.clear();
		arcadeModeRunDraw(player);
		window.display();


		if (bufPaused != paused)
		{
			pausedScreen.create(window.getSize().x, window.getSize().y);
			pausedScreen.update(window);
			return;
		}
		if (bufState != state)
		{
			return;
		}
		if (bufDeath != playerDeath)
		{
			return;
		}
		if (bufLevel != player[0].getLevel())
		{
			pausedScreen.create(window.getSize().x, window.getSize().y);
			pausedScreen.update(window);
			levelUp = 1;
			return;
		}

		while (clock.getElapsedTime() < TimePerFrame)
		{
			;
		}
	}
}

void Game::arcadeModeRunUpdate()
{

}

void Game::arcadeModePause()
{
	sf::Sprite prevFrame(pausedScreen);
	sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	int bufState, bufPaused;
	while (window.isOpen())
	{
		bufState = state;
		bufPaused = paused;
		readInputAM();
		arcadeModePauseUpdate();
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			window.clear();
			timeSinceLastUpdate -= TimePerFrame;
			arcadeModePauseDraw(prevFrame);
			window.display();
		}
		if (bufPaused != paused)
		{
			return;
		}
		if (bufState != state)
		{
			return;
		}
	}
}

void Game::arcadeModePauseUpdate()
{
	if (inputs[5] == 1 and (sf::Mouse::getPosition().x > 800 and sf::Mouse::getPosition().x < 1110 and sf::Mouse::getPosition().y > 490 and sf::Mouse::getPosition().y < 580))
	{
		state = 0;
		paused = 0;
		playerState = 0;
	}
}

void Game::readInputAM()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::LostFocus)
		{
			paused = 1;
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				if (paused == 1)
				{
					paused = 0;
				}
				else
				{
					paused = 1;
				}
			}
			if (event.key.code == sf::Keyboard::W)
			{
				inputs[1] = 1;
			}
			if (event.key.code == sf::Keyboard::A)
			{
				inputs[2] = 1;
			}
			if (event.key.code == sf::Keyboard::S)
			{
				inputs[3] = 1;
			}
			if (event.key.code == sf::Keyboard::D)
			{
				inputs[4] = 1;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				inputs[5] = 1;
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				inputs[1] = 0;
			}
			if (event.key.code == sf::Keyboard::A)
			{
				inputs[2] = 0;
			}
			if (event.key.code == sf::Keyboard::S)
			{
				inputs[3] = 0;
			}
			if (event.key.code == sf::Keyboard::D)
			{
				inputs[4] = 0;
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				inputs[5] = 0;
			}
		}
	}
}

void Game::arcadeModeRunDraw(Player* player)
{

	sf::View view = window.getView();
	view.setCenter(player[0].getSprite().getPosition().x + 30, player[0].getSprite().getPosition().y + 30);
	window.setView(view);
	

	sf::Sprite bg(*bgTexture, sf::IntRect(0, 0, 2000000, 2000000));
	bg.setScale(sf::Vector2f(10.f, 10.f));
	bg.setPosition(sf::Vector2f(-1000000, -1000000));

	//background
	window.draw(bg);

	//draw mana orbs
	for (int i = 0; i < manaCounter; i++)
	{
		window.draw(manaBuffer[i].getSprite());
	}
	
	//draw the player
	window.draw(player[0].getSprite());



	//draw the enemies
	for (int i = 0; i < enemyCounter; i++)
	{
		window.draw(enemyBuffer[i].getSprite());
	}

	//draw bullets
	for (int i = 0; i < bulletCounter; i++)
	{
		window.draw(bulletBuffer[i].getSprite());
	}

	//draw hud
	sf::RectangleShape healthBarOut(sf::Vector2f(200, 20));
	healthBarOut.setPosition(view.getCenter().x+700,view.getCenter().y + 300);
	healthBarOut.setFillColor(sf::Color(143, 188, 143, 0));
	healthBarOut.setOutlineColor(sf::Color::Black);
	healthBarOut.setOutlineThickness(5.f);
	sf::RectangleShape expBarOut(sf::Vector2f(200, 20));
	expBarOut.setPosition(view.getCenter().x + 700, view.getCenter().y + 340);
	expBarOut.setFillColor(sf::Color(143, 188, 143, 0));
	expBarOut.setOutlineColor(sf::Color::Black);
	expBarOut.setOutlineThickness(5.f);
	sf::RectangleShape healthBarFill(sf::Vector2f(200*(player[0].getHealth()/100.f), 20));
	healthBarFill.setPosition(view.getCenter().x + 700, view.getCenter().y + 300);
	healthBarFill.setFillColor(sf::Color::Red);
	sf::RectangleShape expBarFill(sf::Vector2f(200*(static_cast<float>(player[0].getExp())/player[0].getExpCap()), 20));
	expBarFill.setPosition(view.getCenter().x + 700, view.getCenter().y + 340);
	expBarFill.setFillColor(sf::Color::Blue);
	window.draw(healthBarFill);
	window.draw(expBarFill);
	window.draw(healthBarOut);
	window.draw(expBarOut);

	//draw text
	labelStatistic.setFont(fontMM2);
	std::string stat;
	stat += "Timer: ";
	stat += std::to_string(timer.getElapsedTime().asSeconds());
	stat += "\n";
	stat += "Coord: ";
	stat +=	std::to_string(player[0].getSprite().getPosition().x);
	stat += " ";
	stat += std::to_string(player[0].getSprite().getPosition().y);
	stat += "\n";
	stat += "Level: ";
	stat += std::to_string(player[0].getLevel());
	stat += "\n";
	stat += "Exp: ";
	stat += std::to_string(player[0].getExp());
	stat += " \\ ";
	stat += std::to_string(player[0].getExpCap());
	stat += "\n";
	stat += "Health: ";
	stat += std::to_string(player[0].getHealth());
	stat += " \\ 100";
	stat += "\n";
	stat += "Speed: ";
	stat += std::to_string(player[0].getSpeed());
	stat += "\n";
	stat += "Cast cooldown: ";
	stat += std::to_string(player[0].getCastSpeed());
	stat += "\n";
	labelStatistic.setString(stat);
	labelStatistic.setPosition(sf::Vector2f(view.getCenter().x-(1910/2), view.getCenter().y-(1070/2)));
	labelStatistic.setFillColor(sf::Color::White);
	labelStatistic.setCharacterSize(30);
	labelStatistic.setLetterSpacing(1.5);
	window.draw(labelStatistic);

	////cursor
	//window.draw(cursor);
}

void Game::arcadeModePauseDraw(sf::Sprite prevFrame)
{
	sf::View view = window.getView();
	view.setCenter(1920/2,1080/2);
	window.setView(view);
	window.draw(prevFrame);
	sf::RectangleShape buf(sf::Vector2f(1920, 1080));
	buf.setPosition(0, 0);
	buf.setFillColor(sf::Color(0, 0, 0, 200));
	labelbuttonArcadeModePauseMM.setFont(fontMM2);
	labelbuttonArcadeModePauseMM.setString("BACK TO MAIN MENU");
	labelbuttonArcadeModePauseMM.setPosition(buttonArcadeModePauseMM.getBody().getPosition().x + 25, buttonArcadeModePauseMM.getBody().getPosition().y - 15);
	labelbuttonArcadeModePauseMM.setFillColor(sf::Color(180, 180, 180));
	labelbuttonArcadeModePauseMM.setCharacterSize(90);
	labelbuttonArcadeModePauseMM.setLetterSpacing(1.5);

	sf::Sprite cursor;
	cursor.setTexture(cursorTexture);
	cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition().x - 5, sf::Mouse::getPosition().y - 5));
	cursor.setScale(sf::Vector2f(5, 5));

	window.draw(buf);
	window.draw(buttonArcadeModePauseMM.getBody());
	window.draw(labelbuttonArcadeModePauseMM);
	window.draw(cursor);
}

void Game::updatePlayer(sf::Time elapsedTime, Player* player)
{
	float del = elapsedTime.asSeconds();
	sf::Vector2f tmp;
	if (inputs[1] == 1 and inputs[2] == 0 and inputs[3] == 0 and inputs[4] == 0 or inputs[1] == 1 and inputs[2] == 1 and inputs[3] == 0 and inputs[4] == 1)
	{
		tmp = player[0].getSprite().getPosition();
		tmp.y = tmp.y - player[0].getSpeed() * del;
		player[0].setPos(tmp);
		//std::con << "up" << std::endl;
	}
	if (inputs[1] == 1 and inputs[2] == 0 and inputs[3] == 0 and inputs[4] == 1)
	{
		tmp = player[0].getSprite().getPosition();
		tmp.y = tmp.y - player[0].getSpeed() * del;
		tmp.x = tmp.x + player[0].getSpeed() * del;
		player[0].setPos(tmp);
		//std::cout << "up+r" << std::endl;
	}
	if (inputs[1] == 0 and inputs[2] == 0 and inputs[3] == 0 and inputs[4] == 1 or inputs[1] == 1 and inputs[2] == 0 and inputs[3] == 1 and inputs[4] == 1)
	{
		tmp = player[0].getSprite().getPosition();
		tmp.x = tmp.x + player[0].getSpeed() * del;
		player[0].setPos(tmp);
		//std::cout << "r" << std::endl;
	}
	if (inputs[1] == 0 and inputs[2] == 0 and inputs[3] == 1 and inputs[4] == 1)
	{
		tmp = player[0].getSprite().getPosition();
		tmp.y = tmp.y + player[0].getSpeed() * del;
		tmp.x = tmp.x + player[0].getSpeed() * del;
		player[0].setPos(tmp);
		//std::cout << "down+r" << std::endl;
	}
	if (inputs[1] == 0 and inputs[2] == 0 and inputs[3] == 1 and inputs[4] == 0 or inputs[1] == 0 and inputs[2] == 1 and inputs[3] == 1 and inputs[4] == 1)
	{
		tmp = player[0].getSprite().getPosition();
		tmp.y = tmp.y + player[0].getSpeed() * del;
		player[0].setPos(tmp);
		//std::cout << "down" << std::endl;
	}
	if (inputs[1] == 0 and inputs[2] == 1 and inputs[3] == 1 and inputs[4] == 0)
	{
		tmp = player[0].getSprite().getPosition();
		tmp.y = tmp.y + player[0].getSpeed() * del;
		tmp.x = tmp.x - player[0].getSpeed() * del;
		player[0].setPos(tmp);
		//std::cout << "down+l" << std::endl;
	}
	if (inputs[1] == 0 and inputs[2] == 1 and inputs[3] == 0 and inputs[4] == 0 or inputs[1] == 1 and inputs[2] == 1 and inputs[3] == 1 and inputs[4] == 0)
	{
		tmp = player[0].getSprite().getPosition();
		tmp.x = tmp.x - player[0].getSpeed() * del;
		player[0].setPos(tmp);
		//std::cout << "l" << std::endl;
	}
	if (inputs[1] == 1 and inputs[2] == 1 and inputs[3] == 0 and inputs[4] == 0)
	{
		tmp = player[0].getSprite().getPosition();
		tmp.y = tmp.y - player[0].getSpeed() * del;
		tmp.x = tmp.x - player[0].getSpeed() * del;
		player[0].setPos(tmp);
		//std::cout << "up+l" << std::endl;
	}
}

void Game::updateMana(sf::Time elapsedTime, Player* player)
{
	if (manaTickCounter > 144)
		manaTickCounter = 0;
	srand(time(0) * manaTickCounter);
	manaTickCounter++;
	sf::Vector2f posPlayer, posMana;
	int dist;
	posPlayer = player[0].getSprite().getPosition();
	posMana.x = -3000 + posPlayer.x + rand() % 6000;
	posMana.y = -3000 + posPlayer.y + rand() % 6000;
	dist = sqrt(pow(posPlayer.x - posMana.x, 2) + pow(posPlayer.y - posMana.y, 2));
	if (dist > 2000 and manaCounter < 2000)
	{
		Mana mana(posMana, manaTexture);
		manaBuffer.push_back(mana);
		manaCounter++;
	}
}

void Game::updateBullets(sf::Time elapsedTime, Player* player)
{
	castCooldown++;
	int* distBuffer = new int[enemyCounter];
	for (int i = 0; i < enemyCounter; i++)
	{
		sf::Vector2f posPlayer, posEnemy;
		int dist;
		posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 70, player[0].getSprite().getPosition().y + 15);
		posEnemy = sf::Vector2f(enemyBuffer[i].getSprite().getPosition().x + 20, enemyBuffer[i].getSprite().getPosition().y + 20);
		dist = sqrt(pow(posPlayer.x - posEnemy.x, 2) + pow(posPlayer.y - posEnemy.y, 2));
		distBuffer[i] = dist;
		//if (dist < 300 and castCooldown > player[0].getCastSpeed())
		//{
		//	castCooldown = 0;
		//	Bullet bullet(posPlayer, bulletTexture);
		//	bullet.setDir(sf::Vector2f(
		//		(posEnemy.x - posPlayer.x) / (std::abs(posEnemy.x - posPlayer.x) + std::abs(posEnemy.y - posPlayer.y)),
		//		(posEnemy.y - posPlayer.y) / (std::abs(posEnemy.x - posPlayer.x) + std::abs(posEnemy.y - posPlayer.y))
		//	));
		//	bulletBuffer.push_back(bullet);
		//	bulletCounter++;
		//}
	}
	int dist = 3000, num = 0;
	for (int i = 0; i < enemyCounter; i++)
	{
		if (dist > distBuffer[i])
		{
			num = i;
			dist = distBuffer[i];
		}

		//if (dist < 300 and castCooldown > player[0].getCastSpeed())
		//{
		//	castCooldown = 0;
		//	Bullet bullet(posPlayer, bulletTexture);
		//	bullet.setDir(sf::Vector2f(
		//		(posEnemy.x - posPlayer.x) / (std::abs(posEnemy.x - posPlayer.x) + std::abs(posEnemy.y - posPlayer.y)),
		//		(posEnemy.y - posPlayer.y) / (std::abs(posEnemy.x - posPlayer.x) + std::abs(posEnemy.y - posPlayer.y))
		//	));
		//	bulletBuffer.push_back(bullet);
		//	bulletCounter++;
		//}
	}
	if (dist < 300 and castCooldown > player[0].getCastSpeed())
	{
		castCooldown = 0;
		Bullet bullet(sf::Vector2f(player[0].getSprite().getPosition().x + 70, player[0].getSprite().getPosition().y + 15), bulletTexture);
		bullet.setDir(sf::Vector2f(
			(enemyBuffer[num].getSprite().getPosition().x - player[0].getSprite().getPosition().x - 50) / (std::abs(enemyBuffer[num].getSprite().getPosition().x - player[0].getSprite().getPosition().x - 50) + std::abs(enemyBuffer[num].getSprite().getPosition().y - player[0].getSprite().getPosition().y + 5)),
			(enemyBuffer[num].getSprite().getPosition().y - player[0].getSprite().getPosition().y + 5) / (std::abs(enemyBuffer[num].getSprite().getPosition().x - player[0].getSprite().getPosition().x - 50) + std::abs(enemyBuffer[num].getSprite().getPosition().y - player[0].getSprite().getPosition().y + 5))
		));
		bulletBuffer.push_back(bullet);
		bulletCounter++;
	}

	for (int i = 0; i < bulletCounter; i++)
	{
		sf::Vector2f dir;
		int buf;
		dir = bulletBuffer[i].getDir();
		bulletBuffer[i].setPos(sf::Vector2f(
			bulletBuffer[i].getSprite().getPosition().x + bulletBuffer[i].getSpeed() * elapsedTime.asSeconds() * dir.x,
			bulletBuffer[i].getSprite().getPosition().y + bulletBuffer[i].getSpeed() * elapsedTime.asSeconds() * dir.y
		));
		buf = bulletBuffer[i].getHealth();
		buf--;
		if (buf < 0)
		{
			bulletBuffer.erase(bulletBuffer.begin() + i);
			bulletCounter--;
		}
		else
		{
			bulletBuffer[i].setHealth(buf);
		}
	}
}

void Game::updateEnemies(sf::Time elapsedTime, Player* player)
{
	enemyCooldown++;
	if (enemyTickCounter > 144)
		enemyTickCounter = 0;
	srand(time(0) * enemyTickCounter);
	enemyTickCounter++;
	sf::Vector2f posPlayer, posEnemy;
	int dist;
	posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
	posEnemy.x = -2000 + posPlayer.x + rand() % 4000;
	posEnemy.y = -2000 + posPlayer.y + rand() % 4000;
	dist = sqrt(pow(posPlayer.x - posEnemy.x,2) + pow(posPlayer.y - posEnemy.y,2));
	if (dist > 1000 and enemyCooldown > 50 and enemyCounter < 1000)
	{
		Enemy enemy(enemyTexture, posEnemy);
		enemyBuffer.push_back(enemy);
		enemyCounter++;
		enemyCooldown = 0;
	}
	for (int i = 0; i < enemyCounter; i++)
	{
		posEnemy = enemyBuffer[i].getSprite().getPosition();
		posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
		enemyBuffer[i].setPos(sf::Vector2f(
			posEnemy.x + enemyBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((posPlayer.x - 20 - posEnemy.x) / ((std::abs(posPlayer.x - 20 - posEnemy.x) + std::abs(posPlayer.y - 20 - posEnemy.y))))),
			posEnemy.y + enemyBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((posPlayer.y - 20 - posEnemy.y) / ((std::abs(posPlayer.x - 20 - posEnemy.x) + std::abs(posPlayer.y - 20 - posEnemy.y)))))
		));
	}
}
	
void Game::updateCollision(sf::Time elapsedTime, Player* player)
{
	for (int i = 0; i < bulletCounter; i++)
	{
		for (int j = 0; j < enemyCounter; j++)
		{
			if (abs(bulletBuffer[i].getSprite().getPosition().x - enemyBuffer[j].getSprite().getPosition().x - 10) < 20 and abs(bulletBuffer[i].getSprite().getPosition().y - enemyBuffer[j].getSprite().getPosition().y - 10) < 20)
			{
				bulletBuffer.erase(bulletBuffer.begin() + i);
				enemyBuffer.erase(enemyBuffer.begin() + j);
				bulletCounter--;
				enemyCounter--;
				player[0].setExp(player[0].getExp() + 10);
				break;
			}
		}
	}
	for (int j = 0; j < enemyCounter; j++)
	{
		if (abs(player[0].getSprite().getPosition().x + 25 - enemyBuffer[j].getSprite().getPosition().x) < 30 and abs(player[0].getSprite().getPosition().y + 40 - enemyBuffer[j].getSprite().getPosition().y) < 40)
		{
			enemyBuffer.erase(enemyBuffer.begin() + j);
			enemyCounter--;
			player[0].setExp(player[0].getExp() + 10);
			player[0].setHealth(player[0].getHealth() - 10);
			break;
		}
	}
	for (int i = 0; i < manaCounter; i++)
	{
		if (abs(player[0].getSprite().getPosition().x + 35 - manaBuffer[i].getSprite().getPosition().x) < 30 and abs(player[0].getSprite().getPosition().y + 50 - manaBuffer[i].getSprite().getPosition().y) < 40)
		{
			manaBuffer.erase(manaBuffer.begin() + i);
			manaCounter--;
			player[0].setExp(player[0].getExp() + manaBuffer[i].getValue());
			break;
		}
	}
	if (player[0].getHealth() < 1)
	{
		playerDeath = 1; //die screen
	}
}

void Game::updateLevel(sf::Time elapsedTime, Player* player)
{
	if (player[0].getExp() >= player[0].getExpCap())
	{
		player[0].setExp(player[0].getExp() - player[0].getExpCap());
		player[0].setExpCap(player[0].getExpCap() * 1.1);
		player[0].setLevel(player[0].getLevel() + 1);
	}
}

void Game::collectFarObjects(sf::Time elapsedTime, Player* player)
{
	for (int i = 0; i < enemyCounter; i++)
	{
		sf::Vector2f posPlayer, posEnemy;
		int dist;
		posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
		posEnemy = enemyBuffer[i].getSprite().getPosition() + sf::Vector2f(20,20);
		dist = sqrt(pow(posPlayer.x - posEnemy.x, 2) + pow(posPlayer.y - posEnemy.y, 2));
		if (dist > 4000)
		{
			enemyBuffer.erase(enemyBuffer.begin() + i);
			enemyCounter--;
			i--;
		}
	}
	for (int i = 0; i < manaCounter; i++)
	{
		sf::Vector2f posPlayer, posMana;
		int dist;
		posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
		posMana = manaBuffer[i].getSprite().getPosition() + sf::Vector2f(20, 20);
		dist = sqrt(pow(posPlayer.x - posMana.x, 2) + pow(posPlayer.y - posMana.y, 2));
		if (dist > 4000)
		{
			manaBuffer.erase(manaBuffer.begin() + i);
			manaCounter--;
			i--;
		}
	}
}

void Game::arcadeModeDeath()
{
	sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	sf::Clock clock;

	std::string time = std::to_string(timer.getElapsedTime().asSeconds());
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	int bufState;
	while (window.isOpen())
	{
		bufState = state;
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		readInputAM();//checking what stupid human do
		if (inputs[5] == 1 and (sf::Mouse::getPosition().x > 800 and sf::Mouse::getPosition().x < 1110 and sf::Mouse::getPosition().y > 490 and sf::Mouse::getPosition().y < 580))
		{
			state = 0;
			playerState = 0;
			playerDeath = 0;
		}
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			window.clear();
			arcadeModeDeathDraw(time);
			window.display();
		}
		if (bufState != state)
		{
			return;
		}
	}
}

void Game::arcadeModeDeathDraw(std::string time)
{
	sf::View view = window.getView();
	view.setCenter(1920 / 2, 1080 / 2);
	window.setView(view);
	sf::RectangleShape buf(sf::Vector2f(1920, 1080));
	buf.setPosition(0, 0);
	buf.setFillColor(sf::Color(0, 0, 0, 200));
	labelbuttonArcadeModePauseMM.setFont(fontMM2);
	labelbuttonArcadeModePauseMM.setString("BACK TO MAIN MENU");
	labelbuttonArcadeModePauseMM.setPosition(buttonArcadeModePauseMM.getBody().getPosition().x + 25, buttonArcadeModePauseMM.getBody().getPosition().y - 15);
	labelbuttonArcadeModePauseMM.setFillColor(sf::Color(180, 180, 180));
	labelbuttonArcadeModePauseMM.setCharacterSize(90);
	labelbuttonArcadeModePauseMM.setLetterSpacing(1.5);

	sf::Sprite cursor;
	cursor.setTexture(cursorTexture);
	cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition().x - 5, sf::Mouse::getPosition().y - 5));
	cursor.setScale(sf::Vector2f(5, 5));

	window.draw(buf);
	window.draw(buttonArcadeModePauseMM.getBody());
	window.draw(labelbuttonArcadeModePauseMM);

	labelStatistic.setString(time);
	labelStatistic.setPosition(sf::Vector2f(820, 200));
	labelStatistic.setFillColor(sf::Color::White);
	labelStatistic.setCharacterSize(150);
	labelStatistic.setLetterSpacing(1.5);
	window.draw(labelStatistic);

	window.draw(cursor);
}

void Game::arcadeModeLevelUp(Player* player)
{
	sf::Sprite prevFrame(pausedScreen);
	sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	int bufState;
	while (window.isOpen())
	{
		bufState = levelUp;
		readInputAM();
		arcadeModeLevelUpUpdate(TimePerFrame, player);
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			window.clear();
			timeSinceLastUpdate -= TimePerFrame;
			arcadeModeLevelUpDraw(prevFrame);
			window.display();
		}
		if (bufState != levelUp)
		{
			return;
		}
	}
}

void Game::arcadeModeLevelUpDraw(sf::Sprite prevFrame)
{
	sf::View view = window.getView();
	view.setCenter(1920 / 2, 1080 / 2);
	window.setView(view);
	window.draw(prevFrame);
	sf::RectangleShape buf(sf::Vector2f(1920, 1080));
	buf.setPosition(0, 0);
	buf.setFillColor(sf::Color(0, 0, 0, 200));

	sf::Sprite cursor;
	cursor.setTexture(cursorTexture);
	cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition().x - 5, sf::Mouse::getPosition().y - 5));
	cursor.setScale(sf::Vector2f(5, 5));

	labelbuttonArcadeModeUpCastSpeed.setFont(fontMM2);
	labelbuttonArcadeModeUpCastSpeed.setString("UP CAST SPEED");
	labelbuttonArcadeModeUpCastSpeed.setPosition(buttonArcadeModeUpCastSpeed.getBody().getPosition().x + 25, buttonArcadeModePauseMM.getBody().getPosition().y - 15);
	labelbuttonArcadeModeUpCastSpeed.setFillColor(sf::Color(180, 180, 180));
	labelbuttonArcadeModeUpCastSpeed.setCharacterSize(90);
	labelbuttonArcadeModeUpCastSpeed.setLetterSpacing(1.5);

	labelbuttonArcadeModeUpSpeed.setFont(fontMM2);
	labelbuttonArcadeModeUpSpeed.setString("UP PLAYER SPEED");
	labelbuttonArcadeModeUpSpeed.setPosition(buttonArcadeModeUpSpeed.getBody().getPosition().x + 25, buttonArcadeModePauseMM.getBody().getPosition().y - 15);
	labelbuttonArcadeModeUpSpeed.setFillColor(sf::Color(180, 180, 180));
	labelbuttonArcadeModeUpSpeed.setCharacterSize(90);
	labelbuttonArcadeModeUpSpeed.setLetterSpacing(1.5);

	labelbuttonArcadeModeHeal.setFont(fontMM2);
	labelbuttonArcadeModeHeal.setString("HEAL");
	labelbuttonArcadeModeHeal.setPosition(buttonArcadeModeHeal.getBody().getPosition().x + 25, buttonArcadeModePauseMM.getBody().getPosition().y - 15);
	labelbuttonArcadeModeHeal.setFillColor(sf::Color(180, 180, 180));
	labelbuttonArcadeModeHeal.setCharacterSize(90);
	labelbuttonArcadeModeHeal.setLetterSpacing(1.5);

	window.draw(buf);
	window.draw(buttonArcadeModeUpSpeed.getBody());
	window.draw(labelbuttonArcadeModeUpSpeed);
	if (player[0].getCastSpeed() > 5)
	{
		window.draw(buttonArcadeModeUpCastSpeed.getBody());
		window.draw(labelbuttonArcadeModeUpCastSpeed);
	}
	if (player[0].getHealth() < 100)
	{
		window.draw(buttonArcadeModeHeal.getBody());
		window.draw(labelbuttonArcadeModeHeal);
	}
	window.draw(cursor);
}

void Game::arcadeModeLevelUpUpdate(sf::Time elapsedTime, Player* player)
{
	if (inputs[5] == 1)
	{
		if (sf::Mouse::getPosition().x > 800 and sf::Mouse::getPosition().x < 1110 and sf::Mouse::getPosition().y > 490 and sf::Mouse::getPosition().y < 580) //up cast speed
		{
			if (player[0].getCastSpeed() > 5)
			{
				player[0].setCastSpeed(player[0].getCastSpeed() - 10);
				levelUp = 0;
			}
		}
		if (sf::Mouse::getPosition().x > 460 and sf::Mouse::getPosition().x < 740 and sf::Mouse::getPosition().y > 490 and sf::Mouse::getPosition().y < 580) //heal
		{
			if (player[0].getHealth() < 100)
			{
				player[0].setHealth(player[0].getHealth() + 10);
				levelUp = 0;
			}
		}
		if (sf::Mouse::getPosition().x > 1140 and sf::Mouse::getPosition().x < 1450 and sf::Mouse::getPosition().y > 490 and sf::Mouse::getPosition().y < 580) //up speed
		{
			player[0].setSpeed(player[0].getSpeed() + 10);
			levelUp = 0;
		}
		
	}
}