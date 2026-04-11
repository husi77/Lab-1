#include <iostream>
using namespace std;

#include "Node.h"
#include "FirstOnlyLinkedList.h"
#include "myFirstOnlyLinkedList.h"

/*

1. What I understand about this task:

I need to add new functions to myFirstOnlyLinkedList class.
These functions are search, getSize, get, put, swap, and sort.
The class only has a first pointer so everything starts from there.


2. How I will solve it:

search: walk through list and compare each node data with target value.
(10 -> 20 -> 30) search(20) -> found at second node -> return true

getSize: walk through list and count nodes.
(10 -> 20 -> 30) -> count = 3

get(pos): walk to position, remove that node and return its value.
(10 -> 20 -> 30) get(1) -> remove 20, return 20 -> list: (10 -> 30)

put(pos, value): walk to position and insert new node there.
(10 -> 30) put(1, 25) -> insert 25 at pos 1 -> list: (10 -> 25 -> 30)

swap(xi, yi): find nodes at both positions and swap their data.
(10 -> 25 -> 30) swap(0, 2) -> swap 10 and 30 -> list: (30 -> 25 -> 10)

sort(asc): bubble sort by comparing and swapping data values.
(30 -> 25 -> 10) sort(true) -> ascending -> list: (10 -> 25 -> 30)


3. Reused functions:

getSize is reused inside get and put to check valid positions.
insertAtFirst and insertAtLast are reused inside put for edge cases.
removeFromFirst is reused inside get when position is 0.


4. What I learned:

Adding new functions to an existing class follows the same pattern.
Sorting a linked list is done by swapping data not pointers which is easier.


5. Skills developed:

I can now add searching, sorting and position based operations to a
linked list. These are commonly needed in real applications.

*/

int main()
{
    myFirstOnlyLinkedList list;

    list.insertAtLast(10);
    list.insertAtLast(30);
    list.insertAtLast(20);
    list.insertAtLast(50);
    list.insertAtLast(40);

    cout << "Original list: ";
    list.display();

    cout << "Size: " << list.getSize() << endl;

    cout << "Search 30: " << list.search(30) << endl;
    cout << "Search 99: " << list.search(99) << endl;

    cout << "\nget(2) removes and returns: " << list.get(2) << endl;
    cout << "After get(2): ";
    list.display();

    list.put(1, 25);
    cout << "After put(1, 25): ";
    list.display();

    list.swap(0, 3);
    cout << "After swap(0, 3): ";
    list.display();

    list.sort(true);
    cout << "After sort ascending: ";
    list.display();

    list.sort(false);
    cout << "After sort descending: ";
    list.display();

    cout << "\nFinal size: " << list.getSize() << endl;

    return 0;
}
