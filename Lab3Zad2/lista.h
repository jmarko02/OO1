#ifndef _lista_h_
#define _lista_h_

#include<exception>
//using namespace std;

class GPosition : public std::exception {
public:
	const char* what() const override {
		return "Lose zadata pozicija! ";
	}
};

template<typename T>
class Lista {
private:
	struct Node {
		T data;
		Node* next;
		Node(const T& data, Node* next = nullptr):data(data), next(next){}
	};
	Node* first = nullptr;
	Node* last = nullptr;

	int numberOfElements;

	void clear();
	void copy(const Lista& l);
	void move(Lista& l);

public:

	Lista();

	Lista(const Lista& l);
	Lista(Lista&& l);
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			clear();
			copy(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			clear();
			move(l);
		}
		return *this;
	}
	~Lista();

	void operator+=(const T& t);

	int getNumOfElem() const { return numberOfElements; }

	const T& operator[](int position) const;
	T& operator[](int position);

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
	numberOfElements = 0;
}

template<typename T>
void Lista<T>::copy(const Lista& l)
{
	first = last = nullptr;
	numberOfElements = l.numberOfElements;
	for (Node* temp = l.first; temp; temp = temp->next) {
		last = (!first ? first : last->next) = new Node(temp->data);
	}
}

template<typename T>
void Lista<T>::move(Lista& l)
{
	first = l.first;
	last = l.last;
	numberOfElements = l.numberOfElements;
	l.last = l.first = nullptr;

}

template<typename T>
Lista<T>::Lista()
{
	first = last = nullptr;
	numberOfElements = 0;
}

template<typename T>
Lista<T>::Lista(const Lista& l)
{
	copy(l);
}

template<typename T>
Lista<T>::Lista(Lista&& l)
{
	move(l);
}

template<typename T>
Lista<T>::~Lista()
{
	clear();
}

template<typename T>
void Lista<T>::operator+=(const T& t)
{
	last = (!first ? first : last->next) = new Node(t);
	numberOfElements++;
}

template<typename T>
const T& Lista<T>::operator[](int position) const 
{
	Node* temp = first;
	if (position > numberOfElements) throw GPosition();
	for (; position > 0; position--) {
		temp = temp->next;
	}
	return temp->data;
}

template<typename T>
T& Lista<T>::operator[](int position)
{
	
	Node* temp = first;
	if (position > numberOfElements) throw GPosition();
	for (; position > 0; position--) {
		temp = temp->next;
	}
	return temp->data;
	
}


#endif _lista_h_