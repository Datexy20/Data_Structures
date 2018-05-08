/*--------------- Stack . c p p  ---------------

by:   Derek Teixeira
16.322 Data Structures
ECE Dept.
UMASS Lowell

PURPOSE
This module defines operations on objects of class Position.
*/

#include <iostream>
#include <cassert>
using namespace std;

#include "Stack.h"

StackElement Stack::Top() const
{
	assert(!Empty());
	return tos->data;
//top is the current value
}


void Stack::Push(const StackElement &p)
{
    //Node *newNode = new(nothrow) Node(p);

    Node *newNode = new Node;
    assert(newNode != 0);
    newNode->data = p;
    newNode->next = tos;
    tos = newNode;
//push a new node on the the stack, make it the top of stack
}

StackElement Stack::Pop()
{
	assert(!Empty());
	Node *ptr = tos;
	tos = tos->next;
	return ptr->data;
	delete ptr;
//remove top of the stack and change value to visited or passed
}
