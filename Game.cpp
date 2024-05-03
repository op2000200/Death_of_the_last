#include "Game.h"
#include "button.h"
Game::Game()
	//windows
	: window(sf::VideoMode(1920, 1080), "Death of the last", sf::Style::Fullscreen)
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
	playerState = 0;
	for (int i = 0; i < 200; i++)
	{
		inputs[i] = 0;
	}
	enemyCooldown = 0;
	enemyTickCounter = 0;
	enemyCounter = 0;
	bulletCounter = 0;
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
	window.clear();
}

void Game::mainMenu()
{
	sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	int bufState;
	while (window.isOpen())
	{
		bufState = state;
		readInputMM();
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			drawMM();
			//updateMM();
			window.display();
		}
		if (bufState != state)
		{
			return;
		}
	}
}

void Game::drawMM()
{
	window.clear();
	sf::RectangleShape background;
	background.setPosition(sf::Vector2f(0, 0));
	background.setSize(sf::Vector2f(1920, 1080));
	background.setFillColor(sf::Color::Color(105, 105, 105));
	window.clear();
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
	window.draw(buttonSM.getBody());
	window.draw(labelButtonSM);
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
void Game::processInput()
{

}

void Game::arcadeMode()
{
	if (playerState == 0)
	{
		player = new Player(playerTexture);
		playerState = 1;
	}
	while (true)
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

void Game::arcadeModeRun(Player* player)
{
	window.clear();
	sf::Time TimePerFrame = sf::seconds(1.f / 144.f);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	int bufState, bufPaused;
	while (window.isOpen())
	{
		bufState = state;
		bufPaused = paused;
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		readInputAM();//checking what stupid human do
		arcadeModeRunUpdate();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			updatePlayer(TimePerFrame, player);
			updateEnemies(TimePerFrame, player);
			updateBullets(TimePerFrame, player);
			updateCollision(TimePerFrame, player);
			timeSinceLastUpdate -= TimePerFrame;
			window.clear();
			arcadeModeRunDraw(player);
			window.display();
		}
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
	}
}


void Game::arcadeModeRunUpdate()
{

}

void Game::arcadeModePause()
{
	window.clear();
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
	sf::RectangleShape buf(sf::Vector2f(1920, 1080));
	buf.setPosition(0, 0);
	buf.setFillColor(sf::Color(143, 188, 143));

	sf::Sprite cursor;
	cursor.setTexture(cursorTexture);
	cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition().x - 5, sf::Mouse::getPosition().y - 5));
	cursor.setScale(sf::Vector2f(5, 5));
	//background
	window.draw(buf);
	
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

	//cursor
	window.draw(cursor);
}

void Game::arcadeModePauseDraw(sf::Sprite prevFrame)
{
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

void Game::updateBullets(sf::Time elapsedTime, Player* player)
{
	castCooldown++;
	for (int i = 0; i < enemyCounter; i++)
	{
		sf::Vector2f posPlayer, posEnemy;
		int dist;
		posPlayer = player[0].getSprite().getPosition();
		posEnemy = enemyBuffer[i].getSprite().getPosition();
		dist = sqrt(pow(posPlayer.x - posEnemy.x, 2) + pow(posPlayer.y - posEnemy.y, 2));
		if (dist < 20000 and castCooldown > player[0].getCastSpeed())
		{
			castCooldown = 0;
			Bullet bullet(posPlayer, bulletTexture);
			bullet.setPos(posEnemy);
			bulletBuffer.push_back(bullet);
			bulletCounter++;
		}
	}
	for (int i = 0; i < bulletCounter; i++)
	{
		bulletBuffer[i].getSprite().setPosition(sf::Vector2f(
			bulletBuffer[i].getSprite().getPosition().x + bulletBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((bulletBuffer[i].getPos().x + 30 - bulletBuffer[i].getSprite().getPosition().x) / ((std::abs(bulletBuffer[i].getPos().x + 30 - bulletBuffer[i].getSprite().getPosition().x) + std::abs(bulletBuffer[i].getPos().y + 30 - bulletBuffer[i].getSprite().getPosition().y))))),
			bulletBuffer[i].getSprite().getPosition().y + bulletBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((bulletBuffer[i].getPos().y + 30 - bulletBuffer[i].getSprite().getPosition().y) / ((std::abs(bulletBuffer[i].getPos().x + 30 - bulletBuffer[i].getSprite().getPosition().x) + std::abs(bulletBuffer[i].getPos().y + 30 - bulletBuffer[i].getSprite().getPosition().y)))))
		));
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
	posPlayer = player[0].getSprite().getPosition();
	posEnemy.x = -200 + posPlayer.x + rand() % 600;
	posEnemy.y = -200 + posPlayer.y + rand() % 600;
	dist = sqrt(pow(posPlayer.x - posEnemy.x,2) + pow(posPlayer.y - posEnemy.y,2));
	if (dist > 1 and enemyCooldown > 500 and enemyCounter < 1000)
	{
		Enemy enemy(enemyTexture, posEnemy);
		enemyBuffer.push_back(enemy);
		enemyCounter++;
		enemyCooldown = 0;
	}
	for (int i = 0; i < enemyCounter; i++)
	{
		posEnemy = enemyBuffer[i].getSprite().getPosition();
		posPlayer = player[0].getSprite().getPosition();
		enemyBuffer[i].setPos(sf::Vector2f(
			posEnemy.x + enemyBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((posPlayer.x + 30 - posEnemy.x) / ((std::abs(posPlayer.x + 30 - posEnemy.x) + std::abs(posPlayer.y + 30 - posEnemy.y))))),
			posEnemy.y + enemyBuffer[i].getSpeed() * elapsedTime.asSeconds() * (((posPlayer.y + 30 - posEnemy.y) / ((std::abs(posPlayer.x + 30 - posEnemy.x) + std::abs(posPlayer.y + 30 - posEnemy.y)))))
		));
	}

}

void Game::updateCollision(sf::Time elapsedTime, Player* player)
{

}