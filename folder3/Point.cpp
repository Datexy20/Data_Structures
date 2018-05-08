using namespace std;


#include <iostream>
#include <cmath>
#include <limits>

#include "Point.h"


//----- D a t a    T y p e    P o i n t    F u n c t i o n s -----

// . . . Define Functions for Data Type Point Here . . .
//Obtains the distance between two vertices on a graph

Point::Point()              //Default is empty for Point
{
}

double Point::X() const     //Accessor Function X
{
    return x;

}
double Point::Y() const     //Accessor Function Y
{

    return y;

}

void Point::Set(double xVal, double yVal)   //Mutator functions
{
    x = xVal;   //sets xVal to equal x
    y = yVal;   //sets yVal to equal y
}

Point::Point(double xVal, double yVal)
{
    Set(xVal, yVal);        //Gives ability to use set points
}                           //



double Point::Length(Point pt2) //Calculate Length from pt1 to pt2
{
    double dx = pt2.x - x;
    double dy = pt2.y - y;

    return sqrt(dx*dx + dy*dy);
}

//Function returns distance

//Ends input one and empty line with Enter inputted
bool Point::Get(istream &is)
{
    bool gotNum = false;

	if (is.peek() != '\n')
        {
            double xVal;
            double yVal;

            is >> xVal >> yVal;    //accepts input of coordinate without a leading Enter

            Set(xVal, yVal);

            gotNum = true;
        }
    is.ignore(INT_MAX, '\n');
    return gotNum;
}
//ShowPoint obtains point with coordinate outputs
void Point::Show(ostream &os) const
{

	os << "(" << X() << ", " << Y() << ")" << endl;
	//Read out coordinates in cartesian format
}
