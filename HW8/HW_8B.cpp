v /**
 PROGRAM 8B:
 ARRAYS and FUNCTIONS: SORTING using the SELECTION SORT function
 
 Find and fix errors. Run the program once and save the output as a comment at the end
 of the source file.
 
 
 //  Mega Putra
 
 */

#include <iostream>
#include <fstream>

using namespace std;

void selectionSort(int array[], int size); //for the other HW double scores and need string name array.

int main()
{
    int list[100] = {50, 30, 80, 10, 30, 40, 90, 30, 80, 30}; //4 30's
    int size = 10;
    
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    
    
    //void selectionSort(int array[], int size); // not a call
    selectionSort(list, size);
    
    
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/***************************************************
 This function sorts an array in ascending (small 2 large) order
 using the selection sort algorithm
 */
void selectionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++) //gotta be -1 instead of plus 1 and =
    {
        // look for smallest
        int minIndex = i;
        for(int k = i + 1; k < size; k++) // less than or equal to, NO EQUAL
        {
            if (array[k] < array[minIndex])
                minIndex = k;
        }
        // swap
        
    //} original error
    int hold = array[minIndex];
    array[minIndex] = array[i];
    array[i] = hold;
    } //curly braces are supposed to be here.
        //end of outer for loop.
    return;
}

/****************** OUTPUT
 50 30 80 10 30 40 90 30 80 30
 10 30 30 30 30 40 50 80 80 90
 Program ended with exit code: 0
 */
