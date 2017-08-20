/**
 PART A
 
 A movie theater keeps 20 percent of the gross box office profit.  The remainder goes to the movie distributor.
 Write a program that calculates a theater’s gross and net box office profit for a night and one movie.
 The program asks for the name of the movie, and how many adult and child tickets were sold.
 The price of an adult ticket is $10.00 and a child’s ticket is $6.00. Display a report as shown below:
 
 Movie Name: 			  "Star Wars: The Force Awakens"
 Adult Tickets Sold:		 		 382
 Child Tickets Sold:				 127
 Gross Box Office Profit:   	  $ 4582.00
 Net Box Office Profit:   	      $  916.40
 Amount Paid to Distributor:    $ 3665.60
 
 Define and use named constants in your program. Output should be aligned as shown above (notice that the decimal points are all aligned).
 Run the program twice: first time enter the data above, the second time enter the following data:
 “The Good Dinosaur”, 100 adult tickets sold, and 200 child tickets sold.
 
 
 Mega Putra
 */

#include <iostream>
#include <string>
#include <iomanip> //setprecision and setw
using namespace std;
int main()
{
    //Defining variables
    string moviename;
    int adult, child;
    double gross, net, paid2dist;
    
    //Enter the name of the movie
    cout << "Movie Name:";
    getline(cin, moviename);
    
    //How much adult tickets are sold?
    cout << "Adult Tickets Sold:";
    cin >> adult;
    
    //How much adult tickets are sold?
    cout << "Child Tickets Sold:";
    cin >> child;
    
    //Calculating the gross profit for the box office
    gross = 10 * adult + 6 * child;
    
    //Calculating the net profit for the box office
    net = gross * 0.2;
    
    //Calculating the amount paid to distributor
    paid2dist = gross - net;
    
    
    //Displaying the Output!
    cout << setprecision(2) << fixed << right;
    cout << endl;
    cout << "Movie Name:           " << setw(6) << moviename << endl;
    cout << "Adult Tickets Sold:       " <<  setw(7) <<adult << endl;
    cout << "Child Tickets Sold:       " <<  setw(7) <<child << endl;
    cout << "Gross Box Office Profit:   $" <<  setw(6) <<gross << endl;
    cout << "Net Box Office Profit:     $ " <<  setw(6) <<net << endl;
    cout << "Amount Paid to Distributor:$" <<  setw(6) <<paid2dist << endl;
    return 0;
}
/***********************************************************************
 Movie Name:            Star Wars: The Force Awakens
 Adult Tickets Sold:           382
 Child Tickets Sold:           127
 Gross Box Office Profit:   $4582.00
 Net Box Office Profit:     $ 916.40
 Amount Paid to Distributor:$3665.60
 
 */


/***********************************************************************
 Movie Name:The Good Dinosaur
 Adult Tickets Sold:100
 Child Tickets Sold:200
 
 Movie Name:                The Good Dinosaur
 Adult Tickets Sold:          100
 Child Tickets Sold:          200
 Gross Box Office Profit:   $2200.00
 Net Box Office Profit:     $ 440.00
 Amount Paid to Distributor:$1760.00
 */
