#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "Position.h"

typedef Position QueueElem;

class Queue
{
private:
	//List node class definition
	struct Node
	{
		QueueElem   data;   //The Contents of the node
		Node        *succ;  //Link to the successor node

		Node() : succ(0) {}
		Node(const QueueElem &theData) : data(theData), succ(0) { }
	};

public:
	Queue() : head(0), tail(0) { }              //Default constructor
	bool Empty() const { return head == 0; }    //Returns true if empty
	void EnQueue(QueueElem &p);                 //Add new
	QueueElem DeQueue();                        //Remove and return head element
	QueueElem Head();                           //Return but don't remove head element
private:
	Node *head;
	Node *tail;
};



#endif // QUEUE_H_INCLUDED
