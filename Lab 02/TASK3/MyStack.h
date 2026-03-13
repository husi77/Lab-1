#pragma once

#include <iostream>
#include "Stack.h"
using namespace std;

class MyStack : public Stack {
public:
    MyStack(int _maxCapacity = 0) : Stack(_maxCapacity) {}
    MyStack(const MyStack& ma) : Stack(ma) {}

    void push(int v);
    bool pop(int& v);
};

void MyStack::push(int v) {
    if (!isFull()) {
        currentIndex++;
        values[currentIndex] = v;
        return;
    }
    cout << "Array is full\n";
}

bool MyStack::pop(int& v) {
    if (!isEmpty()) {
        v = values[currentIndex];
        currentIndex--;
        return true;
    }
    return false;
}