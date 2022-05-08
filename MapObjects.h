#pragma once
#include <SFML/Graphics.hpp>
/**
 * @brief Obiekty znajdujące się na mapie
 * 
 */
class MapObjects
{
private:
	sf::Texture texture;/*!<Tekstura obiektu>*/
	sf::Sprite body;/*!<Ciało obiektu>*/
	sf::RectangleShape hitBox;/*!<Hitbox obiektu>*/

	void loadTexture(std::string path);
public:
	/**
	 * @brief Ustawianie pozycji obiektu sektora
	 * 
	 * @param pos nowa pozycja
	 */
	void setBodyPosition(sf::Vector2f pos);
	/**
	 * @brief Ustawienie pozycji fitboxa obiektu
	 * 
	 * @param pos pozycja
	 * @param offsetx przesuniecie na osi x
	 * @param offsety przesuniecie na osi y
	 */
	void setHitBoxPosition(sf::Vector2f pos,float offsetx, float offsety);
	/**
	 * @brief Ustawienie rozmiaru hitboxa
	 * 
	 * @param size rozrozmiaru
	 */
	void setHitboxSize(sf::Vector2f size);
	/**
	 * @brief Dostęp do obszaru hitboxa
	 * 
	 * @return sf::FloatRect - obszar hitboxa
	 */
	sf::FloatRect getColisonGlobalBounds();
	/**
	 * @brief Dostęp do pozycji obiektu 
	 * 
	 * @return sf::Vector2f - pozycja
	 */
	sf::Vector2f getPosition();
	/**
	 * @brief Ustawienie pozycji obiektu
	 * 
	 * @param tmp nowa pozycja
	 */
	void setTexture(sf::Texture *tmp);
	/**
	 * @brief Konstruktor inicjujący nowy obiekt na mapie
	 * 
	 * @param tmp wskaźnik do tekstury
	 * @param posx pozycja na osi X
	 * @param posy pozycja na osi Y
	 * @param scaleX skalowanie hitboxa na osi X
	 * @param scaleY skalowanie hitboxa na osi Y
	 * @param texscaleX skalowanie tekstury na osi X
	 * @param texscaleY skalowanie tekstury na osi Y
	 * @param offsetx przesunięcie na osi X
	 * @param offsety przesunięcie na osi Y
	 */
	MapObjects(sf::Texture *tmp,float posx,float posy,float scaleX,float scaleY,float texscaleX, float texscaleY, float offsetx, float offsety);
	/**
	 * @brief Aktualizacja stanu obiektu mapy
	 * 
	 */
	void update();
	/**
	 * @brief Wyśietlanie obiektu na mapie
	 * 
	 * @param target wskażniek do ekranu gry
	 */
	void render(sf::RenderTarget *target);
};

