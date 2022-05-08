#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
/**
 * @brief Klasa obsługująca animacje
 * 
 */
class Animation
{
private:
	float sumaTime;/*!<Czas trwania animacji>*/
	int textureIndex;/*!<Inedeks tekstury która obecnie ma zostać zwrócona przez obiekt>*/
public:
	/**
	 * @brief kontruktor ustawiający domyślne wartości klasy
	 * 
	 */
	Animation();
	/**
	 * @brief 
	 * 
	 * @param textures kontener z poszczególnymi klatkami animacji
	 * @param dtTime czas pomiędzy poprzednią a obecną klatką okna aplikacji
	 * @param oneFrameTime  co jaki czas ma się zmieniać animacja
	 * @param name bazowa część nazwy zbioru tekstur
	 * @param lastFrame informacja zwrotna czy została wykonana ostatnia klatka animacji
	 * @return teksture ktora jest aktualnie ustawiana
	 */
	sf::Texture objectAnimation(std::map < std::string, sf::Texture > & textures, double dtTime, float oneFrameTime,std::string name,bool &lastFrame);
};

