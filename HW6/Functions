/**~*~*
 Project 6A:
 
 Defining and using functions in a C++ program:
 
 void funA(void);               // No paramaters, no return value
 void funB(char, int, double);  // PASS BY VALUE
 int  funC(void);               // return a value
 int  funD(int, int);           // receive values and a return
 
 This program will output the circumference and area
 of a circle with a given radius.
 
 NAME: Mega Putra
 
 *~**/

#include <iostream>

using namespace std;

const  double PI = 3.14;
void printInfo(void); //copied from bottom, have to declare the function
void printEnd(void);
void displayResults (double radius, double area, double circ);
double getRadius (void);
double calcCirc (double radius);
double calcArea (double radius);
int main()
{
    double radius;
    double area, circ;
    
    printInfo();

    // get data
    radius = getRadius();
    
    // calculations
    circ = calcCirc(radius);
    area = calcArea(radius);
    
    // Output
    displayResults (radius, area, circ);
    printEnd();
    
    return 0;
}
/**************
 HEADER:
 This is the printInfo fuction:
 task: print a welcome message
 */

void printInfo(void) //void means it does not have arguments/doesnt return any value, you can put void printInfo()
{                //Definition
    cout << "WELCOME to the CIRCLE calculator!\n\n"
    << "This program will output the\n"
    << "\tcircumference and\n"
    << "\tarea\n"
    << "of a circle with a given radius.\n\n";
    
}




/**************
 HEADER:
 This is the printEnd fuction:
 task: print a farewell message
 */

void printEnd (void) //Definition
{
    cout << "\n\n"
    << "\t ~~*~~ The END ~~*~~ \n\n"
    << "\t        ~~*~~ \n"
    << "\t      Thank you\n\tfor using my program!\n";
}



/**************
 HEADER:
 This is the displayResults fuction:
 task: radius, area, circumference of a circle
 */

void displayResults (double radius, double area, double circ) //have to repeat type
{                       //these are parameters, order doest matter, but once you decide an order
    // you have to follow your order for the rest of the function
    // Output
    cout << "\n\nRESULTS\n";
    cout << "\tRadius = " << radius << endl;
    cout << "\tCircumference = " << circ << endl;
    cout << "\tArea = " << area << endl;
}



/**************
 HEADER:
 This is the getRadius fuction:
 task: prompt use to enter a valid radius
 */
double getRadius (void)

{
    double radius; //need to define it again - this is a LOCAL VARIABLE
    // get data
    do
    {
        cout << "Enter radius (must be > 0): ";
        cin  >> radius;
    } while (radius <= 0);
    
    return radius; //to send back a value to main.. goes back to the caller: a single value, i
    // if u need to return multiple values, you cant use return.
}



/**************
 HEADER:
 This is the calcCirc fuction:
 task: calculates circumference of a circle
 */
double calcCirc (double radius)
{
    double circ;
    circ = 2 * PI * radius;
    return circ;
}




/**************
 HEADER:
 This is the calcArea fuction:
 task: calculates area circle
 */
double calcArea (double radius)
{
    double area;
    area = PI * radius * radius;
    return area;
}

/* 
 OUTPUT:

 WELCOME to the CIRCLE calculator!
 
 This program will output the
	circumference and
	area
 of a circle with a given radius.
 
 Enter radius (must be > 0): 10
 
 
 RESULTS
	Radius = 10
	Circumference = 62.8
	Area = 314
 
 
 ~~*~~ The END ~~*~~
 
 ~~*~~
 Thank you
	for using my program!
 Program ended with exit code: 0
 
*/
