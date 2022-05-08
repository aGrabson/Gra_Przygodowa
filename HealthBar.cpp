#include "HealthBar.h"

HealthBar::HealthBar(Color healthColor)
{
	haveQuest = false;
	healthBar.setSize(Vector2f(100, 10));
	healthBar.setFillColor(healthColor);
	healthBarBackGround.setSize(Vector2f(100, 10));
	healthBarBackGround.setFillColor(Color(105, 105, 105));
	healthBarBackGround.setOutlineColor(Color::Black);
	healthBarBackGround.setOutlineThickness(2);

	font.loadFromFile("data/fonts/font.ttf");
	healthText.setFont(font);

	healthText.setString("Health:");
	healthText.setFillColor(Color::White);
	healthText.setCharacterSize(8);

	questChar.setFont(font);
	questChar.setString("!");
	questChar.setFillColor(Color::Yellow);
	questChar.setCharacterSize(25);
}

void HealthBar::setQuest(bool value)
{
	haveQuest = value;
}

void HealthBar::setColor(Color color)
{
	healthBar.setFillColor(color);
}

void HealthBar::render(RenderTarget *target)
{
	target->draw(healthBarBackGround);
	target->draw(healthBar);
	target->draw(healthText);
	if(haveQuest)
		target->draw(questChar);
}

void HealthBar::update(const Vector2f& EntityPos,double &health)
{
	std::string tmp = std::to_string(health);
	tmp.resize(5);
	tmp += "/100 hp";
	//std::string tmp = std::to_string(health) + "/100 hp";
	healthText.setString(tmp);
	healthBarBackGround.setPosition(EntityPos.x - 40, EntityPos.y - 80);
	questChar.setPosition(EntityPos.x - 40+120, EntityPos.y - 80);
	healthBar.setPosition(EntityPos.x - 40, EntityPos.y - 80);
	healthBar.setSize(Vector2f(health, 10));
	healthText.setPosition(EntityPos.x - 40, EntityPos.y -80);
}
