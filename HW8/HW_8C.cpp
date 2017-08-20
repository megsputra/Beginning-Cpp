// main.cpp
// HW_8C
//
// Created by Mega Putra on 12/5/16.
// Copyright © 2016 Mega Putra. All rights reserved.
// Star search version II

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//function prototypes
void welcome();
void readScores(string names[], double scores[], int &size);
double findLowest(double scores[]);
double findHighest(double scores[]);
double calcScore(double scores[], int size);

void sortDescend(string names[], double scores[], int size);
void sortAscend(string names[], double scores[], int size);
void writeListFile(string names[], double scores[], int size, string fileName);
void displayWinner(string names[], double finalScore[]);
void farewell(void);

const int SIZE = 8; //basically the size of array
const int NUM_SCORES = 5;

int main()
{
    //variable declaration
    ifstream inFile;
    ofstream outFile;
    double scores[SIZE], finalScore[SIZE];
    int size;
    string names[SIZE], playerName;
    cout << setprecision(2) << fixed;
    
    //hello
    welcome();
    
    //read from file
    readScores(names, scores, size);
    //cout << "size= " << size << endl;
    
    //write to out1
    
    
    writeListFile(names, scores, size, "out1.txt"); //check compability filename.c_str
    
    //sort score - descending order
    sortDescend(names, scores, size);
    
    //write to out2
    writeListFile(names, scores, size, "out2.txt");
    
    //display winner & score to screen (1st person on sortAscend)
    displayWinner(names, finalScore);
    
    //sort name - ascending order
    sortAscend(names, scores, size);
    
    //write to out3
    writeListFile(names, scores, size, "out3.txt");
    
    //closing statement
    farewell();
    
    return 0;
}

/* ___________________________
 welcome function
 displays welcome message to the user
 ___________________________*/
void welcome(void)
{
    cout << "Welcome to star search version II \n"
    << "This was a very challenging project but I learned a lot" << endl;
}
/* ___________________________
 readScores function
 reads data from an input file
 ___________________________*/

void readScores (string names[], double scores[], int &size)
{
    ifstream inFile;
    
    inFile.open("performers.txt"); //original data
    double performanceScores[5];
    string name;
    int n = 0;
    bool success = true;
    
    inFile >> names [n];
    
    while (success)
    {
        
        for (int i = 0; i < NUM_SCORES; i++)
        {
            inFile >> performanceScores[i];
        }
        scores[n] = calcScore(performanceScores, NUM_SCORES);

        inFile >> names [++n];
        if (! inFile)
        {
            success = false;
        }
        
    }

    // close
    inFile.close();
    size = n;
}

/*___________________________
 findLowest
 This function finds a performer's lowest score (out of 5)
 *the lowest score then will be dropped out of the calculation
 ____________________________*/
double findLowest(double scores[], int size)
{
    double lowest = scores[0];
    
    for (int i = 1; i < 5; i++)
        if (scores[i] < lowest)
            lowest = scores[i];
    //cout << "low = "<< lowest << endl;
    return lowest;
}
/*___________________________
 findHighest
 This function finds a performer's highest score (out of 5)
 *the highest score then will be dropped out of the calculation
 ____________________________*/
double findHighest(double scores[], int size) // do i need this?
{
    double highest = scores[0];
    
    for (int i = 1; i < 5; i++)
        if (scores[i] > highest)
            highest = scores[i];
    //cout << "highest = "<< highest;
    return highest;
}
/* ___________________________
 calcScore
 This function is to calculate a performer’s score;
 this function calls two functions: findLowest & findHighest
 to subtract by the highest and lowest scores.
 ___________________________*/
double calcScore(double scores[], int size)
{
    double total = 0.0, finalScore = 0.0;
    
    for (int i = 0; i < NUM_SCORES; i++)
    {
        total += scores[i];
    }
    
    finalScore = (total - findLowest(scores, size) - findHighest(scores, size))/3;
    //cout << "final score= " << finalScore;
    // cout << "calc done";
    return finalScore;
}
/*___________________________
 sortDescend
 This function sorts the scores from highest to lowest..
 giving us the winner at scores[0];
 ____________________________*/
void sortDescend (string names[], double scores[], int size)
{
    int startScan, maxIndex;
    double maxValue;
    string maxName;
    
    for(startScan = 0; startScan < size; startScan++)
    {
        maxIndex = startScan;
        maxValue = scores[startScan];
        for (int index = startScan + 1; index < size; index ++)
        {
            if (scores[index] > maxValue)
            {
                maxValue = scores[index];
                maxIndex = index;
            }
        }
        scores[maxIndex] = scores[startScan];
        scores[startScan] = maxValue;
        
        maxName = names[maxIndex];
        names[maxIndex] = names[startScan];
        names[startScan] = maxName;
        //names[maxIndex] = names[startScan];
        //scores[startScan] = maxValue;
    }
    return;
}

/*___________________________
 sortAscend
 This function sorts the scores from highest to lowest..
 giving us the winner at scores[0];
 ____________________________*/
void sortAscend (string names[], double scores[], int size)
{
    int startScan, minIndex;
    string minValue;
    
    for(startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = names[startScan];
        for (int index = startScan + 1; index < size; index ++)
        {
            if (names[index] > minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        scores[minIndex] = scores[startScan];
        names[startScan] = minValue;
    }
    return;
    
}
/*___________________________
 writeListFile
 This function is to write to the score the performers' to a file
 ____________________________*/ //cout rounds to 2 decimals for you.

void writeListFile(string names[], double scores[], int size, string fileName)
{
    ofstream outFile;
    
    outFile.open(fileName.c_str());
    
    for (int i = 0; i < size; i++)
    {
        int scoreHundred = scores[i] * 100;
        scores [i] = scoreHundred / 100.0;
        outFile << names[i] << ": " << scores[i] << endl; // how to call
    }
    cout << "Data written to file.\n";
    //close file here?
    outFile.close();
}
/*___________________________
 farewell
 This function is to display an end-of-the-program message
 such as: "Good bye ~"
 ____________________________*/
void farewell()
{
    cout << "THE STAR HAS NOW BEEN DISCOVERED!" << endl;
}
/*___________________________
 displayWinner
 This function displays the winner's score & name
 ____________________________*/
void displayWinner(string names[], double finalScore[])
{
    ifstream inFile;
    string winner;
    double winnerScore;
    
    
    inFile.open("out2.txt");
    inFile >> winner;
    inFile >> winnerScore;
    cout << "The winner is " << winner << " with a score of " << winnerScore << endl;
}
