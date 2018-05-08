#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

// --------------- D a t a    T y p e    P o i n t ---------------

// . . . Define Data Type Point Here . . .
//Give location of a point on a cartesian graph
struct Point
{
	double x;       //The x-coordinate of a point
	double y;       //The y-coordinate of a point
};

double Length(Point pt1, Point pt2);
bool GetPoint(Point &pt);
void ShowPoint(Point pt);


#endif // POINT_H_INCLUDED
