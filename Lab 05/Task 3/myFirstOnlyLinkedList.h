class myFirstOnlyLinkedList : public FirstOnlyLinkedList
{
public:
    myFirstOnlyLinkedList() : FirstOnlyLinkedList() {}
    ~myFirstOnlyLinkedList() {}
    void insertAtFirst(int);
    void insertAtLast(int);
    void display();
    int removeFromFirst();
    int removeFromLast();
};

int myFirstOnlyLinkedList::removeFromLast()
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
    {
        t = t->next;
    }
    int val = t->next->data;
    delete t->next;
    t->next = nullptr;
    return val;
}

int myFirstOnlyLinkedList::removeFromFirst()
{
    if (first == nullptr)
    {
        cout << "List is Empty\n";
        return -9999;
    }
    if (first->next == nullptr)
    {
        int val = first->data;
        delete first;
        first = nullptr;
        return val;
    }
    int val = first->data;
    Node* t = first;
    first = first->next;
    delete t;
    return val;
}

void myFirstOnlyLinkedList::display()
{
    if (first == nullptr)
    {
        cout << "LL is empty" << endl;
        return;
    }
    Node* temp = first;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void myFirstOnlyLinkedList::insertAtFirst(int value)
{
    Node* nn = new Node;
    nn->next = nullptr;
    nn->data = value;
    if (first == nullptr)
        first = nn;
    else
    {
        nn->next = first;
        first = nn;
    }
}

void myFirstOnlyLinkedList::insertAtLast(int value)
{
    Node* nn = new Node;
    nn->next = nullptr;
    nn->data = value;
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
