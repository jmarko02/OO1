#include"lista.h"
#include"Vreme.h"
#include"domaci.h"
#include"strani.h"

#include<iostream>
using namespace std;

int main() {
	try {
		Vreme v1(1, 50);
		//cout << v1;
		Vreme v2(4,20);
		Vreme v3(12,35); //napravi exception za ovo

		Vreme v4 = v1+v2;
		//cout << v4;

		//cout << v1 << endl << v2 << endl << v3 << endl;

		//Vreme v4 = v1 + v2 + v3;
		//cout << v4 << endl;
		//Vreme v5 = v4;
		//cout << v5 << endl;

		////cout << (v5 < v2);

		Domaci d1("Kamiondzije", v2);
		d1.rateFilm(5);
		d1.rateFilm(6);
		//cout << d1 << endl;

		Strani s1("Endgame", v3, "USA", TITLOVAN);
		s1.rateFilm(7);
		s1.rateFilm(10);

		Lista<Film*> list;
		
		list += &d1;
		list += &s1;

		for (int i = 0; i < list.getNumOfElem(); i++) {
			cout << *list[i] << endl;
		}

		Lista<Film*> list1;

		list1 = list;

		for (int i = 0; i < list1.getNumOfElem(); i++) {
			cout << *list1[i] << endl;
		}

	}
	catch (exception& e) {
		cout << e.what();
	}
	
}



