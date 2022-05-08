#include "NPC.h"

void NPC::EntityAI(float pPosX, float pPosY, float dt, std::queue<double>& playerDamage, bool playerLastFrame)
{
	if (colision == true && colisionReaction == false)
	{

		colisionDirection = lastDirection;
		colisionReaction = true;
		if (colisionDirection == LEFT_D)
		{
			pointOfWalkAroud.x = position.x;
			pointOfWalkAroud.y = position.y - 150;
		}
		else if (colisionDirection == RIGHT_D)
		{
			pointOfWalkAroud.x = position.x;
			pointOfWalkAroud.y = position.y + 150;
		}
		else if (colisionDirection == UP_D)
		{
			pointOfWalkAroud.x = position.x - 150;
			pointOfWalkAroud.y = position.y;
		}
		else if (colisionDirection == DOWN_D)
		{
			pointOfWalkAroud.x = position.x + 150;
			pointOfWalkAroud.y = position.y;
		}

	}
	////////////////////////////////////////////

	if (colisionReaction == true)
	{

		if (backToPoint(pointOfWalkAroud.x, pointOfWalkAroud.y, dt))
		{

			colision = false;
			colisionReaction = false;
		}
		else
		{
			return;
		}
	}
	if (goTooDirection == false)
	{
		if (backToPoint(spawnPosX, spawnPosY, dt))
		{
			randPosX = spawnPosX + rand() % 400;
			randPosY = spawnPosY + rand() % 400;
		}

	}
	else
	{
		if (backToPoint(randPosX, randPosY, dt))
		{
			randPosX = spawnPosX + rand() % 400;
			randPosY = spawnPosY + rand() % 400;
		}
	}
}

void NPC::loadTextures()
{
	sf::Texture tmp;

	bodyTexture.loadFromFile("data/texture/npc/gd1.png");

	for (int i = 0; i < 3; i++)
	{
		tmp.loadFromFile("data/texture/npc/gd" + std::to_string(i + 1) + ".png");
		down.insert(std::make_pair("down" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/npc/gl" + std::to_string(i + 1) + ".png");
		left.insert(std::make_pair("left" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/npc/gp" + std::to_string(i + 1) + ".png");
		right.insert(std::make_pair("right" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/npc/gg" + std::to_string(i + 1) + ".png");
		up.insert(std::make_pair("up" + std::to_string(i + 1), tmp));
	}
}

NPC::NPC(float posx, float posy, float spawnPosX, float spawnPosY,bool movable, bool haveQuest, int questType)
{
	this->questType = questType;
	this->haveQuest = haveQuest;
	this->movable = movable;
	colisionReaction = false;
	colisionDirection = 0;
	pointOfWalkAroud = Vector2f(0, 0);
	colision = false;
	lastFrame = false;
	health = 100;
	goTooDirection = false;
	lastDirection = UP_D;
	loadTextures();
	hitbox.setFillColor(sf::Color(0, 0, 0, 0));
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(0);

	body.setTexture(bodyTexture);
	body.setOrigin(body.getGlobalBounds().width / 2, body.getGlobalBounds().height / 2);
	body.setScale(1, 1);


	hitbox.setSize(sf::Vector2f(body.getGlobalBounds().width, body.getGlobalBounds().height));
	hitbox.setOrigin(body.getGlobalBounds().width / 2, body.getGlobalBounds().height / 2);//to jest dobrze
	hitbox.scale(static_cast <float>(0.3), static_cast<float>(0.5));


	position.x = posx;
	position.y = posy;

	this->spawnPosX = spawnPosX;
	this->spawnPosY = spawnPosY;

	body.setPosition(sf::Vector2f(posx, posy));
	entitySpeed = 150;
	entitySpeedDown = entitySpeedUp = entitySpeedLeft = entitySpeedRight = 150;

	entityHealthBar.setColor(Color::Blue);
	if(haveQuest)
		entityHealthBar.setQuest(true);
}

void NPC::update(float pPosX, float pPosY, float dt, std::queue<double>& playerDamage, bool playerLastFrame, std::vector<Quest> &playerQuests)
{
	if (sqrt(pow(abs(position.x - pPosX), 2) + pow(abs(position.y - pPosY), 2)) > 2000)
		return;

	
	if (haveQuest)
	{
		bool canBeActive = true;
		for (int i = 0; i < playerQuests.size(); i++)
		{
	
			if (playerQuests[i].getType() == questType)
			{
				canBeActive = false;
			}
		}
		if (canBeActive)
			entityHealthBar.setQuest(true);
		if (sqrt(pow(abs(pPosX - position.x), 2) + pow(abs(pPosY - position.y), 2)) < 100)
		{
			if (Keyboard::isKeyPressed(Keyboard::R))
			{
				for (int i = 0; i < playerQuests.size(); i++)
				{
					if (playerQuests[i].getType() == questType)
						return;
					
				}
				playerQuests.push_back(Quest(questType));
				entityHealthBar.setQuest(false);
			}
		}
	}
	

	if (position.x)
		entityHealthBar.update(position, health);
	if(movable)
		EntityAI(pPosX, pPosY, dt, playerDamage, playerLastFrame);
	body.setPosition(position);
	hitbox.setPosition(position);
}

