#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"
/*

The functions include:
- reading values into Queue
- displaying Queue
- appending one Queue into another
- appending limited number of values
- reverse appending
- finding size
- calculating sum and average
- checking if two Queues are equal

The main idea is to use only enqueue and dequeue to manipulate the Queue.


Display Queue

(A → B → C →)

Step 1: dequeue A → print → enqueue A
Step 2: dequeue B → print → enqueue B
Step 3: dequeue C → print → enqueue C

Queue remains same:
(A → B → C →)


Append Queue
Src: (A → B → C →)
Dst: ( )

Step:
Take each element from Src → insert into Dst → restore Src

Result:
Dst: (A → B → C →)


Append Limited Values
Only take first N values from source

Example:
Src: (A → B → C →)
append 2 values

Result:
Dst: (A → B →)


Reverse Append (Using Stack)
Queue cannot reverse directly because it is FIFO.

So I use Stack:
Queue: (A → B → C →)

Push into Stack:
Top: C B A

Pop from Stack and enqueue into destination:
(C → B → A →)


Get Size
Count elements by dequeue and enqueue


Stats (Sum and Average)
Traverse queue:
Add values → calculate average


Check Equality
Compare both queues element by element

Example:
(A → B → C →) == (A → B → C →) → Equal
(A → B → C →) != (A → C → B →) → Not Equal



3. Functions Reused and Explanation


I reused:

1. getSize()
- Used in almost every function to control loops

2. display()
- To print queue safely

3. append()
- To copy values between queues


Flow Example


Queue A:
(A → B → C →)

After append(A, B):
B → (A → B → C →)

After reverseAppend(A, D):
D → (C → B → A →)

After stats:
Sum = A + B + C
Average = Sum / Size



*/
// get size of queue
int getSize(Queue* q)
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

// read values into queue
void read(Queue* q, istream& in)
{
    int x;
    while (!q->isFull())
    {
        cout << "Enter value: ";
        in >> x;
        q->enqueue(x);
    }
}

// display queue WITHOUT destroying it
void display(Queue* q, ostream& out)
{
    int size = getSize(q);

    for (int i = 0; i < size; i++)
    {
        int val = q->dequeue();
        out << val << " ";
        q->enqueue(val); // put back
    }
    out << endl;
}

// append src into dst
void append(Queue* src, Queue* dst)
{
    int size = getSize(src);

    for (int i = 0; i < size; i++)
    {
        int val = src->dequeue();
        if (!dst->isFull())
            dst->enqueue(val);

        src->enqueue(val); // restore src
    }
}

// append limited values
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

// reverse append (uses stack because queue can't reverse alone easily)
void reverseAppend(Queue* src, Queue* dst)
{
    MyStack st(29); // temporary stack

    int size = getSize(src);

    // push all elements into stack
    for (int i = 0; i < size; i++)
    {
        int val = src->dequeue();
        st.push(val);
        src->enqueue(val);
    }

    // pop from stack (reverse order)
    int val;
    while (st.pop(val))
    {
        if (!dst->isFull())
            dst->enqueue(val);
    }
}



// stats (sum + average)
void stats(Queue* q, int& sum, float& avg)
{
    int size = getSize(q);
    sum = 0;

    for (int i = 0; i < size; i++)
    {
        int val = q->dequeue();
        sum += val;
        q->enqueue(val);
    }

    avg = (float)sum / size;
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

const int MAX_SIZE = 5;
int main()
{
    Queue* A = new MyQueue (MAX_SIZE);
    int n = 0;
    read(A, cin);
    cout << " Queue A Values: ";
    display(A, cout);
    Queue* B = new MyQueue(MAX_SIZE);
    append(A, B);
    cout << " Queue B Values: ";
    display(B, cout);
    Queue* C = new MyQueue(MAX_SIZE);
    C->enqueue(9);
    C->enqueue(7);
    C->enqueue(5);
    append(A, C, 2);
    cout << "Queue C Values after append of 2 values from A: ";
    display(C, cout);
    Queue* D = new MyQueue(MAX_SIZE);
    reverseAppend(C, D);
    cout << "Queue D Values after reverse append from V: ";
    display(D, cout);
    int mx = 0;
    float ag = 0.0;
    stats(A, mx, ag);
    cout << "Queue A Values: ";
    display(A, cout);
    cout << "Average is " << ag << " maximum is " << mx << endl;
    Queue* M = new MyQueue(MAX_SIZE);
    Queue* N = new MyQueue(MAX_SIZE);
    Queue* P = new MyQueue(MAX_SIZE);
    append(A, M);
    append(N, M);
    append(N, P);
    P->enqueue(111);
    if (!isEqual(A, M))
    {
        cout << "Not Equal:\n";
    }
    else
    {
        cout << "Equal:\n";
    }
    if (!isEqual(A, P))
    {
        cout << "Not Equal:\n";
    }
    else
    {
        cout << "Equal:\n";
    }
    return 0;
}

