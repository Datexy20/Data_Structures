#include <iostream>
#include <cmath>
#include <limits>


using namespace std;

#include "Point.h"


//----- D a t a    T y p e    P o i n t    F u n c t i o n s -----

// . . . Define Functions for Data Type Point Here . . .
//Obtains the distance between two vertices on a graph
double Length(Point pt1, Point pt2)
{
	double distance = 0;
	return distance += sqrt(((pt1.x - pt2.x)*(pt1.x - pt2.x)) + ((pt1.y - pt2.y)*(pt1.y - pt2.y)));
	//Function returns distance
}
//Ends input one and empty line with Enter inputted
bool GetPoint(Point &pt)
{
    bool gotNum = false;

	if (cin.peek() != '\n')
        {
            cin >> pt.x >> pt.y;    //accepts input of coordinate without a leading Enter

            gotNum = true;
        }
    cin.ignore(INT_MAX, '\n');
    return gotNum;
}
//ShowPoint obtains point with coordinate outputs
void ShowPoint(Point pt)
{
	cout << "(" << pt.x << ", " << pt.y << ")" << endl;
	//Read out coordinates in cartesian format
}
