#pragma once
#include"Inventory.h"
/**
 * @brief Typ wyliczeniowy z możliwymi kierunkami poruszania się
 * 
 */
enum lastDirection_name { DOWN_D, UP_D, LEFT_D, RIGHT_D };
/**
 * @brief Klasa podstawowa dla każdego stworzenia z podstawowymi elementami i mechanikami
 * 
 */
class EntityBase
{
protected:
	bool nop;/*!<Zmiennna pomocnicza>*/
	
	
	
	sf::RectangleShape hitbox;/*!<Kształt hitboxa>*/
	
	int lastDirection;/*!<Kierunek w którym ostatio porszał się obiekt>*/

	sf::Sprite body;/*!<Ciało obiektu>*/
	sf::Texture bodyTexture;/*!<Tekstura obiektu>*/
	std::map<std::string, sf::Texture> down;/*!<Kontener z teksturami animacji poruszania sie w dół>*/
	std::map<std::string, sf::Texture> left;/*!<Kontener z teksturami animacji poruszania sie w lewo>*/
	std::map<std::string, sf::Texture> right;/*!<Kontener z teksturami animacji poruszania sie w prawo>*/
	std::map<std::string, sf::Texture> up;/*!<Kontener z teksturami animacji poruszania sie w góre>*/

	Animation downAnimation;/*!<Obiekt odgrywający animacje poruszania w dół>*/
	Animation leftAnimation;/*!<Obiekt odgrywający animacje poruszania w lewo>*/
	Animation rightAnimation;/*!<Obiekt odgrywający animacje poruszania w prawo>*/
	Animation upAnimation;/*!<Obiekt odgrywający animacje poruszania w góre>*/

	Vector2f position;/*!<Pozycja obiektu>*/
	

	float entitySpeedLeft;/*!<Prędkość poruszania w lewo>*/
	float entitySpeedRight;/*!<Prędkość poruszania w prawo>*/
	float entitySpeedUp;/*!<Prędkość poruszania w góre>*/
	float entitySpeedDown;/*!<Prędkość poruszania w dół>*/

	double health;/*!<Ilość życia>*/

	virtual void loadTextures() = 0;
	/**
	 * @brief metoda odpowiedzialna za poruszanie się w dół
	 * 
	 * @param dt czas między poprzednją a obecną klatką okna aplikacji
	 */
	void moveDown(float dt);
	/**
	 * @brief metoda odpowiedzialna za poruszanie się w górę
	 * 
	 * @param dt czas między poprzednją a obecną klatką okna aplikacji
	 */
	void moveUp(float dt);
	/**
	 * @brief metoda odpowiedzialna za poruszanie się w lewo
	 * 
	 * @param dt czas między poprzednją a obecną klatką okna aplikacji
	 */
	void moveLeft(float dt);
	/**
	 * @brief metoda odpowiedzialna za poruszanie się w górę
	 * 
	 * @param dt czas między poprzednją a obecną klatką okna aplikacji
	 */
	void moveRight(float dt);

public:
	bool colision;/*!<Informacja czy doszło do kolizji>*/
	bool lastFrame;
	HealthBar entityHealthBar;
	/**
	 * @brief metoda odpowiedzialna za wykrywanie kolizji z objektami na mapie
	 * 
	 * @param SectorObjects obiekty na sektorze
	 * @return true 
	 * @return false 
	 */
	bool detectColision(std::vector<MapObjects*>& SectorObjects);
};

