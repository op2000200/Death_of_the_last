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
	BasicMissleColdTexture = new sf::Texture;
	BasicMissleColdTexture->loadFromFile("assets/textures/basicCold.png");
	BasicMissleColdTexture->setSmooth(true);
	StandartEnemyFireTexture = new sf::Texture;
	StandartEnemyFireTexture->loadFromFile("assets/textures/standartEnemyFire.png");
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
	settingState = 0; //0 = video 1 = audio 2 = gameplay
	basicMissleColdCooldown = 0;
	basicMissleColdCounter = 0;
	enemyCooldownVar = 300;
	enemyCountVar = 100;
	manaCountVar = 20;
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
			//settings();
		}
		if (state == 4) //exit
		{
			window.close();
			break;
		}
	}
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
	window.draw(buttonSettings.getBody());
	window.draw(labelbuttonSettings);
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

void Game::settings()
{
	sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	int bufState;
	CheckBox* checkBox = new CheckBox(sf::Vector2f(1200, 620), sf::Vector2f(100, 100));
	while (window.isOpen())
	{
		bufState = state;

		settingsReadInput();//checking what stupid human do
		settingsUpdate(checkBox[0]);
		window.clear();
		settingsDraw(checkBox[0]);
		window.display();
		if (bufState != state)
		{
			return;
		}
	}
}

void Game::settingsReadInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				inputs[0] = 1;
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				inputs[0] = 0;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				inputs[5] = 1;
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

void Game::settingsDraw(CheckBox checkBox)
{
	sf::View view = window.getView();
	view.setCenter(1920 / 2, 1080 / 2);
	window.setView(view);
	sf::RectangleShape background;
	background.setPosition(sf::Vector2f(0, 0));
	background.setSize(sf::Vector2f(1920, 1080));
	background.setFillColor(sf::Color::Color(105, 105, 105));

	sf::RectangleShape* buttonsSettings = new sf::RectangleShape[4];
	buttonsSettings[0].setPosition(sf::Vector2f(20, 20));
	buttonsSettings[0].setSize(sf::Vector2f(300, 80));
	buttonsSettings[0].setFillColor(sf::Color(60,60,60));
	buttonsSettings[0].setOutlineColor(sf::Color(180,180,180));
	buttonsSettings[0].setOutlineThickness(5.f);
	buttonsSettings[1].setPosition(sf::Vector2f(540, 20));
	buttonsSettings[1].setSize(sf::Vector2f(300, 80));
	buttonsSettings[1].setFillColor(sf::Color(60, 60, 60));
	buttonsSettings[1].setOutlineColor(sf::Color(180, 180, 180));
	buttonsSettings[1].setOutlineThickness(5.f);
	buttonsSettings[2].setPosition(sf::Vector2f(860, 20));
	buttonsSettings[2].setSize(sf::Vector2f(300, 80));
	buttonsSettings[2].setFillColor(sf::Color(60, 60, 60));
	buttonsSettings[2].setOutlineColor(sf::Color(180, 180, 180));
	buttonsSettings[2].setOutlineThickness(5.f);
	buttonsSettings[3].setPosition(sf::Vector2f(1180, 20));
	buttonsSettings[3].setSize(sf::Vector2f(300, 80));
	buttonsSettings[3].setFillColor(sf::Color(60, 60, 60));
	buttonsSettings[3].setOutlineColor(sf::Color(180, 180, 180));
	buttonsSettings[3].setOutlineThickness(5.f);
	sf::Text* labelButtonsSettings = new sf::Text[4];
	labelButtonsSettings[0].setFont(fontMM2);
	labelButtonsSettings[0].setString("BACK");
	labelButtonsSettings[0].setPosition(buttonsSettings[0].getPosition() + sf::Vector2f(125, -5));
	labelButtonsSettings[0].setFillColor(sf::Color(180, 180, 180));
	labelButtonsSettings[0].setCharacterSize(70);
	labelButtonsSettings[0].setLetterSpacing(1.5);
	labelButtonsSettings[1].setFont(fontMM2);
	labelButtonsSettings[1].setString("VIDEO");
	labelButtonsSettings[1].setPosition(buttonsSettings[1].getPosition() + sf::Vector2f(125, -5));
	labelButtonsSettings[1].setFillColor(sf::Color(180, 180, 180));
	labelButtonsSettings[1].setCharacterSize(70);
	labelButtonsSettings[1].setLetterSpacing(1.5);
	labelButtonsSettings[2].setFont(fontMM2);
	labelButtonsSettings[2].setString("TBD"); //audio
	labelButtonsSettings[2].setPosition(buttonsSettings[2].getPosition() + sf::Vector2f(135, -5));
	labelButtonsSettings[2].setFillColor(sf::Color(180, 180, 180));
	labelButtonsSettings[2].setCharacterSize(70);
	labelButtonsSettings[2].setLetterSpacing(1.5);
	labelButtonsSettings[3].setFont(fontMM2);
	labelButtonsSettings[3].setString("TBD"); //gameplay
	labelButtonsSettings[3].setPosition(buttonsSettings[3].getPosition() + sf::Vector2f(135, -5));
	labelButtonsSettings[3].setFillColor(sf::Color(180, 180, 180));
	labelButtonsSettings[3].setCharacterSize(70);
	labelButtonsSettings[3].setLetterSpacing(1.5);

	window.draw(background);
	for (int i = 0; i < 4; i++)
	{
		window.draw(buttonsSettings[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		window.draw(labelButtonsSettings[i]);
	}
	if (settingState == 0)
	{
		sf::Text* textSettingsVideo = new sf::Text[3];
		textSettingsVideo[0].setFont(fontMM2);
		textSettingsVideo[0].setString("Resolution");
		textSettingsVideo[0].setPosition(sf::Vector2f(400,400));
		textSettingsVideo[0].setFillColor(sf::Color(180, 180, 180));
		textSettingsVideo[0].setCharacterSize(120);
		textSettingsVideo[0].setLetterSpacing(1.5);
		textSettingsVideo[1].setFont(fontMM2);
		textSettingsVideo[1].setString("V-sync");
		textSettingsVideo[1].setPosition(sf::Vector2f(400, 600));
		textSettingsVideo[1].setFillColor(sf::Color(180, 180, 180));
		textSettingsVideo[1].setCharacterSize(120);
		textSettingsVideo[1].setLetterSpacing(1.5);
		textSettingsVideo[2].setFont(fontMM2);
		textSettingsVideo[2].setString("FPS limiter");
		textSettingsVideo[2].setPosition(sf::Vector2f(400, 800));
		textSettingsVideo[2].setFillColor(sf::Color(180, 180, 180));
		textSettingsVideo[2].setCharacterSize(120);
		textSettingsVideo[2].setLetterSpacing(1.5);
		for (int i = 0; i < 3; i++)
		{
			window.draw(textSettingsVideo[i]);
		}
		if (checkBox.getState() == 1)
		{
			window.draw(checkBox.getCirc());
			window.draw(checkBox.getRect());
		}
		else
		{
			window.draw(checkBox.getRect());
		}
	}
	if (settingState == 1)
	{

	}
	if (settingState == 2)
	{

	}

	sf::Sprite cursor;
	cursor.setTexture(cursorTexture);
	cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition().x - 5, sf::Mouse::getPosition().y - 5));
	cursor.setScale(sf::Vector2f(5, 5));
	window.draw(cursor);
}

void Game::settingsUpdate(CheckBox checkBox)
{
	if (inputs[0] == 1)
	{
		state = 0;
		inputs[0] = 0;
	}
	if (inputs[5] == 1)
	{
		if (sf::Mouse::getPosition().x > 1200 and sf::Mouse::getPosition().x < 1300 and sf::Mouse::getPosition().y > 620 and sf::Mouse::getPosition().y < 720)
		{
			checkBox.clicked();
			inputs[5] == 0;
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
		basicMissleColdBuffer.clear();
		basicMissleColdCooldown = 0;
		basicMissleColdCounter = 0;
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
			if (paused == 0)
			{
				arcadeModeRun(player);
				if (levelUp > 0)
				{
					arcadeModeLevelUp(player);
					return;
				}
				return;
			}
			if (paused == 1)
			{
				//sf::Clock breakTime;
				arcadeModePause();
				//timer = breakTime.getElapsedTime();
				return;
			}
		}
	}
}

void Game::arcadeModeRun(Player* player)
{
	sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	timerHealth.restart();
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
		//updateBullets(TimePerFrame, player);
		updateBasicMissle(TimePerFrame, player);
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
		if (bufLevel != player[0].getLevel() and player[0].getLevel() < 251)
		{
			//pausedScreen.create(window.getSize().x, window.getSize().y);
			//pausedScreen.update(window);
			return;
		}
		if (timer.getElapsedTime().asSeconds() > sf::seconds(1200).asSeconds())
		{
			playerDeath = 1;
			return;
		}
		if (timer.getElapsedTime().asSeconds() > 120)
		{
			enemyCooldownVar = 160;
			enemyCountVar = 400;
			manaCountVar = 40;
		}
		if (timer.getElapsedTime().asSeconds() > 240)
		{
			enemyCooldownVar = 140;
			enemyCountVar = 500;
			manaCountVar = 60;
		}
		if (timer.getElapsedTime().asSeconds() > 360)
		{
			enemyCooldownVar = 120;
			enemyCountVar = 1000;
			manaCountVar = 80;
		}
		if (timer.getElapsedTime().asSeconds() > 480)
		{
			enemyCooldownVar = 100;
			enemyCountVar = 2000;
			manaCountVar = 100;
		}
		if (timer.getElapsedTime().asSeconds() > 600)
		{
			enemyCooldownVar = 50;
			enemyCountVar = 3000;
			manaCountVar = 120;
		}
		if (timer.getElapsedTime().asSeconds() > 720)
		{
			enemyCooldownVar = 20;
			enemyCountVar = 4000;
			manaCountVar = 140;
		}
		if (timer.getElapsedTime().asSeconds() > 840)
		{
			enemyCooldownVar = 10;
			enemyCountVar = 5000;
			manaCountVar = 160;
		}
		if (timer.getElapsedTime().asSeconds() > 960)
		{
			enemyCooldownVar = 2;
			enemyCountVar = 8000;
			manaCountVar = 180;
		}
		if (timer.getElapsedTime().asSeconds() > 1080)
		{
			enemyCooldownVar = 1;
			enemyCountVar = 10000;
			manaCountVar = 200;
		}
		if (timerHealth.getElapsedTime().asSeconds() > 1 and player[0].getHealthCur() < player[0].getHealth())
		{
			player[0].setHealthCur(player[0].getHealthCur() + player[0].getHealthRecover());
			if (player[0].getHealthCur() > player[0].getHealth())
				player[0].setHealthCur(player[0].getHealth());
			timerHealth.restart();
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
	view.setCenter(static_cast<int>(player[0].getSprite().getPosition().x + 30), static_cast<int>(player[0].getSprite().getPosition().y + 30));
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
		window.draw(StandartEnemyFireBuffer[i].getSprite());
	}

	//draw bullets
	for (int i = 0; i < bulletCounter; i++)
	{
		window.draw(bulletBuffer[i].getSprite());
	}

	for (int i = 0; i < basicMissleColdCounter; i++)
	{
		
		//window.draw(basicMissleColdBuffer[i].getSprite());
		//basicMissleColdBuffer[i].setRotation(i);
		//basicMissleColdBuffer[i].setPosition(sf::Vector2f(
		//	(basicMissleColdBuffer[i].getSprite().getPosition().x + (65 + 56.5 * cos((basicMissleColdBuffer[i].getRotation() + 225) / (180 / 3.14)))),
		//	(basicMissleColdBuffer[i].getSprite().getPosition().y + (10 + 56.5 * sin((basicMissleColdBuffer[i].getRotation() + 225) / (180 / 3.14))))
		//));
		
		window.draw(basicMissleColdBuffer[i].getSprite());
		//basicMissleColdBuffer[i].setPosition(sf::Vector2f(
		//	(basicMissleColdBuffer[i].getSprite().getPosition().x - (65 + 56.5 * cos((basicMissleColdBuffer[i].getRotation() + 225) / (180 / 3.14)))),
		//	(basicMissleColdBuffer[i].getSprite().getPosition().y - (10 + 56.5 * sin((basicMissleColdBuffer[i].getRotation() + 225) / (180 / 3.14))))
		//));

		//for (int j = 0; j < 360; j++)
		//{
		//	basicMissleColdBuffer[i].setPosition(sf::Vector2f(
		//		(basicMissleColdBuffer[i].getSprite().getPosition().x + (80 + 113 * cos(j))),
		//		(basicMissleColdBuffer[i].getSprite().getPosition().y + (80 + 113 * sin(j)))
		//	));
		//	window.draw(basicMissleColdBuffer[i].getSprite());
		//	basicMissleColdBuffer[i].setPosition(sf::Vector2f(
		//		(basicMissleColdBuffer[i].getSprite().getPosition().x - (80 + 113 * cos(j))),
		//		(basicMissleColdBuffer[i].getSprite().getPosition().y - (80 + 113 * sin(j)))
		//	));
		//}
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
	sf::RectangleShape healthBarFill(sf::Vector2f(200*(static_cast<float>(player[0].getHealthCur()) / player[0].getHealth()), 20));
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
	stat += std::to_string(player[0].getHealthCur());
	stat += " \\ ";
	stat += std::to_string(player[0].getHealth());
	stat += "\n";
	//stat += "Speed: ";
	//stat += std::to_string(player[0].getSpeed());
	//stat += "\n";
	//stat += "Cast cooldown: ";
	//stat += std::to_string(player[0].getCastSpeed());
	//stat += "\n";
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
		tmp.y = tmp.y - player[0].getSpeed() * del * 0.707;
		tmp.x = tmp.x + player[0].getSpeed() * del * 0.707;
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
		tmp.y = tmp.y + player[0].getSpeed() * del * 0.707;
		tmp.x = tmp.x + player[0].getSpeed() * del * 0.707;
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
		tmp.y = tmp.y + player[0].getSpeed() * del * 0.707;
		tmp.x = tmp.x - player[0].getSpeed() * del * 0.707;
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
		tmp.y = tmp.y - player[0].getSpeed() * del * 0.707;
		tmp.x = tmp.x - player[0].getSpeed() * del * 0.707;
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
	if (dist > 2500 and manaCounter < manaCountVar)
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

void Game::updateBasicMissle(sf::Time elapsedTime, Player* player)
{
	if (basicMissleColdCooldown > 144 * 0.5 * (100.f / static_cast<float>(player[0].getCastSpeed())))
	{
		int* distBuffer = new int[enemyCounter];
		int num;
		if (0.5 * (100.f / static_cast<float>(player[0].getCastSpeed())) > 144)
		{
			num = 1;
		}
		else
		{
			num = static_cast <float>(1 / (0.5 * (100.f / static_cast<float>(player[0].getCastSpeed()))));
		}
		int* distBuffer2 = new int[num];
		int* nums = new int[num];
		for (int j = 0; j < num; j++)
		{
			distBuffer2[j] = 10000;
			nums[j] = 0;
		}

		for (int i = 0; i < enemyCounter; i++)
		{
			sf::Vector2f posPlayer, posEnemy;
			int dist;
			posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
			posEnemy = sf::Vector2f(StandartEnemyFireBuffer[i].getSprite().getPosition().x + 20, StandartEnemyFireBuffer[i].getSprite().getPosition().y + 20);
			dist = sqrt(pow(posPlayer.x - posEnemy.x, 2) + pow(posPlayer.y - posEnemy.y, 2));
			distBuffer[i] = dist;
		}
		for (int i = 0; i < enemyCounter; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (distBuffer[i] < distBuffer2[j])
				{
					for (int k = j; k < num - 1; k++)
					{
						distBuffer2[k + 1] = distBuffer2[k];
						nums[k + 1] = nums[k];
					}
					distBuffer2[j] = distBuffer[i];
					nums[j] = i;
					break;
				}
			}
		}
		for (int i = 0; i < num; i++)
		{
			if (distBuffer2[i] < 700)
			{
				BasicMissleCold missle(sf::Vector2f(player[0].getSprite().getPosition().x + 30, player[0].getSprite().getPosition().y - 15), BasicMissleColdTexture);
				//BasicMissleCold missle(sf::Vector2f(0, 0), BasicMissleColdTexture);
				missle.setDirection(sf::Vector2f(
					(StandartEnemyFireBuffer[nums[i]].getSprite().getPosition().x - player[0].getSprite().getPosition().x - 75) / (std::abs(StandartEnemyFireBuffer[nums[i]].getSprite().getPosition().x - player[0].getSprite().getPosition().x - 75) + std::abs(StandartEnemyFireBuffer[nums[i]].getSprite().getPosition().y - player[0].getSprite().getPosition().y + 25)),
					(StandartEnemyFireBuffer[nums[i]].getSprite().getPosition().y - player[0].getSprite().getPosition().y + 25) / (std::abs(StandartEnemyFireBuffer[nums[i]].getSprite().getPosition().x - player[0].getSprite().getPosition().x - 75) + std::abs(StandartEnemyFireBuffer[nums[i]].getSprite().getPosition().y - player[0].getSprite().getPosition().y + 25))
				));
				double rot1 = (std::acos((-1 * missle.getDirection().y) / (std::sqrt(missle.getDirection().x * missle.getDirection().x + missle.getDirection().y * missle.getDirection().y))) * (180.0 / 3.14));
				if (missle.getDirection().x < 0)
				{
					rot1 = 360.f - rot1;
				}
				//else
				//{
				//	rot1 = 360.f - rot1;
				//}
				missle.setRotation(rot1);
				missle.setPosition(sf::Vector2f(
					(missle.getSprite().getPosition().x + (65 + 56.5 * cos((missle.getRotation() + 225) / (180 / 3.14)))),
					(missle.getSprite().getPosition().y + (10 + 56.5 * sin((missle.getRotation() + 225) / (180 / 3.14))))
				));
				//missle.setRotation(350);
				//missle.setPosition(sf::Vector2f(
				//	(missle.getSprite().getPosition().x + 120.f * (rot1 - ((rot1 - 90.f) * 2) / 90.f)),
				//	(missle.getSprite().getPosition().y + 120.f * (rot1 / 180.f))
				//));
				//missle.setPosition(sf::Vector2f(
				//	(missle.getSprite().getPosition().x + 60.f),
				//	(missle.getSprite().getPosition().y - 20.f)
				//));
				//if (rot1 > 0)
				//{
				//	if (rot1 > 90.f)
				//	{
				//		missle.setPosition(sf::Vector2f(
				//			(missle.getSprite().getPosition().x + 120.f * (rot1 - ((rot1 - 90.f) * 2) / 90.f)),
				//			(missle.getSprite().getPosition().y + 120.f * (rot1 / 180.f))
				//		));
				//	}
				//	else
				//	{
				//		missle.setPosition(sf::Vector2f(
				//			(missle.getSprite().getPosition().x + 120.f * (rot1 / 90.f)),
				//			(missle.getSprite().getPosition().y + 120.f * (rot1 / 180.f))
				//		));
				//	}
				//}
				//else
				//{
				//	//if (rot1 > 90.f)
				//	//{
				//	//	missle.setPosition(sf::Vector2f(
				//	//		(missle.getSprite().getPosition().x + 120.f * (rot1 - ((rot1 - 90.f) * 2) / 90.f)),
				//	//		(missle.getSprite().getPosition().y + 160.f * (rot1 / 180.f))
				//	//	));
				//	//}
				//	//else
				//	//{
				//	//	missle.setPosition(sf::Vector2f(
				//	//		(missle.getSprite().getPosition().x + 120.f * (rot1 / 90.f)),
				//	//		(missle.getSprite().getPosition().y + 160.f * (rot1 / 180.f))
				//	//	));
				//	//}
				//}
				basicMissleColdBuffer.push_back(missle); 
				basicMissleColdCounter++;
			}
		}
		basicMissleColdCooldown = 0;
	}
	else
	{
		basicMissleColdCooldown++;
	}
	for (int i = 0; i < basicMissleColdCounter; i++)
	{
		basicMissleColdBuffer[i].setPosition(sf::Vector2f(
			basicMissleColdBuffer[i].getSprite().getPosition().x + basicMissleColdBuffer[i].getSpeed() * sf::seconds(1.f / 144.f).asSeconds() * basicMissleColdBuffer[i].getDirection().x,
			basicMissleColdBuffer[i].getSprite().getPosition().y + basicMissleColdBuffer[i].getSpeed() * sf::seconds(1.f / 144.f).asSeconds() * basicMissleColdBuffer[i].getDirection().y
		));
		int buf;
		buf = basicMissleColdBuffer[i].getHealth();
		buf--;
		if (buf < 0)
		{
			basicMissleColdBuffer.erase(basicMissleColdBuffer.begin() + i);
			basicMissleColdCounter--;
		}
		else
		{
			basicMissleColdBuffer[i].setHealth(buf);
		}
	}
}

void Game::updateEnemies(sf::Time elapsedTime, Player* player)
{
	//old
	//enemyCooldown++;
	//if (enemyTickCounter > 144)
	//	enemyTickCounter = 0;
	//srand(time(0) * enemyTickCounter);
	//enemyTickCounter++;
	//sf::Vector2f posPlayer, posEnemy;
	//int dist;
	//posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
	//posEnemy.x = -3000 + posPlayer.x + rand() % 6000;
	//posEnemy.y = -3000 + posPlayer.y + rand() % 6000;
	//dist = sqrt(pow(posPlayer.x - posEnemy.x,2) + pow(posPlayer.y - posEnemy.y,2));
	//if (dist > 1500 and enemyCooldown > enemyCooldownVar and enemyCounter < enemyCountVar)
	//{
	//	Enemy enemy(enemyTexture, posEnemy);
	//	enemyBuffer.push_back(enemy);
	//	enemyCounter++;
	//	enemyCooldown = 0;
	//}
	//for (int i = 0; i < enemyCounter; i++)
	//{
	//	posEnemy = enemyBuffer[i].getSprite().getPosition();
	//	posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
	//	enemyBuffer[i].setPos(sf::Vector2f(
	//		posEnemy.x + enemyBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((posPlayer.x - 20 - posEnemy.x) / ((std::abs(posPlayer.x - 20 - posEnemy.x) + std::abs(posPlayer.y - 20 - posEnemy.y))))),
	//		posEnemy.y + enemyBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((posPlayer.y - 20 - posEnemy.y) / ((std::abs(posPlayer.x - 20 - posEnemy.x) + std::abs(posPlayer.y - 20 - posEnemy.y)))))
	//	));
	//}

	//new
	enemyCooldown++;
	if (enemyTickCounter > 144)
		enemyTickCounter = 0;
	srand(time(0) * enemyTickCounter);
	enemyTickCounter++;
	sf::Vector2f posPlayer, posEnemy;
	int dist;
	posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
	posEnemy.x = -3000 + posPlayer.x + rand() % 6000;
	posEnemy.y = -3000 + posPlayer.y + rand() % 6000;
	dist = sqrt(pow(posPlayer.x - posEnemy.x, 2) + pow(posPlayer.y - posEnemy.y, 2));
	if (dist > 1500 and enemyCooldown > enemyCooldownVar and enemyCounter < enemyCountVar)
	{
		StandartEnemy enemy(StandartEnemyFireTexture, posEnemy, timer.getElapsedTime().asSeconds());
		StandartEnemyFireBuffer.push_back(enemy);
		enemyCounter++;
		enemyCooldown = 0;
	}
	for (int i = 0; i < enemyCounter; i++)
	{
		posEnemy = StandartEnemyFireBuffer[i].getSprite().getPosition();
		posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
		StandartEnemyFireBuffer[i].setPosition(sf::Vector2f(
			posEnemy.x + StandartEnemyFireBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((posPlayer.x - 20 - posEnemy.x) / ((std::abs(posPlayer.x - 20 - posEnemy.x) + std::abs(posPlayer.y - 20 - posEnemy.y))))),
			posEnemy.y + StandartEnemyFireBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((posPlayer.y - 20 - posEnemy.y) / ((std::abs(posPlayer.x - 20 - posEnemy.x) + std::abs(posPlayer.y - 20 - posEnemy.y)))))
		));
	}
}
	
void Game::updateCollision(sf::Time elapsedTime, Player* player)
{
	//for (int i = 0; i < bulletCounter; i++)
	//{
	//	for (int j = 0; j < enemyCounter; j++)
	//	{
	//		if (abs(bulletBuffer[i].getSprite().getPosition().x - enemyBuffer[j].getSprite().getPosition().x - 10) < 20 and abs(bulletBuffer[i].getSprite().getPosition().y - enemyBuffer[j].getSprite().getPosition().y - 10) < 20)
	//		{
	//			bulletBuffer.erase(bulletBuffer.begin() + i);
	//			enemyBuffer.erase(enemyBuffer.begin() + j);
	//			bulletCounter--;
	//			enemyCounter--;
	//			player[0].setExp(player[0].getExp() + 10);
	//			break;
	//		}
	//	}
	//}
	
	for (int i = 0; i < basicMissleColdCounter; i++)
	{
		for (int j = 0; j < enemyCounter; j++)
		{
			if (abs(basicMissleColdBuffer[i].getSprite().getPosition().x + (56.5 * cos((basicMissleColdBuffer[i].getRotation() + 45) / (180 / 3.14))) - StandartEnemyFireBuffer[j].getSprite().getPosition().x - 20) < 20 and abs(basicMissleColdBuffer[i].getSprite().getPosition().y + (56.5 * sin((basicMissleColdBuffer[i].getRotation() + 45) / (180 / 3.14))) - StandartEnemyFireBuffer[j].getSprite().getPosition().y - 20) < 20)
			{
				srand(time(0) * timer.getElapsedTime().asMicroseconds());
				float crit = 1.f;
				int randNum = rand() % 1000000;
				if (randNum > 1000000 * ((player[0].getCritChance() + basicMissleColdBuffer[i].getCritRate()) / 100.f))
					crit = crit + (basicMissleColdBuffer[i].getDamageMP() / 100.f);
				int damage = player[0].getBaseAttack() * (basicMissleColdBuffer[i].getDamageMP() / 100.f) * crit; 
				basicMissleColdBuffer.erase(basicMissleColdBuffer.begin() + i);
				basicMissleColdCounter--;
				StandartEnemyFireBuffer[j].setHealth(StandartEnemyFireBuffer[j].getHealth() - damage * ((100 - StandartEnemyFireBuffer[j].getResist()) / 100.f));
				if (StandartEnemyFireBuffer[j].getHealth() < 1)
				{
					Mana mana(StandartEnemyFireBuffer[j].getSprite().getPosition() + sf::Vector2f(15,15), manaTexture);
					manaBuffer.push_back(mana);
					manaCounter++;
					StandartEnemyFireBuffer.erase(StandartEnemyFireBuffer.begin() + j);
					enemyCounter--;
					player[0].setExp(player[0].getExp() + StandartEnemyFireBuffer[j].getManaValue());
				}
				break;
			}
		}
	}
	
	for (int j = 0; j < enemyCounter; j++)
	{
		if (abs(player[0].getSprite().getPosition().x + 25 - StandartEnemyFireBuffer[j].getSprite().getPosition().x) < 30 and abs(player[0].getSprite().getPosition().y + 40 - StandartEnemyFireBuffer[j].getSprite().getPosition().y) < 40)
		{
			StandartEnemyFireBuffer.erase(StandartEnemyFireBuffer.begin() + j);
			enemyCounter--;
			player[0].setExp(player[0].getExp() + StandartEnemyFireBuffer[j].getManaValue());
			player[0].setHealthCur(player[0].getHealthCur() - StandartEnemyFireBuffer[j].getDamage() * (1 - (player[0].getResist() / 100.f)));
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

	if (player[0].getHealthCur() < 1)
	{
		playerDeath = 1; //die screen
	}
}

void Game::updateLevel(sf::Time elapsedTime, Player* player)
{
	while (player[0].getExp() >= player[0].getExpCap())
	{
		
		if (player[0].getLevel() >= 250)
		{
			player[0].setLevel(250);
			player[0].setExp(0);
		}
		else
		{
			player[0].setExp(player[0].getExp() - player[0].getExpCap());
			player[0].setExpCap(player[0].getExpCap() * 1.03);
			player[0].setLevel(player[0].getLevel() + 1);
			levelUp++;
			levelUp++;
		}
	}
}

void Game::collectFarObjects(sf::Time elapsedTime, Player* player)
{
	for (int i = 0; i < enemyCounter; i++)
	{
		sf::Vector2f posPlayer, posEnemy;
		int dist;
		posPlayer = sf::Vector2f(player[0].getSprite().getPosition().x + 45, player[0].getSprite().getPosition().y + 60);
		posEnemy = StandartEnemyFireBuffer[i].getSprite().getPosition() + sf::Vector2f(20,20);
		dist = sqrt(pow(posPlayer.x - posEnemy.x, 2) + pow(posPlayer.y - posEnemy.y, 2));
		if (dist > 4000)
		{
			StandartEnemyFireBuffer.erase(StandartEnemyFireBuffer.begin() + i);
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

	std::string time = std::to_string(static_cast<int>(timer.getElapsedTime().asSeconds()));
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
	while (window.isOpen())
	{
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
		if (levelUp < 1)
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
	//window.draw(prevFrame);
	sf::RectangleShape buf(sf::Vector2f(1920, 1080));
	buf.setPosition(0, 0);
	buf.setFillColor(sf::Color(0, 0, 0, 200));

	sf::Sprite cursor;
	cursor.setTexture(cursorTexture);
	cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition().x - 5, sf::Mouse::getPosition().y - 5));
	cursor.setScale(sf::Vector2f(5, 5));

	//labelbuttonArcadeModeUpCastSpeed.setFont(fontMM2);
	//labelbuttonArcadeModeUpCastSpeed.setString("UP CAST SPEED");
	//labelbuttonArcadeModeUpCastSpeed.setPosition(buttonArcadeModeUpCastSpeed.getBody().getPosition().x + 25, buttonArcadeModePauseMM.getBody().getPosition().y - 15);
	//labelbuttonArcadeModeUpCastSpeed.setFillColor(sf::Color(180, 180, 180));
	//labelbuttonArcadeModeUpCastSpeed.setCharacterSize(90);
	//labelbuttonArcadeModeUpCastSpeed.setLetterSpacing(1.5);

	//labelbuttonArcadeModeUpSpeed.setFont(fontMM2);
	//labelbuttonArcadeModeUpSpeed.setString("UP PLAYER SPEED");
	//labelbuttonArcadeModeUpSpeed.setPosition(buttonArcadeModeUpSpeed.getBody().getPosition().x + 25, buttonArcadeModePauseMM.getBody().getPosition().y - 15);
	//labelbuttonArcadeModeUpSpeed.setFillColor(sf::Color(180, 180, 180));
	//labelbuttonArcadeModeUpSpeed.setCharacterSize(90);
	//labelbuttonArcadeModeUpSpeed.setLetterSpacing(1.5);

	//labelbuttonArcadeModeHeal.setFont(fontMM2);
	//labelbuttonArcadeModeHeal.setString("HEAL");
	//labelbuttonArcadeModeHeal.setPosition(buttonArcadeModeHeal.getBody().getPosition().x + 25, buttonArcadeModePauseMM.getBody().getPosition().y - 15);
	//labelbuttonArcadeModeHeal.setFillColor(sf::Color(180, 180, 180));
	//labelbuttonArcadeModeHeal.setCharacterSize(90);
	//labelbuttonArcadeModeHeal.setLetterSpacing(1.5);

	//window.draw(buf);
	//if (player[0].getSpeed() < 500)
	//{
	//	window.draw(buttonArcadeModeUpSpeed.getBody());
	//	window.draw(labelbuttonArcadeModeUpSpeed);
	//}
	//if (player[0].getCastSpeed() > 5)
	//{
	//	window.draw(buttonArcadeModeUpCastSpeed.getBody());
	//	window.draw(labelbuttonArcadeModeUpCastSpeed);
	//}
	//if (player[0].getHealth() < 100)
	//{
	//	window.draw(buttonArcadeModeHeal.getBody());
	//	window.draw(labelbuttonArcadeModeHeal);
	//}

	//new
	sf::Text* labelSecondaryAttributes = new sf::Text[11];
	sf::String str;
	labelSecondaryAttributes[0].setFont(fontMM2);
	labelSecondaryAttributes[0].setFillColor(sf::Color::White);
	labelSecondaryAttributes[0].setCharacterSize(50);
	labelSecondaryAttributes[0].setLetterSpacing(1.5);
	labelSecondaryAttributes[0].setLineSpacing(1.045);
	labelSecondaryAttributes[0].setPosition(sf::Vector2f(20, 300));
	labelSecondaryAttributes[0].setString("Base attack:\nCrit chance:\nDamage resistance:\nHealth:\nHealth recover rate:\nSpeed:\nAttack speed MP:\nMana:\nMana recover rate:\nMana usage rate:");
	
	labelSecondaryAttributes[1].setFont(fontMM2);
	labelSecondaryAttributes[1].setFillColor(sf::Color::White);
	labelSecondaryAttributes[1].setCharacterSize(50);
	labelSecondaryAttributes[1].setLetterSpacing(1.5);
	labelSecondaryAttributes[1].setPosition(sf::Vector2f(200, 300));
	str = std::to_string(player[0].getBaseAttack());
	labelSecondaryAttributes[1].setString(str);

	labelSecondaryAttributes[2].setFont(fontMM2);
	labelSecondaryAttributes[2].setFillColor(sf::Color::White);
	labelSecondaryAttributes[2].setCharacterSize(50);
	labelSecondaryAttributes[2].setLetterSpacing(1.5);
	labelSecondaryAttributes[2].setPosition(sf::Vector2f(200, 350));
	str = std::to_string(player[0].getCritChance());
	str += " %";
	labelSecondaryAttributes[2].setString(str);

	labelSecondaryAttributes[3].setFont(fontMM2);
	labelSecondaryAttributes[3].setFillColor(sf::Color::White);
	labelSecondaryAttributes[3].setCharacterSize(50);
	labelSecondaryAttributes[3].setLetterSpacing(1.5);
	labelSecondaryAttributes[3].setPosition(sf::Vector2f(200, 400));
	str = std::to_string(player[0].getResist());
	str += " %";
	labelSecondaryAttributes[3].setString(str);

	labelSecondaryAttributes[4].setFont(fontMM2);
	labelSecondaryAttributes[4].setFillColor(sf::Color::White);
	labelSecondaryAttributes[4].setCharacterSize(50);
	labelSecondaryAttributes[4].setLetterSpacing(1.5);
	labelSecondaryAttributes[4].setPosition(sf::Vector2f(200, 450));
	str = std::to_string(player[0].getHealth());
	labelSecondaryAttributes[4].setString(str);

	labelSecondaryAttributes[5].setFont(fontMM2);
	labelSecondaryAttributes[5].setFillColor(sf::Color::White);
	labelSecondaryAttributes[5].setCharacterSize(50);
	labelSecondaryAttributes[5].setLetterSpacing(1.5);
	labelSecondaryAttributes[5].setPosition(sf::Vector2f(200, 500));
	str = std::to_string(player[0].getHealthRecover());
	str += " per second";
	labelSecondaryAttributes[5].setString(str);

	labelSecondaryAttributes[6].setFont(fontMM2);
	labelSecondaryAttributes[6].setFillColor(sf::Color::White);
	labelSecondaryAttributes[6].setCharacterSize(50);
	labelSecondaryAttributes[6].setLetterSpacing(1.5);
	labelSecondaryAttributes[6].setPosition(sf::Vector2f(200, 550));
	str = std::to_string(player[0].getSpeed());
	labelSecondaryAttributes[6].setString(str);

	labelSecondaryAttributes[7].setFont(fontMM2);
	labelSecondaryAttributes[7].setFillColor(sf::Color::White);
	labelSecondaryAttributes[7].setCharacterSize(50);
	labelSecondaryAttributes[7].setLetterSpacing(1.5);
	labelSecondaryAttributes[7].setPosition(sf::Vector2f(200, 600));
	str = std::to_string(player[0].getCastSpeed());
	str += " %";
	labelSecondaryAttributes[7].setString(str);

	labelSecondaryAttributes[8].setFont(fontMM2);
	labelSecondaryAttributes[8].setFillColor(sf::Color::White);
	labelSecondaryAttributes[8].setCharacterSize(50);
	labelSecondaryAttributes[8].setLetterSpacing(1.5);
	labelSecondaryAttributes[8].setPosition(sf::Vector2f(200, 650));
	str = std::to_string(player[0].getMana());
	labelSecondaryAttributes[8].setString(str);

	labelSecondaryAttributes[9].setFont(fontMM2);
	labelSecondaryAttributes[9].setFillColor(sf::Color::White);
	labelSecondaryAttributes[9].setCharacterSize(50);
	labelSecondaryAttributes[9].setLetterSpacing(1.5);
	labelSecondaryAttributes[9].setPosition(sf::Vector2f(200, 700));
	str = std::to_string(player[0].getManaRecover());
	str += " per second";
	labelSecondaryAttributes[9].setString(str);

	labelSecondaryAttributes[10].setFont(fontMM2);
	labelSecondaryAttributes[10].setFillColor(sf::Color::White);
	labelSecondaryAttributes[10].setCharacterSize(50);
	labelSecondaryAttributes[10].setLetterSpacing(1.5);
	labelSecondaryAttributes[10].setPosition(sf::Vector2f(200, 750));
	str = std::to_string(player[0].getManaUsage());
	str += " per second";
	labelSecondaryAttributes[10].setString(str);

	for (int i = 0; i < 11; i++)
	{
		window.draw(labelSecondaryAttributes[i]);
	}

	sf::ConvexShape charactristicOutlineMax;
	charactristicOutlineMax.setPosition(1050, 250);
	charactristicOutlineMax.setFillColor(sf::Color(0,0,0,0));
	charactristicOutlineMax.setPointCount(5);
	charactristicOutlineMax.setOutlineColor(sf::Color(204,0,0));
	charactristicOutlineMax.setOutlineThickness(5.f);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(400, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(400 + 400 * 0.951, 400 - 400 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(400 + 400 * 0.588, 400 + 400 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(400 - 400 * 0.588, 400 + 400 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(400 - 400 * 0.951, 400 - 400 * 0.309));

	window.draw(charactristicOutlineMax);

	charactristicOutlineMax.setPosition(1050 + 400 - 40, 250 + 400 - 40);
	charactristicOutlineMax.setOutlineColor(sf::Color(110, 110, 110, 30));
	charactristicOutlineMax.setOutlineThickness(2.f);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(40, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(40 + 40 * 0.951, 40 - 40 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(40 + 40 * 0.588, 40 + 40 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(40 - 40 * 0.588, 40 + 40 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(40 - 40 * 0.951, 40 - 40 * 0.309));

	window.draw(charactristicOutlineMax);

	charactristicOutlineMax.setPosition(1050 + 400 - 80, 250 + 400 - 80);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(80, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(80 + 80 * 0.951, 80 - 80 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(80 + 80 * 0.588, 80 + 80 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(80 - 80 * 0.588, 80 + 80 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(80 - 80 * 0.951, 80 - 80 * 0.309));

	window.draw(charactristicOutlineMax);

	charactristicOutlineMax.setPosition(1050 + 400 - 120, 250 + 400 - 120);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(120, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(120 + 120 * 0.951, 120 - 120 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(120 + 120 * 0.588, 120 + 120 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(120 - 120 * 0.588, 120 + 120 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(120 - 120 * 0.951, 120 - 120 * 0.309));

	window.draw(charactristicOutlineMax);

	charactristicOutlineMax.setPosition(1050 + 400 - 160, 250 + 400 - 160);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(160, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(160 + 160 * 0.951, 160 - 160 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(160 + 160 * 0.588, 160 + 160 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(160 - 160 * 0.588, 160 + 160 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(160 - 160 * 0.951, 160 - 160 * 0.309));

	window.draw(charactristicOutlineMax);

	charactristicOutlineMax.setPosition(1050 + 400 - 200, 250 + 400 - 200);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(200, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(200 + 200 * 0.951, 200 - 200 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(200 + 200 * 0.588, 200 + 200 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(200 - 200 * 0.588, 200 + 200 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(200 - 200 * 0.951, 200 - 200 * 0.309));

	window.draw(charactristicOutlineMax);

	charactristicOutlineMax.setPosition(1050 + 400 - 240, 250 + 400 - 240);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(240, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(240 + 240 * 0.951, 240 - 240 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(240 + 240 * 0.588, 240 + 240 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(240 - 240 * 0.588, 240 + 240 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(240 - 240 * 0.951, 240 - 240 * 0.309));

	window.draw(charactristicOutlineMax);

	charactristicOutlineMax.setPosition(1050 + 400 - 280, 250 + 400 - 280);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(280, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(280 + 280 * 0.951, 280 - 280 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(280 + 280 * 0.588, 280 + 280 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(280 - 280 * 0.588, 280 + 280 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(280 - 280 * 0.951, 280 - 280 * 0.309));

	window.draw(charactristicOutlineMax);

	charactristicOutlineMax.setPosition(1050 + 400 - 320, 250 + 400 - 320);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(320, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(320 + 320 * 0.951, 320 - 320 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(320 + 320 * 0.588, 320 + 320 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(320 - 320 * 0.588, 320 + 320 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(320 - 320 * 0.951, 320 - 320 * 0.309));

	window.draw(charactristicOutlineMax);

	charactristicOutlineMax.setPosition(1050 + 400 - 360, 250 + 400 - 360);
	charactristicOutlineMax.setPoint(0, sf::Vector2f(360, 0));
	charactristicOutlineMax.setPoint(1, sf::Vector2f(360 + 360 * 0.951, 360 - 360 * 0.309));
	charactristicOutlineMax.setPoint(2, sf::Vector2f(360 + 360 * 0.588, 360 + 360 * 0.809));
	charactristicOutlineMax.setPoint(3, sf::Vector2f(360 - 360 * 0.588, 360 + 360 * 0.809));
	charactristicOutlineMax.setPoint(4, sf::Vector2f(360 - 360 * 0.951, 360 - 360 * 0.309));

	window.draw(charactristicOutlineMax);

	sf::ConvexShape charactristicOutline;
	charactristicOutline.setPosition(1050, 250);
	charactristicOutline.setFillColor(sf::Color(0, 0, 0, 0));
	charactristicOutline.setOutlineColor(sf::Color(0, 230, 0, 80));
	charactristicOutline.setOutlineThickness(2.f);
	charactristicOutline.setPointCount(5);
	charactristicOutline.setPoint(0, sf::Vector2f(400, 400 - player[0].getAttack() * 4));
	charactristicOutline.setPoint(1, sf::Vector2f(400 + player[0].getDefence() * 0.951 * 4, 400 - player[0].getDefence() * 0.309 * 4));
	charactristicOutline.setPoint(2, sf::Vector2f(400 + player[0].getVitality() * 0.588 * 4, 400 + player[0].getVitality() * 0.809 * 4));
	charactristicOutline.setPoint(3, sf::Vector2f(400 - player[0].getAgility() * 0.588 * 4, 400 + player[0].getAgility() * 0.809 * 4));
	charactristicOutline.setPoint(4, sf::Vector2f(400 - player[0].getKnowledge() * 0.951 * 4, 400 - player[0].getKnowledge() * 0.309 * 4));

	window.draw(charactristicOutline);

	sf::Text* labelMainCharacteristics = new sf::Text[5];
	labelMainCharacteristics[0].setFont(fontMM2);
	labelMainCharacteristics[0].setFillColor(sf::Color::White);
	labelMainCharacteristics[0].setCharacterSize(50);
	labelMainCharacteristics[0].setLetterSpacing(1.5);
	labelMainCharacteristics[0].setPosition(sf::Vector2f(1380, 190));
	labelMainCharacteristics[0].setString("Attack");

	labelMainCharacteristics[1].setFont(fontMM2);
	labelMainCharacteristics[1].setFillColor(sf::Color::White);
	labelMainCharacteristics[1].setCharacterSize(50);
	labelMainCharacteristics[1].setLetterSpacing(1.5);
	labelMainCharacteristics[1].setPosition(sf::Vector2f(1830, 440));
	labelMainCharacteristics[1].setString("Defence");

	labelMainCharacteristics[2].setFont(fontMM2);
	labelMainCharacteristics[2].setFillColor(sf::Color::White);
	labelMainCharacteristics[2].setCharacterSize(50);
	labelMainCharacteristics[2].setLetterSpacing(1.5);
	labelMainCharacteristics[2].setPosition(sf::Vector2f(1690, 980));
	labelMainCharacteristics[2].setString("Vitality");

	labelMainCharacteristics[3].setFont(fontMM2);
	labelMainCharacteristics[3].setFillColor(sf::Color::White);
	labelMainCharacteristics[3].setCharacterSize(50);
	labelMainCharacteristics[3].setLetterSpacing(1.5);
	labelMainCharacteristics[3].setPosition(sf::Vector2f(1170, 980));
	labelMainCharacteristics[3].setString("Agility");

	labelMainCharacteristics[4].setFont(fontMM2);
	labelMainCharacteristics[4].setFillColor(sf::Color::White);
	labelMainCharacteristics[4].setCharacterSize(50);
	labelMainCharacteristics[4].setLetterSpacing(1.5);
	labelMainCharacteristics[4].setPosition(sf::Vector2f(1000,440));
	labelMainCharacteristics[4].setString("Knowledge");

	for (int i = 0; i < 5; i++)
	{
		window.draw(labelMainCharacteristics[i]);
	}

	sf::RectangleShape* buttonsArcadeModeLevelUp = new sf::RectangleShape[5];
	buttonsArcadeModeLevelUp[0].setPosition(sf::Vector2f(660, 300));
	buttonsArcadeModeLevelUp[0].setSize(sf::Vector2f(300, 80));
	buttonsArcadeModeLevelUp[0].setFillColor(sf::Color(60, 60, 60));
	buttonsArcadeModeLevelUp[0].setOutlineColor(sf::Color(180, 180, 180));
	buttonsArcadeModeLevelUp[0].setOutlineThickness(5.f);

	buttonsArcadeModeLevelUp[1].setPosition(sf::Vector2f(660, 400));
	buttonsArcadeModeLevelUp[1].setSize(sf::Vector2f(300, 80));
	buttonsArcadeModeLevelUp[1].setFillColor(sf::Color(60, 60, 60));
	buttonsArcadeModeLevelUp[1].setOutlineColor(sf::Color(180, 180, 180));
	buttonsArcadeModeLevelUp[1].setOutlineThickness(5.f);

	buttonsArcadeModeLevelUp[2].setPosition(sf::Vector2f(660, 500));
	buttonsArcadeModeLevelUp[2].setSize(sf::Vector2f(300, 80));
	buttonsArcadeModeLevelUp[2].setFillColor(sf::Color(60, 60, 60));
	buttonsArcadeModeLevelUp[2].setOutlineColor(sf::Color(180, 180, 180));
	buttonsArcadeModeLevelUp[2].setOutlineThickness(5.f);

	buttonsArcadeModeLevelUp[3].setPosition(sf::Vector2f(660, 600));
	buttonsArcadeModeLevelUp[3].setSize(sf::Vector2f(300, 80));
	buttonsArcadeModeLevelUp[3].setFillColor(sf::Color(60, 60, 60));
	buttonsArcadeModeLevelUp[3].setOutlineColor(sf::Color(180, 180, 180));
	buttonsArcadeModeLevelUp[3].setOutlineThickness(5.f);

	buttonsArcadeModeLevelUp[4].setPosition(sf::Vector2f(660, 700));
	buttonsArcadeModeLevelUp[4].setSize(sf::Vector2f(300, 80));
	buttonsArcadeModeLevelUp[4].setFillColor(sf::Color(60, 60, 60));
	buttonsArcadeModeLevelUp[4].setOutlineColor(sf::Color(180, 180, 180));
	buttonsArcadeModeLevelUp[4].setOutlineThickness(5.f);

	sf::Text* labelButtonsArcadeModeLevelUp = new sf::Text[5];
	labelButtonsArcadeModeLevelUp[0].setFont(fontMM2);
	labelButtonsArcadeModeLevelUp[0].setFillColor(sf::Color(180, 180, 180));
	labelButtonsArcadeModeLevelUp[0].setCharacterSize(70);
	labelButtonsArcadeModeLevelUp[0].setLetterSpacing(1.5);
	labelButtonsArcadeModeLevelUp[0].setPosition(sf::Vector2f(725, 300));
	labelButtonsArcadeModeLevelUp[0].setString("Increase attack");

	labelButtonsArcadeModeLevelUp[1].setFont(fontMM2);
	labelButtonsArcadeModeLevelUp[1].setFillColor(sf::Color(180, 180, 180));
	labelButtonsArcadeModeLevelUp[1].setCharacterSize(70);
	labelButtonsArcadeModeLevelUp[1].setLetterSpacing(1.5);
	labelButtonsArcadeModeLevelUp[1].setPosition(sf::Vector2f(720, 400));
	labelButtonsArcadeModeLevelUp[1].setString("Increase defence");

	labelButtonsArcadeModeLevelUp[2].setFont(fontMM2);
	labelButtonsArcadeModeLevelUp[2].setFillColor(sf::Color(180, 180, 180));
	labelButtonsArcadeModeLevelUp[2].setCharacterSize(70);
	labelButtonsArcadeModeLevelUp[2].setLetterSpacing(1.5);
	labelButtonsArcadeModeLevelUp[2].setPosition(sf::Vector2f(720, 500));
	labelButtonsArcadeModeLevelUp[2].setString("Increase vitality");

	labelButtonsArcadeModeLevelUp[3].setFont(fontMM2);
	labelButtonsArcadeModeLevelUp[3].setFillColor(sf::Color(180, 180, 180));
	labelButtonsArcadeModeLevelUp[3].setCharacterSize(70);
	labelButtonsArcadeModeLevelUp[3].setLetterSpacing(1.5);
	labelButtonsArcadeModeLevelUp[3].setPosition(sf::Vector2f(725, 600));
	labelButtonsArcadeModeLevelUp[3].setString("Increase agility");

	labelButtonsArcadeModeLevelUp[4].setFont(fontMM2);
	labelButtonsArcadeModeLevelUp[4].setFillColor(sf::Color(180, 180, 180));
	labelButtonsArcadeModeLevelUp[4].setCharacterSize(70);
	labelButtonsArcadeModeLevelUp[4].setLetterSpacing(1.5);
	labelButtonsArcadeModeLevelUp[4].setPosition(sf::Vector2f(695, 700));
	labelButtonsArcadeModeLevelUp[4].setString("Increase knowlegde");

	if (player[0].getAttack() < 101)
	{
		window.draw(buttonsArcadeModeLevelUp[0]);
		window.draw(labelButtonsArcadeModeLevelUp[0]);
	}
	if (player[0].getDefence() < 101)
	{
		window.draw(buttonsArcadeModeLevelUp[1]);
		window.draw(labelButtonsArcadeModeLevelUp[1]);
	}
	if (player[0].getVitality() < 101)
	{
		window.draw(buttonsArcadeModeLevelUp[2]);
		window.draw(labelButtonsArcadeModeLevelUp[2]);
	}
	if (player[0].getAgility() < 101)
	{
		window.draw(buttonsArcadeModeLevelUp[3]);
		window.draw(labelButtonsArcadeModeLevelUp[3]);
	}
	if (player[0].getKnowledge() < 101)
	{
		window.draw(buttonsArcadeModeLevelUp[4]);
		window.draw(labelButtonsArcadeModeLevelUp[4]);
	}

	window.draw(cursor);
}

void Game::arcadeModeLevelUpUpdate(sf::Time elapsedTime, Player* player)
{
	if (inputs[5] == 1)
	{
		if (sf::Mouse::getPosition().x > 660 and sf::Mouse::getPosition().x < 960 and sf::Mouse::getPosition().y > 300 and sf::Mouse::getPosition().y < 380) //up attack
		{
			if (player[0].getAttack() < 101)
			{
				if (player[0].getAttack() > 0 and player[0].getAttack() < 10)
				{
					player[0].setBaseAttack(player[0].getBaseAttack() + 5);
				}
				else
				{
					if (player[0].getAttack() >= 10 and player[0].getAttack() < 20)
					{
						player[0].setBaseAttack(player[0].getBaseAttack() + 40);
						if (player[0].getAttack() == 19)
						{
							player[0].setCritChance(player[0].getCritChance() + 1);
						}
					}
					else
					{
						if (player[0].getAttack() >= 20 and player[0].getAttack() < 30)
						{
							player[0].setBaseAttack(player[0].getBaseAttack() + 50);
							if (player[0].getAttack() % 2 > 0)
							{
								player[0].setCritChance(player[0].getCritChance() + 1);
							}
						}
						else
						{
							if (player[0].getAttack() >= 30 and player[0].getAttack() < 40)
							{
								player[0].setBaseAttack(player[0].getBaseAttack() + 50);
								if (player[0].getAttack() % 2 > 0)
								{
									player[0].setCritChance(player[0].getCritChance() + 1);
								}
							}
							else
							{
								if (player[0].getAttack() >= 40 and player[0].getAttack() < 50)
								{
									player[0].setBaseAttack(player[0].getBaseAttack() + 100);
									player[0].setCritChance(player[0].getCritChance() + 1);
								}
								else
								{
									if (player[0].getAttack() >= 50 and player[0].getAttack() < 60)
									{
										player[0].setBaseAttack(player[0].getBaseAttack() + 125);
										player[0].setCritChance(player[0].getCritChance() + 1);
									}
									else
									{
										if (player[0].getAttack() >= 60 and player[0].getAttack() < 70)
										{
											player[0].setBaseAttack(player[0].getBaseAttack() + 125);
											player[0].setCritChance(player[0].getCritChance() + 1);
										}
										else
										{
											if (player[0].getAttack() >= 70 and player[0].getAttack() < 80)
											{
												player[0].setBaseAttack(player[0].getBaseAttack() + 200);
												if (player[0].getAttack() < 79)
												{
													player[0].setCritChance(player[0].getCritChance() + 1);
												}
											}
											else
											{
												if (player[0].getAttack() >= 80 and player[0].getAttack() < 90)
												{
													player[0].setBaseAttack(player[0].getBaseAttack() + 200);
												}
												else
												{
													if (player[0].getAttack() >= 90 and player[0].getAttack() < 101)
													{
														player[0].setBaseAttack(player[0].getBaseAttack() + 100);
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
				player[0].setAttack(player[0].getAttack() + 1);
				levelUp--;
				//inputs[5] = 0;
				sf::sleep(sf::milliseconds(300));
			}
		}
		if (sf::Mouse::getPosition().x > 660 and sf::Mouse::getPosition().x < 960 and sf::Mouse::getPosition().y > 400 and sf::Mouse::getPosition().y < 480) //up defence
		{
			if (player[0].getDefence() < 101)
			{
				if (player[0].getDefence() >= 30 and player[0].getDefence() < 79)
				{
					player[0].setResist(player[0].getResist() + 1);
				}
				player[0].setDefence(player[0].getDefence() + 1);
				levelUp--;
				//inputs[5] = 0;
				sf::sleep(sf::milliseconds(300));
			}
		}
		if (sf::Mouse::getPosition().x > 660 and sf::Mouse::getPosition().x < 960 and sf::Mouse::getPosition().y > 500 and sf::Mouse::getPosition().y < 580) //up vitality
		{
			if (player[0].getVitality() < 101)
			{
				if (player[0].getVitality() > 0 and player[0].getVitality() < 10)
				{
					player[0].setHealth(player[0].getHealth() + 5);
				}
				else
				{
					if (player[0].getVitality() >= 10 and player[0].getVitality() < 20)
					{
						player[0].setHealth(player[0].getHealth() + 20);
					}
					else
					{
						if (player[0].getVitality() >= 20 and player[0].getVitality() < 30)
						{
							player[0].setHealth(player[0].getHealth() + 20);
						}
						else
						{
							if (player[0].getVitality() >= 30 and player[0].getVitality() < 40)
							{
								player[0].setHealth(player[0].getHealth() + 88);
							}
							else
							{
								if (player[0].getVitality() >= 40 and player[0].getVitality() < 50)
								{
									player[0].setHealth(player[0].getHealth() + 88);
								}
								else
								{
									if (player[0].getVitality() >= 50 and player[0].getVitality() < 60)
									{
										player[0].setHealth(player[0].getHealth() + 88);
									}
									else
									{
										if (player[0].getVitality() >= 60 and player[0].getVitality() < 70)
										{
											player[0].setHealth(player[0].getHealth() + 88);
										}
										else
										{
											if (player[0].getVitality() >= 70 and player[0].getVitality() < 80)
											{
												if (player[0].getHealth() == 70)
												{
													player[0].setHealth(4000);
												}
												else
												{
													player[0].setHealth(player[0].getHealth() + 50);
												}
											}
											else
											{
												if (player[0].getVitality() >= 80 and player[0].getVitality() < 90)
												{
													player[0].setHealth(player[0].getHealth() + 50);
												}
												else
												{
													if (player[0].getVitality() >= 90 and player[0].getVitality() < 101)
													{
														player[0].setHealth(player[0].getHealth() + 50);
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
				player[0].setHealthRecover(player[0].getHealth() / 55.f);
				player[0].setVitality(player[0].getVitality() + 1);
				levelUp--;
				//inputs[5] = 0;
				sf::sleep(sf::milliseconds(300));
			}
		}
		if (sf::Mouse::getPosition().x > 660 and sf::Mouse::getPosition().x < 960 and sf::Mouse::getPosition().y > 600 and sf::Mouse::getPosition().y < 680) //up agility
		{
			if (player[0].getAgility() < 101)
			{
				player[0].setAgility(player[0].getAgility() + 1);
				player[0].setSpeed(player[0].getSpeed() + 4);
				player[0].setCastSpeed(player[0].getCastSpeed() + 2);
				levelUp--;
				//inputs[5] = 0;
				sf::sleep(sf::milliseconds(300));
			}
		}
		if (sf::Mouse::getPosition().x > 660 and sf::Mouse::getPosition().x < 960 and sf::Mouse::getPosition().y > 700 and sf::Mouse::getPosition().y < 780) //up knowledge
		{
			if (player[0].getKnowledge() < 101)
			{
				if (player[0].getKnowledge() > 0 and player[0].getKnowledge() < 20)
				{
					player[0].setMana(player[0].getMana() + 500);
					player[0].setManaRecover(player[0].getMana() / 100);
				}
				else
				{
					if (player[0].getKnowledge() >= 20 and player[0].getKnowledge() < 52)
					{
						player[0].setMana(player[0].getMana() + 2000);
						player[0].setManaRecover(player[0].getMana() / 10);
					}
					else
					{
						if (player[0].getKnowledge() >= 52 and player[0].getKnowledge() < 101)
						{
							player[0].setMana(player[0].getMana() + 4000);
							player[0].setManaRecover(player[0].getMana() / 10);
						}
					}
				}
				player[0].setKnowledge(player[0].getKnowledge() + 1);
				levelUp--;
				//inputs[5] = 0;
				sf::sleep(sf::milliseconds(300));
			}
		}
	}
}
