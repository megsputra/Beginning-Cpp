/**
 PROGRAM 8A:
 ARRAYS and FUNCTIONS: SEARCHING using the Linear Search function
 // also known as Sequential Search
 
 Find and fix errors. Run the program once and save the output as a comment at the end
 of the source file.
 
 
 //  Mega Putra
 
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int searchList(int array[], int size, int target);

int main()
{
    int list[100] = {40, 30, 50, 13, 35, 48, 14, 31, 18, 33};
    int length = 10;
    
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < 2 * length; i++) // SEARCH 20 times
    {
        int target = rand() % 41 + 10;  // generate a random target within the range 10 to 50
        int location = searchList(list, length, target); //no [] in square brackets, max size is 100 but u have 10 only.
        if (location != -1) // NOT instead of ==
            cout << target << " FOUND at location: " << location << endl;
        else
            cout << target << " NOT found!" << endl;
    }
    
    return 0;
}

/***************************************************
 This function searches a list of integers for a given target
 It returns -1 if not found.
 It returns the index of the first element in the array that is equal to
 the target value.
 */
int searchList(int array[], int size, int target)
{
    int index = 0;   // Used as a subscript to search array
    int pos   = -1;  // To record position of search value: -1 means not found
    
    while (index < size && pos == -1)
    {
        if (array[index] == target) // If the value is found
        {
            pos = index; // Record the value's subscript
        }
        index++; // Go to the next element
    }
    return pos; // Return the position, or -1
}

/************** OUTPUT
 
 */
