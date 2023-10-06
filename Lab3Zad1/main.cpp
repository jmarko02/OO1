#include "skup.h"
#include "rec.h"
#include "stih.h"
#include "strofa.h"
#include "katren.h"
#include <iostream>
using namespace std;

int main() {

	try {

		
		Stih verse1, verse2, verse3, verse4;
		cin >> verse1;
		cin >> verse2;
		cin >> verse3;
		cin >> verse4;

		Katren katren1(4);

		katren1 += verse1;
		katren1 += verse2;
		katren1 += verse3;
		katren1 += verse4;

		cout <<endl<< endl << katren1;

		/*
		I ovaj kamen zemlje Srbijeoko
		sto pretec suncu dere kroz oblakmama
		sumornog cela mracnim boramamama
		pokazujuci nemom mimikomoko


		o vekovecnosti prica dalekojmama
		*/


		//Skup skup1("Ab4a34c");
		//skup1 += 'd';
		////cout << skup1('b') << " " << skup1('D') << endl;

		//
		//Rec word1("I");
		//Rec word2("ovaj");
		//Rec word3("kamen");
		//Rec word4("zemlje");
		//Rec word5("Srbijeoko");


		//
		////cout << (word1^word2);

		////cout << word1 << " " << ~word1 << endl;

		////cin >> word1;

		////cout << word1 << " " << ~word1;

		////cout << endl << endl << endl << endl;

		//Rec word6("sto");
		//Rec word7("pretec");
		//Rec word8("suncu");
		//Rec word9("dere");
		//Rec word10("kroz");
		//Rec word11("oblakmama");

		//Rec word12("sumornog");
		//Rec word13("cela");
		//Rec word14("mracnim");
		//Rec word15("boramamama");

		//Rec word16("o");
		//Rec word17("vekovecnosti");
		//Rec word18("prica");
		//Rec word19("dalekojmama");

		//Rec word20("pokazujuci");
		//Rec word21("nemom");
		//Rec word22("mimikomoko");


		//Stih verse1;
		//verse1 += word1;
		//verse1 += word2;
		//verse1 += word3;
		//verse1 += word4;
		//verse1 += word5;

		///*cout << verse1 << endl;
		//cout << (+verse1) << " " << (~verse1) << endl;
		//cout << verse1[0] << endl;*/

		////verse1(3);
		////cout << verse1 << endl;

		////Rec dodata("marko");

		////verse1(dodata, 4);
		////cout << verse1 << endl;

		//Stih verse2;
		//verse2 += word6;
		//verse2 += word7;
		//verse2 += word8;
		//verse2 += word9;
		//verse2 += word10;
		//verse2 += word11;
		////cout << verse2 << endl;

		////cout << (verse1 ^ verse2) << endl;

		//Stih verse3;
		//verse3 += word12;
		//verse3 += word13;
		//verse3 += word14;
		//verse3 += word15;


		//Stih verse4;
		//verse4 += word16;
		//verse4 += word17;
		//verse4 += word18;
		//verse4 += word19;


		//Stih verse5;
		//verse5 += word20;
		//verse5 += word21;
		//verse5 += word22;
		////cin >> verse3;

		////cout << verse3 << endl;

		////Stih verse4;
		////cin >> verse4;
		////cout << verse4 << endl;

		////Stih verse5;
		////cin >> verse5;
		////cout << verse5 << endl;

		//Katren part(5);
		//part += verse1;
		//part += verse2;
		//part += verse3;
		//part += verse5;
		////part += verse5;

		////cout << part << +part << endl;

		////-part;
		////cout << part;

		////cout << endl << endl << endl;

		//cout << part;
		////part(1, 2);
		//cout << endl;

		//cout << *part << " " << part.tag() << endl << endl;
		//
		//Rec r404("Marko");
		//Stih stih;
		//stih += r404;
		//part += stih;
		//cout << part << endl << endl << endl;

		//-part;
		//cout << part << endl;
		//part(0, 2);
		//cout << part;

		//cout << endl << +part;
		//cout << endl << part[0];



		//cout << part;

		/*Strofa p2(4);
		Stih s1, s2, s3, s4;
		std::cin >> s1 >> s2 >> s3 >> s4;

		(((p2 += s1 )+= s2) += s3) += s4;

		std::cout << p2;*/

		/*
		Do juce su punile predamnom klupe
		devojke smernih skuta kao u buba
		kao ladolez oko mamama stuba
		i savijale se oko me sve blupe


		I ovaj kamen zemlje Srbijeoko
		sto pretec suncu dere kroz oblakmama
		sumornog cela mracnim boramamama
		pokazujuci nemom mimikomoko


		o vekovecnosti prica dalekojmama


		*/

	}
	catch (exception& e) {
		cout << e.what() << endl;
	}


}