#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

// --------------- D a t a    T y p e    P o l y g o n ---------------

// . . . Define Data Type Polygon Here . . .
//Defines a polygon with 3-10 sides
const unsigned MaxSides = 10;       //Max ten sided polygon
const unsigned MinSides = 3;        //Minimum is 3 sided polygon

struct Polygon
{
	unsigned    numSides;       // number of vertices
	Point       v[MaxSides];    // uses point from the point structure
};

double PolyCircumference(Polygon &thePoly);
void PolyArea(Polygon &thePoly, double *area);
void ShowPoly(Polygon &p);
//Polygon Function Prototypes



#endif // POLYGON_H_INCLUDED






