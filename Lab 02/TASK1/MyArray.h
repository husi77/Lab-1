#pragma once

#include <iostream>
#include "AbstractArray.h"
using namespace std;

class MyArray : public AbstractArray {
public:
    MyArray(int _maxCapacity = 0) : AbstractArray(_maxCapacity) {}
    MyArray(const MyArray& ma) : AbstractArray(ma) {}

    void add(int v);
    bool remove(int& v);
    bool get(int index, int& v);
    void insert(int index, int value);
};

void MyArray::add(int v) {
    if (!isFull()) {
        currentIndex++;
        values[currentIndex] = v;
        return;
    }
    cout << "Array is full\n";
}

bool MyArray::remove(int& v) {
    if (!isEmpty()) {
        v = values[currentIndex];
        currentIndex--;
        return true;
    }
    return false;
}

bool MyArray::get(int index, int& v) {
    if (index >= 0 && index <= currentIndex) {
        v = values[index];
        return true;
    }
    return false;
}

void MyArray::insert(int index, int value) {
    if (index >= 0 && index <= currentIndex) {
        values[index] = value;
        return;
    }
    cout << index << " is invalid\n";
}