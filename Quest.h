#pragma once
#include <iostream>
#include <vector>
/**
 * @brief Typ wyliczeniowy z rodzajmi zdażeń wymaganych to wykonywania zadań
 * 
 */
enum questEventsName{killSkeleton};
/**
 * @brief Typ wyliczeniowy z typami zadań
 * 
 */
enum questTypesName{q1,q2,q3};
/**
 * @brief Klasa reprezentująca zadania otrzymywane przez gracza
 * 
 */
class Quest
{
private:
	std::string descripton;/*!<Opis zadania>*/
	bool complete;/*!<Informacja czy zadanie zostało wykonane>*/
	int type;/*!<Typ zadania>*/
	int currentProgress;/*!<Obecne postępy w wykonywaniu zadania>*/
	int maxProgress;/*!<Wartość jaką musi osiągnąć zmienna currentProgress aby zadanie zostało zaliczone>*/
public:
	/**
	 * @brief konstruktor tworzący określony typ zadania
	 * 
	 * @param type określa które zadanie ma być wybrane
	 */
	Quest(int type);
	/**
	 * @brief metoda tworząca opis zadania
	 * 
	 * @return opis zadania
	 */
	std::string getDescription();
	/**
	 * @brief metoda która jest warunkiem zakończenia zadania
	 * 
	 * @return maksymalną wartość na zakończenie zadania
	 */
	int getMaxProgress();
	/**
	 * @brief metoda zawierająca aktualny stan zadania
	 * 
	 * @return aktualny stan zadania 
	 */
	int getCurrentProgress();
	/**
	 * @brief metoda zawierająca typ zadania
	 * 
	 * @return typ zadania
	 */
	int getType();
	/**
	 * @brief 
	 * 
	 * @param questEvents kontener zawierający informacje na temat postępów zadań 
	 * @return true jeśli zadanie jest przyjęte
	 * @return false jeśli zadanie nie jest przyjęte
	 */
	bool update(std::vector<int>& questEvents);
};

