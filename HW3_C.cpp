/**
  Part C

  Find and fix the errors
  Run the program once and save the output as a comment at the end
  of the source file.

  Mega Putra
*/

#include <iostream> //added #
using namespace std;

int main()
{
   int begInv, sold, store1, store2, store3; //changed int to include multiple assignment


   // Get the beginning inventory for all the stores.
   cout << "One week ago, 3 new widget stores opened \n"; //change count to cout, and the slash direction
   cout << "at the same time with the same beginning inventory \n"; //change count to cout, and slash direction
   cout << "What was the beginning inventory?"; //Added closing semicolon
   cin >> begInv; //added closing semicolon

   // Set each store's inventory. //Added double slash to make comment
   store1 = store2 = store3 = begInv;

   // Get the number of widgets sold at store 1.
   cout << "How many widgets has store 1 sold? "; // added ;
   cin >> sold;
   store1 -= sold; // Adjust store 1's inventory & changed position of negative sign

   // Get the number of widgets sold at store 2.
   cout << "How many widgets has store 2 sold? "; //changed direction of <<
   cin >> sold;
   store2 -= sold; // Adjust store 2's inventory.

   // Get the number of widgets sold at store 3.
   cout << "How many widgets has store 3 sold? ";
   cin >> sold; //changed >> direction
   store3 -= sold; // Adjust store 3's inventory.

   // Display each store's current inventory.
   cout << "\nThe current inventory of each store:\n"; //changed direction
   cout << "Store 1: " << store1 << "\n";
   cout << "Store 2: " << store2 << "\n"; //changed the position of "
   cout << "Store 3: " << store3 << "\n"; //changed the position of "

   return 0; //added space in between
}
/***********************************************************************
 SAVE THE OUTPUT HERE:
One week ago, 3 new widget stores opened
at the same time with the same beginning inventory
What was the beginning inventory?100
How many widgets has store 1 sold? 45
How many widgets has store 2 sold? 72
How many widgets has store 3 sold? 34

The current inventory of each store:
Store 1:55
Store 2:28
Store 3:66

 */
