#include "Engine.h"
Engine::Engine()
{

	gameMap = new GameMap();
	initVar();
	window->setFramerateLimit(60);
	gameState.push(MAINMENU);

}

Engine::~Engine()
{
	delete menu;
	delete window;
	delete player;
	delete gameMap;
	
}

void Engine::initVar()
{
	windowWidth = 1920;
	windowHeight = 1080;
	window = new RenderWindow(VideoMode(windowWidth,windowHeight),"Gra Przygodowa",Style::Default);
	player = new Player(&playerInventory,&playerEquipment,&playerQuestLog);
	menu =  new MainMenu(Vector2f(windowWidth,windowHeight));
	playerEquipment.setIconSprite((player->getPlayerFront()));
	gameFont.loadFromFile("data/fonts/font.ttf");
	playerEquipment.setFonts(gameFont);

}

bool Engine::isRunning()
{
	return window->isOpen();
}

void Engine::resetGame()
{
	player->restart();
	playerInventory.clear();
	playerEquipment.clear();
	gameMap->spawner->resetEnemies();
}

void Engine::detectColision()
{
	int column = gameMap->findColumn(player->getPlayerPosition().x);
	int row = gameMap->findRow(player->getPlayerPosition().y);
	int playerSector = gameMap->findSector(player->getPlayerPosition().x, player->getPlayerPosition().y);

	int neighborSector[8];
	neighborSector[0] = gameMap->findSector(column, row + 1, playerSector);;
	neighborSector[1] = gameMap->findSector(column+1, row + 1, playerSector);;
	neighborSector[2] = gameMap->findSector(column+1, row, playerSector);;
	neighborSector[3] = gameMap->findSector(column+1, row - 1, playerSector);;
	neighborSector[4] = gameMap->findSector(column, row - 1, playerSector);;
	neighborSector[5] = gameMap->findSector(column-1, row -1, playerSector);;
	neighborSector[6] = gameMap->findSector(column-1, row , playerSector);;
	neighborSector[7] = gameMap->findSector(column-1, row + 1, playerSector);;
	for (int j = 0; j < gameMap->sectors[playerSector]->SectorObjectsFront.size(); j++)
	{
		if (player->detectColision(gameMap->sectors[playerSector]->SectorObjectsFront[j]->getColisonGlobalBounds()))
		{
			player->setColision(true);
			return;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < gameMap->sectors[neighborSector[i]]->SectorObjectsFront.size(); j++)
		{
			if (player->detectColision(gameMap->sectors[neighborSector[i]]->SectorObjectsFront[j]->getColisonGlobalBounds()))
			{
				player->setColision(true);
				return;
			}
		}
	}
}
void Engine::updateCameraPos()
{
	Vector2f playerPosition = player->getPlayerPosition();
	//system("cls");
	//std::cout << gameMap.findPlayerSector(playerPosition.x,playerPosition.y);
	gameView.reset(FloatRect(playerPosition.x - windowWidth / 2, playerPosition.y - windowHeight / 2, windowWidth, windowHeight));
	//system("cls");
	//std::cout << playerPosition.x - windowWidth / 2 << playerPosition.y - windowHeight / 2;
	if (playerPosition.x - windowWidth / 2<0)
		gameView.reset(FloatRect(1,gameView.getCenter().y-windowHeight/2, windowWidth, windowHeight));
	if (playerPosition.y - windowHeight / 2<0)
		gameView.reset(FloatRect(gameView.getCenter().x-windowWidth/2, 1, windowWidth, windowHeight));


	if (playerPosition.y-windowHeight/2 > gameMap->getYSize()-windowHeight)
		gameView.reset(FloatRect(gameView.getCenter().x - windowWidth / 2, gameMap->getYSize() - windowHeight, windowWidth, windowHeight));


	if(playerPosition.x - windowWidth / 2 > gameMap->getXSize() - windowWidth)
		gameView.reset(FloatRect(gameMap->getXSize()-windowWidth, gameView.getCenter().y - windowHeight / 2, windowWidth, windowHeight));
	
	gameView.zoom(1);
	window->setView(gameView);

}

void Engine::updateTime()
{
	oneFrameTime = mainClock.restart();
}

void Engine::updateEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			window->close();
	}

}
void Engine::update()
{

	updateTime();
	updateEvents();
	if (gameState.top() == GAME)
	{
		if (player->itemFromQuest == true)
		{
			player->itemFromQuest = false;
			playerInventory.addItem(Item(&gameMap->items.find("potion")->second,Vector2f(0,0),"potion",0,0,0,-1));
		}
		bool tmpBool=false;
		Item tmpItem;
		playerInventory.update(tmpBool,tmpItem);
		if (tmpBool == true)
		{
			if (tmpItem.slotId == -1)
			{
				player->healthValues += 30;
				if (player->healthValues > 100)
					player->healthValues = 100;

			}
			else
			{
				playerEquipment.addItem(tmpItem, tmpBool);
				if (tmpBool == true)
				{
					tmpBool = false;
					playerInventory.addItem(tmpItem);
				}
			}
		}

		player->collectItem(gameMap->droppedItems);
		player->updatePart1(oneFrameTime.asSeconds(), gameMap->getColumn(), gameMap->getRow(),gameState);
		detectColision();
		player->updatePart2(oneFrameTime.asSeconds(), gameMap->getColumn(), gameMap->getRow());
		gameMap->updateMap(player->getPlayerPosition().x, player->getPlayerPosition().y, oneFrameTime.asSeconds(), player->receivedDamage, player->lastFrame,player->questEvents,player->playerQuests,player->damageValues+playerEquipment.getStat().damage);
		updateCameraPos();

	}
	else if (gameState.top() == MAINMENU)
	{
		if (menu->update(*window, gameState, player->healthValues))
		{
			resetGame();
		}
	}
	else if (gameState.top() == EXIT)
	{
		window->close();
	}
}

void Engine::render()
{
	if (gameState.top() == GAME)
	{
		window->clear(Color(0, 0, 0));
		// Rzeczy do wyswietlenia

		gameMap->render(window, *player);
		playerQuestLog.show(window, gameView.getCenter(),player->playerQuests);
		playerInventory.show(window, gameView.getCenter());
		playerEquipment.show(window, gameView.getCenter());

		//player.render(window);
	}
	else if (gameState.top() == MAINMENU)
	{
		gameView.reset(FloatRect(0,0, windowWidth, windowHeight));
		window->setView(gameView);
		menu->render(window);
	}
	window->display();
}
