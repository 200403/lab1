
#include "dzialanie.hh"
#include <iostream>
#include <fstream>

using namespace std;


/*!
	 * \brief metoda wczytuje dane do tablicy znajdujacej sie w zmiennej wejscie.
	 *
	 * 	Format danych w pliku jest nastepujacy:
	 * 	pierwszy wiersz - ilosc elementow, a nastepnie w kolumnie kolejne wartosci tablicy.
	 * 	\param nazwaPliku - nazwa pliku do otwarcia
	 * 	\return void
	 */
void Dzialanie::wczytajDane(){
	wejscie.wczytajDane("wejscia.txt");
}

/*!
	 * \brief Metoda uruchamia pomiar czasu
	 *
	 *  Czas jest mierzony w milisekundach
	 * 	\return czas, w ktorym zostal wlaczony stoper
	 */
LARGE_INTEGER Dzialanie::wlaczStoper(){

	 LARGE_INTEGER start;
	 DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	 QueryPerformanceCounter(&start);
	 SetThreadAffinityMask(GetCurrentThread(), oldmask);
	 return start;
}

/*!
		 * \brief Metoda konczy pomiar czasu
		 *
		 *  Czas jest mierzony w milisekundach
		 * 	\return czas, w ktorym stoper zostal wylaczony
		 */
LARGE_INTEGER Dzialanie::wylaczStoper(){

	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}

/*!
		 * \brief Metoda wykonuje algorytm na danych wejsciowych ( tablicy)
		 *
		 * 	Algorytm do wykonania : pomnoz kazdy element razy 2.
		 *
		 * 	\return void
		 */
void Dzialanie::wykonajAlgorytm(){
	for(unsigned int i=0; i<wejscie.rozmiar; i++){
		wejscie.dane[i]*=2;
	}
}

/*!
		 * \brief Metoda sprawdza poprawnosc algorytmu
		 *
		 *	Wczytywane sa poprawne dane wynikowe, a nastepnie sa one porownywane z tymi
		 *	otrzymanymi przez wykonanie algorytmu
		 *
		 * 	\return 0 - gdy algorytm jest poprawny, -1 - gdy nie.
		 */
int Dzialanie::sprawdz(){
	Dane wynik;
	wynik.wczytajDane("test.txt");
	for(unsigned int i=0; i<wejscie.rozmiar; i++){
		if(wejscie.dane[i]!=wynik.dane[i]){
			return -1;
		}
	}
	return 0;
}

