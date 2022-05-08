#include "Player.h"

void Player::loadTextures()
{
	Texture tmp;
	bodyTexture.loadFromFile("data/texture/player/d1.png");

	for (int i = 0; i < 5; i++)
	{
		tmp.loadFromFile("data/texture/player/d" + std::to_string(i + 1) + ".png");
		down.insert(std::make_pair("down" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/player/l" + std::to_string(i + 1) + ".png");
		left.insert(std::make_pair("left" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/player/p" + std::to_string(i + 1) + ".png");
		right.insert(std::make_pair("right" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/player/g" + std::to_string(i + 1) + ".png");
		up.insert(std::make_pair("up" + std::to_string(i + 1), tmp));

		
	}
	for (int i = 0; i < 3; i++)
	{
		tmp.loadFromFile("data/texture/player/ga" + std::to_string(i + 6) + ".png");
		aup.insert(std::make_pair("up" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/player/da" + std::to_string(i + 6) + ".png");
		adown.insert(std::make_pair("down" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/player/la" + std::to_string(i + 6) + ".png");
		aleft.insert(std::make_pair("left" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/player/pa" + std::to_string(i + 6) + ".png");
		aright.insert(std::make_pair("right" + std::to_string(i + 1), tmp));
	}
}

void Player::colisionReaction()
{
	if (colision)
	{/*
		if (lastKey == 'A')
		{
			entitySpeedLeft = 0;
		}
		if (lastKey == 'D')
		{
			entitySpeedRight = 0;
		}
		else if (lastKey == 'W')
		{
			entitySpeedUp = 0;
		}
		else if (lastKey == 'S')
		{
			entitySpeedDown = 0;
		}*/
		position = playerLastPos;
		body.setPosition(playerLastPos);
		hitbox.setPosition(playerLastPos);
		//entitySpeedLeft = entitySpeedRight = entitySpeedUp = entitySpeedDown = 0;
	}
	else
	{
		//entitySpeedDown = entitySpeedUp = entitySpeedLeft = entitySpeedRight = 900;
	}
	colision = false;
}

void Player::setDefaultParameters()
{
	armorValues = 0;
	damageValues =10;
	healthValues =100;
	agilityValues =30;
}

void Player::takeDamage()
{
	float tmp = armorValues + equipment->getStat().armor;
	if (tmp > 50)
		tmp = 50;
	while (!receivedDamage.empty())
	{
		healthValues -= receivedDamage.front()-((tmp)/100*receivedDamage.front());
		receivedDamage.pop();
	}
}


void Player::collectItem(std::vector<Item>& droppedItems)
{
	for (int i = 0;i<droppedItems.size(); i++)
	{

		if (body.getGlobalBounds().intersects(droppedItems[i].getSize()))
		{
			inventory->addItem(droppedItems[i]);
			droppedItems.erase(droppedItems.begin() + i);
			break;
		}
	}
}

Texture* Player::getPlayerFront()
{
	return &(down.find("down1")->second);
}

Player::Player(Inventory* inventory,Equipment * equipment,QuestLog *questlog)
{
	//playerQuests.push_back(Quest(q1));
	//playerQuests.push_back(Quest(q1));
	itemFromQuest = false;
	this->inventory = inventory;
	this->equipment = equipment;
	this->questlog = questlog;
	loadTextures();
	
	entityHealthBar.setColor(Color::Green);

	body.setPosition(640, 360);
	body.setTexture(bodyTexture);
	body.setOrigin(body.getGlobalBounds().width/2,body.getGlobalBounds().height/2);
	body.setScale(Vector2f(2,2));

	hitbox.setFillColor(Color(0, 0, 0, 0));
	hitbox.setOutlineColor(Color::Red);
	hitbox.setOutlineThickness(2);
	hitbox.setSize(Vector2f(body.getGlobalBounds().width,body.getGlobalBounds().height));
	hitbox.setOrigin(body.getGlobalBounds().width / 2, body.getGlobalBounds().height / 2);
	hitbox.setScale(0.5,0.5);

	position = startPos = Vector2f(3208,4385);
	entitySpeedDown = entitySpeedUp = entitySpeedLeft = entitySpeedRight = 300;
	colision = false;
	lastKey = 'V';
	IKeyReleased = true;
	EKeyReleased = true;
	EscapeKeyReleased = true;
	IKeyReleased = true;

	setDefaultParameters();
	equipment->setDefaultParameters(&healthValues, &damageValues, &armorValues, &agilityValues);
}

Player::~Player()
{

}

Vector2f Player::getPlayerPosition()
{
	return position;
}

void Player::restart()
{
	position = startPos;
	healthValues = 100;
	playerQuests.clear();
}

void Player::setColision(bool value)
{
	colision = value;
}

bool Player::detectColision(sf::FloatRect colisionObject)
{
	return hitbox.getGlobalBounds().intersects(colisionObject);
}



void Player::playerKeyControl(float oneFrameTime,int numberOfColumn,int numberOfRow, std::stack<int>& gameState)
{
		if(!colision)
		playerLastPos = position;
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			if(!colision)
			lastKey = 'A';
			lastDirection = LEFT_D;
			position.x -= (entitySpeedLeft+equipment->getStat().agility*10) * oneFrameTime;
			bodyTexture = leftAnimation.objectAnimation(left, oneFrameTime, 0.1, "left", nop);
			if (position.x <= 0)
				position.x = 0;
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			if (!colision)
			lastKey = 'D';
			lastDirection = RIGHT_D;
			position.x += (entitySpeedRight + equipment->getStat().agility * 10) * oneFrameTime;
			bodyTexture = rightAnimation.objectAnimation(right, oneFrameTime, 0.1, "right", nop);
			if (position.x >= numberOfColumn * 800 - body.getGlobalBounds().width)
				position.x = numberOfColumn * 800 - body.getGlobalBounds().width;
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (!colision)
			lastKey = 'W';
			lastDirection = UP_D;
			position.y -= (entitySpeedUp + equipment->getStat().agility * 10) * oneFrameTime;
			bodyTexture = upAnimation.objectAnimation(up, oneFrameTime, 0.1, "up", nop);
			if (position.y <= 0)
				position.y = 0;
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			if (!colision)
			lastKey = 'S';
			lastDirection = DOWN_D;
			position.y += (entitySpeedDown + equipment->getStat().agility * 10) * oneFrameTime;
			bodyTexture = downAnimation.objectAnimation(down, oneFrameTime, 0.1, "down", nop);
			if (position.y >= numberOfRow * 800 - body.getGlobalBounds().height)
				position.y = numberOfRow * 800 - body.getGlobalBounds().height;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			playAtackAnimation(oneFrameTime);
			lastKey = 'P';
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			if (EscapeKeyReleased)
			{
				gameState.pop();
				EscapeKeyReleased = false;
			}
		}
		else if (!Keyboard::isKeyPressed(Keyboard::Escape))
		{
			EscapeKeyReleased = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::I))
		{
			if (IKeyReleased)
			{
				if (inventory->visable == true)
					inventory->visable = false;
				else
					inventory->visable = true;
			}

			IKeyReleased = false;
		}
		else if (!Keyboard::isKeyPressed(Keyboard::I))
		{
			IKeyReleased = true;
		}

		if (Keyboard::isKeyPressed(Keyboard::E))
		{
			if (EKeyReleased)
			{
				if (equipment->visable == true)
					equipment->visable = false;
				else
					equipment->visable = true;
			}

			EKeyReleased = false;
		}
		else if (!Keyboard::isKeyPressed(Keyboard::E))
		{
			EKeyReleased = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Q))
		{
			if (QKeyReleased)
			{
				if (questlog->visable == true)
					questlog->visable = false;
				else
					questlog->visable = true;
			}
			QKeyReleased = false;
		}
		else
		{
			QKeyReleased = true;
		}
		body.setPosition(position);
}

void Player::updatePart1(float oneFrameTime, int numberOfColumn, int numberOfRow, std::stack<int> &gameState)
{
	for (int i = 0; i < playerQuests.size(); i++)
	{
		if (playerQuests[i].update(questEvents))
		{
			itemFromQuest = true;
			playerQuests.erase(playerQuests.begin()+i);
		}
	}
	if (playerQuests.empty())
		questEvents.clear();
	
	lastFrame = false;
	takeDamage();
	playerKeyControl(oneFrameTime, numberOfColumn, numberOfRow, gameState);
	hitbox.setPosition(body.getPosition());
	
	if (healthValues <= 0)
		gameState.pop();
}

void Player::updatePart2(float oneFrameTime, int numberOfColumn, int numberOfRow)
{
	colisionReaction();
	entityHealthBar.update(position, healthValues);
}

void Player::render(RenderTarget *target)
{
	//std::cout << "X:"<<position.x<<" "<< "y: "<<position.y<< std::endl;
	target->draw(body);
	//target->draw(hitbox);


}
