#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
using namespace sf;
/**
 * @brief Klasa przycisków
 * 
 */
class Button
{
private:
	Texture texture;/*!<Tekstura przycisku>*/
	Sprite body;/*!<>Ciało przycisku*/
public:
	/**
	* @brief konstruktor domyślny
	* 
	*/
	Button();
	/**
	 * @brief konstruktor inicjujący przycisk
	 * 
	 * @param path ścieżka do textury przycisku
	 * @param position pozycja na ekranie przycisku
	 */
	Button(std::string path,Vector2f position);
	/**
	 * @brief Wykrywanie wcisnięcia przycisku
	 * 
	 * @param window referencja do okna aplikacji
	 * @return true jeżeli przycisk został wciśnięty
	 * @return false jeżeli przycisk nie został wciśnięty
	 */
	bool PressDetection(const RenderWindow &window);
	/**
	 * @brief Skalowanie rozmiaru przycisku o zadaną Wartość
	 * 
	 * @param x skalowanie na osi x
	 * @param y skalowanie na osi y
	 */
	void setScale(double x, double y);
	/**
	 * @brief aktualizowanie stanu przycisku
	 * 
	 */
	void update();
	/**
	 * @brief wyświetlanie przycisku na ekranie
	 * 
	 * @param target wskaźnik na okno gry
	 */
	void render(RenderTarget *target);
};

