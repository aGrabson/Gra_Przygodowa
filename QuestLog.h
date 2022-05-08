#pragma once
#include <SFML/Graphics.hpp>
#include "Quest.h"

using namespace sf;
/**
 * @brief Okno z obecnie posiadanymi zadaniami wyświetlane na ewkranie
 * 
 */
class QuestLog
{
private:
	Font font;/*!<Trzcionka>*/
	Text text;/*!<Wyświetlany tekst z opisem zadania>*/
	Text text2;/*!<Wyświetlany tekst z postępem w wykonywaniu zadania>*/
	RectangleShape background;/*!<Tło okna>*/
	RectangleShape questBackground;/*!<Tło okna wewnętrznego>*/

	float sizeX;/*!<Rozmiar okna na osi X>*/
	float sizeY;/*!<Rozmiar okna na osi y>*/
public:
	bool visable;/*!<Informacja czy okno jest widoczne>*/
	/**
	 * @brief Koknstruktor inicjujący okienko z zadaniami
	 * 
	 */
	QuestLog();
	/**
	 * @brief Wyświetlanie okienka z zadaniami
	 * 
	 * @param target wskaźnik na oknko gry 
	 * @param pos pozycja kamery na mapie
	 * @param playerQuests kontener z zadaniami posiadanymi przez gracza
	 */
	void show(RenderTarget* target, Vector2f pos,std::vector<Quest>&playerQuests);

};

