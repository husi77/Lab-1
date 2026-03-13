#pragma once

class Stack {
public:
    Stack(int _maxCapacity = 0);
    Stack(const Stack& AA);

    virtual void push(int v) = 0;
    virtual bool pop(int& value) = 0;

    bool isEmpty();
    bool isFull();

    virtual ~Stack();

protected:
    int currentIndex;
    int* values;
    int maxCapacity;
};

Stack::Stack(int _maxCapacity) {
    currentIndex = -1;
    maxCapacity = _maxCapacity;
    values = new int[maxCapacity] {0};
}

Stack::Stack(const Stack& AA) {
    maxCapacity = AA.maxCapacity;
    currentIndex = AA.currentIndex;
    values = new int[maxCapacity] {0};

    for (int i = 0; i <= currentIndex; i++) {
        values[i] = AA.values[i];
    }
}

bool Stack::isEmpty() {
    return (currentIndex < 0);
}

bool Stack::isFull() {
    return (currentIndex == maxCapacity - 1);
}

Stack::~Stack() {
    delete[] values;
}