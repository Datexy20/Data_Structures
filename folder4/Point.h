#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
// --------------- D a t a    T y p e    P o i n t ---------------

// . . . Define Data Type Point Here . . .
//Give location of a point on a cartesian graph

class Point
{
public:
        // Constructors
        Point();                            //Default constructor
        Point (double xVal, double yVal);   //Explicit constructor

        //Accessors
        double X() const;   //Returns x coordinate
        double Y() const;   //Returns y coordinate

        //Mutator Function: Sets x and y coordinates of a point
        void Set(double xVal, double yVal);

        //Return the length of a line from the calling point to point pt2
        double Length(Point pt2);

        //Input - Output Functions
        bool Get(istream &is=cin);
        void Show(ostream &os=cout) const;

private:
        double x; //Can only be accessed through the mutator function or accessors.
        double y;
        //X and Y cannot be accessed by client

};


#endif // POINT_H_INCLUDED
