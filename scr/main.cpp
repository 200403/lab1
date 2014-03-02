#include "dzialanie.hh"
#include <iostream>
using namespace std;

int main(){
	LARGE_INTEGER start;
	LARGE_INTEGER end;
	Dzialanie program;

	program.wczytajDane();
	start=program.wlaczStoper();
	program.wykonajAlgorytm();
	end=program.wylaczStoper();
	if(program.sprawdz()==-1){
		cout << "bledny algorytm" <<endl;
	}
	else{
		cout << "Wykonanie algorytmu zajelo: ";
		cout << end.QuadPart - start.QuadPart << " milisekund." << endl;
	}


}



