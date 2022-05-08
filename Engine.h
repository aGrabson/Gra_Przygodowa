#include "GameMap.h"
#include "MainMenu.h"

/**
 * @brief Główna klasa gry w której zbiegają się wszystkie elementy gry
 * 
 */
class Engine
{
private:
	
	MainMenu *menu;/*!<Wskaźnik na obiekt zawierający menu główne>*/
	std::stack<int> gameState;/*!<Stos stanu silnika gry>*/
		
	Inventory playerInventory;/*!<Wskażnik na obiekt zawierający inventory gracza>*/
	Equipment playerEquipment;/*!<Wskażnik na obiekt zawierający equipment gracza>*/
	QuestLog playerQuestLog;/*!<Wskażnik na obiekt zawierający questlog gracza>*/
	GameMap *gameMap;/*!<Wskażnik na obiekt zawierający mape wraz z obiektami>*/
	Player *player;/*!<Wskażnik na obiekt zawierający gracza>*/
	RenderWindow* window;/*!<Wskażnik na obiekt zawierający główne okno aplikacji>*/
	Event event;/*!<Obiekt obsługi zdarzeń SFML>*/
	Clock mainClock;/*!<Obiekt mierzący czas>*/
	Time oneFrameTime;/*!<Obiekt przechowujący czas pomiędzy pojedynczymi klatkami>*/
	View gameView;/*!<Kamera podążająca za graczem>*/
	Font gameFont;/*!<Trzcionka>*/
	float windowWidth;/*!<Szerokość okna>*/
	float windowHeight;/*!<Wysokość okna>*/


public:
	/**
	 * @brief Konstruktor inicjujący silnik gry
	 * 
	 */
	Engine();
	/**
	 * @brief Destruktor sprzątający po obiekcie
	 * 
	 */
	virtual ~Engine();
	/**
	 * @brief Inicjowanie wartości zmiennych silnika
	 * 
	 */
	void initVar();
	/**
	 * @brief Informacja o tym czy aplikacja wciąż paracuje
	 * 
	 * @return true jeżeli pracuje
	 * @return false jeżeli ma zostać wyłaczona
	 */
	bool isRunning();
	/**
	 * @brief Resetowanie wszystkich elementów gry do stanu początkowego
	 * 
	 */
	void resetGame();
	/**
	 * @brief Obsługa wykrywania kolizji gracza z otaczającymi obiektami
	 * 
	 */
	void detectColision();
	void deleteObjects();
	/**
	 * @brief Aktualizacja pozycji kamery podażającej za graczem
	 * 
	 */
	void updateCameraPos();
	/**
	 * @brief Pobranie czasu jaki minął od wyświetlenia ostatniej klatki na ekranie
	 * 
	 */
	void updateTime();
	/**
	 * @brief Pobranie i obsługa podstawowych zdarzeń biblioteki SFML
	 * 
	 */
	void updateEvents();
	/**
	 * @brief Aktualizacja wszystkich elementów silnika 
	 * 
	 */
	void update();
	/**
	 * @brief Wyświetlenie wszystkich elementów silnika
	 * 
	 */
	void render();
};












