/*=============== P r o g 1 . c p p ===============

Starter Code by:  George Cheney
                  ECE Dept.
                  UMASS Lowell

Finished Code by:  Derek Teixeira

PURPOSE
Read in the definition of an arbitrary convex polygon, and then
compute both the circumference and the area of the polygon.

CHANGES
09-02-2016 gpc  -   Distribute to EECE322 class.
*/

#include <iostream>
#include <cmath>

using namespace std;

// --------------- D a t a    T y p e    P o i n t ---------------

// . . . Define Data Type Point Here . . .
//Give location of a point on a cartesian graph
struct Point
{
	double x;       //The x-coordinate of a point
	double y;       //The y-coordinate of a point
};

//----- D a t a    T y p e    P o i n t    F u n c t i o n s -----

// . . . Define Functions for Data Type Point Here . . .
//Obtains the distance between two vertices on a graph
double Length(Point pt1, Point pt2)
{
	double distance = 0;
	return distance += sqrt(((pt1.x - pt2.x)*(pt1.x - pt2.x)) + ((pt1.y - pt2.y)*(pt1.y - pt2.y)));
	//Function returns distance
}
//Ends input when the point x is negative
bool GetPoint(Point &pt)
{
	cin >> pt.x >> pt.y;
	if (pt.x < 0)
		return false;
	else
		return true;
}
//ShowPoint obtains point with coordinate outputs
void ShowPoint(Point pt)
{
	cout << "(" << pt.x << ", " << pt.y << ")" << endl;
	//Read out coordinates in cartesian format
}

// --------------- D a t a    T y p e    P o l y g o n ---------------

// . . . Define Data Type Polygon Here . . .
//Defines a polygon with 3-10 sides
const unsigned MaxSides = 10;
const unsigned MinSides = 3;

struct Polygon
{
	unsigned    numSides;       // number of vertices
	Point       v[MaxSides];    // uses point from the point structure
};

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

//--------------- m a i n ( ) ---------------

int main()
{
   Polygon poly;   // The polygon definition

   // Start out with zero polygon sides.
   poly.numSides = 0;

   // Read in a polygon definition. If a valid polygon was entered,
   // display its circumference and area; otherwise display an
   // error message and terminate execution.
   cout << "ENTER A POLYGON DEFINITION: " << endl << endl;

   for (;;)
      {
      // Read in the next point
      cout << "Enter next point: ";
      if (!GetPoint(poly.v[poly.numSides]))
         break;

      // Update the ploygon size.
      ++poly.numSides;

      // If the polygon is full, say so and stop taking input.
      if (poly.numSides >= MaxSides)
         {
         cout << "\nPolynomial Full" << endl;
         break;
         }
      }

   // Make sure that the polygon is valid.
   if (poly.numSides < MinSides)
      {
      cout << "***ERROR: A polygon must have at least 3 sides" << endl;
      return 0;
      }

   // The definition is valid, show the definition.
   cout << endl << "Here is the polygon definition:" << endl;
   ShowPoly(poly);

   // Compute and display the circumference.
   cout << "\nCircumference = " << PolyCircumference(poly) << endl;

   // Compute and display the areas of the polygon and its embedded triangles.

   // area[0] gives the area of the entire polygon.
   // area[i] (i > 0) gives the area of the i'th embedded triangle.
   double area[MaxSides+1];

   PolyArea(poly, area);

   cout << "\nPolygon Area = " << area[0] << endl << endl;

   const unsigned numTriangles = poly.numSides - 2;   // Number of embedded triangles

   for (unsigned i=1; i<=numTriangles; ++i)
      cout << "Triangle " << i << ": Area = " << area[i] << endl;

   cout << endl;

   return 0;
}
