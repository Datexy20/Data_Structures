/*---------PolyCircumference-----------

Purpose: Compute the perimeter of a convex polygon.

Input Parameters
thePoly -- the polygon whose perimeter is needed

Return Value
The perimeter
*/
#include <iostream>
#include <cmath>

using namespace std;

#include "Point.h"
#include "Polygon.h"


double PolyCircumference(Polygon &thePoly)
{
    double circ = 0; // Initialize Circumference

    //Add the length of the polygon sides.
    for(unsigned i=0; i<thePoly.numSides; i++)
        {
        Point pt1 = thePoly.v[i];
        Point pt2 = thePoly.v[(i+1) % thePoly.numSides];
                                                            //Add the next side length
        circ += pt1.Length(pt2);
        }
    return circ;
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
		a = thePoly.v[0].Length(thePoly.v[i + 1]);
		b = thePoly.v[i + 1].Length(thePoly.v[i + 2]);
		c = thePoly.v[i + 2].Length(thePoly.v[0]);
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
    for(unsigned i=0; i<p.numSides; i++)
    {

        Point pt = p.v[i];

        pt.Show(cout);

    }
        //Outputs each point of the entered Polygon
}

