#include "MapSector.h"
#include "Enemy.h"
#include "NPC.h"
#include <map>
#include <iterator>
#include "Script_interpreter.h"
#include "Animation.h"
#include "EnemySpawner.h"
#include "Item.h"
enum texture_name{CLEAR_GREEN=0,LEFT_TOP_DARK_GREEN,RIGHT_TOP_DARK_GREEN,TOP_GREEN_DARK,CLEAR_DARK_GREEN,BOOTOM_DARK_GREEN};

/**
 * @brief Klasa mapy gry zawierająca sektory, przeciwnmików, NPC oraz itemy leżące na ziemi
 * 
 */
class GameMap
{
private:

	EnemySpawner* spawner;/*!<Obiekt obszaru pojawiania się przewciwników>*/
	std::vector<NPC*>NpcContainer;/*!<Kontener NPC znajdujących się na mapie>*/
	std::vector<Item> droppedItems;/*!<Kontener przedmiotów leżących na mapie>*/


	friend class Engine;
	int numbersOfSectors;/*!<Ilość sektorów mapy>*/
	float camPosX;/*!<Pozycja kamery na osi x>*/
	float camPosY;/*!<Pozycja kamery na osi y>*/

	std::vector<MapSector*> sectors;/*!<Kotener sektorów mapy>*/
	std::map<char,std::string> fileNames;/*!<Kontener przypisujący litere do konkretnej nazwy teksury podłoża>*/
	std::map<std::string, Texture*> groundTextures;/*!<Kontener tekstur podłoża>*/
	std::map<std::string, Texture> objectTextures;/*!<Kontener tekstur obiektów>*/
	std::map<std::string, Texture> tree1;/*!<Kontener tekstur drzewa nr 1>*/
	std::map<std::string, Texture> tree4;/*!<Kontener tekstur drezwa nr 2>*/
	std::map<std::string, Texture> fireplace;/*!<Kontener tekstur ogniska>*/
	std::map<std::string, Texture> bush;/*!<Kontener tekstur krzaka>*/

	std::map<std::string, Texture> items;/*!<Kontener tekstur przedmiotów>*/


	int curentMainSectorColumn;/*!<Kolumna w której obecnie znajduje się gracz>*/
	int curentMainSectorRow;/*!<Wiersz w którym obecnie znajduje się gracz>*/

	int numberOfColumn;/*!<Ilość kolumn mapy>*/
	int numberOfRow;/*!<Ilość wierszy mapy>*/

	Animation treeAnimation;/*!<Klasa animująca drezwo>*/
	Animation tree4Animation;/*!<Klasa animująca drezwo>*/
	Animation fireplaceAnimation;/*!<Klasa animująca ognisko>*/

	/**
	 * @brief Inicjowanie domyślnych wartości parametrów
	 * 
	 */
	void initVar();	
	/**
	 * @brief metoda odpowiedzialna za ładowanie tekstur podłoża
	 * 
	 */
	void loadGroundTextures();
	/**
	 * @brief metoda odpowiedzialna za załadowanie sektorów z pliku 
	 * 
	 */
	void loadSectors();
	/**
	 * @brief metoda odpowiedzialna za ładowanie tekstur obiektów
	 * 
	 */
	void loadMapObjectTexture();
	/**
	 * @brief metoda odpowiedzialna za ładowanie ułożenia obiektów na mapie z pliku
	 * 
	 */
	void loadObjectsFromFile();
	/**
	 * @brief wyświetlanie podłoża mapy
	 * 
	 * @param target wskaźnik na okno gry
	 * @param player wskaźnik na gracza
	 */
	void renderBackground(RenderTarget* target,Player& player);
	/**
	 * @brief metoda odpowiadająca za ustawienie typu podłoża do litery z pliku
	 * 
	 */
	void initMap();

public:
	/**
	 * @brief Konstruktor inicjujący konm
	 * 
	 */
	GameMap();
	~GameMap();
	/**
	 * @brief metoda służąca do wyliczenia sektora 
	 * 
	 * @param playerX pozycja na osi x
	 * @param playerY pozycja na osi y
	 * @return numer sektora 
	 */
	int findSector(float playerX, float playerY);
	/**
	 * @brief metoda odpowiedzialna za znalezienie sektora na którym znajduje się gracz
	 * 
	 * 
	 * 
	 * @param column liczba kolumn 
	 * @param row liczba wierszy
	 * @param playerSector numer sektora na którym znajduję się gracz
	 * @return numer sektora na którym znajduje się gracz
	 */
	int findSector(int column, int row, int playerSector);
	/**
	 * @brief metoda służąca do znalezienia kolumny na którym znajduje się gracz
	 * 
	 * @param playerX pozycja na osi x
	 * @return numer kolumny 
	 */
	int findColumn(float playerX);
	/**
	 * @brief metoda służąca do znalezienia wiersza na którym znajduje się gracz
	 * 
	 * @param playerY pozycja na osi y
	 * @return numer wiersza
	 */
	int findRow(float playerY);
	/**
	 * @brief metoda obliczająca wielkość całej mapy w osi x
	 * 
	 * @return wielkość całej mapy w osi x
	 */
	float getXSize();
	/**
	 * @brief metoda obliczająca wielkość całej mapy w osi y
	 * 
	 * @return wielkość całej mapy w osi y
	 */
	float getYSize();
	/**
	 * @brief metoda zwracająca liczbę wszystkich kolumn
	 * 
	 * @return liczbę wszystkich kolumn
	 */
	int getColumn();
	/**
	 * @brief metoda zwracająca liczbę wszystkich wierszy
	 * 
	 * @return liczbę wszystkich wierszy
	 */
	int getRow();
	/**
	 * @brief metoda wyświetlająca wszystkie przedmioty na mapie
	 * 
	 * @param target wskaźnik na okno gry
	 */
	void renderItems(RenderTarget* target);
	/**
	 * @brief Wyświetlanie podłoża i przedmiotów
	 * 
	 * @param target wskaźnik na okno gry
	 * @param player wskaźnik na gracza
	 */
	void render(RenderTarget* target,Player &player);
	/**
	 * @brief metoda odpowiedzialna za aktualizacje stanu mapy
	 * 
	 * @param playerX pozycja na osi x
	 * @param playerY pozycja na osi y
	 * @param dt czas między poprzednią a obecną klatką okna aplikacji
	 * @param playerDamage kolejka na obrażenia które przeciwnik zadaje graczowi
	 * @param playerLastFrame informacja czy została odegrana ostatnia klatka animacji gracza
	 * @param questEvents kontener zawierający informacje na temat postępów zadań
	 * @param playerQuests kontener zawierający zadania gracza
	 * @param damageDealt siła ataku gracza
	 */
	void updateMap(float playerX, float playerY,float dt, std::queue<double>& playerDamage, bool playerLastFrame, std::vector<int>& questEvents, std::vector<Quest> &playerQuests, double damageDealt);
};

