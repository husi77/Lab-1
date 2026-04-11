// changed MyQueue to use myLinkedList instead of array
// reason: task requires linked list storage
// enqueue adds at end of list, dequeue removes from front (FIFO)
// mutable used because Queue display is const but list methods are not

#include "Queue.h"

class MyQueue : public Queue
{
public:
    MyQueue(int s) : Queue(s) {}

    void enqueue(const int& value) override
    {
        if (!isFull())
        {
            list.insertAtLast(value);
            count++;
        }
        else
            cout << "Queue is full\n";
    }

    int dequeue() override
    {
        if (!isEmpty())
        {
            int val = list.removeFromFirst();
            count--;
            return val;
        }
        cout << "Queue is empty\n";
        return -1;
    }

    void display(ostream& out) const override
    {
        list.display();
    }

private:
    mutable myLinkedList list;
};
