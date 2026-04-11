class Stack 
{
public:
    Stack(int _maxCapacity = 0);
    Stack(const Stack& s);
    virtual void push(int v) = 0;
    virtual bool pop(int& value) = 0;
    bool isEmpty();
    bool isFull();
protected:
    int currentIndex;
    int* values;
    int maxCapacity;
};

Stack::Stack(int _maxCapacity)
{
    currentIndex = -1;
    maxCapacity = _maxCapacity;
    values = new int[maxCapacity]{0};
}

Stack::Stack(const Stack& s) 
{
    currentIndex = -1;
    maxCapacity = s.maxCapacity;
    values = new int[maxCapacity]{0};
    for (int i = 0; i < maxCapacity; i++)
        values[i] = s.values[i];
}

bool Stack::isEmpty() 
{
    return (currentIndex < 0);
}

bool Stack::isFull()
{
    return (currentIndex == maxCapacity - 1);
}
