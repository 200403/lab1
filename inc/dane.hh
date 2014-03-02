#include <string>
#include <vector>
using namespace std;

/*!
 *\brief Struktura Dane
 *
 *	Struktura posiada 2 pola:
 *	-tablice (vector),
 *	-rozmiar tablicy.
 */
typedef struct Dane{
	vector <int> dane;
	unsigned int rozmiar;

	/*!
	 * \brief metoda wczytuje dane do tablicy z pliku
	 *
	 * 	Format danych w pliku jest nastepujacy:
	 * 	pierwszy wiersz - ilosc elementow, a nastepnie w kolumnie kolejne wartosci tablicy.
	 * 	\param nazwaPliku - nazwa pliku do otwarcia
	 * 	\return void
	 */
	void wczytajDane(char* nazwaPliku);
}Dane;

