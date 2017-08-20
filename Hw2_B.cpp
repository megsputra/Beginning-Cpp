/**
   Constants, variables and arithmetic operators

   This program will output the circumference and area
   of the circle with a given radius.

   Mega Putra
*/
#include <iostream>

using namespace std;

const  double PI = 3.14;

int main()
{
	double circumference;                // definition of circumference
    double radius = 5.4;                 // definition and initialization of the radius
    double area;                         // definition of area of circle //Error 1: Included Double

    // Calculations Section
    circumference = 2 * PI * radius;    // computes circumference //Error 2: Radius needs to be lower case letters

    area = PI * radius * radius;               // computes area //Error 3: inputed the formula to find area

    // Display Results Section
    // Fill in the code for the cout statement that will output (with description)
    // the radius
    cout << "the radius is " << radius << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the circumference
    cout << "the circumference is " << circumference << endl;

    // Fill in the code for the cout statement that will output (with description)
    // the area of the circle
    cout << "the area of the circle is " << area << endl;


   return 0;
}
/*********************************************************************************
the radius is 5.4
the circumference is 33.912
the area of the circle is 91.5624

*/
