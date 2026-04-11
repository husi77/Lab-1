// changed to use FirstOnlyLinkedList instead of array
// reason: task requires linked list with only first pointer
// enqueue adds at end, dequeue removes from front (FIFO)

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
    mutable myFirstOnlyLinkedList list;
};
