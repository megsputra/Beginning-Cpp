// This program gets a series of test scores and
// calculates the average of the scores with the
// lowest score dropped.
// Find and fix the errors. Run the program once (enter at least 5 scores) and
// save the output at the end of the source file a a comment

// NAME: Mega Putra

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getTestScores(double scores[], int &size);
double getTotal(const double array[], int size);
double getLowest(const double array[], int size);

int main()
{
    const int SIZE = 45;      // Array maximum size
    int size;                // Array actual size
    double testScores[SIZE], // Array of test scores
    total,            // Total of the scores
    lowestScore,      // Lowest test score
    average;          // Average test score
    
    // Get the test scores from the user.
    getTestScores(testScores, size);
    
    // Get the total of the test scores.
    total = getTotal(testScores, size);
                     
    // Get the lowest test score.
    lowestScore = getLowest(testScores, size);
                     
    // Subtract the lowest score from the total.
    total -= lowestScore;
                     
    // Calculate the average. Divide by 3 because
    // the lowest test score was dropped.
    average = total / static_cast<double>(size - 1);
                     
    // Set up numeric output formatting.
    cout << fixed << showpoint << setprecision(1);
                    
    // Display the average.
    cout << "The lowest score is " << lowestScore << ".\n";
    cout << "The average with the lowest score " << "dropped is " << average << ".\n";
  
    return 0;
}
                     
                     //************************************************************
                     // The getTestScores function accepts an array and its size  *
                     // as arguments. It prompts the user to enter test scores,   *
                     // which are stored in the array.                            *
                     //************************************************************
                     void getTestScores(double scores[], int &size)
    {
        // Loop counter
        int index;
        
        // Get the number of scores
        cout << "Enter the number of scores (45 scores max): ";
        cin >> size;
        // Get each test score.
        for (index = 0; index < size ; index++)
        {
            cout << "Enter test score number "
            << index +1 << ": ";
            cin >> scores[index];
        }
    }
                     
                     //****************************************************
                     // The getTotal function accepts a double array      *
                     // and its size as arguments. The sum of the array's *
                     // elements is returned as a double.                 *
                     //****************************************************
                     
        double getTotal(const double array[], int size)
    {
        double total = 0; // Accumulator
        
        // Add each element to total.
        for (int count = 0; count < size; count++)
            total += array[count];
        
        // Return the total.
        return total;
    }
                     
                     //****************************************************
                     // The getLowest function accepts a double array and *
                     // its size as arguments. The lowest value in the    *
                     // array is returned as a double.                    *
                     //****************************************************
                     
        double getLowest(const double array[], int size)
    {
        double lowest;  // To hold the lowest value
        
        // Get the first array's first element.
        lowest = array[0];
        
        // Step through the rest of the array. When a
        // value less than lowest is found, assign it
        // to lowest.
        for (int count = 0; count < size; count++)
        {
            if (array[count] < lowest)
                lowest = array[count];
        }
        
        // Return the lowest value.
        return lowest;
    }

    /************ OUTPUT *******************
     
     Enter the number of scores (45 scores max): 5
     Enter test score number 1: 11.5
     Enter test score number 2: 12.7
     Enter test score number 3: 19.3
     Enter test score number 4: 15.2
     Enter test score number 5: 16.1
     The lowest score is 11.5.
     The average with the lowest score dropped is 15.8.
     Program ended with exit code: 0
     */
