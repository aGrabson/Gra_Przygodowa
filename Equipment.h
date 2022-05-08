#pragma once
#include "Slot.h"
/**
 * @brief Klasa z wyposarzeniem gracza w postaci założonych przedmiotów oraz statystyk
 * 
 */
class Equipment
{
private:
	std::vector<ItemSlot> slots;/*!<Kontener z slotami znajdującymi się w equipment gracza>*/
	Sprite playerIcon;/*!<Ikona gracza wyświetlana w equipment>*/
	float sizeX;/*!<Pozycja okna na osi x>*/
	float sizeY;/*!<Pozycja okna na osi y>*/

	Text armor;/*!<Tekst do statystyki obrony>*/
	Text damage;/*!<Tekst do statystyki obrażeń>*/
	Text health;/*!<Tekst do statystyki zdrowia>*/
	Text agility;/*!<Tekst do statystyki zwinności>*/

	double *armorValues;/*!<>*/
	double *damageValues;/*!<>*/
	double *agilityValues;/*!<>*/
	double *healthValues;/*!<>*/

	Font gameFont;/*!<Trzcionka>*/

	RectangleShape background;/*!<Tło okna equipment>*/
	/**
	 * @brief Ustawienie pozycjislotów w wyposarzeniu
	 * 
	 * @param bcgPos pozycja tła wypozarzenia na ekranie
	 */
	void positioningSlots(Vector2f bcgPos);
	/**
	 * @brief Aktulizacja stanu statystyk wyswietlanych w wyposarzeniu
	 * 
	 * @param pos pozycja tła wypozarzenia na ekranie
	 */
	void updateStatistics(Vector2f pos);
	/**
	 * @brief Tworzenie wyaganej ilości slotów
	 * 
	 */
	void createSlots();

	struct statistics bonusStat;

	
public:
	/**
	 * @brief Przekopiowanie wskażników statystyk gracza
	 * 
	 * @param health wskażnik na wartość zdrowia
	 * @param damage wskażnik na wartość obrażeń
	 * @param armor wskażnik na wartość obrony
	 * @param agility wskażnik na wartość zwinności
	 */
	void setDefaultParameters(double* health, double* damage, double* armor, double* agility);
	/**
	 * @brief ustawienie trzcionka
	 * 
	 * @param font referencja do obiektu Font
	 */
	void setFonts(const Font& font);
	bool visable;
	/**
	 * @brief Konstruktor inicjujący obiekt
	 * 
	 */
	Equipment();
	/**
	 * @brief Aktualizacja wszystkich elementów obiektu
	 * 
	 */
	void update();
	/**
	 * @brief usuwanie przedmiotów i zerowanie statystyk
	 * 
	 */
	void clear();
	/**
	 * @brief Get the Stat object
	 * 
	 * @return struct statistics - struktura zawierająca informacje o statystykach gracza
	 */
	struct statistics getStat();
	/**
	 * @brief Dodawanie przedmiotu do ekwipunku
	 * 
	 * @param item przedmiot który ma zostać dodany
	 * @param tmpbool infromacja zwrotna o tym czy doszło do podmiany przedmiotów 
	 */
	void addItem(Item &item, bool& tmpbool);
	/**
	 * @brief Ustawienie ikony dla tekstury gracza wyświetlaniej w wyposażeniu
	 * 
	 * @param player wskaźnik do tekstury gracza
	 */
	void setIconSprite( Texture* player);
	/**
	 * @brief Wyświetlenie wyposarzenia gracza
	 * 
	 * @param target wskaźnik do okna gry
	 * @param pos pozycja kamery gry
	 */
	void show(RenderTarget* target, Vector2f pos);

};

