#include <iostream>
using namespace std;

#include "Node.h"
#include "Stack.h"
#include "MyStack.h"
#include "MyQueue.h"

/*

1. What I understand about this task:

This is similar to Task 2 but instead of using myLinkedList (which has both
first and last pointers), here I use FirstOnlyLinkedList which only has a
first pointer. So all operations have to work by traversing from the first
node only. The goal is same: make Stack and Queue use linked list storage.


2. How I will solve it:

Same idea as Task 2:
Stack uses insertAtFirst for push and removeFromFirst for pop.
Queue uses insertAtLast for enqueue and removeFromFirst for dequeue.

The difference is insertAtLast is slower here because we have to walk
all the way to the end since there is no last pointer.

Stack push(10): (10 ->)
Stack push(20): (20 -> 10 ->)
Stack pop(): removes 20, returns 20, list: (10 ->)

Queue enqueue(10): (10 ->)
Queue enqueue(20): (10 -> 20 ->)
Queue dequeue(): removes 10, returns 10, list: (20 ->)


3. Reused functions:

insertAtFirst, insertAtLast, removeFromFirst from myFirstOnlyLinkedList.
display from myFirstOnlyLinkedList to show the contents.


4. What I learned:

Even without a last pointer, linked list operations still work.
insertAtLast becomes O(n) instead of O(1) because we have to walk to end.


5. Skills developed:

I understand the tradeoff between having one pointer vs two pointers
in a linked list. Less memory but slower for some operations.

*/

int main()
{
    cout << "--- Testing Stack with FirstOnlyLinkedList ---" << endl;

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
    s1.pop(val);
    cout << "Popped: " << val << endl;

    cout << "\n--- Testing Queue with FirstOnlyLinkedList ---" << endl;

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

    cout << "\n--- Full and empty tests ---" << endl;
    Queue* q2 = new MyQueue(2);
    q2->enqueue(1);
    q2->enqueue(2);
    cout << "Full queue: ";
    q2->display(cout);
    q2->enqueue(3);

    delete q1;
    delete q2;

    return 0;
}
