#pragma once
#include "Entity.h"
/**
 * @brief Klasa reprezentująca NPC
 * 
 */
class NPC:
	public Entity
{
private:
	bool movable;/*!<Informacja o tym czy NPC ma zdolność poruszania>*/
	bool haveQuest;/*!<Informacja czy NPC posiada zadanie>*/
	int questType;/*!<Typ zadania>*/
	/**
	 * @brief metoda implementująca inteligencje przeciwników
	 * 
	 * @param pPosX pozycja gracza na współrzędnej X
	 * @param pPosY pozycja gracza na współrzędnej Y
	 * @param dt czas między poprzednią a obecną klatką okna aplikacji
	 * @param playerDamage kolejka na obrażenia które przeciwnik zadaje graczowi
	 * @param playerLastFrame informacja czy została odegrana ostatnia klatka animacji gracza
	 */
	void EntityAI(float pPosX, float pPosY, float dt, std::queue<double>& playerDamage, bool playerLastFrame);
	/**
	 * @brief ładuje teksture NPC
	 * 
	 */
	void loadTextures();

public:
	/**
	* @brief konstruktor zawierający podstawowe ustawienia każdego NPC
	* 
	* @param posx pozycja NPC na współrzędnej X
	* @param posy pozycja NPC na współrzędnej Y
	* @param spawnPosX miejsce spawnu NPC na współrzędnej X
	* @param spawnPosY miejsce spawnu NPC na współrzędnej Y
	* @param movable określa czy NPC może się poruszać
	* @param haveQuest określa czy NPC ma możliwość dania zadania
	* @param questType określa jakiego typu jest dane zadanie
	*/
	NPC(float posx, float posy, float spawnPosX, float spawnPosY,bool movable,bool haveQuest,int questType);
	/**
	 * @brief Aktualizacja stanu przeciwnika
	 * 
	 * @param pPosX pozycja gracza na osi x
	 * @param pPosY pozycja gracza na osi y
	 * @param dt czas pomiędzy poprzednią a obecną klatką okna aplikacji
	 * @param playerDamage kolejka na obrażenia które przeciwnik zadaje graczowi
	 * @param playerLastFrame informacja czy została odegrana ostatnia klatka animacji gracza
	 * @param playerQuests kontener zawierający zadania gracza
	 */
	void update(float pPosX, float pPosY, float dt, std::queue<double>& playerDamage, bool playerLastFrame, std::vector<Quest> &playerQuests);
	
};

