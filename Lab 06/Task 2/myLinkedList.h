class myLinkedList : public LinkedList
{
public:
    myLinkedList() : LinkedList() {}
    myLinkedList(const myLinkedList& other) : LinkedList(other)
    {
        Node* t = other.first;
        while (t != nullptr)
        {
            insertAtLast(t->data);
            t = t->next;
        }
    }

    void insertAtLast(int value);
    void insertAtFirst(int value);
    void display();
    int removeFromFirst();
    int removeFromLast();
    bool isEmpty();
    int getSize();
    bool search(int v);
    int peek(int pos);
    int get(int pos);
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

int myLinkedList::getSize()
{
    int count = 0;
    Node* t = first;
    while (t != nullptr)
    {
        count++;
        t = t->next;
    }
    return count;
}

bool myLinkedList::search(int v)
{
    Node* t = first;
    while (t != nullptr)
    {
        if (t->data == v)
            return true;
        t = t->next;
    }
    return false;
}

int myLinkedList::peek(int pos)
{
    if (isEmpty() || pos < 0)
        return -99999;

    Node* t = first;
    for (int i = 0; i < pos && t != nullptr; i++)
        t = t->next;

    if (t == nullptr)
        return -99999;

    return t->data;
}

int myLinkedList::get(int pos)
{
    if (isEmpty() || pos < 0)
        return -99999;

    int size = getSize();
    if (pos >= size)
        return -99999;

    if (pos == 0)
        return removeFromFirst();

    if (pos == size - 1)
        return removeFromLast();

    Node* t = first;
    for (int i = 0; i < pos - 1; i++)
        t = t->next;

    Node* toRemove = t->next;
    int val = toRemove->data;
    t->next = toRemove->next;
    delete toRemove;
    return val;
}
