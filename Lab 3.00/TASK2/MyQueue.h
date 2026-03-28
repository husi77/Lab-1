#include "Queue.h"

class MyQueue : public Queue
{
public:
    MyQueue(int s) : Queue(s)
    {
        if (s != 0)
        {
            values = new int[maxCapacity] {0};
        }
    }

    MyQueue(const MyQueue& mq) : Queue(mq)
    {
        if (maxCapacity != 0)
        {
            values = new int[maxCapacity] {0};
            for (int i = 0; i < count; i++)
            {
                values[i] = mq.values[i];
            }
        }
    }

    ~MyQueue()
    {
        if (values != nullptr)
        {
            delete[] values;
            values = nullptr;
        }
    }

    void enqueue(const int& value) override
    {
        if (!isFull())
        {
            if (startOfQIndex == -1) startOfQIndex = 0;
            topOfQIndex = (topOfQIndex + 1) % maxCapacity;
            values[topOfQIndex] = value;
            count++;
        }
        else
        {
            cout << "Queue is full\n";
        }
    }

    int dequeue() override
    {
        if (!isEmpty())
        {
            int val = values[startOfQIndex];
            startOfQIndex = (startOfQIndex + 1) % maxCapacity;
            count--;
            if (count == 0)
            {
                startOfQIndex = -1;
                topOfQIndex = -1;
            }
            return val;
        }
        cout << "Queue is empty\n";
        return -1;
    }

    void display(ostream& out) const override
    {
        if (isEmpty())
        {
            out << "Queue is empty\n";
            return;
        }
        int idx = startOfQIndex;
        for (int i = 0; i < count; i++)
        {
            out << values[idx] << " ";
            idx = (idx + 1) % maxCapacity;
        }
        out << endl;
    }

private:
    int* values;
};
