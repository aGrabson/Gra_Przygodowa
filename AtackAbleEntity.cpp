#include "AtackAbleEntity.h"

void AtackAbleEntity::playAtackAnimation(double dt)
{
	if (lastDirection == DOWN_D)
	{
		bodyTexture = AtackDownAnimation.objectAnimation(adown, dt, 0.2, "down", lastFrame);
	}
	else if (lastDirection == UP_D)
	{
		bodyTexture = AtackUpAnimation.objectAnimation(aup, dt, 0.2, "up", lastFrame);
	}
	else if (lastDirection == LEFT_D)
	{
		bodyTexture = AtackLeftAnimation.objectAnimation(aleft, dt, 0.2, "left", lastFrame);
	}
	else if (lastDirection == RIGHT_D)
	{
		bodyTexture = AtackRightAnimation.objectAnimation(aright, dt, 0.2, "right", lastFrame);
	}
}
