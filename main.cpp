#include <iostream>
#include "list.h"
#include "queue.h"
#include "iterator.h"
#include "array.h"


void printSequence(Iterator *i)//vytiskne posloup seznamu
{
    std::cout << "-----------------\n";
    i->reset();
    while (i->next())
    {
        std::cout << i->data()<< "\n";
    }
    std::cout << "-----------------\n";
}

Data findMin(Iterator *i)
{
    Data min;
    bool valid = false;
    i->reset(); //abych zase zacal od zacatku
    while (i->next()) //dokud cele neprojde
    {
        if (!valid)
    //zajistim abych mel na zacatku porovnavaci hodnotu z prvniho prvku seznamu s daty
        {
            min=i->data();
            valid=true;
        }
        else if (i->data()<min) //pokud najde mensi
        {
            min=i->data(); //tamk to priradi
        }
    }
    std::cout << "Minimum je:" << min << "\n";
}


int main() {

    List l;
    l.pushBack(9);
    l.pushFront(5);
    l.pushBack(6);
    l.pushFront(2);
    //l.print();
    ListIterator *li=l.getIterator();
    //priradi listu li iterator, vlastne mi nezalezi na datech co tam jsou
    //staci mit specializaci pro danou tridu
    printSequence(li);
    findMin(li);
    List m(l); //kopirovaci konstruktor
    m.print();

    Array a (3);
    //takhle syntax kdyz ma classa parametr
    a.setData(1,0);
    a.setData(2,1);
    a.setData(3,2);
    ArrayIterator *ai=a.getIterator();
    printSequence(ai);
    findMin(ai);

    Queue q;
    for (int i = 0; i < 11; ++i) {
        q.push(i);
    }
    while (!q.isEmpty())
    {
        std::cout<< q.front() << "\n";
        q.pop();
    }
    return 0;
}
