#include "Equipment.h"

void Equipment::positioningSlots(Vector2f bcgPos)
{
	slots[0].setPosition(Vector2f(bcgPos.x + 10, bcgPos.y + 10));
	slots[1].setPosition(Vector2f(bcgPos.x + 10, bcgPos.y + 70));
	slots[2].setPosition(Vector2f(bcgPos.x + 10, bcgPos.y + 130));
	slots[3].setPosition(Vector2f(bcgPos.x + 10, bcgPos.y + 190));

	slots[4].setPosition(Vector2f(bcgPos.x + 250, bcgPos.y + 10));
	slots[5].setPosition(Vector2f(bcgPos.x + 250, bcgPos.y + 70));
	slots[6].setPosition(Vector2f(bcgPos.x + 250, bcgPos.y + 130));
}
void Equipment::updateStatistics(Vector2f pos)
{
	armor.setString("ARMOR: "+std::to_string(*armorValues+bonusStat.armor));
	armor.setPosition(pos.x+10,pos.y+300);

	damage.setString("DAMAGE: " + std::to_string(*damageValues+bonusStat.damage));
	damage.setPosition(pos.x + 10, pos.y + 325);

	health.setString("HEALTH: " + std::to_string(*healthValues));
	health.setPosition(pos.x + 10, pos.y + 350);

	agility.setString("AGILITY: " + std::to_string(*agilityValues+bonusStat.agility));
	agility.setPosition(pos.x + 10, pos.y + 375);
}
void Equipment::setFonts(const Font& font)
{
	gameFont = font;
}
void Equipment::createSlots()
{
	for(int i=0;i<7;i++)
		slots.push_back(ItemSlot(Vector2f(0, 0), Vector2f(50, 50), Color(255, 229, 180, 90)));
}

void Equipment::setDefaultParameters(double* health, double* damage, double* armor, double* agility)
{
	armorValues = armor;
	damageValues = damage;
	agilityValues = agility;
	healthValues = health;
}

Equipment::Equipment()
{
	visable = false;
	sizeX = 310;
	sizeY = 400;
	background.setPosition(0, 0);
	background.setSize(Vector2f(sizeX, sizeY));
	background.setFillColor(Color(0, 0, 0, 150));

	//gameFont.loadFromFile("data/fonts/font.ttf");

	armor.setFont(gameFont);
	damage.setFont(gameFont);
	health.setFont(gameFont);
	agility.setFont(gameFont);

	armor.setFillColor(Color::White);
	damage.setFillColor(Color::White);
	health.setFillColor(Color::White);
	agility.setFillColor(Color::White);

	armor.setCharacterSize(12);
	damage.setCharacterSize(12);
	health.setCharacterSize(12);
	agility.setCharacterSize(12);

	bonusStat.agility = 0;
	bonusStat.armor = 0;
	bonusStat.damage = 0;

	createSlots();
}

void Equipment::update()
{

}

void Equipment::clear()
{
	for (int i = 0; i < slots.size(); i++)
	{
		slots[i].empty = true;
	}
	bonusStat.agility = 0;
	bonusStat.armor = 0;
	bonusStat.damage = 0;
}

statistics Equipment::getStat()
{
	return bonusStat;
}

void Equipment::addItem(Item &item,bool &tmpbool)
{
	Item tmp;
	if (slots[item.slotId].empty == true)
	{
		bonusStat.agility += item.getStat().agility;
		bonusStat.armor	+= item.getStat().armor;
		bonusStat.damage += item.getStat().damage;
		slots[item.slotId].item = item;
		slots[item.slotId].empty = false;
		tmpbool = false;
	}
	else
	{
		bonusStat.agility	-= slots[item.slotId].item.getStat().agility;
		bonusStat.armor		 -= slots[item.slotId].item.getStat().armor;
		bonusStat.damage	-= slots[item.slotId].item.getStat().damage;

		bonusStat.agility += item.getStat().agility;
		bonusStat.armor += item.getStat().armor;
		bonusStat.damage += item.getStat().damage;

		tmpbool = true;
		tmp = slots[item.slotId].item;
		slots[item.slotId].item = item;
		slots[item.slotId].empty = false;
		item = tmp;
	}
	
}

void Equipment::setIconSprite(Texture* player)
{
	playerIcon.setTexture(*player);
	playerIcon.setOrigin(playerIcon.getGlobalBounds().width/2,playerIcon.getGlobalBounds().height/2);
	playerIcon.setScale(4, 4);
}

void Equipment::show(RenderTarget* target, Vector2f pos)
{
	if (visable)
	{
		
		background.setPosition(Vector2f(pos.x - 770, pos.y - sizeY / 2));
		playerIcon.setPosition(Vector2f(pos.x - 770+ background.getLocalBounds().width/2, pos.y - sizeY / 2+ background.getLocalBounds().height / 2-60));
		updateStatistics(background.getPosition());
		target->draw(background);
		target->draw(playerIcon);
		positioningSlots(background.getPosition());
		for (int i = 0; i < slots.size(); i++)
		{
			slots[i].render(target);
		}
		target->draw(armor);
		target->draw(damage);
		target->draw(health);
		target->draw(agility);
	}
}
