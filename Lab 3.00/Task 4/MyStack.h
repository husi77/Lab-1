#include "Stack.h"

class MyStack : public Stack
{
public:
    MyStack(int _capacity = 0) : Stack(_capacity) {}
    MyStack(const MyStack& ma) : Stack(ma) {}

    void push(int v) override;
    bool pop(int& v) override;
};

void MyStack::push(int v)
{
    if (!isFull()) {
        values[++currentIndex] = v;
        return;
    }
    cout << "Stack is full\n";
}

bool MyStack::pop(int& v)
{
    if (!isEmpty()) 
    {
        v = values[currentIndex--];
        return true;
    }
    return false;
}

