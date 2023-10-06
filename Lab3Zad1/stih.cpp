#include "stih.h"

void Stih::copy(const Stih& verse)
{
    first = last = nullptr;
    for (Node* temp =verse.first; temp; temp = temp->next) {
        if (!first) first = last = new Node(temp->word);
        else last = last->next = new Node(temp->word);
    }
}

void Stih::move(Stih& verse)
{
    first = verse.first;
    last = verse.last;
    verse.last = verse.first = nullptr;
}

void Stih::clear()
{
    while (first) {
        Node* old = first;
        first = first->next;
        delete old;
    }
    first = last = nullptr;
}

Stih::Stih(const Stih& verse)
{
    copy(verse);
}

Stih::Stih(Stih&& verse)
{
    move(verse);
}

Stih& Stih::operator=(const Stih& verse)
{
    if (this != &verse) {
        clear();
        copy(verse);
    }
    return *this;
}

Stih& Stih::operator=(Stih&& verse)
{
   if (this != &verse) {
        clear();
        move(verse);
   }
   return *this;

}

Stih::~Stih()
{
    clear();
}

Stih& Stih::operator+=(Rec word)
{
    if (!first) first = last = new Node(word);
    else last = last->next = new Node(word);
    return *this;
}

int Stih::operator+() const
{
    int num = 0;
    for (Node* curr = first; curr; curr = curr->next) {
        num++;
    }
    return num;
}

int Stih::operator~() const
{
    int num = 0;
    for (Node* curr = first; curr; curr = curr->next) {
        num += ~(curr->word);
    }
    return num;
}

Rec Stih::operator[](int position)
{
    Node* temp = first;
    for (; position > 0; position--) {
        temp = temp->next;
    }
    return temp->word;
}

const Rec Stih::operator[](int position) const
{
    Node* temp = first;
    for (; position > 0; position--) {
        temp = temp->next;
    }
    return temp->word;
}

void Stih::operator()(int position)
{
    
    if (position <= 0 || position > +(*this)) throw GIndex();
    Node* temp = first;
    if (position == 1) {
        first = first->next;
        delete temp;
        return;
    }
    Node* curr = first;
    temp = temp->next;
    if (position == 2) {
        curr->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return;
    }
    while (position > 2) {
        curr = temp;
        temp = temp->next;
        position--;
    }
    if (temp->next == nullptr) last = curr;
    curr->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return;
}

void Stih::operator()(Rec newWord, int position)
{
    if (position <= 0 || position > +(*this)) throw GIndex();
    Node* temp = first;
    if (position == 1) {
        Node* newborn = new Node(newWord);
        newborn->next = first;
        first = newborn;
        return ;
    }
    Node* prev = nullptr;
    while (position >= 2) {
        prev = temp;
        temp = temp->next;
        position--;
    }
    Node* newborn = new Node(newWord);
    newborn->next = temp;
    prev->next = newborn;
    return ;

}


bool operator^(const Stih& verse1, const Stih& verse2)
{
    return verse1.last->word ^ verse2.last->word;
}

istream& operator>>(istream& is,Stih& verse)
{
    string newVerse;
    //cin.clear();
    //cin.ignore(100, '\n');
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(is, newVerse);
    string temp;
    //verse.~Stih();
    for (auto i : newVerse) {
    //for(auto i = newVerse.begin(); i<newVerse.end(); i++){
        if (i == ' ') {
            Rec newWord(temp);
            verse += newWord;
            temp = "";
        }
        temp += i;
    }
    Rec newWord(temp);
    verse += newWord;
    return is;

}

ostream& operator<<(ostream& os, const Stih& verse)
{
    for (Stih::Node* temp = verse.first; temp; temp = temp->next) {
        os << temp->word;
    }
    return os;
}
