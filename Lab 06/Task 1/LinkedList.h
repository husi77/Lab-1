// FIXED: the original destructor was deleting first and last separately
// which causes double delete when list has one node (first == last)
// and memory leak for middle nodes
// now it walks through the chain and deletes each node properly

class LinkedList
{
protected:
    Node* first;
    Node* last;
public:
    LinkedList() { first = nullptr; last = nullptr; }
    LinkedList(const LinkedList& other);
    virtual ~LinkedList();
    virtual void insertAtLast(int) = 0;
    virtual void insertAtFirst(int) = 0;
    virtual int removeFromFirst() = 0;
    virtual int removeFromLast() = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
};

// FIXED: added proper copy constructor
// original had no copy constructor so compiler made a shallow copy
// that means two lists would share same nodes -> crash on delete
LinkedList::LinkedList(const LinkedList& other)
{
    first = nullptr;
    last = nullptr;
    // actual deep copy will be done in child class
    // because insertAtLast is virtual and we cant call it here
}

// FIXED: old destructor was:
// delete first; delete last;
// problem 1: if only one node, first == last, deletes same memory twice
// problem 2: middle nodes never get deleted (memory leak)
// new destructor walks through chain and deletes every node
LinkedList::~LinkedList()
{
    Node* temp;
    while (first != nullptr)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    last = nullptr;
}
