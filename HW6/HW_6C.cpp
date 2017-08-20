/**~*~*
 Project: Star Search
 A particular talent competition has five judges, each of whom awards a score between
 0 and 10 to each performer. Fractional scores, such as 8.3, are allowed.
 A performer's final score is determined by dropping the highest and the lowest score
 received, then averaging the three remaining scores. Write a program that calculates
 the score of each performer and determines the winner.
 Assume there's only one winner!
 
 Input: Read data from an input file named performers.txt.
 Output: Write the number of participants, the name of the winner and winnerís score to
 the screen. Write to a file named results.txt the names of the performers and their
 final score.
 
 Mega Putra
 
 How to calculate score? eliminate highest and lowest
 Calculate the sum and divide by 3
 
 *~**/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void welcome(void);
bool getScores(ifstream &inFile, string &name, double &score1, double &score2, double &score3, double &score4, double &score5);
double calcScore(double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);
double findHighest(double score1, double score2, double score3, double score4, double score5);
void writeScore(ofstream &outFile, string name, double finalScore);
void farewell(void);

int main()
{
    // declare the variables needed in main()
    ifstream inFile;
    ofstream outFile;
    double score1, score2, score3, score4, score5;
    double winnerScore = 0.0, finalScore = 0.0;
    int count = 0;
    string name, talent, winner;
    

    welcome();
    // open the input file + validation
    inFile.open ("performers.txt");
    if (!inFile)
    {
        cout << "ERROR!\nFail to open file, please make sure file exists!" << endl;
    }
    
    // open the output file + validation
        outFile.open ("results.txt");
    if (!outFile)
    {
        cout <<"ERROR!\nFail to find output file, please make sure file exists!" << endl;
    }
    
    while (getScores(inFile, name, score1, score2, score3, score4, score5))
    {
        
        count += 1;
        talent = name;
        
        finalScore = calcScore(score1, score2, score3, score4, score5);
        
        // determine the winner so far
        if (finalScore > winnerScore)
        {
            winnerScore = finalScore;
            winner = name;
        }
        
    outFile << setprecision(2) << fixed;
    writeScore(outFile, name, finalScore);
    }
    
    cout << setprecision(2) << fixed;
    
    // close the input file
    inFile.close();
    
    
    // close the output file
    outFile.close();
    
    
    // display the number of participants
    cout << "\n\n\nWe have the results!!!" << endl;
    cout << "There were " << count << " contestants.....\n" << endl;
    
    // display the winner and the winner's score
    cout << "with an outstanding score of " << winnerScore << endl;
    cout << "The winner of STAR SEARCH 2016 is........ \n\n\n\n" << winner << "!!!!\n\n" << endl;
    
    farewell();
    return 0;
}

// This function displays general information about the program
void welcome(void)
{
    cout << "\t\t\t~~*~~PROJECT **STAR** SEARCH~~*~~\n" << endl;
    cout<<"#############################################################"<<endl;
    cout<<"#                                                           #"<<endl;
    cout<<"#                       ,                                   #"<<endl;
    cout<<"#                    \\  :  /                                #"<<endl;
    cout<<"#                 `. __/ \\__ .'                             #"<<endl;
    cout<<"#                 _ _\\     /_ _                             #"<<endl;
    cout<<"#                    /_   _\\                                #"<<endl;
    cout<<"#                  .'  \\ /  `.                              #"<<endl;
    cout<<"#                    /  :  \\                                #"<<endl;
    cout<<"#                                                           #"<<endl;
    cout<<"#                  _  _                                     #"<<endl;
    cout<<"#                 ( `   )_                                  #"<<endl;
    cout<<"#                (    )    `)                               #"<<endl;
    cout<<"#              (_   (_ .  _) _)                             #"<<endl;
    cout<<"#                                             _             #"<<endl;
    cout<<"#                                            (  )           #"<<endl;
    cout<<"#             _ .                         ( `  ) . )        #"<<endl;
    cout<<"#           (  _ )_                      (_, _(  ,_)_)      #"<<endl;
    cout<<"#         (_  _(_ ,)                                        #"<<endl;
    cout<<"#############################################################"<<endl;
    cout << "\n\tThis program determines who deserves to be the STAR!!!" << endl;
    cout << "\t(it is also for my CIS22A homework assignment)" << endl;
    cout << "\n\tContestants will be judged based on their highest average score" << endl;
    cout << "\n\tand The next winner will go to.. WHOLLYWOOD!\n\n" << endl;
}
/* ___________________________
 getScores
 This function reads the scores of each contestant
 from a file. It returns true in case of success, false otherwise.
 This function is to calculate a performer’s score; this function calls two functions: findLowest & findHighest
 ___________________________*/
 bool getScores(ifstream &inFile, string &name, double &score1, double &score2, double &score3, double &score4, double &score5)
{
    // cout << "This is the getScores function" << endl;
    if (inFile >> name >> score1 >> score2 >> score3 >> score4 >> score5)
        return 1;
    
    return 0;
}
/* ___________________________
 calcScore
 This function is to calculate a performer’s score;
 his function calls two functions: findLowest & findHighest
   ___________________________*/
double calcScore(double score1, double score2, double score3, double score4, double score5)
{
    double lowestScore = 0.0, highestScore = 0.0, sumScore = 0.0, finalScore = 0.0;
    
    cout << "\n\nCalculating the contestant's score...." << endl;
    lowestScore = findLowest(score1, score2, score3, score4, score5);
    cout << "The lowest number is:  " << lowestScore << endl;
    
    highestScore = findHighest(score1, score2, score3, score4, score5);
    cout << "The highest number is: " << highestScore << "\n\n";
    
    sumScore = score1 + score2 + score3 + score4 + score5 - lowestScore - highestScore;
    
    finalScore = sumScore / 3;
    
    return finalScore;
}

/*___________________________
 findLowest
 This function finds a performer's lowest score (out of 5)
 *the lowest score then will be dropped out of the calculation
 ____________________________*/
 
double findLowest(double score1, double score2, double score3, double score4, double score5)
{
    cout << "\n*******LOW**********" << endl;
    
    double lowestScore = 0.0;
    lowestScore = score1;
    
    if (score2 <= lowestScore)
        lowestScore = score2;
    
    if (score3 <= lowestScore)
        lowestScore = score3;
    
    if (score4 <= lowestScore)
        lowestScore = score4;
    
    if (score5 <= lowestScore)
        lowestScore = score5;
    
    return lowestScore;
}

/*___________________________
 findHighest
 This function finds a performer's highest score (out of 5)
 *the highest score then will be dropped out of the calculation
 ____________________________*/
double findHighest(double score1, double score2, double score3, double score4, double score5)
{
    cout << "\n*******HIGH*********" << endl;
    double highestScore = score1;
    
    if (score2 >= highestScore)
        highestScore = score2;
    
    if (score3 >= highestScore)
        highestScore = score3;
    
    if (score4 >= highestScore)
        highestScore = score4;
    
    if (score5 >= highestScore)
        highestScore = score5;
    
    return highestScore;
}
/*___________________________
 writeScore
This function is to write to the score the performers' on the file
 the file was defined above as "results.txt"
  ____________________________*/

void writeScore(ofstream &outFile, string name, double finalScore)
{
    outFile << name << ": " << finalScore << endl;
}
/*___________________________
 farewell
This function is to display an end-of-the-program message
such as: "Good bye ~"
  ____________________________*/
void farewell(void)
{
    cout << "AMERICA, YOU HAVE MADE YOUR CHOICE.." << endl;
    cout << "THE STAR HAS NOW BEEN DISCOVERED!" << endl;
    cout << "WE WILL SEE YOU NEXT TIME IN WHOLYWOOD!!!!!!!!!\n\n" << endl;
    
}


/* OUTPUT:
 
 ~~*~~PROJECT **STAR** SEARCH~~*~~
 
 #############################################################
 #                                                           #
 #                       ,                                   #
 #                    \  :  /                                #
 #                 `. __/ \__ .'                             #
 #                 _ _\     /_ _                             #
 #                    /_   _\                                #
 #                  .'  \ /  `.                              #
 #                    /  :  \                                #
 #                                                           #
 #                  _  _                                     #
 #                 ( `   )_                                  #
 #                (    )    `)                               #
 #              (_   (_ .  _) _)                             #
 #                                             _             #
 #                                            (  )           #
 #             _ .                         ( `  ) . )        #
 #           (  _ )_                      (_, _(  ,_)_)      #
 #         (_  _(_ ,)                                        #
 #############################################################
 
	This program determines who deserves to be the STAR!!!
	(it is also for my CIS22A homework assignment)
 
	Contestants will be judged based on their highest average score
 
	and The next winner will go to.. WHOLLYWOOD!
 
 
 
 
 Calculating the contestant's score....
 
 *******LOW**********
 The lowest number is:  7
 
 *******HIGH*********
 The highest number is: 7.9
 
 
 
 Calculating the contestant's score....
 
 *******LOW**********
 The lowest number is:  2.9
 
 *******HIGH*********
 The highest number is: 9.8
 
 
 
 Calculating the contestant's score....
 
 *******LOW**********
 The lowest number is:  7.9
 
 *******HIGH*********
 The highest number is: 8.9
 
 
 
 Calculating the contestant's score....
 
 *******LOW**********
 The lowest number is:  8.7
 
 *******HIGH*********
 The highest number is: 9.1
 
 
 
 Calculating the contestant's score....
 
 *******LOW**********
 The lowest number is:  8.8
 
 *******HIGH*********
 The highest number is: 9.7
 
 
 
 Calculating the contestant's score....
 
 *******LOW**********
 The lowest number is:  8.2
 
 *******HIGH*********
 The highest number is: 9.3
 
 
 
 Calculating the contestant's score....
 
 *******LOW**********
 The lowest number is:  5.6
 
 *******HIGH*********
 The highest number is: 9.9
 
 
 
 Calculating the contestant's score....
 
 *******LOW**********
 The lowest number is:  7.6
 
 *******HIGH*********
 The highest number is: 8.2
 
 
 
 
 We have the results!!!
 There were 8 contestants.....
 
 with an outstanding score of 9.13
 The winner of STAR SEARCH 2016 is........
 
 
 
 Ann!!!!
 
 
 AMERICA, YOU HAVE MADE YOUR CHOICE..
 THE STAR HAS NOW BEEN DISCOVERED!
 WE WILL SEE YOU NEXT TIME IN WHOLYWOOD!!!!!!!!!
 
 
 Program ended with exit code: 0*/
 






