#include <iostream>
using namespace std;

#include "Node.h"
#include "LinkedList.h"
#include "myLinkedList.h"

/*

1. What I understand about this task:

The original LinkedList.h and myLinkedList.h have bugs in their destructors
and copy constructors. The destructor was doing delete first and delete last
separately. This causes two problems:
- If list has one node (first == last), it deletes same memory twice (crash)
- Middle nodes between first and last never get deleted (memory leak)

Also there was no proper copy constructor, so copying a list would make
both lists share the same nodes. When one list gets deleted, the other
list points to deleted memory (dangling pointer).


2. How I will solve it:

For destructor fix:
Instead of delete first; delete last;
I walk through the entire chain from first to end.
At each step I save current node, move to next, then delete saved node.

(10 -> 20 -> 30)
Step 1: save 10, move to 20, delete 10 -> (20 -> 30)
Step 2: save 20, move to 30, delete 20 -> (30)
Step 3: save 30, move to null, delete 30 -> empty
Set last to nullptr.

For copy constructor fix:
Walk through the original list and call insertAtLast for each value.
This creates brand new nodes with same values.

Original: (10 -> 20 -> 30)
Copy walks: 10, insert -> (10)
           20, insert -> (10 -> 20)
           30, insert -> (10 -> 20 -> 30)  separate memory


3. Reused functions:

insertAtLast is reused inside copy constructor to build the new list.
isEmpty is reused to check before operations.


4. What I learned:

Shallow copy is dangerous with linked lists because two objects share
same memory. Deep copy creates independent copies of all nodes.
Destructor must free ALL nodes not just first and last.


5. Skills developed:

I understand memory management in linked structures now.
I can spot and fix common bugs like double-delete and memory leaks.

*/

int main()
{
    cout << "--- Testing Fixed Destructor ---" << endl;

    myLinkedList list1;
    list1.insertAtLast(10);
    list1.insertAtLast(20);
    list1.insertAtLast(30);
    cout << "List1: ";
    list1.display();

    cout << "\n--- Testing Copy Constructor ---" << endl;

    myLinkedList list2(list1);
    cout << "List2 (copy of List1): ";
    list2.display();

    // modify list1 to prove they are independent
    list1.removeFromFirst();
    cout << "\nAfter removing from List1:" << endl;
    cout << "List1: ";
    list1.display();
    cout << "List2 (should be unchanged): ";
    list2.display();

    cout << "\n--- Testing single node case ---" << endl;
    myLinkedList list3;
    list3.insertAtFirst(99);
    cout << "List3: ";
    list3.display();

    myLinkedList list4(list3);
    cout << "List4 (copy of List3): ";
    list4.display();

    cout << "\n--- Testing empty list copy ---" << endl;
    myLinkedList emptyList;
    myLinkedList emptyCopy(emptyList);
    cout << "Empty list: ";
    emptyList.display();
    cout << "Empty copy: ";
    emptyCopy.display();

    cout << "\nAll destructors will run when main ends..." << endl;

    return 0;
}
