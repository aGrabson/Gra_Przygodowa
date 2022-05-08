#include "EnemySpawner.h"

void EnemySpawner::respawnEnemy(float dt)
{
	
	if (enemyGroup.size() <= numberOfEnemy)
	{
		int tmp = rand() % 5 + 1;
		respawnTime += dt;
		if (respawnTime >= 20)
		{
			respawnTime = 0;
			createEnemy(tmp);
		}
	}
}

void EnemySpawner::createEnemy(int number)
{
	float tmpX;
	float tmpY;
	int tmp1= static_cast<int>(size.x);
	int tmp2= static_cast<int>(size.y);
	srand(static_cast<unsigned>(time(NULL)));
	for (int i = 0; i < number; i++)
	{
		 tmpX = position.x + (rand() % static_cast<int>(size.x)) - (size.x / 2);
		 tmpY = position.y + (rand() % static_cast<int>(size.y)) - (size.y / 2);
		enemyGroup.push_back(new Enemy(tmpX,tmpY,tmpX,tmpY));
	}
}

EnemySpawner::EnemySpawner(Vector2f size,Vector2f position,int numberOfEnemy)
{
	this->position = position;
	this->size = size;
	this->numberOfEnemy = numberOfEnemy;
	respawnTime = 0;
	createEnemy(numberOfEnemy);
}

void EnemySpawner::detectVolision(std::vector<MapObjects*>& SectorObjects)
{
	for (int i = 0; i < enemyGroup.size(); i++)
	{
		enemyGroup[i]->colision=enemyGroup[i]->detectColision(SectorObjects);
	}
}

void EnemySpawner::update(float pPosX, float pPosY, float dt, std::queue<double>& playerDamage,bool playerLastFrame, std::vector<int>& questEvents, std::vector<Item> &droppedItems, std::map<std::string, Texture> &items, double damageDealt)
{
	respawnEnemy(dt);
	for (int i = 0; i < enemyGroup.size(); i++)
	{
		if (enemyGroup[i]->getHp() <= 0)
		{

			int num = rand() % 201;
			if (num<=20)
			{
				if(num<=5)
				droppedItems.push_back(Item(&items.find("belt1")->second, enemyGroup[i]->getPosition(), "belt", 5, 2, 0,2));
				else if (num <= 8)
				droppedItems.push_back(Item(&items.find("belt2")->second, enemyGroup[i]->getPosition(), "belt", 3, 6, 0,2));
				else if (num <= 12)
				droppedItems.push_back(Item(&items.find("belt3")->second, enemyGroup[i]->getPosition(), "belt", 6, 9, 0,2));
				else if (num <= 16)
				droppedItems.push_back(Item(&items.find("belt4")->second, enemyGroup[i]->getPosition(), "belt", 1, 7, 0,2));
				else if (num <= 20)
				droppedItems.push_back(Item(&items.find("belt5")->second, enemyGroup[i]->getPosition(), "belt", 4, 4, 0,2));
			}
			else if (num > 20 && num <= 40)
			{
				if (num <= 24)
					droppedItems.push_back(Item(&items.find("helmet1")->second, enemyGroup[i]->getPosition(), "helmet", 14, 5, 0, 0));
				else if (num <= 28)
					droppedItems.push_back(Item(&items.find("helmet2")->second, enemyGroup[i]->getPosition(), "helmet", 13, 6, 0, 0));
				else if (num <= 32)
					droppedItems.push_back(Item(&items.find("helmet3")->second, enemyGroup[i]->getPosition(), "helmet", 16, 6, 0, 0));
				else if (num <= 36)
					droppedItems.push_back(Item(&items.find("helmet4")->second, enemyGroup[i]->getPosition(), "helmet", 15, 3, 0, 0));
				else if (num <= 40)
					droppedItems.push_back(Item(&items.find("helmet5")->second, enemyGroup[i]->getPosition(), "helmet", 12, 10, 0, 0));
			}
			else if (num > 40 && num <= 60)
			{
				if (num <= 44)
					droppedItems.push_back(Item(&items.find("chest1")->second, enemyGroup[i]->getPosition(), "chest", 15, 0, 0, 1));
				else if (num <= 48)
					droppedItems.push_back(Item(&items.find("chest2")->second, enemyGroup[i]->getPosition(), "chest", 15, 3, 0, 1));
				else if (num <= 52)
					droppedItems.push_back(Item(&items.find("chest3")->second, enemyGroup[i]->getPosition(), "chest", 13, 6, 0, 1));
				else if (num <= 56)
					droppedItems.push_back(Item(&items.find("chest4")->second, enemyGroup[i]->getPosition(), "chest", 12, 2, 0, 1));
				else if (num <= 60)
					droppedItems.push_back(Item(&items.find("chest5")->second, enemyGroup[i]->getPosition(), "chest", 18, 11, 0, 1));
			}
			else if (num > 60 && num <= 70)
			{
				if (num <= 64)
					droppedItems.push_back(Item(&items.find("legins1")->second, enemyGroup[i]->getPosition(), "legins", 15, 5, 0, 3));
				else if (num <= 68)
					droppedItems.push_back(Item(&items.find("legins2")->second, enemyGroup[i]->getPosition(), "legins", 13, 4, 0, 3));
				else if (num <= 72)
					droppedItems.push_back(Item(&items.find("legins3")->second, enemyGroup[i]->getPosition(), "legins", 16, 1, 0, 3));
				else if (num <= 76)
					droppedItems.push_back(Item(&items.find("legins4")->second, enemyGroup[i]->getPosition(), "legins", 11, 4, 0, 3));
				else if (num <= 80)
					droppedItems.push_back(Item(&items.find("legins5")->second, enemyGroup[i]->getPosition(), "legins", 14, 3, 0, 3));
			}
			else if (num > 70 && num <= 90)
			{
				if (num <= 74)
					droppedItems.push_back(Item(&items.find("boots1")->second, enemyGroup[i]->getPosition(), "boots", 5, 15, 0, 4));
				else if (num <= 78)
					droppedItems.push_back(Item(&items.find("boots2")->second, enemyGroup[i]->getPosition(), "boots", 3, 20, 0, 4));
				else if (num <= 82)
					droppedItems.push_back(Item(&items.find("boots3")->second, enemyGroup[i]->getPosition(), "boots", 7, 13, 0, 4));
				else if (num <= 86)
					droppedItems.push_back(Item(&items.find("boots4")->second, enemyGroup[i]->getPosition(), "boots", 11, 4, 0, 4));
				else if (num <= 90)
					droppedItems.push_back(Item(&items.find("boots5")->second, enemyGroup[i]->getPosition(), "boots", 10, 1, 0, 4));
			}
			else if (num > 90 && num <= 115)
			{
				if (num <= 94)
					droppedItems.push_back(Item(&items.find("shield1")->second, enemyGroup[i]->getPosition(), "shield", 10, 3, 0, 5));
				else if (num <= 98)
					droppedItems.push_back(Item(&items.find("shield2")->second, enemyGroup[i]->getPosition(), "shield", 20, 10, 0, 5));
				else if (num <= 102)
					droppedItems.push_back(Item(&items.find("shield3")->second, enemyGroup[i]->getPosition(), "shield", 15, 4, 0, 5));
				else if (num <= 106)
					droppedItems.push_back(Item(&items.find("shield4")->second, enemyGroup[i]->getPosition(), "shield", 11, 3, 0, 5));
				else if (num <= 110)
					droppedItems.push_back(Item(&items.find("shield5")->second, enemyGroup[i]->getPosition(), "shield", 30, 0, 0, 5));
				else if (num <= 115)
					droppedItems.push_back(Item(&items.find("shield6")->second, enemyGroup[i]->getPosition(), "shield", 18, 5, 0, 5));
			}
			else if (num>=120&&num<=170)
			{
				if (num <= 120)
					droppedItems.push_back(Item(&items.find("sword1")->second, enemyGroup[i]->getPosition(), "sword", 0, 2, 30, 6));
				else if (num <= 125)
					droppedItems.push_back(Item(&items.find("sword2")->second, enemyGroup[i]->getPosition(), "sword", 0, 1, 24, 6));
				else if (num <= 130)
					droppedItems.push_back(Item(&items.find("sword3")->second, enemyGroup[i]->getPosition(), "sword", 0, 1, 21, 6));
				else if (num <= 135)
					droppedItems.push_back(Item(&items.find("sword4")->second, enemyGroup[i]->getPosition(), "sword", 0, 7, 11, 6));
				else if (num <= 140)
					droppedItems.push_back(Item(&items.find("sword5")->second, enemyGroup[i]->getPosition(), "sword", 0, 4, 17, 6));
				else if (num <= 145)
					droppedItems.push_back(Item(&items.find("sword6")->second, enemyGroup[i]->getPosition(), "sword", 0, 3, 8, 6));
				else if (num <= 150)
					droppedItems.push_back(Item(&items.find("sword7")->second, enemyGroup[i]->getPosition(), "sword", 0, 1, 15, 6));
				else if (num <= 155)
					droppedItems.push_back(Item(&items.find("sword8")->second, enemyGroup[i]->getPosition(), "sword", 0, 1, 23, 6));
				else if (num <= 160)
					droppedItems.push_back(Item(&items.find("sword9")->second, enemyGroup[i]->getPosition(), "sword", 0, 7, 26, 6));
				else if (num <= 165)
					droppedItems.push_back(Item(&items.find("sword10")->second, enemyGroup[i]->getPosition(), "sword", 0, 9, 30, 6));
				else if (num <= 170)
					droppedItems.push_back(Item(&items.find("sword11")->second, enemyGroup[i]->getPosition(), "sword", 0, 4, 19, 6));
			}
			

			enemyGroup.erase(enemyGroup.begin() + i);
			questEvents.push_back(killSkeleton);


			

		}
		enemyGroup[i]->update(pPosX, pPosY, dt, playerDamage, playerLastFrame,damageDealt);
	}
		
}

void EnemySpawner::render(RenderTarget* target, float pPosX, float pPosY)
{

	for (int i = 0; i < enemyGroup.size(); i++)
		enemyGroup[i]->render(target,pPosX,pPosY);
}

void EnemySpawner::resetEnemies()
{
	for (int i = 0; i < enemyGroup.size(); i++)
	{
		enemyGroup[i]->sethp(100);
	}
}
