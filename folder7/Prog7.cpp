/*--------------- P r o g 4 . c p p ---------------

by:   George Cheney
16.322 Data Structures
ECE Dept.
UMASS Lowell

PURPOSE
Find a path through a maze.

DEMOSTRATES
Stack as Linked List
Backtracking

CHANGES
10-19-2016 gpc - Distribute to 16.322 class.
10-20-2016 gpc - Install naive SolveMaze( ) function.
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

#include "CursorCntl.h"
#include "Maze.h"
//#include "Stack.h"

/*----- M a z e : : T r a v e r s e (  ) -----

PURPOSE
Naive maze traversal algorithm. Try all possible next
positions, but give up at a dead end..

RETURN VALUE
true  -- a solution was found.
false -- failed to find a solution.
*/

bool YouCanGetThereFrom(Maze &maze, Position curPos)
{
	//Position curPos;     // The current position

	{
	// Repeatedly find a next move until the goal is reached.
	if (maze.IsOpen(curPos))
		maze.Visit(curPos);

		if(curPos == maze.Goal())
				
			cin.get();  // Wait for a key press.

		if (curPos == maze.Goal() || YouCanGetThereFrom(maze, curPos + StepEast)
			|| YouCanGetThereFrom(maze, curPos + StepSouth) \
			|| YouCanGetThereFrom(maze, curPos + StepWest)	\
			|| YouCanGetThereFrom(maze, curPos + StepNorth))

		{

			maze.MarkPathCell(curPos);
			return true;

		}

	maze.Reject(curPos);
				
	}		
	//if(!YouCanGetThereFrom(maze, curPos))
return false;
}

/*--------------- m a i n ( ) ---------------*/

int main(void)
{
	// Screen positions
	const unsigned XResult = 15;
	const unsigned YResult = 5;
	const unsigned XFinish = 0;
	const unsigned YFinish = 20;

	// Position stack remembers visited positions.
	Maze maze;

	Position curPos;

	curPos = maze.Start();
	maze.Visit(curPos);
	

	

	// Construct a maze from a maze definition file.
	

	// Traverse the maze.
	bool success = YouCanGetThereFrom(maze, curPos);
	// Indicate success or failure.
	gotoxy(XResult, YResult);
	if (!success)
		cout << "Failed: No path from start to goal exists." << endl;
	else
	{
		cout << "Success: Found a path." << endl;

		cin.get();  // Wait for a key press.

					// Retrace the path back to the goal.
		//while (!posStack.Empty())
			//maze.MarkPathCell(posStack.Pop());
	}
	// Done
	gotoxy(XFinish, YFinish);

	return 0;
}
