#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"


// this function calculates how many elements are in the queue
// only queue operations are used (no arrays or other structures)
int getSize(Queue* q)
{
    int size = 0;
    int temp;

    // we remove each element one by one and count it
    // then we insert it back so queue does not lose data
    while (!q->isEmpty())
    {
        temp = q->dequeue();      // take element from front
        size++;                   // increase count
        q->enqueue(temp);         // put it back
    }

    // after above loop, queue order gets rotated
    // so we rotate again to bring it back to original state
    for (int i = 0; i < size; i++)
    {
        q->enqueue(q->dequeue());
    }

    return size;                  // total number of elements
}


// this function reverses only the first k elements of the queue
void reverseFirstKElements(Queue* q, int k)
{
    int size = getSize(q);        // get total elements

    // stack is used because queue cannot reverse order by itself
    // queue works FIFO but reversing needs LIFO behaviour
    MyStack s(k);

    // take first k elements and push them into stack
    // this automatically reverses their order
    for (int i = 0; i < k; i++)
    {
        s.push(q->dequeue());
    }

    // now pop from stack and insert back into queue
    // this gives reversed order for first k elements
    int value;
    for (int i = 0; i < k; i++)
    {
        s.pop(value);
        q->enqueue(value);
    }

    // remaining elements should stay in same order
    // so we rotate them to the back
    for (int i = 0; i < size - k; i++)
    {
        q->enqueue(q->dequeue());
    }
}


// simple function to print queue without changing it
void displayQueue(Queue* q)
{
    int size = getSize(q);

    // remove each element, print it, then add it back
    for (int i = 0; i < size; i++)
    {
        int val = q->dequeue();
        cout << val << " ";
        q->enqueue(val);
    }

    cout << endl;
}



int main()
{
    const int MAX_SIZE = 10;

    Queue* q1 = new MyQueue(MAX_SIZE);    // first queue

    // inserting some values
    q1->enqueue(10);
    q1->enqueue(20);
    q1->enqueue(30);
    q1->enqueue(40);
    q1->enqueue(50);

    cout << "Original Queue: ";
    displayQueue(q1);

    reverseFirstKElements(q1, 3);   // reverse first 3 values only

    cout << "After reversing first 3 elements: ";
    displayQueue(q1);



    Queue* q2 = new MyQueue(MAX_SIZE);    // second example

    q2->enqueue(99);
    q2->enqueue(-3);
    q2->enqueue(0);
    q2->enqueue(15);

    cout << "\nOriginal Queue: ";
    displayQueue(q2);

    reverseFirstKElements(q2, 4);   // reverse all elements here

    cout << "After reversing first 4 elements: ";
    displayQueue(q2);
    // this approach ensures queue data is not lost and original structure is safe

    return 0;
}