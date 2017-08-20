/**
 PART B
 
 Write a program that will do the following steps (pseudo-code):
 1.	Display a welcome message and a title, such as “Working with random numbers and simple mathematical functions”. Then display the name of the library functions you are going to use in this program and the header files needed for each function.
 2.	Generate 4 random numbers between 2 and 19 inclusive
 // r1, r2, r3, r4
 3.	Generate one random number between 3 and 7 inclusive, name it x
 4.	Calculate pwr as  r1 to the power of x
 5.	Calculate the average of the 4 random numbers
 6.	Calculate the square root of the average
 7.	Calculate the geometric mean of the random numbers (the product of these numbers to the power of 1 / 4)
 8.	Display a line of asterisks, such as “********************\n”
 9.	Display the following (with description):
 •	r1, r2, r3, r4
 •	r1, x, and pwr
 •	average of the 4 numbers with 1 digit after the decimal point
 •	square root of the average with 3 digits after the decimal point
 •	geometric mean of the random numbers with 3 digits after the decimal point
 
 
 Note: Please define and use as many variables you consider useful.
 
 Mega Putra
 
 */
#include <iostream>
#include <cmath> //mathematical fuctions
#include <cstdlib> // rand and srand
#include <iomanip> // For setprecision
#include <ctime>     // For the time function
using namespace std;

int main()
{
    //1. Displaying the welcome message and library programs
    cout << "Working with random numbers and simple mathematical functions" << endl;
    cout << "Library functions used: <iostream> for cin/cout, <cmath> for mathematical functions, and <cstdlib> for rand and srand, and <iomanip> for setprecision." << endl;
    
    //2. Generate 4 random numbers between 2 and 19 inclusive
    // r1, r2, r3, r4
    
    int r1, r2, r3, r4, x;
    double pwr, average, sqav, geomean, product;
   
    srand(time(NULL));
    r1 = (rand() % 18) + 2;// 2 to 19
    r2 = (rand() % 18) + 2;
    r3 = (rand() % 18) + 2;
    r4 = (rand() % 18) + 2;
 
    //3. Generate one random number between 3 and 7 inclusive, name it x
    x = (rand() % 5) + 3; //3 to 7
    
    //4. Calculate pwr as  r1 to the power of x
    pwr = pow(r1, x);

    //5. Calculate the average of the 4 random numbers
    average = (r1 + r2 + r3 + r4) / 4;
    
    //6. Calculate the square root of the average=
    sqav = sqrt(average);
    
    //7. Calculate the geometric mean of the random numbers (the product of these numbers to the power of 1 / 4)
    product = r1 * r2 * r3 * r4;
    geomean = pow(product, 0.25);
    
    //8. Display a line of asterisks, such as “********************\n”

    cout << "********************\n";

    //9.	Display the following (with description):
    cout << "•  Let's generate 4 random numbers! "<< r1 << ", "<< r2 << ", "<< r3 << ", "<< r4 <<endl;
    cout << "•  The first random number is: " << r1 << ", and x is " << x << ". "<< "So, "<< r1 << " to the power of " << x<< " is: "<< pwr << endl;
    cout << "•  The average of the 4 random numbers is: "<< setprecision(1) << fixed << average << endl;
    cout << "•  The square root of the average is: "<< setprecision(3) << fixed << sqav << endl;
    cout << "•  The geometric mean of the 4 random numbers is: " << setprecision(3) << fixed << geomean << endl;
    
    return 0;
}
/*********************************************************************************
 Working with random numbers and simple mathematical functions
 Library functions used: <iostream> for cin/cout, <cmath> for mathematical functions, and <cstdlib> for rand and srand, and <iomanip> for setprecision.
 ********************
 •  Let's generate 4 random numbers! 15, 9, 7, 4
 •  The first random number is: 15, and x is 3. So, 15 to the power of 3 is: 3375
 •  The average of the 4 random numbers is: 8.0
 •  The square root of the average is: 2.828
 •  The geometric mean of the 4 random numbers is: 7.841
 
 */


/*********************************************************************************
 Working with random numbers and simple mathematical functions
 Library functions used: <iostream> for cin/cout, <cmath> for mathematical functions, and <cstdlib> for rand and srand, and <iomanip> for setprecision.
 ********************
 •  Let's generate 4 random numbers! 5, 17, 13, 3
 •  The first random number is: 5, and x is 3. So, 5 to the power of 3 is: 125
 •  The average of the 4 random numbers is: 9.0
 •  The square root of the average is: 3.000
 •  The geometric mean of the 4 random numbers is: 7.588
 
 */
