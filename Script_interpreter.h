#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
/**
 * @brief Typ wyliczeniowy z obsługiwanymi komendami przez interpretator
 * 
 */
enum load_objects_operation { NOP,ONEOBJECT,TABOBJECT,SETSECTOR,SETPOSITION,CREATEOBJ,CREATETAB,SETSIZE,SETCOLUMN,SETROW, SETTEXTURE, SETPOSX, SETPOSY, SETSCALEX, SETSCALEY, CREATE,SETTEXTURESCALEX,SETTEXTURESCALEY,
	TEXTUREOBJECT,SETOFFSETX,SETOFFSETY
};

/**
 * @brief Obiekt przechowujący wartości odczytanew przez interpreter
 * 
 */
class Script_values
{
public:
	int column;/*!<Numer kolumny>*/
	int row;/*!<Numer wiersza>*/
	string texture_name;/*!<Nazwa tekstury>*/
	int posx;/*!<Pozycja na osi x>*/
	int posy;/*!<Pozycja na osi y>*/
	int offsetx;/*!<Przesuniecie hitboxa na osi x>*/
	int offsety;/*!<Przesunięcie hitboxa na osi y>*/
	double colision_x_scale;/*!<Wartość skalowania hitboxa na osi x>*/
	double colision_y_scale;/*!<Wartość skalowania hitboxa na osi y>*/
	double texture_scale_X;/*!<Wartość skalowania tektury na osi x>*/
	double texture_scale_Y;/*!<Wartość skalowania tekstury na osi y>*/
};
typedef vector<Script_values> Script;
/**
 * @brief KLasa słóżąca do odczytywanian z pliku informacji o rozmieszczeniu obiektów na mapie oraz informacji o ich cechach
 * 
 */
class Script_interpreter
{
	int tabsize;/*!<Rozmiar tablicy obiektów>*/
	string stringnum;/*!<Zmienna pomocnicza>*/
	string tmp;/*!<Zmienna pomocnicza >*/
	string strbuffX;/*!<Zmienna pomocnicza>*/
	string strbuffY;/*!<Zmienna pomocnicza>*/
	int operation;/*!<Numer operacji >*/
	int type;/*!<Typ odczytywanego bloku poleceń>*/
	int index;/*!<Indeks pomocniczy>*/
	int numberOfObjects;/*!<Liczba obiektów w bloku>*/
	Script valuesTab;/*!<Kontener z odczytanymi obiektami>*/
	/**
	 * @brief Wykonanie zadanej operacji dla trybu pojedynczego obiektu
	 * 
	 * @return true jezeli została wykonana któraś operacja 
	 * @return false jeżeli nie została wykonana żadna operacja
	 */
	bool oneObjectOperations();
	/**
	 * @brief Wykonanie zadanej operacji dla trybu tablicy obiektów
	 * 
	 * @return true jezeli została wykonana któraś operacja 
	 * @return false jeżeli nie została wykonana żadna operacja
	 */
	bool tabObjectOperations();
	/**
	 * @brief Odczyt typu operacji
	 * 
	 * @return true jeżeli otrzymano koniec pliku
	 * @return false w przeciwnym wyadku
	 */
	bool readOperation();
	Script_values values;
public:
	/**
	 * @brief Konstruktor inicjujący obiekt
	 * 
	 */
	Script_interpreter();
	/**
	 * @brief Odczytywanie i interpretowanie pliku
	 * 
	 * @param path ścieżka do pliku
	 * @return vector z obiektami typu Script_values z informacjami o obiektach do dodania
	 */
	Script readFile(string path);
};

