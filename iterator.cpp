//
// Created by stept on 19.10.2020.
//

#include "iterator.h"
#include "list.h"
#include "element.h"
#include "array.h"
//============================================================
ListIterator::ListIterator(List *l)
: list(l), current(l->first)
{}

void ListIterator::reset() {
current = list->first; //vrati ukazatel na zacatek
}

bool ListIterator::next() {
    if(current!=list->last){
        //funkce na prochazeni, nevim kde zacinam
        current=current->next; //kontrola jestli nejsem na konci
    }
    else{
        reset(); //kdyz jsem na konci skoc
        //zase na zacatek abych prosel cele
        // kdybych nezacinal na zacatku
    }
    if(current==list->last) { //pripad kdy jen dva prvky
        return false;
    }
    return true;
}

Data &ListIterator::data() {
    return current->data;
}
//=================================================================
  ArrayIterator::ArrayIterator(Array *a) //nepotrebuji index promenou
  : array(a), current(-1)
  {}

  void ArrayIterator::reset() {
    current=-1;
    //opet pred vsechny data
}

    bool ArrayIterator::next()
{
    if (current==array->getSize())
        //pokud neni na konci pole
    {
    reset();
    }
    else
    {
        current++;
    }
    if (current==array->getSize()) //pokud na konci pole
    {
        return false;
    }
    return true;
}

    Data &ArrayIterator::data() {
    return array->at(current);
}

/*alternativa
ArrayIterator::ArrayIterator(Array *a)
: array(a), index(-1), current(a->at(index))
//abych zacinal pred zacatkem
{}

void ArrayIterator::reset() {
    index=-1;
    current=array->at(index);
    //opet pred vsechny data
}

bool ArrayIterator::next()
{
    if (index!=((array->capacity)))
        //pokud neni na konci pole
    {

        current=array->at(++index);//posun se o index


    }
    else
    {
        reset();
    }
    if (index==((array->capacity))) //pokud na konci pole
    {
        return false;
    }
    return true;
}

Data &ArrayIterator::data() {
    return current;
}
*/