class SortedFirstOnlyLinkedList : public FirstOnlyLinkedList
{
public:
    void display();
    int removeFromFirst();
    int removeFromLast();
    void insertSorted(int);
    bool deleteValue(int);
    bool search(int);
    bool isEmpty();
protected:
    bool ascending;
private:
    void insertAtLast(int value);
    void insertAtFirst(int value);
};

bool SortedFirstOnlyLinkedList::isEmpty()
{
    return first == nullptr;
}

void SortedFirstOnlyLinkedList::display()
{
    if (first == nullptr)
    {
        cout << "LL is empty" << endl;
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

void SortedFirstOnlyLinkedList::insertAtFirst(int value)
{
    Node* nn = new Node;
    nn->data = value;
    nn->next = nullptr;
    if (first == nullptr)
        first = nn;
    else
    {
        nn->next = first;
        first = nn;
    }
}

void SortedFirstOnlyLinkedList::insertAtLast(int value)
{
    Node* nn = new Node;
    nn->data = value;
    nn->next = nullptr;
    if (first == nullptr)
        first = nn;
    else
    {
        Node* t = first;
        while (t->next != nullptr)
            t = t->next;
        t->next = nn;
    }
}

int SortedFirstOnlyLinkedList::removeFromFirst()
{
    if (first == nullptr)
    {
        cout << "List is Empty\n";
        return -9999;
    }
    int val = first->data;
    Node* t = first;
    first = first->next;
    delete t;
    return val;
}

int SortedFirstOnlyLinkedList::removeFromLast()
{
    if (first == nullptr)
    {
        cout << "Empty List\n";
        return -9999;
    }
    if (first->next == nullptr)
    {
        int val = first->data;
        delete first;
        first = nullptr;
        return val;
    }
    Node* t = first;
    while (t->next->next != nullptr)
        t = t->next;
    int val = t->next->data;
    delete t->next;
    t->next = nullptr;
    return val;
}

void SortedFirstOnlyLinkedList::insertSorted(int value)
{
    if (first == nullptr)
    {
        insertAtFirst(value);
        return;
    }

    // default ascending order
    if (value <= first->data)
    {
        insertAtFirst(value);
        return;
    }

    Node* t = first;
    while (t->next != nullptr)
    {
        if (t->next->data >= value)
        {
            Node* nn = new Node;
            nn->data = value;
            nn->next = t->next;
            t->next = nn;
            return;
        }
        t = t->next;
    }

    insertAtLast(value);
}

bool SortedFirstOnlyLinkedList::deleteValue(int value)
{
    if (first == nullptr)
        return false;

    if (first->data == value)
    {
        removeFromFirst();
        return true;
    }

    Node* t = first;
    while (t->next != nullptr)
    {
        if (t->next->data == value)
        {
            Node* toDelete = t->next;
            t->next = toDelete->next;
            delete toDelete;
            return true;
        }
        t = t->next;
    }

    return false;
}

bool SortedFirstOnlyLinkedList::search(int value)
{
    Node* t = first;
    while (t != nullptr)
    {
        if (t->data == value)
            return true;
        t = t->next;
    }
    return false;
}
