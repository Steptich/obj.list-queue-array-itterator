//
// Created by stept on 16.10.2020.
//

#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

#include "datatype.h"

class Element{
    Data data;
    Element *prev; //spoj seznam, ukazatel na predchozi
    Element *next; //ukazatel na dalsi
public:
    Element() : prev(nullptr), next(nullptr) {}
    Element(Data d) : data(d), prev(nullptr), next(nullptr) {}
    Data getData() const;
    void setData(const Data &value); //abych nekopiroval data ale primo mel ty stejna
    void print() const;
    friend class List; //aby nova trida mohla sahat na prev,next,data
    friend class ListIterator;
};

#endif //LIST_ELEMENT_H
