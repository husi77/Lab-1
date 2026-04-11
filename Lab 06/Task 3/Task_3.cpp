#include <iostream>
using namespace std;

#include "Node.h"
#include "LinkedList.h"
#include "myLinkedList.h"

/*

1. What I understand about this task:

I need to add three more functions to myLinkedList using the functions
I already made in Task 2 (getSize, search, peek, get):
put - inserts a value at a specific position
swap - swaps values at two positions
sort - sorts the list ascending or descending


2. How I will solve it:

put(value, pos): walk to position and insert new node there.
(10 -> 30 -> 50) put(20, 1) -> insert 20 at pos 1
Result: (10 -> 20 -> 30 -> 50)

swap(xi, yi): find nodes at both positions, swap their data values.
(10 -> 20 -> 30 -> 50) swap(0, 3) -> swap 10 and 50
Result: (50 -> 20 -> 30 -> 10)

sort(asc): bubble sort by comparing adjacent nodes and swapping data.
(50 -> 20 -> 30 -> 10) sort(true) ascending:
Pass 1: compare pairs, swap if needed
(20 -> 30 -> 10 -> 50) after pass 1
(20 -> 10 -> 30 -> 50) after pass 2
(10 -> 20 -> 30 -> 50) after pass 3
Final: (10 -> 20 -> 30 -> 50)


3. Reused functions:

getSize is reused inside put and sort to know list length.
insertAtFirst is reused inside put when position is 0.
insertAtLast is reused inside put when position is at end.
swap is basically reused inside sort for each comparison.


4. What I learned:

Bubble sort works on linked lists too, just swap data not pointers.
put function is like insert but at any position you want.
Building complex functions from simpler ones makes coding easier.


5. Skills developed:

I can now sort a linked list, insert at any position, and swap values.
These are the most common operations needed in data manipulation.

*/

int main()
{
    myLinkedList list;

    list.insertAtLast(10);
    list.insertAtLast(50);
    list.insertAtLast(30);

    cout << "Original list: ";
    list.display();

    // test put
    list.put(20, 1);
    cout << "After put(20, 1): ";
    list.display();

    list.put(40, 3);
    cout << "After put(40, 3): ";
    list.display();

    list.put(5, 0);
    cout << "After put(5, 0) at start: ";
    list.display();

    list.put(60, 10);
    cout << "After put(60, 10) at end: ";
    list.display();

    // test swap
    cout << "\nBefore swap: ";
    list.display();
    list.swap(0, 6);
    cout << "After swap(0, 6): ";
    list.display();

    list.swap(2, 4);
    cout << "After swap(2, 4): ";
    list.display();

    // test sort ascending
    cout << "\nBefore sort: ";
    list.display();
    list.sort(true);
    cout << "After sort ascending: ";
    list.display();

    // test sort descending
    list.sort(false);
    cout << "After sort descending: ";
    list.display();

    cout << "\nFinal size: " << list.getSize() << endl;

    return 0;
}
