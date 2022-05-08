#include "GameMap.h"

GameMap::GameMap()
{
	spawner = new EnemySpawner(Vector2f(4000, 700), Vector2f(2000, 2500),10);
	//e1 = new Enemy(300,300, 300, 300);
	//e2 = new Enemy(600, 600, 600, 600);
	//e3 = new Enemy(1500,1500, 1500, 1500);
	NpcContainer.push_back(new NPC(1330, 1850, 1330, 1850,false,true,q1));
	NpcContainer.push_back(new NPC(1080, 1850, 1080, 1850,false, false, q1));
	NpcContainer.push_back(new NPC(2200, 1300, 2200, 1300,true, true, q2));
	NpcContainer.push_back(new NPC(1800, 500, 1800, 500,true, false, q1));
	NpcContainer.push_back(new NPC(1800, 500, 1800, 500,true, false, q1));
	NpcContainer.push_back(new NPC(2000, 350, 2000, 350,true, true, q3));

	initMap();
	initVar();
	loadGroundTextures();
	loadSectors();
	loadMapObjectTexture();
	loadObjectsFromFile();
	//sectors[0]->createNewMapObject(objectTextures.find("bush")->second, 200, 200);

}

GameMap::~GameMap()
{
	//delete spawner;
}


float GameMap::getXSize()
{
	return numberOfColumn * 800;
}

float GameMap::getYSize()
{
	return numberOfRow * 800;
}

int GameMap::getColumn()
{
	return numberOfColumn;
}

int GameMap::getRow()
{
	return numberOfRow;
}

void GameMap::renderItems(RenderTarget* target)
{
	for (int i = 0; i < droppedItems.size(); i++)
	{
		droppedItems[i].render(target);
	}
}


void GameMap::initVar()
{
	numbersOfSectors = 30;
	camPosX = camPosY = 0;
	numberOfColumn = 5;
	numberOfRow = 6;
}



void GameMap::loadGroundTextures()
{
	groundTextures.insert(std::make_pair("grass_nopath", new Texture));
	groundTextures.find("grass_nopath")->second->loadFromFile("data/map/grass_nopath.png");

	groundTextures.insert(std::make_pair("grass_lurd", new Texture));
	groundTextures.find("grass_lurd")->second->loadFromFile("data/map/grass_lurd.png");

	groundTextures.insert(std::make_pair("grass_lr", new Texture));
	groundTextures.find("grass_lr")->second->loadFromFile("data/map/grass_lr.png");

	groundTextures.insert(std::make_pair("grass_ud", new Texture));
	groundTextures.find("grass_ud")->second->loadFromFile("data/map/grass_ud.png");

	groundTextures.insert(std::make_pair("grass_lrd", new Texture));
	groundTextures.find("grass_lrd")->second->loadFromFile("data/map/grass_lrd.png");

	groundTextures.insert(std::make_pair("grass_lur", new Texture));
	groundTextures.find("grass_lur")->second->loadFromFile("data/map/grass_lur.png");

	groundTextures.insert(std::make_pair("grass_lud", new Texture));
	groundTextures.find("grass_lud")->second->loadFromFile("data/map/grass_lud.png");

	groundTextures.insert(std::make_pair("grass_urd", new Texture));
	groundTextures.find("grass_urd")->second->loadFromFile("data/map/grass_urd.png");

	groundTextures.insert(std::make_pair("grass_ld", new Texture));
	groundTextures.find("grass_ld")->second->loadFromFile("data/map/grass_ld.png");

	groundTextures.insert(std::make_pair("grass_rd", new Texture));
	groundTextures.find("grass_rd")->second->loadFromFile("data/map/grass_rd.png");

	groundTextures.insert(std::make_pair("grass_ur", new Texture));
	groundTextures.find("grass_ur")->second->loadFromFile("data/map/grass_ur.png");

	groundTextures.insert(std::make_pair("grass_lu", new Texture));
	groundTextures.find("grass_lu")->second->loadFromFile("data/map/grass_lu.png");
}

void GameMap::loadSectors()
{
	std::fstream file;
	std::map<char, std::string>::iterator it;
	file.open("data/map/map.txt", std::ios::in);
	if (!file.good())
	{
		std::cout << "No such file\n";
	}
	while (!file.eof())
	{
		char sectorType;
		file >> sectorType;
		it = fileNames.find(sectorType);
		std::string path = "data/map/"+it->second;
		sectors.push_back(new MapSector(groundTextures.find(it->second)->second));
	}
	file.close();
}

void GameMap::loadMapObjectTexture()
{
	Texture tmp = Texture();
	tmp.loadFromFile("data/texture/house/house.png");
	objectTextures.insert(std::make_pair("house", tmp));
	tmp.loadFromFile("data/texture/house/shouse.png");
	objectTextures.insert(std::make_pair("shouse", tmp));
	tmp.loadFromFile("data/texture/house/bhouse.png");
	objectTextures.insert(std::make_pair("bhouse", tmp));
	tmp.loadFromFile("data/texture/house/h2.png");
	objectTextures.insert(std::make_pair("h2", tmp));
	tmp.loadFromFile("data/texture/house/h3.png");
	objectTextures.insert(std::make_pair("h3", tmp));
	tmp.loadFromFile("data/texture/house/h4.png");
	objectTextures.insert(std::make_pair("h4", tmp));
	tmp.loadFromFile("data/texture/house/h5.png");
	objectTextures.insert(std::make_pair("h5", tmp));
	tmp.loadFromFile("data/texture/house/h6.png");
	objectTextures.insert(std::make_pair("h6", tmp));
	tmp.loadFromFile("data/texture/house/h7.png");
	objectTextures.insert(std::make_pair("h7", tmp));
	tmp.loadFromFile("data/texture/house/h8.png");
	objectTextures.insert(std::make_pair("h8", tmp));
	tmp.loadFromFile("data/texture/house/h9.png");
	objectTextures.insert(std::make_pair("h9", tmp));
	tmp.loadFromFile("data/texture/house/h10.png");
	objectTextures.insert(std::make_pair("h10", tmp));
	tmp.loadFromFile("data/texture/house/h11.png");
	objectTextures.insert(std::make_pair("h11", tmp));
	tmp.loadFromFile("data/texture/house/h12.png");
	objectTextures.insert(std::make_pair("h12", tmp));
	tmp.loadFromFile("data/texture/house/h14.png");
	objectTextures.insert(std::make_pair("h14", tmp));
	tmp.loadFromFile("data/texture/house/h15.png");
	objectTextures.insert(std::make_pair("h15", tmp));
	tmp.loadFromFile("data/texture/house/h16.png");
	objectTextures.insert(std::make_pair("h16", tmp));


	tmp.loadFromFile("data/texture/wall.png");
	objectTextures.insert(std::make_pair("wall", tmp));
	tmp.loadFromFile("data/texture/wallup.png");
	objectTextures.insert(std::make_pair("wallup", tmp));
	tmp.loadFromFile("data/texture/gate_open.png");
	objectTextures.insert(std::make_pair("gate_open", tmp));
	tmp.loadFromFile("data/texture/gate_closed.png");
	objectTextures.insert(std::make_pair("gate_closed", tmp));


	tmp.loadFromFile("data/texture/logs/log1.png");
	objectTextures.insert(std::make_pair("log1", tmp));
	tmp.loadFromFile("data/texture/logs/log2.png");
	objectTextures.insert(std::make_pair("log2", tmp));
	tmp.loadFromFile("data/texture/logs/log3.png");
	objectTextures.insert(std::make_pair("log3", tmp));
	tmp.loadFromFile("data/texture/logs/log4.png");
	objectTextures.insert(std::make_pair("log4", tmp));


	tmp.loadFromFile("data/texture/bush2.png");
	objectTextures.insert(std::make_pair("bush", tmp));


	tmp.loadFromFile("data/texture/Tree/Tree1/1.png");//za�adowanie bazowej tekstury do bufora tmp
	objectTextures.insert(std::make_pair("tree", tmp));//umieszczenie bazowej testury w mapie pod konkretna nazwa ktora jest uzywana w pliku txt do identyfikacji textur obiektow

	tmp.loadFromFile("data/texture/Tree/Tree4/1.png");
	objectTextures.insert(std::make_pair("tree4", tmp));

	tmp.loadFromFile("data/texture/River_Top_Left/1.png");
	objectTextures.insert(std::make_pair("river_top_left", tmp));


	tmp.loadFromFile("data/texture/River_Top_Middle/1.png");
	objectTextures.insert(std::make_pair("river_top_middle", tmp));

	tmp.loadFromFile("data/texture/pillar.png");
	objectTextures.insert(std::make_pair("pillar", tmp));

	tmp.loadFromFile("data/texture/stone_circle.png");
	objectTextures.insert(std::make_pair("stone_circle", tmp));

	tmp.loadFromFile("data/texture/campfire/1.png");
	objectTextures.insert(std::make_pair("campfire", tmp));

	tmp.loadFromFile("data/texture/rock.png");
	objectTextures.insert(std::make_pair("rock", tmp));



	for (int i = 0; i < 6; i++)
	{
		tmp.loadFromFile("data/texture/campfire/" + to_string(i + 1) + ".png");
		fireplace.insert(std::make_pair("campfire" + to_string(i + 1), tmp));
	}

	


	for (int i = 0; i < 4; i++)//�adowanie w petli animacji oiektu
	{
		tmp.loadFromFile("data/texture/Tree/Tree1/" + to_string(i + 1) + ".png");
		tree1.insert(std::make_pair("tree" + to_string(i + 1), tmp));//umieszcznie tekstur w mapie z teksturami animacji danego obiektu
	}
	for (int i = 0; i < 4; i++)
	{
		tmp.loadFromFile("data/texture/Tree/Tree4/" + to_string(i + 1) + ".png");
		tree4.insert(std::make_pair("tree" + to_string(i + 1), tmp));
	}
	for (int i = 0; i < 5; i++)
	{
		tmp.loadFromFile("data/texture/items/belts/b" + to_string(i + 1) + ".png");
		items.insert(std::make_pair("belt"+to_string(i + 1), tmp));
	}

	for (int i = 0; i < 5; i++)
	{
		tmp.loadFromFile("data/texture/items/helmets/h" + to_string(i + 1) + ".png");
		items.insert(std::make_pair("helmet" + to_string(i + 1), tmp));
	}

	for (int i = 0; i < 5; i++)
	{
		tmp.loadFromFile("data/texture/items/chests/ch" + to_string(i + 1) + ".png");
		items.insert(std::make_pair("chest" + to_string(i + 1), tmp));
	}

	for (int i = 0; i < 5; i++)
	{
		tmp.loadFromFile("data/texture/items/legins/l" + to_string(i + 1) + ".png");
		items.insert(std::make_pair("legins" + to_string(i + 1), tmp));
	}

	for (int i = 0; i < 11; i++)
	{
		tmp.loadFromFile("data/texture/items/swords/s" + to_string(i + 1) + ".png");
		items.insert(std::make_pair("sword" + to_string(i + 1), tmp));
	}
	for (int i = 0; i < 5; i++)
	{
		tmp.loadFromFile("data/texture/items/boots/b" + to_string(i + 1) + ".png");
		items.insert(std::make_pair("boots" + to_string(i + 1), tmp));
	}
	for (int i = 0; i < 6; i++)
	{
		tmp.loadFromFile("data/texture/items/shields/sh" + to_string(i + 1) + ".png");
		items.insert(std::make_pair("shield" + to_string(i + 1), tmp));
	}
	tmp.loadFromFile("data/texture/items/potion.png");
	items.insert(std::make_pair("potion", tmp));
}

void GameMap::loadObjectsFromFile()
{
	
	Script_interpreter interpreter;
	Script objectInfo = interpreter.readFile("data/objects/objects.txt");
	int sector_num;

	for (int i = 0; i < objectInfo.size(); i++)
	{
		sector_num = findSector(objectInfo[i].column,objectInfo[i].row,0);
		if(objectInfo[i].texture_name=="stone_circle")//elementy pod graczem
			sectors[sector_num]->createNewMapObject(&objectTextures.find(objectInfo[i].texture_name)->second, objectInfo[i].posx+800*objectInfo[i].column, objectInfo[i].posy+800* objectInfo[i].row, objectInfo[i].colision_x_scale, objectInfo[i].colision_y_scale,objectInfo[i].texture_scale_X, objectInfo[i].texture_scale_Y,objectInfo[i].offsetx,objectInfo[i].offsety,2);
		else//elementy nad graczem
			sectors[sector_num]->createNewMapObject(&objectTextures.find(objectInfo[i].texture_name)->second, objectInfo[i].posx + 800 * objectInfo[i].column, objectInfo[i].posy + 800 * objectInfo[i].row, objectInfo[i].colision_x_scale, objectInfo[i].colision_y_scale, objectInfo[i].texture_scale_X, objectInfo[i].texture_scale_Y, objectInfo[i].offsetx, objectInfo[i].offsety, 1);
	}
		
}







void GameMap::renderBackground(RenderTarget* target, Player& player)
{
	float startXCp = camPosX;
	float startYCp = camPosY;

	for (int i = 0; i < numbersOfSectors; i++)
	{
		camPosX += 800;
		if ((i) % numberOfColumn == 0)
		{
			camPosY += 800;
			camPosX = 0;
		}
		if (i == 0)
			camPosY = 0;

		sectors[i]->renderSector(camPosX, camPosY, target);
	}
	for (int i = 0; i < numbersOfSectors; i++)
	{
		sectors[i]->renderObjectsBack(target);
	}

	player.render(target);
	spawner->render(target, player.getPlayerPosition().x,player.getPlayerPosition().y);
	
	
	//e2->render(target);
	//e3->render(target);

	for (int i = 0; i < numbersOfSectors; i++)
	{
		sectors[i]->renderObjectsFront(target);
	}
	for (int i = 0; i < NpcContainer.size(); i++)
	{
		NpcContainer[i]->render(target, player.getPlayerPosition().x, player.getPlayerPosition().y);
	}
	player.entityHealthBar.render(target);
	
	camPosX = startXCp;
	camPosY = startYCp;

}

void GameMap::initMap()
{
	fileNames.insert(std::make_pair('a', "grass_nopath"));
	fileNames.insert(std::make_pair('b', "grass_lurd"));
	fileNames.insert(std::make_pair('c', "grass_lr"));
	fileNames.insert(std::make_pair('d', "grass_ud"));
	fileNames.insert(std::make_pair('e', "grass_lrd"));
	fileNames.insert(std::make_pair('f', "grass_lur"));
	fileNames.insert(std::make_pair('g', "grass_lud"));
	fileNames.insert(std::make_pair('h', "grass_urd"));
	fileNames.insert(std::make_pair('i', "grass_ld"));
	fileNames.insert(std::make_pair('j', "grass_rd"));
	fileNames.insert(std::make_pair('k', "grass_ur"));
	fileNames.insert(std::make_pair('l', "grass_lu"));
}

int GameMap::findSector(float playerX, float playerY)
{
	int column=playerX/800;
	int row=playerY/800;

	int sectorID = row * numberOfColumn + column;

	return sectorID;
}

int GameMap::findSector(int column, int row , int playerSector)
{
	if (column < 0 || column >= numberOfColumn || row < 0 || row >= numberOfRow)
		return playerSector;
	return row*numberOfColumn + column;
}

int GameMap::findColumn(float playerX)
{
	return playerX/800;
}



int GameMap::findRow(float playerY)
{
	return playerY/800;
}

void GameMap::render(RenderTarget* target,Player& player)
{
	renderBackground(target,player);
	renderItems(target);
	
}

void GameMap::updateMap(float playerX, float playerY, float dt, std::queue<double>& playerDamage, bool playerLastFrame, std::vector<int>& questEvents, std::vector<Quest>& playerQuests, double damageDealt)
{
	for (int i = 0; i < NpcContainer.size(); i++)
	{
		NpcContainer[i]->update(playerX, playerY, dt, playerDamage, playerLastFrame, playerQuests);
	}



	spawner->update(playerX, playerY, dt, playerDamage, playerLastFrame, questEvents, droppedItems, items, damageDealt);


	int column = findColumn(playerX);
	int row = findRow(playerY);
	int playerSector = findSector(playerX, playerY);

	spawner->detectVolision(sectors[playerSector]->SectorObjectsFront);

	sectors[playerSector]->setVisable(true);



	sectors[findSector(column + 1, row, playerSector)]->setVisable(true);
	sectors[findSector(column + 2, row, playerSector)]->setVisable(true);
	sectors[findSector(column - 1, row, playerSector)]->setVisable(true);
	sectors[findSector(column - 2, row, playerSector)]->setVisable(true);

	sectors[findSector(column, row + 1, playerSector)]->setVisable(true);
	sectors[findSector(column, row - 1, playerSector)]->setVisable(true);

	sectors[findSector(column + 1, row - 1, playerSector)]->setVisable(true);
	sectors[findSector(column + 2, row - 1, playerSector)]->setVisable(true);

	sectors[findSector(column + 1, row + 1, playerSector)]->setVisable(true);
	sectors[findSector(column + 2, row + 1, playerSector)]->setVisable(true);

	sectors[findSector(column - 1, row - 1, playerSector)]->setVisable(true);
	sectors[findSector(column - 2, row - 1, playerSector)]->setVisable(true);

	sectors[findSector(column - 1, row + 1, playerSector)]->setVisable(true);
	sectors[findSector(column - 2, row + 1, playerSector)]->setVisable(true);




	bool nop;
	objectTextures.find("campfire")->second = fireplaceAnimation.objectAnimation(fireplace, dt, 0.1, "campfire", nop);
	objectTextures.find("tree")->second = treeAnimation.objectAnimation(tree1, dt, 0.1, "tree", nop);//odgrywanie animacji obiektu
	objectTextures.find("tree4")->second = tree4Animation.objectAnimation(tree4, dt, 0.1, "tree", nop);
}
