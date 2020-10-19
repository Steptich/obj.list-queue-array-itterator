//
// Created by stept on 16.10.2020.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include "datatype.h"
class ListIterator;

class Element; //dopredna deklarace tridy element

class List{
    Element *first;
    Element *last;
    int itemCounter;
    void iniList();
    void copyFrom(List &src);
public:
    List();
    List(List &other); //kopirovaci konstruktor s hlubokou kopii
    ~List();
    bool isEmpty() const {return itemCounter ==0;}
    int getItemCount() const {return itemCounter;} //vrat pocet counteru
    Data front() const;
    Data back() const;
    void pushFront(Data d);
    void pushBack(Data d);
    void popFront();
    void popBack();
    void print() const;
    void clean();
    bool remove(Data d); //metoda na vymazani urciteho prvku s daty
    Element * find(Data d); //hledaci fce
    friend class ListIterator; //aby tato funkce mohla pristupovat k protected, ale nic nezdedi
    ListIterator* getIterator();
};



#endif //LIST_LIST_H
