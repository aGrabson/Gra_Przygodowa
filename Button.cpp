#include "Button.h"

Button::Button(){}

Button::Button(std::string path,Vector2f position)
{

	texture.loadFromFile(path);
	body.setTexture(texture);
	body.setPosition(position);
	body.setOrigin(body.getGlobalBounds().width/2,body.getGlobalBounds().height/2);
}

bool Button::PressDetection(const RenderWindow& window)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{

		if (body.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			return true;
		}
	}
	return false;
}

void Button::setScale(double x, double y)
{
	body.setScale(x, y);
}

void Button::update()
{
	
}

void Button::render(RenderTarget* target)
{
	target->draw(body);
}
