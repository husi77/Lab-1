#include <iostream>
using namespace std;

#include "Node.h"

/*

1. What I understand about this task:

This task wants me to write global functions that work on raw Node pointers.
Not using any LinkedList class here, just nodes connected through next pointers.
The functions are: copy, freeMemory, insert, remove, and display.
So basically I have a chain like (10 -> 20 -> 30) and I work on it directly.


2. How I will solve it:

For copy:
Take each node from original chain and make a new node with same value.
Original: (10 -> 20 -> 30)
Copy:     (10 -> 20 -> 30)   separate memory, same values

For freeMemory:
Go node by node and delete each one.
(10 -> 20 -> 30) becomes empty, all memory freed.

For insert at position:
Chain: (10 -> 20 -> 30)
Insert 99 at pos 1:
Walk to node before pos 1, create new node, link it in.
Result: (10 -> 99 -> 20 -> 30)

For remove at position:
Chain: (10 -> 99 -> 20 -> 30)
Remove at pos 2:
Walk to node before pos 2, save value, relink around it.
Result: (10 -> 99 -> 30), returned value = 20

For display:
Just walk and print each node value.
(10 -> 99 -> 30)


3. Reused functions:
display() is reused after every operation to check if things worked right.


4. What I learned:
Working with raw node pointers teaches how linked lists actually work inside.
Every insert and remove is about relinking pointers carefully.


5. Skills developed:
I can now create, copy, insert into, remove from and free a chain of nodes.
This is the base skill needed for building any linked data structure.

*/

Node* copy(Node* head)
{
    if (head == nullptr)
        return nullptr;

    Node* newHead = new Node;
    newHead->data = head->data;
    newHead->next = nullptr;

    Node* curr = newHead;
    Node* temp = head->next;

    while (temp != nullptr)
    {
        Node* nn = new Node;
        nn->data = temp->data;
        nn->next = nullptr;
        curr->next = nn;
        curr = nn;
        temp = temp->next;
    }

    return newHead;
}

void freeMemory(Node* head)
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void display(Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void insert(Node* head, const int& value, const int& pos)
{
    if (head == nullptr) return;

    if (pos == 0)
    {
        Node* nn = new Node;
        nn->data = head->data;
        nn->next = head->next;
        head->data = value;
        head->next = nn;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

    Node* nn = new Node;
    nn->data = value;
    nn->next = temp->next;
    temp->next = nn;
}

int remove(Node* head, const int& pos)
{
    if (head == nullptr) return -9999;

    if (pos == 0)
    {
        int val = head->data;
        if (head->next != nullptr)
        {
            Node* temp = head->next;
            head->data = temp->data;
            head->next = temp->next;
            delete temp;
        }
        return val;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr) return -9999;

    Node* toDelete = temp->next;
    int val = toDelete->data;
    temp->next = toDelete->next;
    delete toDelete;
    return val;
}

int main()
{
    Node* head = new Node;
    head->data = 10;
    head->next = nullptr;

    Node* n2 = new Node; n2->data = 20; n2->next = nullptr;
    head->next = n2;
    Node* n3 = new Node; n3->data = 30; n3->next = nullptr;
    n2->next = n3;
    Node* n4 = new Node; n4->data = 40; n4->next = nullptr;
    n3->next = n4;
    Node* n5 = new Node; n5->data = 50; n5->next = nullptr;
    n4->next = n5;

    cout << "Original chain: ";
    display(head);

    Node* copied = copy(head);
    cout << "Copied chain: ";
    display(copied);

    insert(head, 99, 2);
    cout << "After inserting 99 at pos 2: ";
    display(head);

    int removed = remove(head, 3);
    cout << "Removed value at pos 3: " << removed << endl;
    cout << "After removing: ";
    display(head);

    insert(head, 5, 0);
    cout << "After inserting 5 at pos 0: ";
    display(head);

    freeMemory(head);
    freeMemory(copied);
    cout << "Memory freed" << endl;

    return 0;
}
