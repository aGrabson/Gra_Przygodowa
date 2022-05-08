#pragma once

#include "Slot.h"
/**
 * @brief Obiekt z przedmiotami posiadanymi przez gracza
 * 
 */
class Inventory
{
private:
	bool navigationKeyPressed;/*!<Informacja o satnie wciśnięcia przycisków do nawigowania po inventory>*/
	std::vector<ItemSlot> slots;/*!<Kontener z slotami należącyni do inventory>*/
	float sizeX;/*!<Rozmiar na osi X>*/
	float sizeY;/*!<Rozmiar na osi y>*/
	int selectedItem;/*!<Id obecnie wybranego slotu w inventory>*/
	int numberOfColumns;/*!<Ilość kolumn w inventory>*/
	int numberOfRows;/*!<Ilość wierszy w inventory>*/
	RectangleShape background;/*!<Tło inventory>*/
	/**
	 * @brief Stworzenie odpowiedniej ilości sltów
	 * 
	 */
	void createSlots();
public:
	bool visable;
	/**
	 * @brief Kasowanie wszystkich przedmiotów z gracza
	 * 
	 */
	void clear();
	/**
	 * @brief Konstruktor inicjujący obiekt
	 * 
	 */
	Inventory();
	/**
	 * @brief Aktualizacja stanu obiektu
	 * 
	 * @param itemToEquip informacja zwrotna o tym czy przedmiot został zlecony do zaożenia
	 * @param item przedmiot zwrotny zlecony do założenia
	 */
	void update(bool &itemToEquip, Item &item);
	/**
	 * @brief dodanie przedmiotu do inventory
	 * 
	 * @param tmp dodawany przedmiot
	 */
	void addItem(Item tmp);
	/**
	 * @brief wyświetlanie inventory gracza
	 * 
	 * @param target wskaźnik do okna gry
	 * @param pos pozyja kamery na mapie
	 */
	void show(RenderTarget* target,Vector2f pos);

};

