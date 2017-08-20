/**
 
 This is a simple guessing game between a computer and a player. First, the computer prompts the player to enter his/her name then it generates a random number between 50 and 70. The player has up to five tries to guess the number. After each guess, the program displays messages such as “Congratulations Susan, you’ve guessed the number in 2 tries!”, or “Sorry, the random number  was 58!” . Ask the player if s/he wants to play again (Y or y for yes, anything else for no) “Susan, would you like to play again?”.
 
 PLEASE ENJOY
 
 Mega Putra
 */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int number, guess, tries, game = -1;
    string name;
    char playAgain;
    srand((unsigned)time(NULL));
    

    //Player name entry and Introduction
    cout << "\t~A SIMPLE GUESSING GAME~\n\n" << endl;
    cout << "Hello, please enter your name.." << endl;
    cin >> name;
    
    cout << "\nHello, " << name << ","
         << " you have 5 chances to guess!" << endl;
    
    //Play the game
    //Generate the number
        number = rand() % 21 + 50; //50 to 70
    do
    {
        
        for (tries = 1; tries <= 5; tries++)
        {
            cout << "Enter a number between 50 and 70" << endl;
            cout << number << endl;
            cin >> guess;
                
            if (guess == number)
            { cout << "Congratulations, " << name << "! You’ve guessed the number in " << tries << " tries." << endl;
                game = 1; break;
            }
        
            {
                cout << "Try again! " << 5 - tries << " try(s) left" << endl;
                
            }
        }
        
        if (game == -1)
        cout << "Sorry, the random number was " << number << endl;
            
    
    //Play again?
    cout << name <<", would you like to play again? (enter Y/N)" << endl;
    cin >> playAgain;
    }
    while (playAgain == 'Y');
    
    if (playAgain == 'N')
        cout << "Game Over!\nThank you for playing." << endl;
    return 0;
}
