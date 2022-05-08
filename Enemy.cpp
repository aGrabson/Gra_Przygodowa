#include "Enemy.h"

void Enemy::EntityAI(float pPosX, float pPosY,float dt, std::queue<double> &playerDamage,bool playerLastFrame,double damageDealt)
{
	if(colision==false)
		cpypos=position;
	if (colision==true /* && colisionReaction == false*/)
	{
		position = cpypos;
		/*
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
			pointOfWalkAroud.x = position.x-150;
			pointOfWalkAroud.y = position.y;
		}
		else if (colisionDirection == DOWN_D)
		{
			pointOfWalkAroud.x = position.x + 150;
			pointOfWalkAroud.y = position.y;
		}*/
		
	}
	////////////////////////////////////////////

	if (colisionReaction == true )
	{

		if (backToPoint(pointOfWalkAroud.x,pointOfWalkAroud.y,dt))
		{

			colision = false;
			colisionReaction = false;
		}
		else
		{
			return;
		}
	}

	////////////////////////////////////////////
	float distanceX=position.x- pPosX;
	float distanceY=position.y-pPosY;
	double distance = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
	
	if (distance < 300)
	{
		if (playerLastFrame)
		{

			health -= damageDealt;
		}
	}

	if (distance < 600)
	{
		
		
		if (backToPoint(pPosX, pPosY, dt))
		{
			playAtackAnimation(dt);
		}
		if (lastFrame)
		{
			playerDamage.push(5);
			lastFrame = false;
		}
		goTooDirection = false;
	}
	else
	{
		if (goTooDirection == false)
		{
			if (backToPoint(spawnPosX, spawnPosY, dt))
			{
				randPosX = spawnPosX + rand() % 400;			
				randPosY= spawnPosY + rand() % 400;
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
		

	
}

void Enemy::loadTextures()
{
	sf::Texture tmp;

	bodyTexture.loadFromFile("data/texture/skeleton/sd1.png");

	for (int i = 0; i < 5; i++)
	{
		tmp.loadFromFile("data/texture/skeleton/sd"+std::to_string(i+1)+".png");
		down.insert(std::make_pair("down"+std::to_string(i+1),tmp));

		tmp.loadFromFile("data/texture/skeleton/sl" + std::to_string(i + 1) + ".png");
		left.insert(std::make_pair("left" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/skeleton/sp" + std::to_string(i + 1) + ".png");
		right.insert(std::make_pair("right" + std::to_string(i + 1), tmp));

		tmp.loadFromFile("data/texture/skeleton/sg" + std::to_string(i + 1) + ".png");
		up.insert(std::make_pair("up" + std::to_string(i + 1), tmp));
	}

	for (int i = 5; i < 8; i++)
	{
		tmp.loadFromFile("data/texture/skeleton/sda" + std::to_string(i + 1) + ".png");
		adown.insert(std::make_pair("down" + std::to_string(i -4), tmp));

		tmp.loadFromFile("data/texture/skeleton/sla" + std::to_string(i + 1) + ".png");
		aleft.insert(std::make_pair("left" + std::to_string(i -4), tmp));

		tmp.loadFromFile("data/texture/skeleton/spa" + std::to_string(i + 1) + ".png");
		aright.insert(std::make_pair("right" + std::to_string(i -4), tmp));

		tmp.loadFromFile("data/texture/skeleton/sga" + std::to_string(i + 1) + ".png");
		aup.insert(std::make_pair("up" + std::to_string(i -4), tmp));
	}
}

Enemy::Enemy(float posx,float posy,float spawnPosX,float spawnPosY)
{
	colisionReaction = false;
	colisionDirection = 0;
	pointOfWalkAroud = Vector2f(0, 0);
	colision = false;
	lastFrame = false;
	health = 90;
	//srand(time(0));
	goTooDirection = false;
	lastDirection = UP_D;
	loadTextures();
	hitbox.setFillColor(sf::Color(0, 0, 0, 0));
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(0);


	body.setTexture(bodyTexture);
	body.setOrigin(body.getGlobalBounds().width/2,body.getGlobalBounds().height/2);
	body.setScale(3, 3);
	
	
	hitbox.setSize(sf::Vector2f(body.getGlobalBounds().width, body.getGlobalBounds().height));
	hitbox.setOrigin(body.getGlobalBounds().width / 2,body.getGlobalBounds().height / 2);//to jest dobrze
	hitbox.scale(static_cast < float>(0.3), static_cast<float>(0.5));


	position.x = posx;
	position.y = posy;

	this->spawnPosX = spawnPosX;
	this->spawnPosY = spawnPosY;

	body.setPosition(sf::Vector2f(posx,posy));
	entitySpeed = 200;
	entitySpeedDown = entitySpeedUp = entitySpeedLeft = entitySpeedRight = 200;
}

Vector2f Enemy::getPosition()
{
	return body.getPosition();
}

void Enemy::update(float pPosX, float pPosY,float dt, std::queue<double>& playerDamage, bool playerLastFrame , double damageDealt)
{
	if (sqrt(pow(abs(position.x - pPosX), 2) + pow(abs(position.y - pPosY), 2)) > 2000)
		return;

	if(position.x)
	entityHealthBar.update(position,health);
	EntityAI(pPosX,pPosY,dt,playerDamage,playerLastFrame,damageDealt);
	body.setPosition(position);
	hitbox.setPosition(position);
}

void Enemy::sethp(double values)
{
	health = values;
}
