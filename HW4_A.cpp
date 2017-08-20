/**
 PART A
 Shipping Charges (Chapter 4, Project 13 – 7th edition, Project 15 – 8th edition):
 
 
Mega Putra
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    
    bool curious;
    //Choose Print Info
    cout << "Curious about the programmer behind this HW? 1 = Yes, 0 = No" << endl;
    cin >> curious;
    
    if (curious == true)
    {
        cout << "Print info: "<< curious << endl;
        cout << "~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~\n";
        cout << "~*~ Mega Putra                            ~*~\n";
        cout << "~*~ Homework 4: Shipping Charges          ~*~\n";
        cout << "~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~\n\n";
    }
        else
        cout << "Okay, let's move on...\n\n";
    
    
        
    //Constants for weights
    const int MAX_WEIGHT = 20, MIN_WEIGHT = 0, MAX_DIST = 3000, MIN_DIST = 10;
    double rate = 0, weight, shipCost;
    int distance;
    const double RATE_0TO2 = 1.10, RATE_2TO6 = 2.20, RATE_6TO10 = 3.70, RATE_10TO20 = 4.80;
 

    //Prompting user to enter weight of package
    cout << "Enter the weight of your package (20kg Max): " << endl;
    cin >> weight;
    
    if (weight <= MIN_WEIGHT || weight > MAX_WEIGHT)
    {
        cout << "ERROR! Weight cannot be less than 0kg or more than 20kg! \n";
        return 0;
    }
    
    
    //Prompting user to enter weight of package
    cout << "Enter the distance of shipping destination: " << endl;
    cin >> distance;
    
    if (distance <= MIN_DIST || distance > MAX_DIST)
    {
        cout << "ERROR! Distance cannot be less than 10mi or more than 3000mi! \n";
        return 0;
    }
    
    if(weight <= 2)
        rate = RATE_0TO2;
    if(weight > 2 && weight <= 6)
        rate = RATE_2TO6;
    if(weight > 6 && weight <= 10)
        rate = RATE_6TO10;
    if(weight > 10 && weight <= 20)
        rate = RATE_10TO20;

    
    
    shipCost = rate * (ceil(distance/500.0));
    
    cout << left << endl;
    cout << "------   " << setw(8) << "--------   " << setw(8) << "--------------------------   " << setw(4) << "------\n";
    cout << "Weight   " << setw(1) << "Distance   " << setw(3) << "Rate per 500 Miles Shipped   " << setw(3) << "Charge\n";
    cout << "======   " << setw(6) << "========   " << setw(3) << "==========================   " << setw(3) << "======\n";
    cout << " " << weight << "         " << distance << "               " << setprecision(2) << fixed << rate << "                " << shipCost << endl ;
    
    return 0;
   
    
}
/***********************************************************************
 Curious about the programmer behind this HW? 1 = Yes, 0 = No
 1
 Print info: 1
 ~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~
 ~*~ Mega Putra                            ~*~
 ~*~ Homework 4: Shipping Charges          ~*~
 ~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~~*~
 
 Enter the weight of your package (20kg Max):
 1.5
 Enter the distance of shipping destination:
 500
 
 ------   --------   --------------------------   ------
 Weight   Distance   Rate per 500 Miles Shipped   Charge
 ======   ========   ==========================   ======
 1.5         500               1.10                1.10
 Program ended with exit code: 0
 
 
 
 
 Curious about the programmer behind this HW? 1 = Yes, 0 = No
 0
 Okay, let's move on...
 
 Enter the weight of your package (20kg Max):
 1.5
 Enter the distance of shipping destination:
 501
 
 ------   --------   --------------------------   ------
 Weight   Distance   Rate per 500 Miles Shipped   Charge
 ======   ========   ==========================   ======
 1.5         501               1.10                2.20
 Program ended with exit code: 0
 
 
 
 
 Curious about the programmer behind this HW? 1 = Yes, 0 = No
 0
 Okay, let's move on...
 
 Enter the weight of your package (20kg Max):
 1.5
 Enter the distance of shipping destination:
 999
 
 ------   --------   --------------------------   ------
 Weight   Distance   Rate per 500 Miles Shipped   Charge
 ======   ========   ==========================   ======
 1.5         999               1.10                2.20
 Program ended with exit code: 0
 
 
 
 
 Curious about the programmer behind this HW? 1 = Yes, 0 = No
 0
 Okay, let's move on...
 
 Enter the weight of your package (20kg Max):
 1.5
 Enter the distance of shipping destination:
 1000
 
 ------   --------   --------------------------   ------
 Weight   Distance   Rate per 500 Miles Shipped   Charge
 ======   ========   ==========================   ======
 1.5         1000               1.10                2.20
 Program ended with exit code: 0
 
 
 
 
 Curious about the programmer behind this HW? 1 = Yes, 0 = No
 0
 Okay, let's move on...
 
 Enter the weight of your package (20kg Max):
 1.5
 Enter the distance of shipping destination:
 1001
 
 ------   --------   --------------------------   ------
 Weight   Distance   Rate per 500 Miles Shipped   Charge
 ======   ========   ==========================   ======
 1.5         1001               1.10                3.30
 Program ended with exit code: 0
 
 
 
 
 Curious about the programmer behind this HW? 1 = Yes, 0 = No
 0
 Okay, let's move on...
 
 Enter the weight of your package (20kg Max):
 1.5
 Enter the distance of shipping destination:
 1500
 
 ------   --------   --------------------------   ------
 Weight   Distance   Rate per 500 Miles Shipped   Charge
 ======   ========   ==========================   ======
 1.5         1500               1.10                3.30
 Program ended with exit code: 0
 
 
 
 
 Curious about the programmer behind this HW? 1 = Yes, 0 = No
 0
 Okay, let's move on...
 
 Enter the weight of your package (20kg Max):
 1.5
 Enter the distance of shipping destination:
 1501
 
 ------   --------   --------------------------   ------
 Weight   Distance   Rate per 500 Miles Shipped   Charge
 ======   ========   ==========================   ======
 1.5         1501               1.10                4.40
 Program ended with exit code: 0
 
 
 
 
 Curious about the programmer behind this HW? 1 = Yes, 0 = No
 0
 Okay, let's move on...
 
 Enter the weight of your package (20kg Max):
 7.5
 Enter the distance of shipping destination:
 200
 
 ------   --------   --------------------------   ------
 Weight   Distance   Rate per 500 Miles Shipped   Charge
 ======   ========   ==========================   ======
 7.5         200               3.70                3.70
 Program ended with exit code: 0
 
 
 
 
 Curious about the programmer behind this HW? 1 = Yes, 0 = No
 0
 Okay, let's move on...
 
 Enter the weight of your package (20kg Max):
 7.5
 Enter the distance of shipping destination:
 520
 
 ------   --------   --------------------------   ------
 Weight   Distance   Rate per 500 Miles Shipped   Charge
 ======   ========   ==========================   ======
 7.5         520               3.70                7.40
 */
