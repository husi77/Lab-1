#pragma once

class AbstractArray {
public:
    AbstractArray(int _maxCapacity = 0);
    AbstractArray(const AbstractArray& AA);

    virtual void add(int v) = 0;
    virtual bool remove(int& value) = 0;
    virtual bool get(int index, int& value) = 0;
    virtual void insert(int index, int value) = 0;

    bool isEmpty();
    bool isFull();

    virtual ~AbstractArray();

protected:
    int currentIndex;
    int* values;
    int maxCapacity;
};

AbstractArray::AbstractArray(int _maxCapacity) {
    currentIndex = -1;
    maxCapacity = _maxCapacity;
    values = new int[maxCapacity] {0};
}

AbstractArray::AbstractArray(const AbstractArray& AA) {
    maxCapacity = AA.maxCapacity;
    currentIndex = AA.currentIndex;
    values = new int[maxCapacity] {0};

    for (int i = 0; i <= currentIndex; i++) {
        values[i] = AA.values[i];
    }
}

bool AbstractArray::isEmpty() {
    return (currentIndex < 0);
}

bool AbstractArray::isFull() {
    return (currentIndex == maxCapacity - 1);
}

AbstractArray::~AbstractArray() {
    delete[] values;
}