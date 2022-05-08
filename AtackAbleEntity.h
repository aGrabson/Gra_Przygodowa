#pragma once
#include "EntityBase.h"
/**
 * @brief Klasa obs�uguj�ca nimacje ataku dla gracza i wrog�w
 * 
 */
class AtackAbleEntity
	:public virtual EntityBase
{
protected:
	std::map<std::string, sf::Texture> adown;/*!<Mapa zawieraj�ca tekstury ataku obiektu zwr�conego w d�>*/
	std::map<std::string, sf::Texture> aleft;/*!<Mapa zawieraj�ca tekstury ataku obiektu zwr�conego w lewo>*/
	std::map<std::string, sf::Texture> aright;/*!<Mapa zawieraj�ca tekstury ataku obiektu zwr�conego w prawo>*/
	std::map<std::string, sf::Texture> aup;/*!<Mapa zawieraj�ca tekstury ataku obiektu zwr�conego w g�re>*/

	Animation AtackDownAnimation;/*!<Obiekt klasy animation odgrywaj�cy animacje ataku w d�>*/
	Animation AtackLeftAnimation;/*!<Obiekt klasy animation odgrywaj�cy animacje ataku w lewo>*/
	Animation AtackRightAnimation;/*!<Obiekt klasy animation odgrywaj�cy animacje ataku w prawo>*/
	Animation AtackUpAnimation;/*!<Obiekt klasy animation odgrywaj�cy animacje ataku w g�re>*/

	/**
	 * @brief Podmienieanie co okre�lony czas odpowiednich tekstur animacji
	 * 
	 * @param dt czas pomi�dzy klatkami okna alikacji
	 */
	void playAtackAnimation(double dt);
};

