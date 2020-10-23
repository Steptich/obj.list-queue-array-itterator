//
// Created by stept on 19.10.2020.
//

#include "array.h"
#include "iterator.h"
#include <cstring>


Array::Array(int size)
: capacity(size), data(new Data[capacity]){
    memset(data,0,capacity*sizeof(Data));
    //misto cyklu da vsude do data hodnotu 0 a
    // udela to pro vsechny prvky jelikoz jede po bitech
}

Array::Array(Array &src)
: capacity(src.capacity), data(new Data[capacity])
{//to stejne, ale zkopiruje
    memcpy(this->data,src.data,capacity*sizeof(Data));
}

Array::~Array(){
    delete[] data;  //smaze cely pole
}
Data &Array::at(int index) const {
    return  data[index]; //vrati data v danem indexu
}

ArrayIterator *Array::getIterator(){
    return new ArrayIterator(this);
}

void Array::setData(Data d, int index) {
    this->data[index]=d;

}

Data &Array::operator[](int index) {
    return data[index];
}

/*
void Array::expand() {
    Data  *newdata = new Data[2*capacity];
    //vytvori nove dvakrat vetsi pole
    memcpy(newdata,data,capacity*sizeof(Data));
    //zkopiruje do newdata data z puvodni az po bit
    // jenz odpovida velikosti puvodniho pole
    memset(newdata+capacity*sizeof(Data),0,
           capacity*sizeof(Data));
    delete [] data;
    data=newdata;
    capacity=2*capacity;
}
*/





