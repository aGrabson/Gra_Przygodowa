#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
/**
 * @brief Struktura statystyk 
 * 
 */
struct statistics
{
	double armor;
	double agility;
	double damage;
};
/**
 * @brief Klasa przedmiotów dostępnych w grze
 * 
 */
class Item
{
private:
	Sprite body;/*!<Ciało obiektu posiadające tekture wyświetlane na ekranie>*/
	std::string name;/*!<Nazwa przedmiotu>*/
	
	struct statistics stat;/*!<Struktura z statystykami przedmiotu>*/
public:
	int slotId;/*!<Typ przedmiotu>*/
	/**
	 * @brief Konstruktor domyślny obiektu
	 * 
	 */
	Item();
	/**
	 * @brief Konstruktor inicjujący wartościami obiekt
	 * 
	 * @param tex wskaźnik na teksture przedmiotu
	 * @param pos pozycja przedmiotu
	 * @param name nazwa przedmiotu
	 * @param armor parametr obronny 
	 * @param agility parametr zwinnosci
	 * @param damage parametr ataku
	 * @param slotId typ przedmiotu
	 */
	Item(Texture *tex,Vector2f pos,std::string name, double armor, double agility,double damage,int slotId);
	/**
	 * @brief Dostęp do struktury z statystykami przedmiotu
	 * 
	 * @return struct statistics zawierającą statystyki przedmiotu
	 */
	struct statistics getStat();
	/**
	 * @brief Dostęp do rozmiaru przedmioru
	 * 
	 * @return FloatRect będący rozmiarem przedmiotu
	 */
	FloatRect getSize();
	/**
	 * @brief Dostęp do pozycji przedmiiotu
	 * 
	 * @return Vector2f-będące pozycja przedmiotu
	 */
	Vector2f getPos();
	/**
	 * @brief Ustawianie pozycji przedmiotu
	 * 
	 * @param pos nowa pozycja
	 */
	void setPos(Vector2f pos);
	/**
	 * @brief Dostęp do nazwy przedmiotu
	 * 
	 * @return std::string-będące nazwą przedmiotu
	 */
	std::string getName();
	/**
	 * @brief Aktualizacja parametrów przedmiotu
	 * 
	 */
	void update();
	/**
	 * @brief Wyświetlanie prezedmiotu na ekranie
	 * 
	 * @param target 
	 */
	void render(RenderTarget *target);
};

