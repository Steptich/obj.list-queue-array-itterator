//
// Created by stept on 16.10.2020.
//

#include "list.h"
#include "element.h"
#include "iterator.h"

List::List()
: first(new Element), last(new Element), itemCounter(0)
//konstruktor vytvori nove first,last a da counter na nulu
{
iniList();
}


List::List(List &other)
        : first(new Element), last(new Element), itemCounter(0)
{
    iniList();
    copyFrom(other);
    //vytvori dalsi seznam a prekoporuje, takze s ni muzu pracovat zvlast a nezmenim puvodni
    //hluboka kopie
}

void List::copyFrom(List &src) {
    Element *ptr = src.first->next; //pomocny ukazatel ukazuje na prvni s daty z puvodniho
    while(ptr!=src.last) //dokud nedojete na konec
    {
        this->pushBack(ptr->getData());
        //ukazatel this ukazuje na objekt classy metody kterou pises ted
        //takze a.copyForm(other) ti udela a.pushBack(ptr.getData())
        //neboli vezme soucany list a strci do zadu prvni prvek z puvodniho seznamu
        ptr = ptr->next;
    }
}

List::~List() {
    clean();
    delete first;
    delete last;
}


void List::pushFront(Data d) {
    first->setData(d); //do prvniho v rade dam data
    first->prev=new Element; //vytvorim novy prazdny ktery je pred prvnim
    first->prev->next = first; //ten novy bude ukazovat na stary first
    first= first->prev; //novy prazdny se stane prvnim
    itemCounter++; //zvednu pocet existujicich
}
//jelikoz tvorime symetricky, postaci first <=> last, prev <=> next

void List::pushBack(Data d) {
    last->setData(d); //do posledniho v rade dam data
    last->next=new Element; //vytvorim novy prazdny ktery je za poslednim
    last->next->prev = last; //ten novy bude ukazovat na stary last
    last= last->next; //novy prazdny se stane last
    itemCounter++; //zvednu pocet existujicich
}

void List::print() const {
    Element* ptr= first->next; //novy ukazatel na prvni
    while (ptr!=last){
        ptr->print();
        ptr=ptr->next; //postupne prochazim
    }

}

void List::popFront() {
    if (!isEmpty()) {
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
        itemCounter--;
    }
}

void List::popBack() {
    if (!isEmpty()){
        last = last->prev;
        delete last->next;
        last->next = nullptr;
        itemCounter--;
    }

}

void List::clean() { //mazani seznamu odpredu
    while (!isEmpty()){
        popFront();
    }
}



Data List::front() const {
    return  first->next->getData(); //prvni uzitecna data
}

Data List::back() const {
    return last->prev->getData(); //posledni uzitecna data
}

void List::iniList() {
    first->next = last; //spojim a vytvorim oboustran seznam
    last->prev = first;
}

Element *List::find(Data d) {
    Element *p= first->next; //ukazatel na prnvni uzitecna data
    last->setData(d);
    while (d!=p->data)
    {
        p=p->next; //prochazeni dat
    }
    return  (p=last ? nullptr : p); //pokud p=last tak da nullptr jinak da p, je to vlastne if
}

bool List::remove(Data d) {
    Element* p=find(d);
    if(!p) //nullptr se pocita jako false takze !nullptr je true
    {
        return false;
    }
    p->next->prev = p->prev; //nasledujici neukazuje jiz na p ale na predchozi
    p->prev->next = p->next;
    delete  p;
    --itemCounter;
}

ListIterator *List::getIterator() {
    return new ListIterator(this); //priradi listu iterator
}









