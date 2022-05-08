#pragma once
#include<vector>
#include<cstdlib>
#include<ctime>
#include"Enemy.h"
#include"Player.h"
#include "Item.h"
/**
 * @brief Klasa służąca do tworzenia obszaru na którym pojawiają się przeciwnicy
 * 
 */
class EnemySpawner
{
private:
	std::vector<Enemy*> enemyGroup;/*!<Kontener z wskażnikami na obiekty wrogów znajdujące się w danym obiekcie>*/
	Vector2f position;/*!<Pozycja obiektu>*/
	Vector2f size;/*!<Rozmiar obiektu>*/
	double respawnTime;/*!<Czas co jaki dochodzi do odrodzenia wroga>*/
	int numberOfEnemy;/*!<Ilość wrogów w obiekcie>*/
	/**
	 * @brief Odradzanie pokonanych przeciwników
	 * 
	 * @param dt czas pomiędzy klatkami okna aplikacji
	 */
	void respawnEnemy(float dt);
	/**
	 * @brief Tworzenie zadanej liczby przeciwników
	 *
	 * @param number ilość wrogów
	 */
	void createEnemy(int number);
public:
	/**
	 * @brief konstruktor odpowiadający za pojawianie się przeciwników na mapie
	 * 
	 * @param size wielkość obszaru 
	 * @param position pozycja obszaru 
	 * @param numberOfEnemy ilość przeciwników 
	 */
	EnemySpawner(Vector2f size, Vector2f position, int numberOfEnemy);
	/**
	 * @brief Wykrywanie kolizji dla wrogów należących do obiektu
	 * 
	 * @param SectorObjects Kontener z obiektami na sektorze
	 */
	void detectVolision(std::vector<MapObjects*>& SectorObjects);
	/**
	 * @brief Aktualizacja stanu obiektu
	 * 
	 * @param pPosX pozycja gracza na osi x
	 * @param pPosY pozycja gracza na osi y
	 * @param dt czas pomiędzy poprzednią a obecną klatką okna aplikacji
	 * @param playerDamage kolejka na obrażenia które przeciwnik zadaje graczowi
	 * @param playerLastFrame informacja czy została odegrana ostatnia klatka animacji gracza
	 * @param questEvents kontener zawierający informacje na temat postępów zadań
	 * @param droppedItems kontener z przedmiorami leżącymi na ziemi
	 * @param items kontener zawierający tekstury przedmiotów
	 * @param damageDealt siła ataku gracza
	 */
	void update(float pPosX, float pPosY, float dt, std::queue<double>& playerDamage, bool playerLastFrame, std::vector<int>& questEvents, std::vector<Item>& droppedItems,  std::map<std::string, Texture>& items,double damageDealt);
	/**
	 * @brief Wyświetlanie obiektu wraz z należącymi do niego przeciwnikami
	 * 
	 * @param target wskaźnik na okno aplikacji
	 * @param pPosX pozycja gracza na osi x
	 * @param pPosY pozycja gracza na osi y
	 */
	void render(RenderTarget* target, float pPosX, float pPosY);
	/**
	 * @brief Resetuje życie przeciwników
	 *
	 */

	void resetEnemies();
};

