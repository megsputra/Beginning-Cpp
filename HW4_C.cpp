/**
 PART C
 
 Project: Calculate average of even numbers, sum of the odd numbers,
 and number of the negative numbers.
 
 Rewrite this program using proper indentation and spacing.
 
 Run the program three times and save each output as a comment at the end
 of the source file.
 
 Mega Putra
 
 */

#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3, eSum, oSum, eCnt, oCnt, nCnt;
    double eAvg = 0;

    cout << "Enter three integers: ";
    cin >> n1 >> n2 >> n3;
    eSum = oSum = 0;
    eCnt = oCnt = nCnt = 0;
    
    if (n1 % 2 == 0)
    {
        eSum += n1;
        eCnt++;
    }
    else
    {
        oSum += n1;
        oCnt++;
    }
    
        if (n1 < 0)
            nCnt++;
    
            if (n2 % 2 == 0)
            {
                eSum += n2;
                eCnt++;
            }
            else
            {
                oSum += n2;
                oCnt++;
            }
    
        if (n2 < 0)
            nCnt++;
    
            if (n3 % 2 == 0)
            {
                eSum += n3;
                eCnt++;
            }
            else
            {
                oSum += n3; //changed n1 to n3
                oCnt++;
            }
    
        if (n3 < 0)
            nCnt++;
    
            if (eCnt > 0)
        
            eAvg = (double)eSum / eCnt;
    
    cout << "n1 = " << n1 << endl << "n2 = " << n2 << endl << "n3 = " << n3 << endl;
    (eCnt > 0) ? cout << "The average of the even numbers is " << eAvg << endl : cout << "There are no even numbers.\n";
    (oCnt > 0) ? cout << "The sum of the odd numbers is " << oSum << endl : cout << "There are no odd numbers\n";
    (nCnt > 0) ? cout << "There are/is " << nCnt <<  " negative number[s]\n" : cout << "There are no negative numbers.\n";
    
    return 0;
    
}

/*********************************************************************************
 Enter three integers: 239 100 -724
 n1 = 239
 n2 = 100
 n3 = -724
 The average of the even numbers is -312
 The sum of the odd numbers is 239
 There are/is 1 negative number[s]
 Program ended with exit code: 0
 */


/*********************************************************************************
 Enter three integers: -55 -28 -83
 n1 = -55
 n2 = -28
 n3 = -83
 The average of the even numbers is -28
 The sum of the odd numbers is -138
 There are/is 3 negative number[s]
 Program ended with exit code: 0
 */

/*********************************************************************************
 Enter three integers: 9800 1599 2481
 n1 = 9800
 n2 = 1599
 n3 = 2481
 The average of the even numbers is 9800
 The sum of the odd numbers is 4080
 There are no negative numbers.
 Program ended with exit code: 0
 */
