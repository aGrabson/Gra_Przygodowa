#include "EntityBase.h"
void EntityBase::moveDown(float dt)
{
	position.y += entitySpeedDown * dt;
}

void EntityBase::moveUp(float dt)
{
	position.y -= entitySpeedUp * dt;
}

void EntityBase::moveLeft(float dt)
{
	position.x -= entitySpeedLeft * dt;
}

void EntityBase::moveRight(float dt)
{
	position.x += entitySpeedRight * dt;
}

bool EntityBase::detectColision(std::vector<MapObjects*>& SectorObjects)
{
	for (int i = 0; i < SectorObjects.size(); i++)
	{
		if (hitbox.getGlobalBounds().intersects(SectorObjects[i]->getColisonGlobalBounds()))
		{
			colision = true;
			return true;
		}
			

	}
	
	return false;
}
