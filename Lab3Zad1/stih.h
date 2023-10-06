#ifndef _stih_h_
#define _stih_h_
#include "rec.h"
#include <exception>
#include <iostream>
//#include <limits>

class GIndex : public exception {
public:
	const char* what() const override {
		return "Nevalidan indeks!";
	}
};
class Stih {
public:
	Stih() {}
	
	Stih(const Stih& verse);
	Stih(Stih&& verse);
	Stih& operator=(const Stih& verse);
	Stih& operator=(Stih&& verse);
	~Stih();
	
	Stih& operator+=(Rec word);
	int operator+() const;
	int operator~() const;

	Rec operator[](int position);
	const Rec operator[](int position) const;

	void operator()(int position);
	void operator()(Rec word, int position);

	friend bool operator^(const Stih& verse1, const Stih& verse2);
	
	friend istream& operator>>(istream& is, Stih& verse);
	friend ostream& operator<<(ostream& os, const Stih& verse);

private:

	struct Node {
		Rec word;
		Node* next;
		Node(Rec word, Node* next = nullptr) :word(word), next(next) {}
	};
	Node* first = nullptr;
	Node* last = nullptr;

	void copy(const Stih& verse);
	void move(Stih& verse);
	void clear();

};

#endif _stih_h_

