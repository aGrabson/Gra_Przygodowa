#include "Slot.h"
void ItemSlot::setItem(Item tmp)
{
    empty = false;
    item = tmp;
}
ItemSlot::ItemSlot(Vector2f pos, Vector2f size, Color color)
{
    empty = true;
    slot.setPosition(pos);
    slot.setSize(size);
    slot.setFillColor(color);
}

Vector2f ItemSlot::getPosition()
{
    return slot.getPosition();
}

void ItemSlot::setPosition(Vector2f pos)
{
    slot.setPosition(pos);
}

Vector2f ItemSlot::getSize()
{
    return slot.getSize();
}

void ItemSlot::render(RenderTarget* target)
{
    target->draw(slot);
    if (empty == false)
    {

        item.setPos(slot.getPosition());
        item.render(target);

    }
}