//
// Created by stept on 16.10.2020.
//

#include "element.h"
#include "iostream"

void Element::setData(const Data &value) {
    data=value;
}

Data Element::getData() const {
    return data;
}

void Element::print() const {
    std::cout << data << "\n";
}


