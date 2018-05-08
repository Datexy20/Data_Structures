#include <iostream>
#include <cmath>

using namespace std;

#include "Point.h"
#include "Polygon.h"


//----- D a t a    T y p e    P o l y g o n    F u n c t i o n s -----

// . . . Define Data Type Polygon Functions Here . . .

//Adds lengths around the circumference of the polygon
double PolyCircumference(Polygon &thePoly)
{
	double circ = 0;
	for (unsigned i = 0; i < thePoly.numSides - 1; i++)         //Loops all sides of Polygon, starts from origin
		circ += Length(thePoly.v[i], thePoly.v[i + 1]);
	circ += Length(thePoly.v[thePoly.numSides - 1], thePoly.v[0]);  //Ends on last side back to origin
	return circ;
	//Add up Lengths of each side, Bring back to origin
}
//Obtains area of a triangle, then adds together for total Polygon area.
void PolyArea(Polygon &thePoly, double *area)
{
	double triangle; //whole triangle area
	double a;   //First side
	double b;   //Second side
	double c;   //Third side
	double s;   //average of sides
	area[0] = 0;

	for (unsigned i = 0; i < thePoly.numSides - 2; i++)
	{
		a = Length(thePoly.v[0], thePoly.v[i + 1]);
		b = Length(thePoly.v[i + 1], thePoly.v[i + 2]);
		c = Length(thePoly.v[i + 2], thePoly.v[0]);
		s = (a + b + c) / 2;
		triangle = sqrt(s*(s - a)*(s - b)*(s - c));
		area[i + 1] = triangle;
		area[0] += triangle;

		//sum all triangles from i+1=1st triangle, i+2=second triangle, i+n=nth triangle
		//total area is at array 0, [o] is total area of polygon
	}

}


/*--------------- S h o w P o l y ( ) ----------

PURPOSE: Display a polygon.

INPUT PARAMETERS:
p  -- the polygon to be displayed.
*/
void ShowPoly(Polygon &p)
{
   for (unsigned i=0; i<p.numSides; i++)
      ShowPoint(p.v[i]);
}
