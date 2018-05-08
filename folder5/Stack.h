#ifndef STACK_H
#define STACK_H
/*--------------- Stack . h ---------------

by:   George Cheney
16.322 Data Structures
ECE Dept.
UMASS Lowell

PURPOSE
Class definition for Stack.cpp.

CHANGES
10-19-2016 gpc - Distribute to 16.322 class.
*/
#include "Position.h"
typedef Position StackElement;
class Stack
{
	//Stack node class definition
	struct Node
	{
		StackElement	data;		//The "Contents" of the node
		Node			*next;		//Link to the next node
		//Node Constructor functions
		Node(){}
		Node(const StackElement &theData, Node *const theNext = 0)
			: data(theData), next(theNext)	{}
	};
public:
	//Constructor
	Stack() : tos(0) {};
	//Return true if the stack is empty.
	bool Empty() const { return tos == 0;  }
	//Return the value of the top element on the stack.
	StackElement Top() const;
	//Push a new element onto the stack.
	void Push(const StackElement &p);
	//Pop the top element from the stack
	StackElement Pop();
private:
	Node *tos;
};
#endif

