//
// Created by stept on 19.10.2020.
//

#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H
//abstraktni iterator, nedela nic
// jen ma specializaci/potomky

#include "datatype.h"

class Iterator{
public:
    Iterator(){}
    virtual ~Iterator(){}; //nedela nic
    virtual void reset() = 0;//vraci nuly
    virtual bool next()= 0;
    virtual Data& data() = 0;
};
//==============================================================================
//dopredna deklarace
class List;
class Element; //includnu az v cpp
class Array;
//================================================================================

//specializace iterator nad seznamem
class ListIterator : public Iterator
{
protected:
    List * list; //ukazatel na list se kterym pracuji
    Element *current; //ukazatel na soucasny prvek
public:
    ListIterator(List *l);
    virtual ~ListIterator(){}
    //nemusel bych psat virtual,
    // ale je to dobry zvyk pro prehled
    virtual void reset();
    virtual bool next();
    virtual Data& data();
};
//================================================================================

//specializace na iterator nad polem

class ArrayIterator : public Iterator{
protected:
    Array * array; //ukazatel na pole se kterym pracuji
    Data   current; //aktualni prvek pole
    int index;
public:
    ArrayIterator(Array *a);
    virtual ~ArrayIterator(){}
    //nemusel bych psat virtual,
    // ale je to dobry zvyk pro prehled
    virtual void reset();
    virtual bool next();
    virtual Data& data();

};

#endif //LIST_ITERATOR_H