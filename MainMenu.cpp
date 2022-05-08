#include "MainMenu.h"

MainMenu::MainMenu(Vector2f screenSize)
{
	backgroundTexture.loadFromFile("data/texture/MainMenu/BACKGROUND.png");
	background.setTexture(backgroundTexture);
	newGameButton = new Button("data/texture/MainMenu/NEWGAME.png",Vector2f(screenSize.x/2,screenSize.y*0.3));
	continueButton = new Button("data/texture/MainMenu/CONTINUE.png",Vector2f(screenSize.x / 2, screenSize.y * 0.5));
	exitButton = new Button("data/texture/MainMenu/EXIT.png",Vector2f(screenSize.x / 2, screenSize.y * 0.7));

	newGameButton->setScale(0.8,0.8);
	continueButton->setScale(0.8, 0.8);
	exitButton->setScale(0.8, 0.8);
}

MainMenu::~MainMenu()
{
	delete newGameButton;
	delete continueButton;
	delete exitButton;
}

bool MainMenu::update(const RenderWindow& window, std::stack<int>&gameState, double health)
{

	if (newGameButton->PressDetection(window))
	{
		gameState.push(GAME);
		return true;
	}
	else if (continueButton->PressDetection(window))
	{
		if(health>0)
			gameState.push(GAME);
	}
	if (exitButton->PressDetection(window))
	{
		gameState.push(EXIT);
	}
	return false;
		
}

void MainMenu::render(RenderTarget* target)
{
	target->draw(background);
	newGameButton->render(target);
	continueButton->render(target);
	exitButton->render(target);
}
