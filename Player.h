#pragma once
#include "HealthBar.h"
#include "AtackAbleEntity.h"
#include "Equipment.h"
#include "QuestLog.h"
#include <queue>
#include "Quest.h"
#include <stack>

using namespace sf;

/**
 * @brief Klasa reprezentująca gracza
 * 
 */
class Player
	:public AtackAbleEntity
{
private:
	friend class Engine;
	std::vector<Quest> playerQuests;/*!<Kontener z zadaniami posiadanymi przez gracza>*/
	std::vector<int> questEvents;/*!<Kontener z odemranymi przez gracza informacjami o postępach w wykonywaniu zadań>*/

	double healthValues;/*!<Ilość życia >*/
	
	bool IKeyReleased;/*!<Informacja o stanie wciśnięcia klawisza I>*/
	bool EKeyReleased;/*!<Informacja o stanie wciśnięcia klawisza E>*/
	bool QKeyReleased;/*!<Informacja o stanie wciśnięcia klawisza Q>*/
	bool EscapeKeyReleased;/*!<Informacja o stanie wciśnięcia klawisza ESCAPE>*/

	Vector2f startPos;/*!<Pozycja startowa gracza>*/

	Vector2f playerLastPos;/*!<Ostatnia pozycja gracza na której nie wykryto kolizji>*/
	
	Inventory* inventory;/*!<Wskażnik na obiekt inventory>*/
	Equipment* equipment;/*!<Wskaźnik na obiekt equipment>*/
	QuestLog* questlog;/*!<Wskażnik na obiekt quest log>*/

	double armorValues;/*!<Wartość obrony gracza>*/
	double damageValues;/*!<Wartość obrażeń gracza>*/
	double agilityValues;/*!<Wartość zwinności gracza>*/

	/**
	 * @brief Wczytywanie wszystkich wymaganych tekstur dla gracza
	 * 
	 */
	void loadTextures();

	char lastKey;/*!<Ostatnio wciśnięty przycisk>*/
	/**
	 * @brief Działania podejmowane w chwili wystąpienia kolizji
	 * 
	 */
	void colisionReaction();
	/**
	 * @brief Ustawianie domyślnych wartości statystyk gracza
	 * 
	 */
	void setDefaultParameters();
	/**
	 * @brief Odbieranie obrażeń zadanych przez przeciwników
	 * 
	 */
	void takeDamage();
public:
	bool itemFromQuest;/*!<Informacje o stanie otrzymanych przedmiotów z misji>*/
	std::queue<double> receivedDamage;/*!<Kontener z obrażeniami przekazanymi przez wrogów do zadania graczowi>*/
	/**
	 * @brief Funkcja zbierająca przedmioty i ziemi
	 * 
	 * @param droppedItems kontener przechowujący przedmioty leżące na ziemi
	 */
	void collectItem(std::vector<Item> &droppedItems);
	/**
	 * @brief Dpstęp do tektury gracza stojącego przodem
	 * 
	 * @return Texture* - gracz stojący rzodem
	 */
	Texture* getPlayerFront();
	/**
	 * @brief Konstruktor inicjujący gracza
	 * 
	 * @param inventory wskaźnik na inventory gracza
	 * @param equipment wskaźnik na equipment gracza
	 * @param questlog wskaźnik na questlog gracza
	 */
	Player(Inventory *inventory,Equipment* equipment,QuestLog *questlog);
	/**
	 * @brief Destruktor gracza
	 * 
	 */
	~Player();
	/**
	 * @brief Dostęp do pozycji gracza
	 * 
	 * @return Vector2f - pozyja gracza
	 */
	Vector2f getPlayerPosition();
	/**
	 * @brief Resetowanie gracza do stanu początkowego
	 * 
	 */
	void restart();
	/**
	 * @brief Zmiana informacji o kolicji
	 * 
	 * @param value  wartość
	 */
	void setColision(bool value);
	/**
	 * @brief Wykrywanie kolizji między graczem a danym obiektem
	 * 
	 * @param colisionObject obszar danego obiektu
	 * @return true - jeżeli jest kolizja
	 * @return false - jeżeli nie ma kolizji
	 */
	bool detectColision(sf::FloatRect colisionObject);
	/**
	 * @brief Obsługa sterowania graczem/obsługa klawiatury 
	 * 
	 * @param oneFrameTime czas pomiędzy klatkami 
	 * @param numberOfColumn ilosc koliumn mapy
	 * @param numberOfRow ilosc wierszy mapy
	 * @param gameState stos przechowyjący stan gry
	 */
	void playerKeyControl(float oneFrameTime, int numberOfColumn, int numberOfRow, std::stack<int> &gameState);
	/**
	 * @brief Pierwszy etap aktualizacji gracza
	 * 
	 * @param oneFrameTime czas pomiędzy klatkami 
	 * @param numberOfColumn ilosc koliumn mapy
	 * @param numberOfRow ilosc wierszy mapy
	 * @param gameState stos przechowyjący stan gry
	 */
	void updatePart1(float oneFrameTime, int numberOfColumn, int numberOfRow, std::stack<int> &gameState);
	/**
	 * @brief Drugi etap aktualizacji gracza
	 * 
	 * @param oneFrameTime czas pomiędzy klatkami 
	 * @param numberOfColumn ilosc koliumn mapy
	 * @param numberOfRow ilosc wierszy mapy
	 * @param gameState stos przechowyjący stan gry
	 */
	void updatePart2(float oneFrameTime, int numberOfColumn, int numberOfRow);
	/**
	 * @brief Wyświetlanie gracza na mapie
	 * 
	 * @param target wkażnik na ekran gry
	 */
	void render(RenderTarget* target);
};

