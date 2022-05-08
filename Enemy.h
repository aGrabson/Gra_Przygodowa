#pragma once
#include "AtackAbleEntity.h"
#include "Entity.h"
#include"Player.h"
/**
	 * @brief klasa obsługująca przeciwników 
	 * 
*/
class Enemy:
	public AtackAbleEntity,
	public Entity
{
private:
	Vector2f cpypos;/*!<Zmienna pomocnicza do kopiowania pozycji>*/
	/**
	 * @brief metoda implementująca inteligencje przeciwników
	 * 
	 * @param pPosX pozycja gracza na współrzędnej X
	 * @param pPosY pozycja gracza na współrzędnej Y
	 * @param dt czas między poprzednią a obecną klatką okna aplikacji
	 * @param playerDamage kolejka na obrażenia które przeciwnik zadaje graczowi
	 * @param playerLastFrame informacja czy została odegrana ostatnia klatka animacji gracza
	 * @param damageDealt siła ataku gracza
	 */

	void EntityAI(float pPosX,float pPosY,float dt, std::queue<double>& playerDamage, bool playerLastFrame, double damageDealt);
	/**
	 * @brief Załadowanie tekstur ataku i poruszania dla wroga
	 * 
	 */
	void loadTextures();
public:
	/**
	* @brief Konstruktor inicjujący przeciwnika
	* 
	* @param posx pozycja przeciwnika na osi x
	* @param posy pozycja przeciwnika na osi y
	* @param spawnPosX współrzędna x na której jest spawnowany przeciwnik 
	* @param spawnPosY współrzędna y na której jest spawnowany przeciwnik 
	*/
	Enemy(float posx, float posy,float spawnPosX, float spawnPosY);
	/**
	 * @brief Getter pozycji przeciwnika
	 * 
	 * @return Vector2f zawierający pozycje przeciwnika
	 */
	Vector2f getPosition();
	/**
	 * @brief Aktualizacja stanu przeciwnika
	 * 
	 * @param pPosX pozycja gracza na osi x
	 * @param pPosY pozycja gracza na osi y
	 * @param dt czas pomiędzy poprzednią a obecną klatką okna aplikacji
	 * @param playerDamage kolejka na obrażenia które przeciwnik zadaje graczowi
	 * @param playerLastFrame informacja czy została odegrana ostatnia klatka animacji gracza
	 * @param damageDealt siła ataku gracza
	 */
	void update(float pPosX, float pPosY,float dt, std::queue<double>& playerDamage, bool playerLastFrame, double damageDealt);
	/**
	 * @brief Ustawia wartość życia przeciwnika
	 *
	 * @param values życie przeciwnika
	 */
	void sethp(double values);
};

