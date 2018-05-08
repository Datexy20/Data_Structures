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
#include "Stack.h"

/*----- M a z e : : T r a v e r s e (  ) -----

PURPOSE
Naive maze traversal algorithm. Try all possible next
positions, but give up at a dead end..

RETURN VALUE
true  -- a solution was found.
false -- failed to find a solution.
*/

bool SolveMaze(Maze &maze, Stack &stack)
{


	//row, column postion, start is row=0 column = 0

    //Push the start cell position onto the position stack
    stack.Push(maze.Start());
	//tos is always current position
    maze.Visit(stack.Top());
    //Mark the tos position "Visited"
    for(;;)
    {
        {
        if(stack.Top() == maze.Goal())                 //break loop when tos = goal
        {

            return true;
        }

        if(maze.IsOpen(stack.Top() + StepEast))
        {
            stack.Push(stack.Top() + StepEast);
            maze.Visit(stack.Top());
        }

        else if(maze.IsOpen(stack.Top() + StepSouth))
        {
            stack.Push(stack.Top() + StepSouth);
            maze.Visit(stack.Top());
        }

        else if(maze.IsOpen(stack.Top() + StepWest))  //cycle east, south, west, north
        {
            stack.Push(stack.Top() + StepWest);
            maze.Visit(stack.Top());
        }

        else if(maze.IsOpen(stack.Top() + StepNorth))
        {
            stack.Push(stack.Top() + StepNorth);
            maze.Visit(stack.Top());
        }
            else
            {
            maze.Reject(stack.Top());
            stack.Pop();                              //pop command if hits deadend or goal
            {
                if(stack.Empty())
                    return false;
            }



        }

        }


    }




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
	Stack posStack;

	// Construct a maze from a maze definition file.
	Maze maze;

	// Traverse the maze.
	bool success = SolveMaze(maze, posStack);
	// Indicate success or failure.
	gotoxy(XResult, YResult);
	if (!success)
		cout << "Failed: No path from start to goal exists." << endl;
	else
	{
		cout << "Success: Found a path." << endl;

		cin.get();  // Wait for a key press.

					// Retrace the path back to the goal.
		while (!posStack.Empty())
			maze.MarkPathCell(posStack.Pop());
	}
	// Done
	gotoxy(XFinish, YFinish);

	return 0;
}
