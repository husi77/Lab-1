// changed to use FirstOnlyLinkedList instead of array
// reason: task asks to implement stack using linked list with only first pointer

#include "Stack.h"
#include "FirstOnlyLinkedList.h"
#include "myFirstOnlyLinkedList.h"

class MyStack : public Stack
{
public:
    MyStack(int _capacity = 0) : Stack(_capacity) {}

    void push(int v) override
    {
        if (!isFull())
        {
            list.insertAtFirst(v);
            currentIndex++;
        }
        else
            cout << "Stack is full\n";
    }

    bool pop(int& v) override
    {
        if (!isEmpty())
        {
            v = list.removeFromFirst();
            currentIndex--;
            return true;
        }
        return false;
    }

private:
    myFirstOnlyLinkedList list;
};
