#include "MapObjects.h"

void MapObjects::loadTexture(std::string path)
{
	texture.loadFromFile(path);
	//shape.setSize(sf::Vector2f(texture.getSize().x,texture.getSize().y));
	//shape.setOrigin(sf::Vector2f(texture.getSize().x/2, texture.getSize().y/2));
	//shape.setScale(5, 5);
	body.setTexture(texture);
	
}

void MapObjects::setBodyPosition(sf::Vector2f pos)
{
	sf::FloatRect tmp = body.getGlobalBounds();
	body.setPosition(pos);
	
}

void MapObjects::setHitBoxPosition(sf::Vector2f pos, float offsetx, float offsety)
{
	hitBox.setPosition(pos);
	hitBox.move(offsetx,offsety);
	//sf::FloatRect tmp = body.getGlobalBounds();
	//hitBox.setOrigin(50, 50);
}

void MapObjects::setHitboxSize(sf::Vector2f size)
{
	
	hitBox.setSize(size);
	sf::FloatRect tmp = hitBox.getGlobalBounds();
	hitBox.setOrigin(tmp.width/2, tmp.height);
	
}

sf::FloatRect MapObjects::getColisonGlobalBounds()
{
	return hitBox.getGlobalBounds();
}

sf::Vector2f MapObjects::getPosition()
{
	return body.getPosition();
}

void MapObjects::setTexture(sf::Texture* tmp)
{
	body.setTexture(*tmp);
	sf::FloatRect bounds = body.getGlobalBounds();
	body.setOrigin(bounds.width/2,bounds.height/2);
}

MapObjects::MapObjects(sf::Texture *tmp,float posx,float posy,float scaleX,float scaleY, float texscaleX, float texscaleY,float offsetx,float offsety)
{
	// Po trzebne tylko przy wyswietlaniu hitboxow
	hitBox.setFillColor(sf::Color(0, 0, 0, 0));
	hitBox.setOutlineColor(sf::Color::Red);
	hitBox.setOutlineThickness(2);
	/////////////////////////////////////////////////
	setBodyPosition(sf::Vector2f(posx,posy));
	setTexture(tmp);
	body.setScale(texscaleX, texscaleY);
	setHitboxSize(sf::Vector2f(body.getGlobalBounds().width*scaleX,body.getGlobalBounds().height*scaleY));
	setHitBoxPosition(sf::Vector2f(posx, posy+body.getGlobalBounds().height*0.55),offsetx,offsety);


	//loadTexture(path);
}

void MapObjects::update()
{
}

void MapObjects::render(sf::RenderTarget* target)
{
	target->draw(body);
	//target->draw(hitBox);
}
