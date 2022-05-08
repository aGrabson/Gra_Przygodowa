#include "Quest.h"

Quest::Quest(int type)
{
	complete = false;
	this->type = type;
	if (type == q1)
	{
		descripton = "Zabij 10 skieletów";
		maxProgress = 10;
		currentProgress = 0;
	}
	else if (type == q2)
	{
		descripton = "Zabij 15 skieletów";
		maxProgress = 15;
		currentProgress = 0;
	}
	else if (type == q3)
	{
		descripton = "Zabij 40 skieletów";
		maxProgress = 40;
		currentProgress = 0;
	}
}

std::string Quest::getDescription()
{
	return descripton;
}

int Quest::getMaxProgress()
{
	return maxProgress;
}

int Quest::getCurrentProgress()
{
	return currentProgress;
}

int Quest::getType()
{
	return type;
}

bool Quest::update(std::vector<int>& questEvents)
{
	if (complete == false)
	{
		switch (type)
		{
		case q1:
			//Zabij 10 szkieletow
			for (int i = 0; i < questEvents.size(); i++)
			{
				if (questEvents[i] == killSkeleton)
				{
					currentProgress++;
				}
			}
			break;
		case q2:
			for (int i = 0; i < questEvents.size(); i++)
			{
				if (questEvents[i] == killSkeleton)
				{
					currentProgress++;
				}
			}
			break;
		case q3:
			for (int i = 0; i < questEvents.size(); i++)
			{
				if (questEvents[i] == killSkeleton)
				{
					currentProgress++;
				}
			}
			break;

		default:
			break;
		}
		if (type == q1)
		{

		}
		else if (type == q2)
		{

		}
		else if (type == q3)
		{

		}

		questEvents.clear();
		if (currentProgress >= maxProgress)
		{
			complete = true;
		}
	}
	return complete;
}
