// changed MyStack to use myLinkedList instead of array
// reason: the task requires linked list based storage
// base Stack still allocates array but we dont use it here
// push adds at front of list, pop removes from front (LIFO)

#include "Stack.h"
#include "LinkedList.h"
#include "myLinkedList.h"

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
    myLinkedList list;
};
