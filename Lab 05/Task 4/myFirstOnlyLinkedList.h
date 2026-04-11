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
    bool search(int data);
    int getSize();
    int get(int pos);
    void put(int pos, int value);
    void swap(int xi, int yi);
    void sort(bool asc);
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
        t = t->next;
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

bool myFirstOnlyLinkedList::search(int value)
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

int myFirstOnlyLinkedList::getSize()
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

int myFirstOnlyLinkedList::get(int pos)
{
    if (first == nullptr || pos < 0)
        return -9999;

    if (pos == 0)
        return removeFromFirst();

    int size = getSize();
    if (pos >= size)
        return -9999;

    Node* t = first;
    for (int i = 0; i < pos - 1; i++)
        t = t->next;

    Node* toRemove = t->next;
    int val = toRemove->data;
    t->next = toRemove->next;
    delete toRemove;
    return val;
}

void myFirstOnlyLinkedList::put(int pos, int value)
{
    if (pos <= 0)
    {
        insertAtFirst(value);
        return;
    }

    int size = getSize();
    if (pos >= size)
    {
        insertAtLast(value);
        return;
    }

    Node* t = first;
    for (int i = 0; i < pos - 1; i++)
        t = t->next;

    Node* nn = new Node;
    nn->data = value;
    nn->next = t->next;
    t->next = nn;
}

void myFirstOnlyLinkedList::swap(int xi, int yi)
{
    if (xi == yi) return;

    // find nodes at both positions and swap their data
    Node* nodeX = first;
    Node* nodeY = first;

    for (int i = 0; i < xi && nodeX != nullptr; i++)
        nodeX = nodeX->next;

    for (int i = 0; i < yi && nodeY != nullptr; i++)
        nodeY = nodeY->next;

    if (nodeX == nullptr || nodeY == nullptr) return;

    int temp = nodeX->data;
    nodeX->data = nodeY->data;
    nodeY->data = temp;
}

void myFirstOnlyLinkedList::sort(bool asc)
{
    int size = getSize();

    // bubble sort by swapping data values
    for (int i = 0; i < size - 1; i++)
    {
        Node* t = first;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (asc)
            {
                if (t->data > t->next->data)
                {
                    int temp = t->data;
                    t->data = t->next->data;
                    t->next->data = temp;
                }
            }
            else
            {
                if (t->data < t->next->data)
                {
                    int temp = t->data;
                    t->data = t->next->data;
                    t->next->data = temp;
                }
            }
            t = t->next;
        }
    }
}
