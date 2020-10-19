//
// Created by stept on 16.10.2020.
//

#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include "list.h"
//chci pomoci obojstran seznamu vytvorit frontu -
//prvni dovnitr je prvni ven
class Queue {
    List* list;
public:
    Queue();
    ~Queue();
    void push(Data d);
    Data front() const;
    void pop();
    bool isEmpty() const;
};


#endif //LIST_QUEUE_H
