#ifndef _lista_h_
#define _lista_h_

#include <exception>

class GNoCurr:public std::exception{
public:
	const char* what() const override {
		return "Nema tekuceg elementa! ";
	}
};

template<typename T>
class Lista {
public:
	Lista() {}

	Lista(const Lista& l) = delete;
	Lista& operator=(const Lista& l) = delete;
	~Lista();

	void operator<<=(const T& d);
	void operator>>=(const T& d);

	void onFirst() const;
	void onNext() const;
	bool existCurr() const;

	T& getData() const;

private:
	struct Node {
		T data;
		Node* next;
		Node(const T& t, Node* next = nullptr):data(t),next(next){}
	};
	Node* first = nullptr;
	Node* last = nullptr;
	mutable Node* current = nullptr;

	void clear();

};

template<typename T>
void Lista<T>::clear()
{
	while (first) {
		Node* old = first;
		first = first->next;
		delete old;
	}
	last = first = nullptr;
}

template<typename T>
Lista<T>::~Lista()
{
	clear();
}

template<typename T>
void Lista<T>::operator<<=(const T& d)
{
	if (!first) last = first = new Node(d); 
	else last = last->next = new Node(d);
}

template<typename T>
void Lista<T>::operator>>=(const T& d)
{
	if (!first) first = last = new Node(d);
	else {
		Node* newborn = new Node(d);
		newborn->next = first;
		first = newborn;
	}
}

template<typename T>
void Lista<T>::onFirst() const
{
	current = first;
}

template<typename T>
void Lista<T>::onNext() const
{
	current = current->next;
}

template<typename T>
bool Lista<T>::existCurr() const
{
	return current != nullptr;
}

template<typename T>
T& Lista<T>::getData() const
{
	if (!existCurr()) throw GNoCurr();
	return current->data;
}

#endif _lista_h_
