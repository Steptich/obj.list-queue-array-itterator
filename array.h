//
// Created by stept on 19.10.2020.
//

#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H

#include "datatype.h"

class ArrayIterator;

//delani classy pole
class Array {
    int capacity;
    Data *data;
public:
    Array(int size);
    Array(Array &src); //copirovaci konstruktor
    ~Array();
    Data &at(int index) const; //napis data na danem indexu
    void setData(Data d, int index);
    int getSize() const { return capacity; }
    friend class ArrayIterator;
    ArrayIterator* getIterator();

};
#endif //LIST_ARRAY_H
