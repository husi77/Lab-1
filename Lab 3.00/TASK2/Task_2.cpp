#include <iostream>
using namespace std;
#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"


const int MAX_SIZE = 10;

/*
-----------------------------------------
1. Understanding of the Task
-----------------------------------------


The main goal is to  the Queue using enqueue (insert) and dequeue (remove) operations.

The functions I need to implement are:
- insert a value at a specific position
- insert one queue into another queue at a position
- shift elements left and right
- reuse functions like display, append, getSize

Also, I must make sure that the Queue remains correct after each operation and elements are not lost.



Each function explained 

Since Queue works in FIFO (First In First Out), I cannot directly access elements like arrays.
So I will use dequeue and enqueue repeatedly to reach needed positions.


INSERT at position:

If I want to insert X at position 1:

Step 1: Remove A → enqueue back → (B → C → D → A →)
Step 2: At position 1, insert X
Step 3: Continue normal flow

Final Queue:
(A → X → B → C → D →)



shiftLeft(1):
Remove A and insert at end
C → D →)

shiftRight(1):
Move last element to front




I reused the following functions:

1. getSize()
- Used to count number of elements in queue
- Needed for looping and position 

Example:
(A → B → C →) → size = 3

2. display()
- Used to print values without changing queue

3. append()
- Used to copy elements from one queue to another

example;

Queue A:
(A → B → C →)

After insert(A, X, 1):
(A → X → B → C →)

After shiftLeft(1):
(X → B → C → A →)

After shiftRight(1):
(A → X → B → C →)



From this task, I learned:

How to work with Queue without using arrayS AND random access using dequeue and enqueue
How to manipulate positions in a Queue



*/

int getSize(Queue* q)  //reused
{
    int count = 0;
    int size = 0;

    while (!q->isEmpty())
    {
        int val = q->dequeue();
        count++;
        q->enqueue(val);
    }

    size = count;
    return size;
}

void display(Queue* q, ostream& out) //reused
{
    int size = getSize(q);

    for (int i = 0; i < size; i++)
    {
        int val = q->dequeue();
        out << val << " ";
        q->enqueue(val);
    }
    out << endl;
}

void append(Queue* src, Queue* dst)//reused
{
    int size = getSize(src);

    for (int i = 0; i < size; i++)
    {
        int val = src->dequeue();
        if (!dst->isFull())
            dst->enqueue(val);
        src->enqueue(val);
    }
}

void append(Queue* src, Queue* dst, int no)
{
    int size = getSize(src);

    for (int i = 0; i < size && i < no; i++)
    {
        int val = src->dequeue();
        if (!dst->isFull())
            dst->enqueue(val);
        src->enqueue(val);
    }
}


// insert value at position
void insert(Queue* q, int v, int pos)
{
    int size = getSize(q);

    for (int i = 0; i < size; i++)
    {
        int val = q->dequeue();

        if (i == pos && !q->isFull())
            q->enqueue(v);

        q->enqueue(val);
    }

    // if pos == end
    if (pos >= size && !q->isFull())
        q->enqueue(v);
}

// insert src into dst at position
void insert(Queue* src, Queue* dst, int pos)
{
    int sizeDst = getSize(dst);
    int sizeSrc = getSize(src);

    for (int i = 0; i < sizeDst; i++)
    {
        int val = dst->dequeue();

        if (i == pos)
        {
            // insert src here
            for (int j = 0; j < sizeSrc; j++)
            {
                int v = src->dequeue();
                if (!dst->isFull())
                    dst->enqueue(v);
                src->enqueue(v);
            }
        }

        dst->enqueue(val);
    }

    // if pos at end
    if (pos >= sizeDst)
    {
        for (int j = 0; j < sizeSrc; j++)
        {
            int v = src->dequeue();
            if (!dst->isFull())
                dst->enqueue(v);
            src->enqueue(v);
        }
    }
}

// shift right from position
void shiftRight(Queue* q, int pos)
{
    int size = getSize(q);

    for (int k = 0; k < pos; k++)
    {
        int last;

        // get last element
        for (int i = 0; i < size - 1; i++)
        {
            int val = q->dequeue();
            q->enqueue(val);
        }

        last = q->dequeue();

        // put at front
        q->enqueue(last);
    }
}

// shift left from position
void shiftLeft(Queue* q, int pos)
{
    int size = getSize(q);

    for (int k = 0; k < pos; k++)
    {
        int first = q->dequeue();
        q->enqueue(first);
    }
}

// check equality
bool isEqual(Queue* q1, Queue* q2)
{
    int size1 = getSize(q1);
    int size2 = getSize(q2);

    if (size1 != size2)
        return false;

    for (int i = 0; i < size1; i++)
    {
        int v1 = q1->dequeue();
        int v2 = q2->dequeue();

        if (v1 != v2)
        {
            q1->enqueue(v1);
            q2->enqueue(v2);
            return false;
        }

        q1->enqueue(v1);
        q2->enqueue(v2);
    }

    return true;
}

int main()
{
	Queue* A = new MyQueue(MAX_SIZE);
	A->enqueue(10);
	A->enqueue(9);
	A->enqueue(2);
	A->enqueue(5);
	A->enqueue(-7);
	cout << " Queue A Values: ";
	display(A, cout);
	Queue* B = new MyQueue(MAX_SIZE);
	insert(B, -100, 2);
	cout << " Queue B Values after insert: ";
	display(B, cout);
	insert(A, B, 2);
	cout << " Queue B Values after insert: ";
	display(B, cout);
	shiftRight(B, 2);
	cout << " Queue B Values after shiftRight from pos 2";
	display(B, cout);
	shiftLeft(B, 2);
	cout << " Queue B Values after shiftLeft from pos 2: ";
	display(B, cout);

	return 0;
}