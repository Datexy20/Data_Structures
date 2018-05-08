/*--------------- LinkedList . c p p ---------------

by:   Derek Teixeira
      16.322 Data Structures
      ECE Department
      UMASS Lowell

PURPOSE
The LinkedList.cpp is use to initialize nodes with an empty list.
We can traverse the list, delete from it, or insert.


DEMONSTRATES
Singly Linked Lists

CHANGES

*/

#include <iostream>
#include <cmath>

using namespace std;

#include "Point.h"
#include "LinkedList.h"

LinkedList::LinkedList()
{
first = 0;
pred = 0;
current = 0;
}

//AT END OF GROUP OF NODES

bool LinkedList::AtEnd()
{
    return current == 0;
}

//EMPTY NODES

bool LinkedList::Empty() const
{

    return first == 0;

}

//SKIP NODES
void LinkedList::Skip()
{
    assert(!AtEnd());
    pred = current;
    current = pred->next;
}


//  INSERT CASSE MIDDLE OR end
void LinkedList::Insert(const NodeData &d)
{
    Node *newNode = new(nothrow) Node(d, current);
    assert(newNode != 0);
    if (pred == 0)
        {
        newNode->next = first;
        first = newNode;
        }
    else
        pred->next = newNode;

    pred = newNode;

}

//DELETE CURRENT ENTRY

void LinkedList::Delete()
{
    assert(!Empty());

    if (pred == 0)
        {
        first = current->next;
        delete current;
        current = first;
        }
    else
        {
        pred->next = current->next;
        delete current;
        current = pred->next;;
        }
}


//SHOW CURRENT ENTRY

NodeData LinkedList::CurrentEntry() const
{

    return current->data;
}






