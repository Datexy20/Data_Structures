/*--------------- P r o g 6 . c p p ---------------

by:   George Cheney
16.322 Data Structures
ECE Dept.
UMASS Lowell

PURPOSE
Find the shortest path through a maze.

CHANGES
10-28-2016 gpc - Distribute to EECE322 class.
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

#include "CursorCntl.h"
#include "Maze.h"

/*----- S o l v e (  ) -----

PURPOSE
Attempt to find the shortest path through the maze.

INPUT PARAMETERS
maze           -- the maze object to be traversed
positionQueue  -- the queue of current and future positions

RETURN VALUE
true  -- a path was found.
false -- failed to find a path.
*/
bool Solve(Maze &maze, Queue &positionQueue)
{
	positionQueue.EnQueue(maze.Start());

	maze.Mark(positionQueue.Head(), 0);


	Position neighborE = positionQueue.Head() + StepEast;
	Position neighborS = positionQueue.Head() + StepSouth;
	Position neighborW = positionQueue.Head() + StepWest;
	Position neighborN = positionQueue.Head() + StepNorth;


	while (!positionQueue.Empty())
	{

		if (maze.State(neighborE) == Open)
		{
			maze.Mark(neighborE, 1 + maze.State(positionQueue.Head()));
			if (neighborE == maze.Goal())
				return true;
			positionQueue.EnQueue(neighborE);
		}
		else if (maze.State(neighborS) == Open)
		{
			maze.Mark(neighborS, 1 + maze.State(positionQueue.Head()));
			if (neighborS == maze.Goal())
				return true;
			positionQueue.EnQueue(neighborS);
		}
		else if (maze.State(neighborW) == Open)
		{
			maze.Mark(neighborW, 1 + maze.State(positionQueue.Head()));
			if (neighborW == maze.Goal())
				return true;
			positionQueue.EnQueue(neighborW);
		}
		else if (maze.State(StepNorth) == Open)
		{
			maze.Mark(neighborN, 1 + maze.State(positionQueue.Head()));
			if (neighborN == maze.Goal())
				return true;
			positionQueue.EnQueue(neighborN);
		}
		else
		{
			positionQueue.DeQueue();
		}



	}
	return false;






}

/*----- R e t r a c e (  ) -----

PURPOSE
Mark the path from the goal to the start cell.

INPUT PARAMETERS
maze           -- the maze object to be marked
*/
void Retrace(Maze &maze)
{
	Position curPos = maze.Goal();                  
	int distance;
	int distanceE;
	int distanceS;
	int distanceW;
	int distanceN;

	while (curPos != maze.Start())
	{
		distance = maze.State(curPos);               
		distanceE = maze.State(curPos + StepEast);   
		distanceS = maze.State(curPos + StepSouth);  
		distanceW = maze.State(curPos + StepWest);   
		distanceN = maze.State(curPos + StepNorth);  

		if (distance - 1 == distanceE)
		{
			maze.Mark(curPos, PathCell);
			curPos += StepEast;
		}
		else if (distance - 1 == distanceS)
		{
			maze.Mark(curPos, PathCell);
			curPos += StepSouth;

		}
		else if (distance - 1 == distanceW)
		{
			maze.Mark(curPos, PathCell);
			curPos += StepWest;
		}
		else if (distance - 1 == distanceN)
		{
			maze.Mark(curPos, PathCell);
			curPos += StepNorth;
		}
		else
		{
			maze.Mark(curPos, PathCell);
			curPos = maze.Start();
		}

	}
}

/*--------------- m a i n ( ) ---------------*/

int main()
{
	// Screen positions
	const unsigned XResult = 35;
	const unsigned YResult = 5;
	const unsigned XFinish = 0;
	const unsigned YFinish = 23;

	Maze  maze;				// Construct a maze from a maze definition file.
	Queue positionQueue;	// Create a queue of future positions to visit

							// Solve the maze.
	bool success = Solve(maze, positionQueue);

	// Indicate success or failure.
	gotoxy(XResult, YResult);
	if (!success)
		cout << "Failed: No path from start to goal exists." << endl;
	else
	{
		cout << "Success: Found the shortest path." << endl;
		gotoxy(XResult, YResult + 2);
		cout << "Press ENTER to highlight the shortest path.";
		cin.get();
		// Retrace the path from the goal cell to the start cell.
		Retrace(maze);
		cout << endl;
	}
	// Done
	gotoxy(XFinish, YFinish);
	clreol();
	return 0;
}
