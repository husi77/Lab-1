#include <iostream>
using namespace std;

#include "Node.h"
#include "Stack.h"
#include "MyStack.h"
#include "MyQueue.h"

/*

1. What I understand about this task:

The task wants me to change MyStack and MyQueue so they use myLinkedList
for storing data instead of arrays. The idea is that instead of maintaining
an array inside, we use a linked list. Push and pop become insert and remove
from the linked list. Same for enqueue and dequeue.


2. How I will solve it:

For Stack (LIFO - last in first out):
Push means add to front of linked list.
Pop means remove from front of linked list.

push(10): list becomes (10 ->)
push(20): list becomes (20 -> 10 ->)
push(30): list becomes (30 -> 20 -> 10 ->)
pop(): removes 30, list becomes (20 -> 10 ->)

For Queue (FIFO - first in first out):
Enqueue means add to end of linked list.
Dequeue means remove from front of linked list.

enqueue(10): list becomes (10 ->)
enqueue(20): list becomes (10 -> 20 ->)
enqueue(30): list becomes (10 -> 20 -> 30 ->)
dequeue(): removes 10, list becomes (20 -> 30 ->)


3. Reused functions:

insertAtFirst and removeFromFirst from myLinkedList are used for Stack.
insertAtLast and removeFromFirst from myLinkedList are used for Queue.
display from myLinkedList is used to show contents.


4. What I learned:

Arrays and linked lists can both be used to implement stack and queue.
The outside behavior stays the same, only the internal storage changes.


5. Skills developed:

I can now swap internal storage of a data structure without changing
how it is used from outside. This is useful when we need dynamic size.

*/

int main()
{
    cout << "--- Testing Stack with LinkedList ---" << endl;

    MyStack s1(10);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    cout << "Pushed 10, 20, 30, 40" << endl;

    int val;
    s1.pop(val);
    cout << "Popped: " << val << endl;
    s1.pop(val);
    cout << "Popped: " << val << endl;

    s1.push(99);
    cout << "Pushed 99" << endl;
    s1.pop(val);
    cout << "Popped: " << val << endl;

    cout << "\n--- Testing Queue with LinkedList ---" << endl;

    Queue* q1 = new MyQueue(10);
    q1->enqueue(100);
    q1->enqueue(200);
    q1->enqueue(300);
    q1->enqueue(400);

    cout << "Enqueued 100, 200, 300, 400" << endl;
    cout << "Queue: ";
    q1->display(cout);

    cout << "Dequeued: " << q1->dequeue() << endl;
    cout << "Dequeued: " << q1->dequeue() << endl;
    cout << "Queue after 2 dequeues: ";
    q1->display(cout);

    q1->enqueue(500);
    cout << "After enqueue 500: ";
    q1->display(cout);

    cout << "\n--- Testing empty checks ---" << endl;
    MyStack s2(3);
    cout << "Stack empty? " << s2.isEmpty() << endl;
    s2.push(1);
    cout << "After push, stack empty? " << s2.isEmpty() << endl;

    Queue* q2 = new MyQueue(3);
    cout << "Queue empty? " << q2->isEmpty() << endl;
    q2->enqueue(1);
    cout << "After enqueue, queue empty? " << q2->isEmpty() << endl;

    delete q1;
    delete q2;

    return 0;
}
