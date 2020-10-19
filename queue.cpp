//
// Created by stept on 16.10.2020.
//

#include "queue.h"

Queue::Queue()
:list(new List()) //udelam ukazatel na seznam
{}

Queue::~Queue() {
delete list;
}

void Queue::push(Data d) {
list->pushBack(d);
}

Data Queue::front() const {
    return list->front(); //vrati prvni uzitecny
}

void Queue::pop() {
list->popFront(); //smaze prvni data
}

bool Queue::isEmpty() const {
    return list->isEmpty();
}
