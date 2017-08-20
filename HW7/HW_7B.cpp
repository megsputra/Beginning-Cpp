//  Created by Mega Putra on 11/20/16.
//  Copyright © 2016 Mega Putra. All rights reserved.

/*
A simplified version of "The Deal or No Deal" game.
 
Mega Putra
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

// Function prototypes
void printInfo();
void shuffleCases (int briefCases[], int size);
int playGame (string &name, int n, int briefCases[]);
int getValidNum (int low, int high);
void write2File(ofstream &outFile, string name, int caseValue); //to "players.txt"
void farewell();

int main()
{
    //defining variables
    const int SIZE = 10;
    ofstream outFile;
    string name;
    char newPlayer;
    int n = 0, counter = 0, caseValue = 0;
    int briefCases[SIZE] = {1, 10, 100, 1000, 10000, 100000, 1000000}; //cases with $money
    srand((unsigned)time(0));
    
    printInfo(); //welcome world!
    
    outFile.open ("players.txt");
    if(!outFile) //checking validity
    {
        cout << "Error! Please make sure output file exists." << endl;
    }
/*
*                          S T A R T                                   *
*                               T H E                                  *
*                                   G A M E                            *
*/
    do
    {
        shuffleCases (briefCases, SIZE);                //different numbers every game
        
        caseValue = playGame(name, n, briefCases);      //play one game
       
        cout << "WOW " << name << "!! You walked home with $" << caseValue << endl; // need to display value
        cout << "Game over for " << name << endl;
       
        write2File(outFile, name, caseValue); //display name and final amount to file
        
        counter += 1; // 5 games allowed
        
        cout << "\n\nAre there any other players who want to play? (y/n)" << endl;
        cin >> newPlayer;
        
    } while (counter <= 5 && newPlayer == 'y');
    
    outFile.close(); //close file
    farewell(); //display farewell message
    
    return 0;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
               printInfo Function
this function prints welcome message and rules of the game
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void printInfo()
{
    cout << "\t\t\t\t~DEAL OR NO DEAL~" << endl;
    cout << "RULES:\n"
    << "There are 10 briefcases with different amounts of money \n"
    << "We have 3 cases that contain no money. There's also cases with values \n"
    << "ranging from $1 to $1 Million!! You can open up to 3 cases. When a case\n"
    << "choosen, you will see the content of the case and you can choose DEAL \n"
    << "to take your current case or you can choose NO DEAL and move on to the next.\n"
    << "After you open 3 cases, you will see the final amount of money \n(last case) "
    << "and the game is over. Up to 5 players can play! \n\nTo Begin.." << endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                shuffleCases Function
 this function shuffle/randomizes the briefcases
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void shuffleCases (int briefCases[], int size) // not uppercase because it's a copy
//reshuffle every game
{
        for (int i = 0 ; i < size ; i++)
        {
            int r = rand() % size;
            int hold = briefCases[i];
            briefCases[i] = briefCases [r];
            briefCases[r] = hold;
        }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                playGame Function
this function starts the game, user will enter name & choose 
 the brief cases! This function then displays the value of case
 and asks the user DEAL OR NO DEAL.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int playGame (string &name, int n, int briefCases[]) //name is returned main displays
{
    int playCount = 1;
    int index; //location of array
    char deal = 'n';
    
    cout << "Please enter your name: ";
    cin >> name;
    
    while ( deal == 'n' && playCount < 4)
    {
        index = getValidNum(0, 9); //location
        cout << "The value of your case was: $" << briefCases[index] << endl; //get whatever' s here
        
        if (playCount < 3)
        {
            cout << "DEAL or NO DEAL? (y/n)" << endl;
            cin.get(deal);
        }
        playCount += 1;
    }
    return briefCases[index];
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                getValidNum
 This function prompts user to enter a number between 0 to 9
 and validates it.
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int getValidNum (int low, int high)
{
    int n;
    bool success;
    
    do
    {
        cout << "Please enter the case of your choice (" << low << " to " << high << "):";
        success = static_cast<bool>(cin >> n); //static cast bool for Xcode *_*
        cin.clear();                           // to clear the error flag
        cin.ignore(80, '\n');                  // to discard the unwanted input from the input buffer
        
    }while(!success || n < low || n > high);
    return n; //how to print the value of chosen case?
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                writePlayers
this function shuffle/randomizes the briefcases
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void write2File(ofstream &outFile, string name, int caseValue)
{
    outFile << setprecision(2) << fixed;
    outFile << name << "'s final amount is: " << caseValue << endl;
    cout << "\nName and score recorded to file." << endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                farewell Function
 this function prints farewell message
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void farewell()
{
    cout << "GAME OVER.. Please enjoy your winnings (if you win)"
    << "\nI hope you enjoy the game.\nThank you for playing :)" << endl;
}


/* OUTPUT:
 
 
 
 This Example uses:
 2/5 players
 1 no deal then deal
 2 no deals - to show auto end
 
 
 
 
 ~DEAL OR NO DEAL~
 RULES:
 There are 10 briefcases with different amounts of money
 We have 3 cases that contain no money. There's also cases with values
 ranging from $1 to $1 Million!! You can open up to 3 cases. When a case
 choosen, you will see the content of the case and you can choose DEAL
 to take your current case or you can choose NO DEAL and move on to the next.
 After you open 3 cases, you will see the final amount of money
 (last case) and the game is over. Up to 5 players can play!
 
 To Begin..
 Please enter your name: Mega
 Please enter the case of your choice (0 to 9):3
 The value of your case was: $0
 DEAL or NO DEAL? (y/n)
 n
 Please enter the case of your choice (0 to 9):6
 The value of your case was: $100000
 DEAL or NO DEAL? (y/n)
 y
 WOW Mega!! You walked home with $100000
 Game over for Mega
 
 Name and score recorded to file.
 
 
 Are there any other players who want to play? (y/n)
 y
 Please enter your name: Fish
 Please enter the case of your choice (0 to 9):8
 The value of your case was: $10000
 DEAL or NO DEAL? (y/n)
 n
 Please enter the case of your choice (0 to 9):9
 The value of your case was: $1000
 DEAL or NO DEAL? (y/n)
 n
 Please enter the case of your choice (0 to 9):4
 The value of your case was: $0
 WOW Fish!! You walked home with $0
 Game over for Fish
 
 Name and score recorded to file.
 
 
 Are there any other players who want to play? (y/n)
 n
 GAME OVER.. Please enjoy your winnings (if you win)
 I hope you enjoy the game.
 Thank you for playing :)
 Program ended with exit code: 0
 
 
 */




