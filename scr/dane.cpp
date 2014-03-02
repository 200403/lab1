#include "dane.hh"
#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

/*!
	 * \brief metoda wczytuje dane do tablicy z pliku
	 *
	 * 	Format danych w pliku jest nastepujacy:
	 * 	pierwszy wiersz - ilosc elementow, a nastepnie w kolumnie kolejne wartosci tablicy.
	 * 	\param nazwaPliku - nazwa pliku do otwarcia
	 * 	\return void
	 */
void Dane::wczytajDane(char* nazwaPliku){
	ifstream plik;
	plik.open(nazwaPliku, ifstream::out);
	plik >> rozmiar;
	while( !plik.eof()){
		int element;
		plik >> element;
		dane.push_back(element);
	}
	assert(rozmiar==dane.size());
	plik.close();
}

