#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include "MapObjects.h"
#include "Player.h"
#include "EnemySpawner.h"
using namespace sf;
/**
 * @brief Klasa sektorów mapy gry
 * 
 */
class MapSector
{
public:
	std::vector<MapObjects*> SectorObjectsFront;/*!<Kontener obiektów znajdujących się na pierwszym planie>*/
	std::vector<MapObjects*> SectorObjectsBack;/*!<Kontener obiektów znajdujących się na drugim planie>*/
	Sprite sectorBody;/*!<Ciało sektora>*/
	sf::RectangleShape border;/*!<Obramowanie sektora>*/
	bool visable;/*!<Informacja czy sektor jest widoczny>*/
public:
	/**
	 * @brief Dodawanie nowego obiektu do sektora
	 * 
	 * @param tmp tekstura obiektu
	 * @param posx pozycja obiektu na osi X
	 * @param posy pozycja obiektu na osi X
	 * @param scaleX skalowanie hitboxa na oxi X
	 * @param scaleY skalowanie hitboxa na oxi Y
	 * @param texscaleX skalowanie tekstury na oxi X
	 * @param texscaleY skalowanie tekstury na oxi Y
	 * @param offsetx przesuniecie na osi x
	 * @param offsety przesuniecie na osi y
	 * @param type typ obiektu
	 */
	void createNewMapObject(sf::Texture *tmp,float posx,float posy, float scaleX, float scaleY, float texscaleX, float texscaleY, float offsetx, float offsety,int type);
	/**
	 * @brief Zmiana widocznosci sektora
	 * 
	 * @param value wartość
	 */
	void setVisable(bool value);
	/**
	 * @brief Konstruktor inicjujący sektor
	 * 
	 * @param ground tekstura podłoża
	 */
	MapSector(sf::Texture *ground);
	/**
	 * @brief Przypisanie tekstury do obiektu typu Sprite
	 * 
	 * @param ground tekstura podłoża
	 */
	void setTextureForSprite(sf::Texture* ground);
	std::string filePath;
	/**
	 * @brief Aktualizacja stanu sektora
	 * 
	 * @param dt czas pomięczy poprzednia a obecną klatką
	 */
	void updateSector(float dt);
	/**
	 * @brief Wyświerlanie sektora 
	 * 
	 * @param renderPosX nowa pozycja sektora na osi x
	 * @param renderPosY nowa pozycja sektora na osi y
	 * @param target wskaźnik na okno gry
	 */
	void renderSector(float& renderPosX, float& renderPosY, RenderTarget* target);
	/**
	 * @brief Wyświetlanie obiektów pierwszoplanowych
	 * 
	 * @param target wskaźnik na okno gry
	 */
	void renderObjectsFront(RenderTarget* target);
	/**
	 * @brief Wyświetlanie obiektów drugoplanowych
	 * 
	 * @param target wskaźnik na okno gry
	 */
	void renderObjectsBack(RenderTarget* target);
};

