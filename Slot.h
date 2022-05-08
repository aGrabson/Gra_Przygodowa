#pragma once
#include "Animation.h"
#include <map>

#include <iostream>
#include <ctime>
#include "HealthBar.h"
#include "MapObjects.h"
#include "Item.h"
/**
 * @brief Klasa slotu w którym znajdują się przedmioty
 * 
 */
class ItemSlot
{
private:
	friend class Inventory;
	friend class Equipment;
	Item item;/*!<Przedmiot znajdujący się w slocie>*/
	RectangleShape slot;/*!<Ciało slota>*/
public:
	bool empty;
	/**
	 * @brief metoda służąca do ustawienia przedmiot w slocie
	 * 
	 * @param tmp przedmiot który wkładamy do slota
	 */
	void setItem(Item tmp);
	/**
	 * @brief konstruktor zawierający podstawowe parametry do stworzenia slota
	 * 
	 * @param pos pozycja slotu 
	 * @param size rozmiar slotu
	 * @param color kolor slotu
	 */
	ItemSlot(Vector2f pos, Vector2f size, Color color);
	/**
	 * @brief metoda zawierająca pozycje obiektu
	 * 
	 * @return wektor z pozycją obiektu
	 */
	Vector2f getPosition();
	/**
	 * @brief metoda ustawiająca pozycje slota
	 * 
	 * @param pos pozycje slota
	 */
	void setPosition(Vector2f pos);
	/**
	 * @brief metoda zawierająca wielkość slota
	 * 
	 * @return wektor zawierający wielkość slota
	 */
	Vector2f getSize();
	/**
	 * @brief metoda odpowiedzialna za renderowanie slotów
	 * 
	 * @param target wskaźnik na okno gry
	 */
	void render(RenderTarget* target);
};

