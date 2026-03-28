#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"


int sizeOfQueue(Queue* q)
{
    Queue copy(*q);   // make a copy so original is safe
    int count = 0;

    while (!copy.isEmpty())
    {
        copy.dequeue();
        count++;
    }

    return count;
}


void displayQueue(Queue* q, ostream& out)
{
    int size = sizeOfQueue(q);

    for (int i = 0; i < size; i++)
    {
        int x = q->dequeue();
        out << x << " ";
        q->enqueue(x);   // put back
    }

    out << endl;
}


void appendQueue(Queue* src, Queue* dst)
{
    int size = sizeOfQueue(src);

    for (int i = 0; i < size; i++)
    {
        int x = src->dequeue();

        if (!dst->isFull())
            dst->enqueue(x);

        src->enqueue(x);
    }
}


void appendQueue(Queue* src, Queue* dst, int n)
{
    int size = sizeOfQueue(src);

    for (int i = 0; i < size; i++)
    {
        int x = src->dequeue();

        if (i < n && !dst->isFull())
            dst->enqueue(x);

        src->enqueue(x);
    }
}


void reverseAppend(Queue* src, Queue* dst)
{
    // queue cannot reverse order easily so stack is used
    int size = sizeOfQueue(src);
    MyStack s(size);

    for (int i = 0; i < size; i++)
    {
        int x = src->dequeue();
        s.push(x);
        src->enqueue(x);
    }

    int val;
    while (!s.isEmpty() && !dst->isFull())
    {
        s.pop(val);
        dst->enqueue(val);
    }
}


void insertValue(Queue* q, int value, int pos)
{
    int size = sizeOfQueue(q);
    MyQueue temp(size + 1);

    for (int i = 0; i < size; i++)
    {
        if (i == pos)
            temp.enqueue(value);

        temp.enqueue(q->dequeue());
    }

    if (pos >= size)
        temp.enqueue(value);

    int newSize = sizeOfQueue(&temp);

    for (int i = 0; i < newSize; i++)
        q->enqueue(temp.dequeue());
}


void insertQueue(Queue* src, Queue* dst, int pos)
{
    int size = sizeOfQueue(src);

    for (int i = 0; i < size; i++)
    {
        int x = src->dequeue();
        dst->enqueue(x);   // same flow
        src->enqueue(x);
    }
}


void shiftRight(Queue* q, int pos)
{
    int size = sizeOfQueue(q);
    MyQueue temp(size + 1);

    for (int i = 0; i < size; i++)
    {
        int x = q->dequeue();

        if (i == pos)
            temp.enqueue(0);   // create space

        temp.enqueue(x);
    }

    int newSize = sizeOfQueue(&temp);

    for (int i = 0; i < newSize; i++)
        q->enqueue(temp.dequeue());
}


void shiftLeft(Queue* q, int pos)
{
    int size = sizeOfQueue(q);
    MyQueue temp(size);

    for (int i = 0; i < size; i++)
    {
        int x = q->dequeue();

        if (i != pos)
            temp.enqueue(x);
    }

    int newSize = sizeOfQueue(&temp);

    for (int i = 0; i < newSize; i++)
        q->enqueue(temp.dequeue());
}


bool isSame(Queue* q1, Queue* q2)
{
    int s1 = sizeOfQueue(q1);
    int s2 = sizeOfQueue(q2);

    if (s1 != s2)
        return false;

    bool same = true;

    for (int i = 0; i < s1; i++)
    {
        int a = q1->dequeue();
        int b = q2->dequeue();

        if (a != b)
            same = false;

        q1->enqueue(a);
        q2->enqueue(b);
    }

    return same;
}


int getValue(Queue* q, int pos)
{
    int size = sizeOfQueue(q);
    int ans = -1;

    for (int i = 0; i < size; i++)
    {
        int x = q->dequeue();

        if (i == pos)
            ans = x;
        else
            q->enqueue(x);
    }

    return ans;
}


void sortQueue(Queue* q)
{
    int size = sizeOfQueue(q);

    for (int i = 0; i < size; i++)
    {
        int minVal = q->dequeue();

        for (int j = 1; j < size - i; j++)
        {
            int x = q->dequeue();

            if (x < minVal)
            {
                q->enqueue(minVal);
                minVal = x;
            }
            else
                q->enqueue(x);
        }

        q->enqueue(minVal);
    }
}


bool isPalindrome(Queue* q)
{
    // using stack because queue cannot compare reverse directly
    int size = sizeOfQueue(q);
    MyStack s(size);

    for (int i = 0; i < size; i++)
    {
        int x = q->dequeue();
        s.push(x);
        q->enqueue(x);
    }

    bool ok = true;
    int y;

    for (int i = 0; i < size; i++)
    {
        int x = q->dequeue();
        s.pop(y);

        if (x != y)
            ok = false;

        q->enqueue(x);
    }

    return ok;
}


void isPalindrome(Queue* q, bool& res)
{
    // no extra structure allowed so rotate and compare
    int size = sizeOfQueue(q);
    res = true;

    for (int i = 0; i < size / 2; i++)
    {
        int first = q->dequeue();

        for (int j = 0; j < size - 2 * i - 2; j++)
            q->enqueue(q->dequeue());

        int last = q->dequeue();

        if (first != last)
            res = false;

        q->enqueue(first);
        q->enqueue(last);
    }
}


void rotateLeft(Queue* q, int k)
{
    for (int i = 0; i < k; i++)
        q->enqueue(q->dequeue());
}


void rotateRight(Queue* q, int k)
{
    int size = sizeOfQueue(q);

    for (int i = 0; i < size - k; i++)
        q->enqueue(q->dequeue());
}