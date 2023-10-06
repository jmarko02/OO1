#include "lista.h"
#include "boja.h"
#include "kugla.h"
#include "ukras.h"
#include <iostream>
#include <exception>
using namespace std;

int main() {

	try {

		Boja b1(31, 2, 3);
		Boja b2(2, 55, 1);
		Boja b3 = b1 + b2;
		Boja b4 = b3 + b1;
		/*cout << b1;
		cout << (b1 == b2) << " " << (b1 != b2) << endl << b3 << endl;*/

		Kugla k1(500, b1, VELIKA);
		//cout << k1 << endl;

		Kugla k2(20, b2, MALA);
		//cout << k2 << endl;

		//Kugla k3(50, b3, SREDNJA);
		//cout << k3 << endl;

		Kugla k4(103.4, b4, NAJVECA);
		//cout << k4 << endl;

		/*Lista<int> list;
		list <<= 5;
		list <<= 4;
		list >>= 3;
		list >>= 2;

		cout << list;

		for (list.onFirst(); list.existCurr(); list.onNext()) {
			cout << list.getData() << " ";
		}*/
		
		Lista<Kugla> list;

		list <<= k1;
		list <<= k2;
		list <<= Kugla(50, b3, SREDNJA);;
		list <<= k4;

		for (list.onFirst(); list.existCurr(); list.onNext()) {
			cout << list.getData() << endl;
		}

	}
	catch (exception& e) {
		cout << e.what();
	}


}