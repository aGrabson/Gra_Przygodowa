#include "Item.h"

Item::Item()
{
}

Item::Item(Texture *tex, Vector2f pos, std::string name, double armor, double agility, double damage, int slotId)
{
    this->slotId = slotId;
    body.setTexture(*tex);
    body.setPosition(pos);
    this->name = name;
    stat.agility = agility;
    stat.armor = armor;

    stat.damage = damage;
}

statistics Item::getStat()
{
    return stat;
}

FloatRect Item::getSize()
{
    return body.getGlobalBounds();
}

Vector2f Item::getPos()
{
    return body.getPosition();
}

void Item::setPos(Vector2f pos)
{
    body.setPosition(pos);
}

std::string Item::getName()
{
    return name;
}

void Item::update()
{
}

void Item::render(RenderTarget* target)
{
    target->draw(body);
}
