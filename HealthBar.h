#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
/**
 * @brief Pasek zdrowia wyświetlany nad obiektami
 * 
 */
class HealthBar
{
protected:
	Font font;/*!<Trzcionka>*/
	Text healthText;/*!<Napis na pasku życia>*/
	Text questChar;/*!<Napis informujący o tym czy obiekt posiada zadanie>*/
	RectangleShape healthBar;/*!<Pasek życia>*/
	RectangleShape healthBarBackGround;/*!<Tło paska życia>*/
	bool haveQuest;/*!<Informacja czy obiekt posiada zadanie>*/
public:
	/**
	 * @brief Konstruktor paska zdrowia
	 * 
	 * @param healthColor kolor paska zdrowia
	 */
	HealthBar(Color healthColor=Color::Red);
	/**
	 * @brief włączenie lub wyłączenie wyświetlania informacji o dostępnym zadaniu
	 * 
	 * @param value informacja czy wyświetlć czy nie
	 */
	void setQuest(bool value);
	/**
	 * @brief Zmiana koloru paska zdrowia
	 * 
	 * @param color nowy kolor
	 */
	void setColor(Color color);
	/**
	 * @brief wyświetlanie paska zdrowia
	 * 
	 * @param target wskażnik na okno gry
	 */
	void render(RenderTarget * target);
	/**
	 * @brief Aktualizowanie stanu paska zdrowia
	 * 
	 * @param EntityPos pozycja obiektu do którego jest przypisany pasek
	 * @param health aktualna wartość zrowia obiektu
	 */
	void update(const Vector2f &EntityPos,double &health);
};

