#pragma once

#include "Button.h"
#include <stack>
//using namespace sf;
/**
 * @brief Struktura stanów silnika gry
 * 
 */
enum stateTitle { MAINMENU, GAME,EXIT };
/**
 * @brief Klasa menu głównego gry
 * 
 */
class MainMenu
{
private:
	Button *newGameButton;/*!<Przycisk New Game>*/
	Button *continueButton;/*!<Przycisk Continue>*/
	Button *exitButton;/*!<Przycisk Exit>*/
	Texture backgroundTexture;/*!<Tekstura tła menu głównego>*/
	Sprite background;/*!<Tło menu głównego>*/
public:
	/**
	* @brief Konstruktor inicjujący menu główne
	* 
	* @param screanSize 
	*/
	MainMenu(Vector2f screanSize);
	/**
	 * @brief Niszczenie menu głównego
	 * 
	 */
	~MainMenu();
	/**
	 * @brief Aktualizacja menu głównego
	 * 
	 * @param window wskaźnik do okna gry
	 * @param gameState referencja do stosu zawierającego obecy stan silnika gry
	 * @param health życie gracza
	 * @return true - jeżeli wcisnięto przycisk newGame
	 * @return false - wpozostałych przypadkach 
	 */
	bool update(const RenderWindow& window, std::stack<int>& gameState,double health);
	/**
	 * @brief Wyświetlanie menu głownego
	 * 
	 * @param target wskaźnik na okno gry
	 */
	void render(RenderTarget *target);
};

