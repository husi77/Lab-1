#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"


// add new order into queue
void addOrder(Queue* q, int orderId)
{
    if (!q->isFull())
    {
        q->enqueue(orderId);
        cout << "Order " << orderId << " added\n";
    }
    else
    {
        cout << "Queue full, cannot add order\n";
    }
}


// process next order (FIFO)
void processOrder(Queue* q)
{
    if (!q->isEmpty())
    {
        int id = q->dequeue();
        cout << "Processing Order: " << id << endl;
    }
    else
    {
        cout << "No orders to process\n";
    }
}


// display all pending orders
void showOrders(Queue* q)
{
    int size = 0;

    // count size manually (queue only)
    Queue temp(*q);
    while (!temp.isEmpty())
    {
        temp.dequeue();
        size++;
    }

    // print without losing data
    for (int i = 0; i < size; i++)
    {
        int val = q->dequeue();
        cout << val << " ";
        q->enqueue(val);
    }

    cout << endl;
}


// find total orders
int totalOrders(Queue* q)
{
    int count = 0;
    Queue temp(*q);

    while (!temp.isEmpty())
    {
        temp.dequeue();
        count++;
    }

    return count;
}


int main()
{
    const int MAX_SIZE = 10;

    Queue* orders = new MyQueue(MAX_SIZE);

    // adding orders
    addOrder(orders, 101);
    addOrder(orders, 102);
    addOrder(orders, 103);
    addOrder(orders, 104);

    cout << "\nCurrent Orders: ";
    showOrders(orders);

    // process some orders
    processOrder(orders);
    processOrder(orders);

    cout << "\nOrders after processing: ";
    showOrders(orders);

    cout << "Total pending orders: " << totalOrders(orders) << endl;

    // add more orders
    addOrder(orders, 105);
    addOrder(orders, 106);

    cout << "\nFinal Orders: ";
    showOrders(orders);

    return 0;
}