class Queue
{
public:
    Queue(int cap);
    Queue(const Queue& q);
    virtual ~Queue() {}
    bool isEmpty() const;
    bool isFull() const;
    virtual void enqueue(const int& value) = 0;
    virtual int dequeue() = 0;
    virtual void display(ostream&) const = 0;
protected:
    int startOfQIndex;
    int topOfQIndex;
    int maxCapacity;
    int count;
};

bool Queue::isEmpty() const 
{
    return (count == 0);
}

bool Queue::isFull() const 
{
    return (count == maxCapacity);
}
