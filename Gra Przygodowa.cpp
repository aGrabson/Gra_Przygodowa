#include "Engine.h"


int main()
{
	srand(time(NULL));
    Engine game;
	while (game.isRunning())
	{
		game.update();
		game.render();
	}
    return 0;
}