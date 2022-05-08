#pragma once

#include "EntityBase.h"
#include "Player.h"
/**
 * @brief Klasa bazowa dla stworzeń występujących w grze w tym dla gracza
 * 
 */
class Entity
	:public virtual EntityBase
{
protected:
	Vector2f pointOfWalkAroud;/*!<Punkt patrolowania>*/
	int colisionDirection;/*!<Kierunek kolizji>*/
	bool colisionReaction;/*!<Informacja czy należy zareagować na kolizje>*/

	bool goTooDirection;/*!<Informacja czy obiekt podąża do zadanego celu>*/

	float randPosX;/*!<Losowa pozycja x>*/
	float randPosY;/*!<Losowa pozycja y>*/

	float spawnPosX;/*!<Startowa pozycja x>*/
	float spawnPosY;/*!<Startowa pozycja y>*/

	float entitySpeed;/*!<Prędkość poruszania obiektu>*/
	/**
	 * @brief metoda odpowiadający za powrót obiektu na obszar spawnu
	 * 
	 * @param pPosX pozycja celu na współrzędnej X
	 * @param pPosY pozycja celu na współrzędnej Y
	 * @param dt czas między poprzednją a obecną klatką okna aplikacji
	 * @return true jeżeli osiągnięto cel
	 * @return false w przeciwnym przypadku
	 */
	bool backToPoint(float pPosX, float pPosY, float dt);
	/**
	 * @brief metoda odpowiadająca za poruszanie się obiektu na osi X
	 * 
	 * @param distanceX odległość pomiędzy przeciwnikiem i celem na osi X
	 * @param dt czas między poprzednją a obecną klatką okna aplikacji
	 */
	void moveByX(float distanceX, float dt);
	/**
	 * @brief metoda odpowiadająca za poruszanie się obiektu na osi Y
	 * 
	 * @param distanceY odległość pomiędzy przeciwnikiem i celem na osi Y
	 * @param dt czas między poprzednją a obecną klatką okna aplikacji
	 */
	void moveByY(float distanceY, float dt);
public:
	double getHp();
	/**
	 * @brief Wyświetlanie obiektu wraz z należącymi do niego przeciwnikami
	 * 
	 * @param target wskaźnik na okno aplikacji
	 * @param pPosX pozycja celu na osi x
	 * @param pPosY pozycja celu na osi y
	 */
	void render(sf::RenderTarget * target, float pPosX, float pPosY);
};

