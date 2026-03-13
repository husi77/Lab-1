#pragma once

template <typename T>
class Stack {
public:
    Stack(int _maxCapacity = 0);
    Stack(const Stack<T>& AA);

    virtual void push(T v) = 0;
    virtual bool pop(T& value) = 0;

    bool isEmpty();
    bool isFull();

    virtual ~Stack();

protected:
    int currentIndex;
    T* values;
    int maxCapacity;
};

template <typename T>
Stack<T>::Stack(int _maxCapacity) {
    currentIndex = -1;
    maxCapacity = _maxCapacity;
    values = new T[maxCapacity];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& AA) {
    maxCapacity = AA.maxCapacity;
    currentIndex = AA.currentIndex;
    values = new T[maxCapacity];

    for (int i = 0; i <= currentIndex; i++) {
        values[i] = AA.values[i];
    }
}

template <typename T>
bool Stack<T>::isEmpty() {
    return (currentIndex < 0);
}

template <typename T>
bool Stack<T>::isFull() {
    return (currentIndex == maxCapacity - 1);
}

template <typename T>
Stack<T>::~Stack() {
    delete[] values;
}