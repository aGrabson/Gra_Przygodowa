#include "QuestLog.h"

QuestLog::QuestLog()
{
    font.loadFromFile("data/fonts/font.ttf");
    text.setCharacterSize(15);
    text.setFillColor(Color::White);
    text.setFont(font);
    text2.setCharacterSize(15);
    text2.setFillColor(Color::White);
    text2.setFont(font);
    visable = false;
    sizeX = 310;
    sizeY = 200;
    background.setPosition(0, 0);
    background.setSize(Vector2f(sizeX, sizeY));
    background.setFillColor(Color(0, 0, 0, 150));

    questBackground.setSize(Vector2f(250,40));
    questBackground.setFillColor(Color(127, 127, 127, 127));
    //przerwa 10px w szez
}

void QuestLog::show(RenderTarget* target, Vector2f pos, std::vector<Quest>& playerQuests)
{ 
    if (visable)
    {
        background.setPosition(Vector2f(pos.x + 450, pos.y - sizeY - 200));
        target->draw(background);
        double starposx= pos.x + 480;
        double starposy= pos.y - sizeY - 200;

        text.setString("Zadania");
        text.setPosition(pos.x+550, starposy+20);
        target->draw(text);

        for (int i = 0; i < playerQuests.size(); i++)
        {
            
            starposy += 50;
            text.setString(playerQuests[i].getDescription());
            text2.setString("progres: "+std::to_string(playerQuests[i].getCurrentProgress()) + "/" + std::to_string(playerQuests[i].getMaxProgress()));
            text.setPosition(starposx,starposy+5);
            text2.setPosition(starposx,starposy+25);

            questBackground.setPosition(starposx, starposy);

            target->draw(questBackground);
            target->draw(text);
            target->draw(text2);

            
        }
        
        
        
    }

}

