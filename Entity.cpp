#include "Entity.h"

bool Entity::backToPoint(float pPosX, float pPosY, float dt)
{
	float distanceX = position.x - pPosX;
	float distanceY = position.y - pPosY;
	float distance = sqrt(pow(distanceX, 2) + pow(distanceY, 2));
	if (distance < 130)
	{
		goTooDirection = true;
		return true;
	}
	if (abs(distanceX)>10)
	{
			moveByX(distanceX, dt);
	}
	else if(abs(distanceY)>10)
	{
			moveByY(distanceY, dt);
	}
	return false;
}

void Entity::moveByX(float distanceX,float dt)
{
	//po x
	if (distanceX < 10)
	{
		//w prawo
		moveRight(dt);
		bodyTexture = rightAnimation.objectAnimation(right, dt, 0.1, "right", nop);
		lastDirection = RIGHT_D;
	}
	else if (distanceX > 10)
	{
		//w lewo
		moveLeft(dt);
		bodyTexture = leftAnimation.objectAnimation(left, dt, 0.1, "left", nop);
		lastDirection = LEFT_D;
	}
}

void Entity::moveByY(float distanceY, float dt)
{
	//po y
	if (distanceY < 0)
	{
		//w dó³
		moveDown(dt);
		bodyTexture = downAnimation.objectAnimation(down, dt, 0.1, "down", nop);
		lastDirection = DOWN_D;
	}
	else if (distanceY > 0)
	{
		//w góre
		moveUp(dt);
		bodyTexture = upAnimation.objectAnimation(up, dt, 0.1, "up", nop);
		lastDirection = UP_D;
	}
}

double Entity::getHp()
{
	return health;
}

void Entity::render(sf::RenderTarget* target, float pPosX, float pPosY)
{
	if (sqrt(pow(abs(position.x - pPosX), 2) + pow(abs(position.y - pPosY), 2)) > 2000)
		return;

	target->draw(hitbox);
	target->draw(body);
	entityHealthBar.render(target);
}
