#include "MapSector.h"


void MapSector::createNewMapObject(sf::Texture *tmp,float posx, float posy,float scaleX,float scaleY,float texscaleX,float texscaleY,float offsetx, float offsety,int type)
{
	if(type==1)
		SectorObjectsFront.push_back(new MapObjects(tmp,posx,posy,scaleX,scaleY,texscaleX,texscaleY,offsetx,offsety));
	else
		SectorObjectsBack.push_back(new MapObjects(tmp, posx, posy, scaleX, scaleY, texscaleX, texscaleY,offsetx,offsety));
	
}

void MapSector::setVisable(bool value)
{
	visable = value;
}

MapSector::MapSector(sf::Texture *ground)
{

	setTextureForSprite(ground);
	visable = false;
	// do wyswietlania borderów
	border.setFillColor(sf::Color(0, 0, 0, 0));
	border.setOutlineColor(sf::Color::Red);
	border.setOutlineThickness(3);
	border.setPosition(sectorBody.getPosition());
	border.setSize(sf::Vector2f(sectorBody.getGlobalBounds().width, sectorBody.getGlobalBounds().height));
	///////////////////////////////////
}

void MapSector::setTextureForSprite(sf::Texture* ground)
{
	
	sectorBody.setTexture(*ground);
}

void MapSector::updateSector(float dt)
{

}

void MapSector::renderSector(float &renderPosX,float &renderPosY, RenderTarget *target)
{
	if (visable)
	{
		sectorBody.setPosition(renderPosX, renderPosY);
		border.setPosition(sectorBody.getPosition());//tez do borderow
		target->draw(sectorBody);
	
		//target->draw(border);
		
	}
}

void MapSector::renderObjectsFront(RenderTarget* target)
{
	if (visable)
	{
		for (int i = 0; i < SectorObjectsFront.size(); i++)
		{	
			SectorObjectsFront[i]->render(target);
		}
	}
	visable = false;
}

void MapSector::renderObjectsBack(RenderTarget* target)
{
	if (visable)
	{
		for (int i = 0; i < SectorObjectsBack.size(); i++)
		{
			SectorObjectsBack[i]->render(target);
		}
	}
}
