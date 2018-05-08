/*--------------- Queue . c p p  ---------------

by:   George Cheney
16.322 Data Structures
ECE Dept.
UMASS Lowell

PURPOSE
This module defines operations on objects of class Position.

CHANGES
10-28-2016 gpc - Distribute to EECE322 class.
*/

#include <iostream>
#include <cassert>

using namespace std;

#include "Queue.h"



void Queue::EnQueue(QueueElem &p)
{
	Node *newNode = new(nothrow) Node(p);
	assert(newNode != 0);
	if (Empty())
	{
		head = tail = newNode;
	}
	else
	{
		tail->succ = newNode;
		tail = newNode;
	}

}



QueueElem Queue::DeQueue()
{
	
	return head->data;
	Node *ptr = head;
	head = head->succ;
	if (head == tail)
	{
		delete ptr;
		head = 0;
		tail = 0;
	}
	else
	{
		head = head->succ;
		delete ptr;
	}
}


QueueElem Queue::Head()
{
	assert(!Empty());
	return (head->data);
}