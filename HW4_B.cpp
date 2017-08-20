/**
 PART B
 
 Project: Guess a number within a given range.
 
 Find and fix the errors.
 Run the program twice and save each output as a comment at the end
 of the source file.
 
 The program generates a random number within the range 1 to 8 (inclusive)
 and asks the user to guess it in one or two tries.
 
 Mega Putra
 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int random_num, num;
    const int MIN = 1, MAX = 8;

    
    srand((unsigned)time(0));
    random_num = rand() % 8 + 1; // (0 to 9) +1 = 1 to 8
    
    cout << "Enter a number within the range 1 to 8: ";
    cin >> num; // first try
    
    if(num == random_num)
        cout << "Congratulations! You did it!\n\n";
    else
    { //add
        if(num < random_num)
            cout << "Your guess is low! ";
        else
        {
            cout << "Your guess is high!";
            cout << " Try again!\n\n";
        }
    }
    
    cout << "Enter a number within the range 1 to 8: ";
    cin >> num; // second try
    
    if(num == random_num)
        cout << "Congratulations! You did it!\n\n";
    
    else;
    {
        cout << "Sorry, the number was " << random_num << endl;
    }
    return 0;
}

/*********************************************************************************
 Enter a number within the range 1 to 8: 3
 Congratulations! You did it!

 
 */


/*********************************************************************************
 Enter a number within the range 1 to 8: 2
 Your guess is low!Enter a number within the range 1 to 8: 4
 Sorry, the number was 7
 
 */
