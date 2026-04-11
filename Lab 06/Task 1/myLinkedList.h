// FIXED: added proper copy constructor that does deep copy
// also added destructor comment explaining why base class handles it

class myLinkedList : public LinkedList
{
public:
    myLinkedList() : LinkedList() {}

    // FIXED: deep copy constructor
    // walks through original list and inserts each value into new list
    myLinkedList(const myLinkedList& other) : LinkedList(other)
    {
        Node* t = other.first;
        while (t != nullptr)
        {
            insertAtLast(t->data);
            t = t->next;
        }
    }

    // destructor handled by base class LinkedList which walks and deletes chain

    void insertAtLast(int value);
    void insertAtFirst(int value);
    void display();
    int removeFromFirst();
    int removeFromLast();
    bool isEmpty();
};

bool myLinkedList::isEmpty()
{
    return first == nullptr && last == nullptr;
}

int myLinkedList::removeFromLast()
{
    if (first == nullptr && last == nullptr)
    {
        cout << "LL is empty" << endl;
        return -99999;
    }
    else if (first == last)
    {
        int val = first->data;
        delete last;
        first = nullptr;
        last = nullptr;
        return val;
    }
    else
    {
        Node* t = first;
        while (t->next != last)
            t = t->next;
        int val = last->data;
        delete last;
        t->next = nullptr;
        last = t;
        return val;
    }
}

int myLinkedList::removeFromFirst()
{
    if (first == nullptr && last == nullptr)
    {
        cout << "LL is empty" << endl;
        return -99999;
    }
    else if (first == last)
    {
        int val = first->data;
        delete first;
        first = nullptr;
        last = nullptr;
        return val;
    }
    else
    {
        int val = first->data;
        Node* t = first;
        first = first->next;
        delete t;
        return val;
    }
}

void myLinkedList::display()
{
    if (first == nullptr && last == nullptr)
    {
        cout << "->" << endl;
        return;
    }
    Node* t = first;
    while (t != nullptr)
    {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << endl;
}

void myLinkedList::insertAtFirst(int value)
{
    Node* nn = new Node;
    nn->data = value;
    nn->next = nullptr;
    if (first == nullptr && last == nullptr)
    {
        first = nn;
        last = nn;
    }
    else
    {
        nn->next = first;
        first = nn;
    }
}

void myLinkedList::insertAtLast(int value)
{
    Node* nn = new Node;
    nn->data = value;
    nn->next = nullptr;
    if (first == nullptr && last == nullptr)
    {
        first = nn;
        last = nn;
    }
    else
    {
        last->next = nn;
        last = nn;
    }
}
