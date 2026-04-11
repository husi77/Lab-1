#include <iostream>
using namespace std;

#include "Node.h"
#include "FirstOnlyLinkedList.h"
#include "SortedFirstOnlyLinkedList.h"

/*

1. What I understand about this task:

I need to write a SortedFirstOnlyLinkedList class that keeps the list in
sorted order at all times. It has only a first pointer (no last pointer).
insertSorted puts value in the right place so list stays sorted.
insertAtFirst and insertAtLast are private so user cannot break the order.


2. How I will solve it:

insertSorted: find the correct position and insert there.
Empty list -> just insert.
If value is smallest -> insertAtFirst.
Otherwise walk until we find a node bigger than value -> insert before it.
If value is biggest -> insertAtLast.

Example:
insertSorted(30): (30 ->)
insertSorted(10): (10 -> 30 ->)
insertSorted(20): (10 -> 20 -> 30 ->)
insertSorted(25): (10 -> 20 -> 25 -> 30 ->)

deleteValue(20): walk to node before 20, relink -> (10 -> 25 -> 30 ->)

search(25): walk through, find 25 -> return true
search(99): walk through, not found -> return false


3. Reused functions:

insertAtFirst is reused when value is smallest.
insertAtLast is reused when value is biggest.
removeFromFirst is reused in deleteValue when deleting first node.


4. What I learned:

Keeping data sorted during insertion saves time later when searching.
Making insertAtFirst and insertAtLast private prevents user from
breaking the sorted order.


5. Skills developed:

I can now build a self-sorting data structure. This is like the base
of many searching algorithms where data needs to stay ordered.

*/

int main()
{
    SortedFirstOnlyLinkedList list;

    cout << "Inserting values in random order..." << endl;
    list.insertSorted(50);
    list.insertSorted(20);
    list.insertSorted(40);
    list.insertSorted(10);
    list.insertSorted(30);

    cout << "Sorted list: ";
    list.display();

    cout << "\nSearch 30: " << list.search(30) << endl;
    cout << "Search 99: " << list.search(99) << endl;

    cout << "\nDelete 20: " << list.deleteValue(20) << endl;
    cout << "After deleting 20: ";
    list.display();

    cout << "Delete 50: " << list.deleteValue(50) << endl;
    cout << "After deleting 50: ";
    list.display();

    cout << "Delete 10: " << list.deleteValue(10) << endl;
    cout << "After deleting 10: ";
    list.display();

    cout << "\nInsert 5 and 35..." << endl;
    list.insertSorted(5);
    list.insertSorted(35);
    cout << "After inserting: ";
    list.display();

    cout << "\nRemove from first: " << list.removeFromFirst() << endl;
    cout << "After removeFromFirst: ";
    list.display();

    cout << "Remove from last: " << list.removeFromLast() << endl;
    cout << "After removeFromLast: ";
    list.display();

    cout << "\nIs empty? " << list.isEmpty() << endl;

    return 0;
}
