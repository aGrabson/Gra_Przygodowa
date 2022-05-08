#pragma once
#include "EntityBase.h"
/**
 * @brief Klasa obs³uguj¹ca nimacje ataku dla gracza i wrogów
 * 
 */
class AtackAbleEntity
	:public virtual EntityBase
{
protected:
	std::map<std::string, sf::Texture> adown;/*!<Mapa zawieraj¹ca tekstury ataku obiektu zwróconego w dó³>*/
	std::map<std::string, sf::Texture> aleft;/*!<Mapa zawieraj¹ca tekstury ataku obiektu zwróconego w lewo>*/
	std::map<std::string, sf::Texture> aright;/*!<Mapa zawieraj¹ca tekstury ataku obiektu zwróconego w prawo>*/
	std::map<std::string, sf::Texture> aup;/*!<Mapa zawieraj¹ca tekstury ataku obiektu zwróconego w góre>*/

	Animation AtackDownAnimation;/*!<Obiekt klasy animation odgrywaj¹cy animacje ataku w dó³>*/
	Animation AtackLeftAnimation;/*!<Obiekt klasy animation odgrywaj¹cy animacje ataku w lewo>*/
	Animation AtackRightAnimation;/*!<Obiekt klasy animation odgrywaj¹cy animacje ataku w prawo>*/
	Animation AtackUpAnimation;/*!<Obiekt klasy animation odgrywaj¹cy animacje ataku w góre>*/

	/**
	 * @brief Podmienieanie co okreœlony czas odpowiednich tekstur animacji
	 * 
	 * @param dt czas pomiêdzy klatkami okna alikacji
	 */
	void playAtackAnimation(double dt);
};

