#include <iostream>
using namespace std;

#include "Node.h"
#include "LinkedList.h"
#include "myLinkedList.h"

/*

1. What I understand about this task:

I need to add four new functions to myLinkedList:
getSize - counts how many nodes are in the list
search - checks if a value exists in the list
peek - returns value at a position WITHOUT removing it
get - removes the node at a position and returns its value

The difference between peek and get is that peek just looks at the value
while get actually removes the node from the list.


2. How I will solve it:

getSize: walk from first to end, count each node.
(10 -> 20 -> 30) -> count = 3

search: walk from first, compare each node data with target.
(10 -> 20 -> 30) search(20) -> found -> true
(10 -> 20 -> 30) search(99) -> not found -> false

peek(pos): walk to position and return data without removing.
(10 -> 20 -> 30) peek(1) -> returns 20, list stays (10 -> 20 -> 30)

get(pos): walk to position, save value, relink, delete node, return value.
(10 -> 20 -> 30) get(1) -> returns 20, list becomes (10 -> 30)


3. Reused functions:

getSize is reused inside get to check if position is valid.
removeFromFirst is reused inside get when position is 0.
removeFromLast is reused inside get when position is last.


4. What I learned:

peek and get show the difference between read-only and destructive access.
Position-based access in linked list needs walking from first every time
because there is no direct index like arrays.


5. Skills developed:

I can now do position-based operations on linked lists.
I understand the difference between peeking and getting a value.

*/

int main()
{
    myLinkedList list;

    list.insertAtLast(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.insertAtLast(40);
    list.insertAtLast(50);

    cout << "List: ";
    list.display();

    cout << "Size: " << list.getSize() << endl;

    cout << "\nSearch 30: " << list.search(30) << endl;
    cout << "Search 99: " << list.search(99) << endl;

    cout << "\nPeek at pos 0: " << list.peek(0) << endl;
    cout << "Peek at pos 2: " << list.peek(2) << endl;
    cout << "Peek at pos 4: " << list.peek(4) << endl;
    cout << "List after peeks (unchanged): ";
    list.display();

    cout << "\nGet at pos 2: " << list.get(2) << endl;
    cout << "List after get(2): ";
    list.display();
    cout << "Size now: " << list.getSize() << endl;

    cout << "\nGet at pos 0: " << list.get(0) << endl;
    cout << "List after get(0): ";
    list.display();

    cout << "\nGet at last pos: " << list.get(list.getSize() - 1) << endl;
    cout << "List after removing last: ";
    list.display();

    return 0;
}
